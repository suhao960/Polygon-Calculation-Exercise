#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"Bank.h"
#include<fstream>
#include<sstream>
class Account
{
	string username;
	long long password;
	Bank* bank;
public:
	Account(string un, long long ps);
	//登录函数
	bool CheckAccount(Bank* bank);//该函数包括：   一个字符一个字符地读取文件，对文件中每个dollar后面的内容与参数进行比较，
											//到EOF都没匹配成功则返回false，若中途匹配到了则完善属性bankk返回true。
	void AssignOldBankToNewBank(Bank* bank);//该函数为上一个步骤的继续，将main函数中new的bank传入，把本类对象的bank的各值赋给它。
};

