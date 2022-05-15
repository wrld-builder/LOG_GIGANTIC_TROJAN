#pragma once

#include <fstream>
#include <exception>

#include "Core.h"

class Bin : protected Core {
 private:
  const char* SRC = "C:\\Windows\\Boot";
  const char* DEST = reinterpret_cast<const char*>(getFileNameToAutoSet());

 public:
  bool copyFile();
  void takeError() const;
};