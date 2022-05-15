#include "Decryptor.h"

std::string DC_Decryptor::ed(std::string val, char key, int mode) {
  std::string output = val;
  if (mode) {
    for (int i = 0; i < val.size(); i++) {
      output[i] = val[i] - key;
    }
    return output;
  } else {
    for (int i = 0; i < val.size(); i++) {
      output[i] = val[i] + key;
    }
    return output;
  }
}