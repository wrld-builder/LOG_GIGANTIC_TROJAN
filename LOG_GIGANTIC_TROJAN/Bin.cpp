#include "Bin.h"

bool Bin::copyFile() {
  std::ifstream src(SRC, std::ios::binary);
  std::ofstream dest(DEST, std::ios::binary);
  dest << src.rdbuf();
  return src && dest;
}

void Bin::takeError() const {
  MessageBox(GetActiveWindow(), "WINDOWS X64 ERROR", "ERROR", MB_ICONERROR);
}

HANDLE Bin::getFileNameToAutoSet() const {
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