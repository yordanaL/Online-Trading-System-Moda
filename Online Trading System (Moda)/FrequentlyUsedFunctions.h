#pragma once
#include <iostream>
#include "Constants.h"
#include <iomanip>
using namespace std;

void awaitingCommand();
bool checkInput();
void clearBuffer();
void newLine();
bool isNumber(char ch);

void setToCurrencyPrintFormat();
void resetPrintFormat();