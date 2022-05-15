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