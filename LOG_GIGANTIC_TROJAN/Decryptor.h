#pragma once

#include <string>

class DC_Decryptor {
 public:
  std::string ed(std::string val, char key, int mode);
};