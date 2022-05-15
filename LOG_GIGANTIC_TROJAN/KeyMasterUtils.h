#pragma once

#include <AclAPI.h>
#include <Windows.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "Sddl.h"

class Utils {
 public:
  std::string FindPath();
  LPCWSTR Path();
  std::string FindDir();
  bool Screenshot(int x, int y, int width, int height, char* filename,
                  HWND hwnd);
};
