#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<easyx.h>
#include<graphics.h>
#include <conio.h>
#include<iostream>
using namespace std;
#include"Bank.h"
#include "Account.h"
#include<time.h>
#include<fstream>
class UserRegisterSystem
{
public:
	inline static TCHAR s[] = _T("黑体");
	static int FirstMenu(Bank* bank);
	static int Register(Bank* bank);
	static int Logon(Bank* bank);
	static bool JudgeInput(wchar_t s[]);

	static char* WCharToChar(const wchar_t* s);
};

