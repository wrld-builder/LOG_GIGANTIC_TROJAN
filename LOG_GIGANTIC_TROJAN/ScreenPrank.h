#pragma once

#include <Windows.h>
#include <ctime>
#include <random>
#include <thread>

#define screen_width GetSystemMetrics(SM_CXSCREEN)
#define screen_height GetSystemMetrics(SM_CYSCREEN)
#define distance 100

void swimScreen(HINSTANCE);
LRESULT CALLBACK Melt(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);