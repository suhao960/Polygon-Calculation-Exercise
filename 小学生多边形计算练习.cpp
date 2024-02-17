#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<graphics.h>
#include<easyx.h>
#include <conio.h>
#include"UserInteraction.h"
#include"UserRegisterSystem.h"
using namespace std;
#include"Bank.h"
#include"Account.h"
//一、实现翻页功能，每页最多显示10个题目，回顾练习界面最多显示5个题目。**********
//二、答题界面新增显示做题公式按钮(，按下后计时暂时停止)，显示各种题目的计算公式图片，按下返回后继续做题。ok
//三、查看成绩部分：新增勉励语句，鼓励小学生多做题。新增正确率。
//Bank新增做题时间，点击开始答题后开始计时（并将计时显示在屏幕上——创建一个专门计1s的变量，如果为1就调用一次显示时间函数），查看成绩可显示做题时间。ok
//
//第三次作业新增功能： 登录注册注销系统  与  题库存储系统位于同一个文件中，但两者分开进行
//第一：、 启动后用户选择登录、注册、注销；每个页面跳转后均有   确定、返回按钮。
// 一、点击登录，界面包含标题登录，用户名、密码，输入用户名和密码后点击确定，判断：①若与文件中的用户名和密码一致则登录成功，则流入该用户原来做过的题目进入题库，用户选择继续练习、回顾练习......
//////当点击继续练习并且提交后，自动储存此次练习的题目。 
// ②若输入的用户名找不到、用户名找到密码不对，则提示“输入账户或密码错误！”，
// 二、点击注册，界面包含标题注册，用户名、密码，输入完后点击确定，文件新建该用户输入的用户名和密码，为其开辟一段题库空间，进入开始练习菜单。
// 后续和登录一致
// 补充：注册时用户名不能和已有的相同！
// 三、点击注销，界面包含标题注销，用户名、密码，输入完点击确定后，在题库中找相应的用户名，如果密码也相同，则删除这个用户下面的题库。
// 
// 补充说明：登录现在只能查看以前的东西，不能再继续做题了，无流出。注册就只有流出没有流入！！！！！！
// 注册一次做题，登录多次回顾！！！！！！
// 
// 题库文件内容：
// 
//$“用户名”#“密码”
// 题库 用户输入的周长 面积//
// （正方形）//Z 1\n
// （长方形）//C 1 2\n
// （圆）    //Y 3\n
// （梯形）  //T 1 2 3 4\n
// （三角形）//S 1 2 3\n
//			 //***
// $
// 
// 
// 排名文件内容：
// 
// 用户名
// 做题时间 做题数量 正确率
// 
// 
// 

int main(int argv,const char* args[])
{
	initgraph(800, 600, EX_SHOWCONSOLE | EX_NOCLOSE);
	//登录注册系统
	
	Bank* bank = new Bank();
	int zh = UserRegisterSystem::FirstMenu(bank);
	if (zh == 1 || zh == 2)
	{
		int od = 1;
		while (od)
		{
			int ok = 1;
			//注册后进入：
			if (zh == 1)
			{
				UserInteraction::ShowMenuStart(bank);
				while (ok)
				{
					MOUSEMSG mouse = GetMouseMsg();
					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						if (mouse.x > 300 && mouse.x < 500 && mouse.y>180 && mouse.y < 280)
						{
							bank->InitBank(UserInteraction::InputBoxatBeginning());//初始化操作完成
							UserInteraction::QuestionMenu(bank);
							ok = 0;
						}
						else if (mouse.x > 300 && mouse.x < 500 && mouse.y>350 && mouse.y < 450)
						{
							if (bank->GetQBNum() == 0)
								bank->SaveOnlyForLogon();
							else if (bank->GetQBNum() != 0)
								bank->SaveQuestionForLogonWay();
							ok = 0;
							od = 0;
							HWND hnd = GetHWnd();
							MessageBox(hnd, _T("已保存！"), _T("提示"), MB_OKCANCEL);
						}
					}
				}
			}
			//登录后进入：
			else if (zh == 2)
			{
				bank->AccumulateEveryandAllandAveragescore();//由于已经初始化了题库数量、题目内容、用户输入。此时先计算正确答案、用户分数、正确率。
				UserInteraction::StreamInRankText();
				UserInteraction::SetBankTimer(bank);//初始化时间
				int okk = 1;
				while (okk)
				{
					UserInteraction::ShowMenuPartTwo(bank);
					while (okk)
					{
						MOUSEMSG mouse = GetMouseMsg();
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (mouse.x > 300 && mouse.x < 500 && mouse.y>130 && mouse.y < 230)
							{
								UserInteraction::ShowRankMenu(bank);//**********important one
								break;
							}
							else if (mouse.x > 300 && mouse.x < 500 && mouse.y>250 && mouse.y < 350)
							{
								UserInteraction::ShowScore(bank);
								break;
							}
							else if (mouse.x > 300 && mouse.x < 500 && mouse.y>370 && mouse.y < 470)
							{
								UserInteraction::ShowFormerPactice(bank);
								break;
							}
							else if (mouse.x > 300 && mouse.x < 500 && mouse.y>490 && mouse.y < 590)
							{
								okk = 0;
							}
						}
					}
				}
				break;
			}
		}
	}
	delete bank;
	return 0;
}
