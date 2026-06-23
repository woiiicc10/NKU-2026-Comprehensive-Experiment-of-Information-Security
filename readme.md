# Information Security Comprehensive Lab (Nankai University, 2026)

Personal coursework repository for **Information Security Comprehensive Experiment** at Nankai University (2026). It contains lab reports, screenshots, and source code.

> **Disclaimer:** Lab manuals and instructional videos are **not** included here (available on the course platform). Some steps were adapted when the campus network environment differed from the course videos. AI tools were used mainly for report writing and code assistance; experiment procedures and screenshots were completed manually. Reports reflect my own work and may contain errors.

---

## Repository Structure

```
.
├── lab1/          # Private CA & X.509 certificates (OpenSSL)
├── lab2/          # Web penetration testing (4 sessions)
├── lab3/          # WPA/WPA2 four-way handshake capture & analysis
├── lab4/          # HTTPS MITM with Burp Suite
├── lab5/          # Behavior monitoring vs. R77 Rootkit (report PDF only)
├── lab6/          # K-Means intrusion detection (KDDCUP99, C++)
└── readme.md
```

Each `labN/` folder typically contains:

| Item | Description |
|------|-------------|
| `report.md` / `实验报告.md` | Written lab report |
| `实验截图/` | Screenshots referenced in the report |
| Source code | Present where applicable (e.g. `lab6/`) |

---

## Lab Overview

| Lab | Topic | Environment & Tools | Key Outcomes |
|-----|-------|---------------------|--------------|
| **Lab 1** | Private CA certificate issuance | Ubuntu 20.04, OpenSSL | Built a private CA; issued server/client certs; revoked a cert; generated CRL |
| **Lab 2** | Web server injection & webshell control | Linux VM + Windows client | DDoS (LOIC), ARP spoofing (dsniff), SQL injection (sqlmap), cookie attacks, file inclusion, unsafe upload (Burp + AntSword) |
| **Lab 3** | WPA/WPA2 protocol analysis | Windows, Wireshark / Network Monitor | Captured 4 EAPOL-Key frames; analyzed Nonce, MIC, Replay Counter; compared WPA2 vs WPA3 |
| **Lab 4** | HTTPS MITM tampering | Windows PC + Android phone, Burp Suite | Trusted Burp CA on phone; intercepted and modified HTTPS responses (e.g. `hello` → `bbbb`) |
| **Lab 5** | Behavior monitoring & Rootkit evasion | Windows 10 VM, VS, Microsoft Detours, R77 | Hooked APIs with Detours; tested R77 hiding; built process-creation monitor via DLL injection |
| **Lab 6** | Intrusion detection with K-Means | Ubuntu, g++, KDDCUP99 | Preprocessed KDDCUP99 data; trained K-Means (K=5); ~96.4% accuracy on test set |

---

## Lab Details

### Lab 1 — Private CA Implementation

Understand PKI, X.509 certificates, and certificate lifecycle management using OpenSSL.

**Main steps:**
1. Create CA directory structure (`myCA/`) and initialize the certificate database
2. Generate a self-signed Root CA certificate (`cacert.pem`)
3. Generate server CSR and sign with the CA
4. Revoke the server certificate and verify status in `index` (V → R)
5. Generate and inspect CRL (`crl.pem`)
6. (Optional) Issue a client certificate

**Report:** [`lab1/实验报告.md`](lab1/实验报告.md)

---

### Lab 2 — Web Penetration Testing (4 Sessions)

Covers network-layer and application-layer attacks in a controlled lab environment.

| Session | Topics | Tools |
|---------|--------|-------|
| 1 | DDoS simulation, ARP spoofing | LOIC, dsniff (`arpspoof`) |
| 2 | SQL injection | sqlmap on a vulnerable PHP + MySQL app |
| 3 | Cookie attacks, local file inclusion (LFI) | Browser DevTools, path traversal (`../`) |
| 4 | Unsafe download/upload, PHP webshell | Burp Suite, AntSword (`<?php @eval($_POST['a']);?>`) |

**Report:** [`lab2/report.md`](lab2/report.md)

---

### Lab 3 — WPA/WPA2 Four-Way Handshake Analysis

Capture and analyze EAPOL-Key frames during WPA2-PSK association.

**Main steps:**
1. Enable a WPA2-PSK hotspot on a smartphone
2. Capture traffic on the wireless interface (Wireshark or Network Monitor)
3. Filter with `eapol` and identify 4 handshake frames
4. Analyze Key Information, ANonce, SNonce, MIC, Replay Counter
5. Research WPA3 improvements (SAE, forward secrecy, OWE)

**Artifacts:** `lab3/eapol.cap`, `lab3/wpa2_eapol.cap`, `lab3/eapol.md`  
**Report:** [`lab3/report.md`](lab3/report.md)

---

### Lab 4 — HTTPS MITM with Burp Suite

Demonstrate how trusting an attacker-controlled CA enables HTTPS interception and response tampering.

