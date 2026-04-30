#include <windows.h>
#include <stdio.h>
#include <detours.h>
#include <string>

#pragma comment(lib, "user32.lib")

// 文件日志路径：直接写到用户桌面上，避免任何权限限制
const char* LOG_FILE = "C:\\Users\\lrj\\Desktop\\process_monitor.log";

// 原始 API 函数指针
static BOOL(WINAPI *TrueCreateProcessW)(
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
) = CreateProcessW;

static BOOL(WINAPI *TrueCreateProcessA)(
    LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
) = CreateProcessA;

// 记录日志的辅助函数
void LogProcessCreation(const char* funcName, const char* appName, const char* cmdLine) {
    FILE* file;
    // 使用追加模式，如果文件不存在则会创建。使用 _fsopen 以防止共享冲突
    if (fopen_s(&file, LOG_FILE, "a") == 0) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] [%s] AppName: %s | CmdLine: %s\n",
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond,
            funcName,
            appName ? appName : "NULL",
            cmdLine ? cmdLine : "NULL");
        fclose(file);
    }
}

// 帮助转换 WCHAR 到 char 的辅助函数
std::string WStringToString(const std::wstring& wstr) {
    if (wstr.empty()) return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

// 我们的 Hook 函数
BOOL WINAPI HookCreateProcessW(
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
) {
    std::string appName = lpApplicationName ? WStringToString(lpApplicationName) : "NULL";
    std::string cmdLine = lpCommandLine ? WStringToString(lpCommandLine) : "NULL";
    
    LogProcessCreation("CreateProcessW", appName.c_str(), cmdLine.c_str());

    return TrueCreateProcessW(
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation
    );
}

BOOL WINAPI HookCreateProcessA(
    LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
) {
    std::string appName = lpApplicationName ? lpApplicationName : "NULL";
    std::string cmdLine = lpCommandLine ? lpCommandLine : "NULL";

    LogProcessCreation("CreateProcessA", appName.c_str(), cmdLine.c_str());

    return TrueCreateProcessA(
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation
    );
}

// DLL 入口点
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    (void)hModule;
    (void)lpReserved;

    if (DetourIsHelperProcess()) {
        return TRUE;
    }

    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        
        DetourRestoreAfterWith();
        
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID&)TrueCreateProcessW, HookCreateProcessW);
        DetourAttach(&(PVOID&)TrueCreateProcessA, HookCreateProcessA);
        DetourTransactionCommit();
        
    } else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID&)TrueCreateProcessW, HookCreateProcessW);
        DetourDetach(&(PVOID&)TrueCreateProcessA, HookCreateProcessA);
        DetourTransactionCommit();
    }
    return TRUE;
}
