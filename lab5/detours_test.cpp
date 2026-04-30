#include <windows.h>
#include <iostream>
#include <string>
#include "detours.h"

// pointer to the original MessageBoxW
static int (WINAPI *TrueMessageBoxW)(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType) = MessageBoxW;

// our hooked MessageBoxW function
int WINAPI HookedMessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType) {
    std::cout << "\n[!] Intercepted MessageBoxW API call!\n";
    
    // Append the required string
    std::wstring newText = std::wstring(lpText) + L" (he hooked!)";
    std::wstring newCaption = L"[Detours Hooked] " + std::wstring(lpCaption);

    return TrueMessageBoxW(hWnd, newText.c_str(), newCaption.c_str(), uType);
}

int main() {
    std::cout << "===== Detours API Hook Basic Test =====\n\n";

    std::cout << "[Step 1] Calling original MessageBoxW ...\n";
    MessageBoxW(NULL, L"This is a normal message box.", L"Before Hook", MB_OK);

    // Initialize and install the hook
    std::cout << "\n[Step 2] Installing Detours Hook ...\n";
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)TrueMessageBoxW, HookedMessageBoxW);
    LONG error = DetourTransactionCommit();

    if (error == NO_ERROR) {
        std::cout << ">>> Hook installed successfully!\n\n";
        
        std::cout << "[Step 3] Calling MessageBoxW again, it should be intercepted ...\n";
        MessageBoxW(NULL, L"This is a normal message box.", L"After Hook", MB_OK);
    } else {
        std::cout << ">>> Failed to install Hook, error code: " << error << "\n";
    }

    // Remove the hook
    std::cout << "\n[Step 4] Removing Detours Hook ...\n";
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)TrueMessageBoxW, HookedMessageBoxW);
    DetourTransactionCommit();

    std::cout << "\n[Step 5] Hook removed. Calling MessageBoxW one last time ...\n";
    MessageBoxW(NULL, L"Hook removed. Back to normal.", L"After Unhook", MB_OK);

    std::cout << "\nPress Enter to exit.";
    std::cin.get();
    return 0;
}
