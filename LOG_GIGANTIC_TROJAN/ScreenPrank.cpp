#include "ScreenPrank.h"

void swimScreen(HINSTANCE inst) {
  ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
  WNDCLASS window_class_ = {
      0, Melt, 0,         0, inst, 0, LoadCursorW(0, (LPCWSTR)IDC_ARROW),
      0, 0,    "Swimming"};

  if (RegisterClass(&window_class_)) {
    HWND hwnd =
        CreateWindowExA(WS_EX_TOPMOST, "Swimming", 0, WS_POPUP, 0, 0,
                        screen_width, screen_height, HWND_DESKTOP, 0, inst, 0);

    if (hwnd) {
      srand(GetTickCount64());
      MSG msg_ = {0};
      while (msg_.message != WM_QUIT) {
        if (PeekMessage(&msg_, 0, 0, 0, PM_REMOVE)) {
          TranslateMessage(&msg_);
          DispatchMessage(&msg_);
        }
      }
    }
  }
}

LRESULT CALLBACK Melt(HWND hwnd, UINT msg, WPARAM w_param,
                                    LPARAM l_param) {
  switch (msg) {
    case WM_CREATE: {
      HDC desktop = GetDC(HWND_DESKTOP);
      HDC window = GetDC(hwnd);
      BitBlt(window, 0, 0, screen_width, screen_height,
             desktop, 0, 0, SRCCOPY);
      ReleaseDC(hwnd, window);
      ReleaseDC(HWND_DESKTOP, desktop);
      SetTimer(hwnd, 0, distance, 0);
      ShowWindow(hwnd, SW_SHOW);
      break;
    }
    case WM_PAINT: {
      ValidateRect(hwnd, 0);
      break;
    }
    case WM_TIMER: {
      HDC window_ = GetDC(hwnd);
      int x = (std::rand() % screen_width - (200 / 2));
      int y = std::rand() % 15;
      int width_ = std::rand() % 200;
      BitBlt(window_, x, y, width_, screen_height, window_, x, 0,
             SRCCOPY);
      ReleaseDC(hwnd, window_);
      break;
    }
    case WM_DESTROY: {
      KillTimer(hwnd, 0);
      PostQuitMessage(0);
      break;
    }
  }

  return DefWindowProc(hwnd, msg, w_param, l_param);
}