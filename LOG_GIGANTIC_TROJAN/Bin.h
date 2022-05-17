#pragma once

#include <fstream>
#include <exception>
#include <Windows.h>
#include <iostream>

class Bin {
 private:
  HANDLE getFileNameToAutoSet() const;
  const char* SRC = "C:\\Windows\\Boot";
  const char* DEST = reinterpret_cast<const char*>(getFileNameToAutoSet());

 public:
  bool copyFile();
  void takeError() const;
};