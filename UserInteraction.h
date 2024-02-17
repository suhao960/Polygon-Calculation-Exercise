#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<easyx.h>
#include<graphics.h>
#include <conio.h>
#include<iostream>
#include<string>
using namespace std;
#include"Bank.h"
#include<time.h>
#include<sstream>
class UserInteraction
{
public:
	struct User
	{
		string name;
		float timer;
		int QB_num;
		float rightrate;
	};
	inline static struct User user[50];
	inline static int user_number = 0;
	inline static float timer = 0, t1 = 0, t2 = 0, tf = 0, c1 = 0, c2 = 0;
	inline static int practice = 0;
	inline static int temp = 0;
	static void ShowMenuStart(Bank* bank);//程序一开始的菜单
	static void ShowMenuPartTwo(Bank* bank);//做过至少一次练习之后的菜单
	static void QuestionMenu(Bank* bank);//*****开始答题前预览题目的界面，里面包含了调用开始答题界面的接口。——最上面显示Preview，一页最多展示5个题，字号大一点
	static void AnswerQuestions(Bank* bank);//*****开始答题时的界面——  一页最多展示4个题，字号大一点
	static void PreviewOneQuestion();
	static void ShowFormerPactice(Bank* bank);//okk展示已经练习过的题目的界面
	static void ShowOneQuestion(Bank* bank, int i, int x1, int y1, int w1, int h1, int tx1, int ty1);
	static void ShowScore(Bank* bank);//展示分数、正确率、答题时间等的界面
	static int InputBoxatBeginning();//用于弹出输入练习题目数量并返回整数的输入框
	static void DisplayFormula();//展示公式的界面
	static void ShowRankMenu(Bank* bank);//依次每行展示每个用户做题时间、正确率、做题数量。（这几样单独开一个文件做）
	static void ShowRightRateRank(Bank* bank);//展示按正确率的排名，后面带上做题数量
	static void ShowTimerRank(Bank* bank);//展示做题时间的排名，后面带上题目数量
	static void SetBankTimer(Bank* bank);//为题库初始化时间
	static void StreamInRankText();//把Rank.text数据流入程序（填充结构体）
};

