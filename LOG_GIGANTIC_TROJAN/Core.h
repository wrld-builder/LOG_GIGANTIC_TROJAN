#pragma once

#ifndef CORE
#define CORE

#include "Decryptor.h"
#include <fstream>
#include <Windows.h>

#pragma warning(disable : 4996)
#pragma warning(disable : 6001)
#pragma warning(disable : 6386)

class Core {
 private:
  inline bool isDirectoryExists(const char* filename);

 protected:
  HANDLE getFileNameToAutoSet() const;

 public:
  void BLoad(DC_Decryptor& enc) const;
  void mv(DC_Decryptor& enc, char *orig) const;
  void dlload(DC_Decryptor& enc) const;
  void createActiveFolderCheck();
  void autoRunSet();
};

#endif  // CORE