**Main steps:**
1. Export Burp CA certificate and install it on an Android phone
2. Share a Wi-Fi hotspot from the PC; configure phone proxy to Burp listener
3. Intercept HTTPS traffic in Burp Proxy
4. Enable response interception and modify content (demonstrated: search result `hello` → `bbbb`)

**Report:** [`lab4/report.md`](lab4/report.md)

---

### Lab 5 — Behavior Monitoring vs. R77 Rootkit

Study API hooking with Microsoft Detours and contrast it with R77 Ring-3 Rootkit hiding.

**Main steps:**
1. Build Detours and hook `MessageBoxW` to verify hook/unhook behavior
2. Install R77 and observe hiding of files, processes, registry keys, and network connections (names prefixed with `$77`)
3. Inject a monitoring DLL into `explorer.exe` to log `CreateProcess` calls
4. Observe monitoring blind spot after R77 overwrites hooks

**Note:** Only `lab5/report.pdf` is kept in this repo (source code was not committed).  
**Report:** [`lab5/report.pdf`](lab5/report.pdf)

---

### Lab 6 — K-Means Intrusion Detection

Cluster network connection records from the KDDCUP99 dataset using K-Means.

**Dataset:** Download from [Kaggle — KDDCUP 1999 Data](https://www.kaggle.com/datasets/galaxyh/kdd-cup-1999-data)

**Build & run (from `lab6/`):**

```bash
# 1. Preprocess raw data
g++ -std=c++11 -include cstdio -include cstring DataPretreat/DataPreTreat.cpp -o datatreat
./datatreat kddcup.data_10_percent
./datatreat corrected

# 2. Compile and run K-Means
g++ -std=c++11 -include cstdio -include cstring KMeans/Kmeans.cpp KMeans/ClusterTree.cpp -o kmeans
./kmeans
# Enter K value when prompted (default: 5)
```

**Result:** ~96.44% accuracy on 311,029 test records (K=5). Outputs: `Log.txt`, `Result.txt`.

**Report:** [`lab6/report.md`](lab6/report.md)

---

## Notes

- Reports are written in Chinese; this README summarizes content in English and Chinese.
- Large datasets (KDDCUP99), capture files, and compiled binaries are excluded per `.gitignore`.
- Lab 5 source code (`detours_test.cpp`, `injector.cpp`, `monitor_dll.cpp`) is embedded in the PDF report.

---

---

# 南开大学 2026 信息安全综合实验

本仓库为南开大学 **信息安全综合实验** 课程的个人作业归档，包含各次实验报告、截图及部分源代码。

> **说明：** 实验手册与教学视频未随仓库提交（可在课程平台「小雅」下载）。部分步骤因校园网环境变化与课程视频存在差异，已尽量复现实验效果。AI 工具主要用于实验报告与代码辅助，实验操作与截图为本人完成。报告内容不代表绝对正确，仅供参考。

---

## 仓库结构

```
.
├── lab1/          # 私有 CA 与 X.509 数字证书（OpenSSL）
├── lab2/          # Web 渗透测试（4 个课时）
├── lab3/          # WPA/WPA2 四次握手抓包与分析
├── lab4/          # Burp Suite 对 HTTPS 的中间人篡改
├── lab5/          # 行为监控与 R77 Rootkit 对抗（仅保留 PDF 报告）
├── lab6/          # K-Means 入侵检测（KDDCUP99，C++）
└── readme.md
```

各 `labN/` 目录通常包含：

| 内容 | 说明 |
|------|------|
| `report.md` / `实验报告.md` | 实验报告正文 |
| `实验截图/` | 报告中引用的截图 |
| 源代码 | 部分实验附带（如 `lab6/`） |

---

## 实验总览

| 实验 | 主题 | 环境与工具 | 主要成果 |
|------|------|-----------|----------|
| **实验 1** | 私有 CA 证书签发 | Ubuntu 20.04、OpenSSL | 搭建私有 CA；签发服务器/客户端证书；吊销证书；生成 CRL |
| **实验 2** | Web 注入与一句话木马 | Linux 虚拟机 + Windows 客户端 | DDoS（LOIC）、ARP 欺骗（dsniff）、SQL 注入（sqlmap）、Cookie 攻击、文件包含、不安全上传（Burp + 蚁剑） |
| **实验 3** | WPA/WPA2 协议分析 | Windows、Wireshark / Network Monitor | 捕获 4 个 EAPOL-Key 帧；分析 Nonce、MIC、Replay Counter；对比 WPA2 与 WPA3 |
| **实验 4** | HTTPS 中间人篡改 | Windows 电脑 + Android 手机、Burp Suite | 手机信任 Burp 证书；拦截并篡改 HTTPS 响应（如 `hello` → `bbbb`） |
| **实验 5** | 行为监控与 Rootkit 对抗 | Windows 10 虚拟机、VS、Detours、R77 | Detours 挂钩 API；验证 R77 隐藏效果；DLL 注入实现进程创建监控 |
| **实验 6** | K-Means 入侵检测 | Ubuntu、g++、KDDCUP99 | 数据预处理；K-Means 聚类（K=5）；测试集准确率约 96.4% |

---

## 各实验简介

### 实验 1 — 私有 CA 证书签发

使用 OpenSSL 理解 PKI 体系、X.509 证书结构与证书全生命周期管理。

**主要步骤：**
1. 创建 CA 目录结构（`myCA/`）并初始化证书数据库
2. 生成自签名根 CA 证书（`cacert.pem`）
3. 生成服务器 CSR 并由 CA 签发
4. 吊销服务器证书，在 `index` 中验证状态变化（V → R）
5. 生成并查看 CRL（`crl.pem`）
6. （补充）签发客户端证书

**报告：** [`lab1/实验报告.md`](lab1/实验报告.md)

---

### 实验 2 — Web 渗透测试（4 课时）

在受控实验环境中覆盖网络层与应用层攻击。

| 课时 | 内容 | 工具 |
|------|------|------|
| 1 | DDoS 模拟、ARP 欺骗 | LOIC、dsniff（`arpspoof`） |
| 2 | SQL 注入 | sqlmap + 漏洞 PHP/MySQL 靶场 |
| 3 | Cookie 攻击、本地文件包含（LFI） | 浏览器 F12、路径遍历（`../`） |
| 4 | 不安全下载/上传、PHP 一句话木马 | Burp Suite、蚁剑（`<?php @eval($_POST['a']);?>`） |

**报告：** [`lab2/report.md`](lab2/report.md)

---

### 实验 3 — WPA/WPA2 四次握手分析

抓取并分析 WPA2-PSK 关联过程中的 EAPOL-Key 帧。

**主要步骤：**
1. 手机开启 WPA2-PSK 热点
2. 在无线网卡接口抓包（Wireshark 或 Network Monitor）
3. 使用 `eapol` 过滤器定位 4 个握手帧
4. 分析 Key Information、ANonce、SNonce、MIC、Replay Counter 等字段
5. 调研 WPA3 改进（SAE、前向安全、OWE）

**附件：** `lab3/eapol.cap`、`lab3/wpa2_eapol.cap`、`lab3/eapol.md`  
**报告：** [`lab3/report.md`](lab3/report.md)

---

### 实验 4 — Burp Suite 对 HTTPS 的中间人篡改

演示在客户端信任攻击者 CA 后，如何解密、拦截并篡改 HTTPS 流量。

**主要步骤：**
1. 导出 Burp CA 证书并在 Android 手机上安装信任
2. PC 开启热点，手机配置代理指向 Burp 监听端口
3. 在 Burp Proxy 中拦截 HTTPS 请求
4. 开启响应拦截并修改内容（演示：搜索结果 `hello` 改为 `bbbb`）

**报告：** [`lab4/report.md`](lab4/report.md)

---

### 实验 5 — 行为监控与 R77 Rootkit 对抗

使用 Microsoft Detours 学习 API 挂钩，并与 R77 用户态 Rootkit 的隐藏能力进行对比。

**主要步骤：**
1. 编译 Detours，挂钩 `MessageBoxW` 验证挂钩/脱钩
2. 安装 R77，观察对文件、进程、注册表、网络连接的隐藏（`$77` 前缀）
3. 将监控 DLL 注入 `explorer.exe`，记录 `CreateProcess` 调用
4. 观察 R77 覆盖 Hook 后监控失效的对抗现象

**说明：** 本仓库仅保留 `lab5/report.pdf`（源代码未提交）。  
**报告：** [`lab5/report.pdf`](lab5/report.pdf)

---

### 实验 6 — K-Means 入侵检测

对 KDDCUP99 网络连接记录进行 K-Means 聚类，实现简单入侵检测。

**数据集：** [Kaggle — KDDCUP 1999 Data](https://www.kaggle.com/datasets/galaxyh/kdd-cup-1999-data)

**编译与运行（在 `lab6/` 目录下）：**

```bash
# 1. 数据预处理
g++ -std=c++11 -include cstdio -include cstring DataPretreat/DataPreTreat.cpp -o datatreat
./datatreat kddcup.data_10_percent
./datatreat corrected

# 2. 编译并运行 K-Means
g++ -std=c++11 -include cstdio -include cstring KMeans/Kmeans.cpp KMeans/ClusterTree.cpp -o kmeans
./kmeans
# 按提示输入 K 值（默认 5）
```

**结果：** K=5 时在 311,029 条测试记录上准确率约 **96.44%**。输出文件：`Log.txt`、`Result.txt`。

**报告：** [`lab6/report.md`](lab6/report.md)

---

## 其他说明

- 实验报告正文为中文；本 README 提供中英文对照概览。
- 大型数据集（KDDCUP99）、抓包文件、编译产物等已按 `.gitignore` 排除。
- 实验 5 完整源码（`detours_test.cpp`、`injector.cpp`、`monitor_dll.cpp`）附在 PDF 报告中。
