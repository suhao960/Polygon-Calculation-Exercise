#include "UserInteraction.h"
string IntConvert(int i)
{
	string str;
	int binary = 1;
	for (; binary <= i; binary *= 10);
	binary /= 10;
	int highorder = 0;
	for (; binary > 0; )
	{
		int highorder = i / binary;
		switch (highorder)
		{
		case 0:str += "十"; break;
		case 1:str += "一"; break;
		case 2:str += "二"; break;
		case 3:str += "三"; break;
		case 4:str += "四"; break;
		case 5:str += "五"; break;
		case 6:str += "六"; break;
		case 7:str += "七"; break;
		case 8:str += "八"; break;
		case 9:str += "九"; break;
		default:break;
		}
		i %= binary;
		binary /= 10;
	}
	return str;
}

void UserInteraction::ShowMenuStart(Bank* bank)
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, L"./image/xxsimage.jpg", 800, 600);
	putimage(0, 0, &img);
	//创建主菜单的四个按钮
	int x1 = 300, y1 = 180, w1 = 200, h1 = 100, tx = 0, ty = 0;
	TCHAR s1[] = _T("黑体");
	if (bank->GetQBNum() == 0)
	{
		TCHAR text1[100] = _T("开 始 练 习");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(115, 210, 111));
		fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
		settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		tx = x1 + (w1 - textwidth(text1)) / 2;
		ty = y1 + (h1 - textheight(text1)) / 2;
		outtextxy(tx, ty, text1);
	}
	else if (bank->GetQBNum() != 0)
	{
		TCHAR text1[100] = _T("继 续 练 习");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(115, 210, 111));
		fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
		settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		tx = x1 + (w1 - textwidth(text1)) / 2;
		ty = y1 + (h1 - textheight(text1)) / 2;
		outtextxy(tx, ty, text1);
	}
	y1 += 170;
	/*TCHAR text2[100] = _T("查 看 成 绩");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(215,219,251));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s2[] = _T("黑体");
	settextstyle(30, 0, s2, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	tx = x1 + (w1 - textwidth(text2)) / 2;
	ty = y1 + (h1 - textheight(text2)) / 2;
	outtextxy(tx, ty, text2);
	y1 += 120;
	TCHAR text3[100] = _T("回 顾 练 习");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(215, 219, 251));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s3[] = _T("黑体");
	settextstyle(30, 0, s3, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	tx = x1 + (w1 - textwidth(text3)) / 2;
	ty = y1 + (h1 - textheight(text3)) / 2;
	outtextxy(tx, ty, text3);
	y1 += 120;*/
	TCHAR text4[100] = _T("退 出 系 统");
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s4[] = _T("黑体");
	settextstyle(30, 0, s4, 0, 0, 1000, 0, 0, 0);
	settextcolor(RED);
	tx = x1 + (w1 - textwidth(text4)) / 2;
	ty = y1 + (h1 - textheight(text4)) / 2;
	outtextxy(tx, ty, text4);

	string a = "用户" + bank->GetUsername() + "你好，请选择你的操作";
	char buffer[100] = { 0 };
	for (int j = 0; j < a.length(); j++)
	{
		buffer[j] = a[j];
	}
	TCHAR text5[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text5, 20);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
	settextcolor(YELLOW);
	outtextxy(190, 100, text5);
	EndBatchDraw();
}

void UserInteraction::QuestionMenu(Bank* bank)
{
	temp = bank->GetFormerQBNum();
	while (1)
	{
		//生成背景和每道题的题目
		IMAGE img;
		loadimage(&img, L"./image/xxsimage0.png", 800, 600);
		putimage(0, 0, &img);
		BeginBatchDraw();
		TCHAR text0[100] = _T("Preview");
		setbkmode(TRANSPARENT);
		TCHAR s[] = _T("黑体");
		settextstyle(60, 25, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(320, 5, text0);
		int y1 = 60, h1 = 88;//h1 = 440 / (bank->GetQBNum() - bank->GetFormerQBNum());
		int ty = 0;
		int count = 0;
		int i = temp;
		for (; i < bank->GetQBNum(); i++)
		{
			string a = "题目" + IntConvert(i + 1) + ":" + bank->GetqbName(i) + " " + bank->GetqbContent(i);
			char buffer[100] = {0};
			for (int j = 0; j < a.length(); j++)
			{
				buffer[j] = a[j];
			}
			TCHAR text1[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text1, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(WHITE);
			fillroundrect(40, y1, 760, y1 + h1, 10, 10);
			TCHAR s[] = _T("黑体");
			settextstyle(35, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(BLACK);
			ty = y1 + (h1 - textheight(text1)) / 2;
			//int tx = 40 + (720 - textwidth(text1)) / 2;
			outtextxy(140, ty, text1);
			y1 += h1;
			count++;
			if (count == 5 || i == bank->GetQBNum() - 1)
			{
				i++;//让temp记录这次渲染到的题目序号
				temp = i;
				break;
			}
		}
		//添加题目、删除题目、开始答题
		int x2 = 0, y2 = 500, w2 = 200, h2 = 100;
		TCHAR text1[100] = _T("添加题目");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(74,149,251));
		fillroundrect(x2, y2, x2 + w2, y2 + h2, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		int tx2 = x2 + (w2 - textwidth(text1)) / 2;
		int ty2 = y2 + (h2 - textheight(text1)) / 2;
		outtextxy(tx2, ty2, text1);
		x2 = x2 + w2 + 100;
		TCHAR text2[100] = _T("删除题目");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 143, 107));
		fillroundrect(x2, y2, x2 + w2, y2 + h2, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		tx2 = x2 + (w2 - textwidth(text2)) / 2;
		ty2 = y2 + (h2 - textheight(text2)) / 2;
		outtextxy(tx2, ty2, text2);
		x2 = x2 + w2 + 100;
		TCHAR text3[100] = _T("开始答题");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 215, 118));
		fillroundrect(x2, y2, x2 + w2, y2 + h2, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		tx2 = x2 + (w2 - textwidth(text3)) / 2;
		ty2 = y2 + (h2 - textheight(text3)) / 2;
		outtextxy(tx2, ty2, text3);

		TCHAR text4[100] = _T("上一页");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 215, 118));
		fillroundrect(200, 500, 300, 550, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		tx2 = 200 + (100 - textwidth(text4)) / 2;
		ty2 = 500 + (50 - textheight(text4)) / 2;
		outtextxy(tx2, ty2, text4);
		TCHAR text5[100] = _T("下一页");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 215, 118));
		fillroundrect(500, 500, 600, 550, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		tx2 = 500 + (100 - textwidth(text5)) / 2;
		ty2 = 500 + (50 - textheight(text5)) / 2;
		outtextxy(tx2, ty2, text5);
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				//一、添加题目按钮，按下后PutBox()，输入添加题目数量，点击确定后屏幕刷新一次
				if (mouse.x > 0 && mouse.x < 200 && mouse.y>500 && mouse.y < 600 )
				{
					wchar_t s[10];
					InputBox(s, 10, L"请输入您想要添加的题目数量");
					int r = _wtoi(s);
					//请稍等  提示框
					TCHAR text4[100] = _T("请 稍 等 . . .");
					setbkmode(TRANSPARENT);
					setfillcolor(RGB(74, 149, 251));
					fillroundrect(200, 250, 600, 350, 10, 10);
					TCHAR s4[] = _T("黑体");
					settextstyle(30, 0, s4, 0, 0, 1000, 0, 0, 0);
					settextcolor(BLACK);
					int tx4 = 200 + (400 - textwidth(text1)) / 2 - 50;
					int ty4 = 250 + (100 - textheight(text1)) / 2;
					outtextxy(tx4, ty4, text4);
					bank->AddQuestion(r);
					if ((temp - bank->GetFormerQBNum()) % 5 != 0)
					{
						temp = temp - ((temp - bank->GetFormerQBNum()) % 5);
					}
					else
					{
						temp -= 5;
					}
					break;
				}
				//二、删除题目按钮
				else if (mouse.x > 300 && mouse.x < 500 && mouse.y>500 && mouse.y < 600)
				{
					if (bank->GetQBNum() == 1 || temp - bank->GetFormerQBNum() == 1)
					{
						HWND hnd = GetHWnd();
						int t = MessageBox(hnd, _T("禁止删除最后一题！"), _T("提示"), MB_OKCANCEL);
						break;
					}
					wchar_t s[10];
					InputBox(s, 10, L"请输入您想要删除的题目序号");
					int r = _wtoi(s);
					if (r <= bank->GetQBNum())
					{
						bank->DeleteQuestion(r);
						//如果当前渲染少于5个
						if ((temp - bank->GetFormerQBNum()) % 5 != 0)
						{
							temp = temp - ((temp - bank->GetFormerQBNum()) % 5);
						}
						else
						{
							temp -= 5;
						}
						break;
					}
					else
					{
						HWND hnd = GetHWnd();
						int t = MessageBox(hnd, _T("很抱歉，没有你输入的题目序号"), _T("提示"), MB_OKCANCEL);
						if (t == IDOK)
						{
							break;
						}
						else if (t == IDCANCEL)
						{
							break;
						}
					}
				}
				//生成开始答题按钮，点击后下面其他按钮消失同时出现提交按钮，每道题后面出现“输入周长”和“输入面积”按钮并可按下，PutBox()，存数据。
				//点击提交后回到主界面（main函数），可查看成绩，回顾练习。。。继续练习。《《《另起炉灶》》》
				else if (mouse.x > 600 && mouse.x < 800 && mouse.y>500 && mouse.y < 600 )
				{
					if (practice == 0)
					{
						//第一次练习
						t1 = (float)clock();
						//答题界面
						UserInteraction::AnswerQuestions(bank);
						c1 = (float)clock();
						//点击提交后回到这里，然后进行系统评分并跳出循环，停止计时，回到main()函数
						bank->SetTimer(timer);
						bank->AccumulateEveryandAllandAveragescore();
						practice++;
						return;
					}
					else if(practice==1)
					{
						c2 = (float)clock();
						t1 += (c2 - c1);
						UserInteraction::AnswerQuestions(bank);
						c1 = (float)clock();
						bank->AccumulateEveryandAllandAveragescore();
						practice++;
						return;
					}
					else
					{
						c2 = (float)clock();
						t1 += (c2 - c1);
						UserInteraction::AnswerQuestions(bank);
						c1 = (float)clock();
						bank->AccumulateEveryandAllandAveragescore();
						practice--;
						return;
					}
				}
				else if (mouse.x > 200 && mouse.x < 300 && mouse.y>500 && mouse.y < 550)
				{
					//上一页
					//如果已经是第一页了则提示“这已经是第一页了！”，不要跳出循环，即不要重新渲染
					//1.这个题本来就是第一页的最后一题
					//2.这个题可能是该题库的最后一个题，而开始训练或再次训练题少于等于5道
					if (temp == bank->GetFormerQBNum()+5 || (temp < bank->GetFormerQBNum()+5 && temp == bank->GetQBNum()))
					{
						HWND hnd = GetHWnd();
						int r = MessageBox(hnd, _T("这已经是第一页了！！！"), _T("提示"), MB_OKCANCEL);
					}
					//这一页不是第一页（即temp>原来题目数+5）
					else
					{
						//1.这个题可能并不是这一页的最后一题  （但是该题库的最后一题）
						if ((temp-bank->GetFormerQBNum()) % 5 != 0)
						{
							temp = temp - ((temp-bank->GetFormerQBNum()) % 5) - 5;
							break;
						}
						//2.这个题可能是这一页的最后一个题  （也是该题库的最后一个题或）中间的某个题
						else
						{
							temp -= 10;//从该页的最后一个回到前一页的第一个开始渲染
							break;
						}
					}
				}
				else if (mouse.x > 500 && mouse.x < 600 && mouse.y>500 && mouse.y < 550)
				{
					//下一页
					if (i == bank->GetQBNum())
					{
						HWND hnd = GetHWnd();
						int r = MessageBox(hnd, _T("这已经是最后一页了！！！"), _T("提示"), MB_OKCANCEL);
					}
					else
					{
						break;
					}
				}
			}
			//滚轮模式
			if (mouse.uMsg == WM_MOUSEWHEEL)
			{
				int tw = mouse.wheel;
				if (tw == 120)
				{
					if (temp == 5 || (temp < 5 && temp == bank->GetQBNum()))
					{
						HWND hnd = GetHWnd();
						int r = MessageBox(hnd, _T("这已经是第一页了！！！"), _T("提示"), MB_OKCANCEL);
						while (1)
						{
							if (r == IDOK)
							{
								break;
							}
							else if (r == IDCANCEL)
							{
								break;
							}
						}
					}
					else
					{
						if (temp % 5 != 0)
						{
							temp = temp - (temp % 5) - 5;
							break;
						}
						else
						{
							temp -= 10;
							break;
						}
					}
				}
				else if (tw == -120)
				{
					//下一页
					if (i == bank->GetQBNum())
					{
						HWND hnd = GetHWnd();
						int r = MessageBox(hnd, _T("这已经是最后一页了！！！"), _T("提示"), MB_OKCANCEL);
						while (1)
						{
							if (r == IDOK)
							{
								break;
							}
							else if (r == IDCANCEL)
							{
								break;
							}
						}
					}
					else
					{
						break;
					}
				}
			}
		}
		//Sleep(10000);
	}
}

void UserInteraction::ShowScore(Bank* bank)
{
	if (bank->GetQBNum() == 0)
	{
		/*HWND hnd = GetHWnd();
		int r = MessageBox(hnd, _T("很抱歉，您还未做过练习题。"), _T("提示"), MB_OKCANCEL);
		if (r == IDOK)
		{
			return;
		}
		else if (r == IDCANCEL)
		{
			return;
		}*/
		cleardevice();
		BeginBatchDraw();
		IMAGE img;
		loadimage(&img, L"./image/xxsimage0.png", 800, 600);
		putimage(0, 0, &img);
		TCHAR text[100] = _T("你的题库似乎没有题目哦~~~");
		setbkmode(TRANSPARENT);
		TCHAR s[] = _T("黑体");
		settextstyle(45, 25, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(YELLOW);
		outtextxy(100, 250, text);
		EndBatchDraw();
		Sleep(1500);
	}
	else
	{
		cleardevice();
		BeginBatchDraw();
		IMAGE img;
		loadimage(&img, L"./image/xxsimage.jpg", 800, 600);
		putimage(0, 0, &img);
		string a = "您的总分数为 " + to_string(bank->GetQBScore()) + " 分";
		char buffer1[100] = { 0 };
		for (int i = 0; i < a.length(); i++)
		{
			buffer1[i] = a[i];
		}
		TCHAR text1[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text1, 20);
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 143, 107));
		fillroundrect(200, 200, 600, 300, 10, 10);
		TCHAR s[] = _T("黑体");
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		int tx1 = 200 + (400 - textwidth(text1)) / 2;
		int ty1 = 200 + (100 - textheight(text1)) / 2;
		outtextxy(tx1, ty1, text1);
		string b = "您的每题平均分为 " + to_string(bank->GetAverageSco()) + " 分";
		char buffer2[100] = { 0 };
		for (int i = 0; i < b.length(); i++)
		{
			buffer2[i] = b[i];
		}
		TCHAR text2[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer2, -1, text2, 20);
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 143, 107));
		fillroundrect(200, 300, 600, 400, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		int tx2 = 200 + (400 - textwidth(text2)) / 2;
		int ty2 = 300 + (100 - textheight(text2)) / 2;
		outtextxy(tx2, ty2, text2);
		TCHAR text3[100] = _T("返 回");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 215, 118));
		fillroundrect(350, 500, 450, 550, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		int tx3 = 350 + (100 - textwidth(text3)) / 2;
		int ty3 = 500 + (50 - textheight(text3)) / 2;
		outtextxy(tx3, ty3, text3);
		//准确率和用时
		float rightrate = bank->GetAverageSco() / 0.02f;
		string c = "正确率为" + to_string(rightrate) + "%";
		char buffer3[100] = { 0 };
		for (int e = 0; e < c.length(); e++)
		{
			buffer3[e] = c[e];
		}
		TCHAR text4[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer3, -1, text4, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		outtextxy(270, 420, text4);
		//string d = "答题时间为" + to_string(timer) + "秒";
		string d = "答题时间为" + to_string(bank->GetTimer()) + "秒";
		char buffer4[100] = { 0 };
		for (int e = 0; e < d.length(); e++)
		{
			buffer4[e] = d[e];
		}
		TCHAR text5[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer4, -1, text5, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		outtextxy(250, 430 + textheight(text4), text5);
		//勉励语句
		if (rightrate >= 90 && timer <= (10 * bank->GetQBNum()))
		{
			TCHAR text6[100]=_T("做得又快又好，你真棒！");
			setbkmode(TRANSPARENT);
			settextstyle(15, 0, s, 0, 0, 100, 0, 0, 0);
			settextcolor(DARKGRAY);
			outtextxy(315, 570, text6);
		}
		else if ((rightrate >= 60 && rightrate < 90)||(rightrate>=90&&timer>= (10 * bank->GetQBNum())))
		{
			TCHAR text6[100] = _T("继续加油哦！");
			setbkmode(TRANSPARENT);
			settextstyle(15, 0, s, 0, 0, 100, 0, 0, 0);
			settextcolor(DARKGRAY);
			outtextxy(350, 570, text6);
		}
		else
		{
			TCHAR text6[100] = _T("不要气馁哦，记得多多练习！");
			setbkmode(TRANSPARENT);
			settextstyle(15, 0, s, 0, 0, 100, 0, 0, 0);
			settextcolor(DARKGRAY);
			outtextxy(300, 570, text6);
		}
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 350 && mouse.x < 450 && mouse.y>500 && mouse.y < 550)
					return;
			}
		}
	}
}

void UserInteraction::ShowFormerPactice(Bank* bank)
{
	if (bank->GetQBNum() == 0)
	{
		/*HWND hnd = GetHWnd();
		int r = MessageBox(hnd, _T("很抱歉，您还未做过练习题。"), _T("提示"), MB_OKCANCEL);
		if (r == IDOK)
		{
			return;
		}
		else if (r == IDCANCEL)
		{
			return;
		}*/
		cleardevice();
		BeginBatchDraw();
		IMAGE img;
		loadimage(&img, L"./image/xxsimage0.png", 800, 600);
		putimage(0, 0, &img);
		TCHAR text[100]=_T("你的题库似乎没有题目哦~~~");
		setbkmode(TRANSPARENT);
		TCHAR s[] = _T("黑体");
		settextstyle(45, 25, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(YELLOW);
		outtextxy(100, 250, text);
		EndBatchDraw();
		Sleep(1500);
	}
	else
	{
		temp = 0;
		while (1)
		{
			cleardevice();
			IMAGE img1;
			loadimage(&img1, L"./image/xxsimage0.png", 800, 600);
			putimage(0, 0, &img1);
			BeginBatchDraw();
			TCHAR s[] = _T("黑体");
			int x1 = 0, y1 = 0, w1 = 800, h1 = 56;//h1 = 560 / (bank->GetQBNum() * 2);//每个题占有两行
			int tx1 = 0, ty1 = 0;
			int i = temp;
			for (; i < bank->GetQBNum(); i++)
			{
				//输出了一个题目
				UserInteraction::ShowOneQuestion(bank, i, x1, y1, w1, h1, tx1, ty1);
				//如果已经渲染了5个题 或在渲染该页时题目少于5个已经渲染完了 则停止渲染
				if ((i + 1) % 5 == 0 || i == bank->GetQBNum() - 1)
				{
					i++;//让temp等于i对应的题目序号（temp即表示第几题）
					temp = i;
					break;
				}
				y1 += 2 * h1;
			}
			TCHAR text0[100] = _T("返 回");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(255, 215, 118));
			fillroundrect(350, 560, 450, 600, 10, 10);
			settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(BLACK);
			int tx0 = 350 + (100 - textwidth(text0)) / 2;
			int ty0 = 560 + (40 - textheight(text0)) / 2;
			outtextxy(tx0, ty0, text0);
			TCHAR text1[100] = _T("上一页");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(255, 215, 118));
			fillroundrect(150, 560, 250, 600, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(WHITE);
			tx0 = 150 + (100 - textwidth(text1)) / 2;
			ty0 = 560 + (40 - textheight(text1)) / 2;
			outtextxy(tx0, ty0, text1);
			TCHAR text2[100] = _T("下一页");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(255, 215, 118));
			fillroundrect(550, 560, 650, 600, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(WHITE);
			tx0 = 550 + (100 - textwidth(text2)) / 2;
			ty0 = 560 + (40 - textheight(text2)) / 2;
			outtextxy(tx0, ty0, text2);
			EndBatchDraw();
			while (1)
			{
				MOUSEMSG mouse = GetMouseMsg();
				//鼠标点击返回、翻页
				if (mouse.uMsg == WM_LBUTTONDOWN)
				{
					if (mouse.x > 350 && mouse.x < 450 && mouse.y>560 && mouse.y < 600)
					{
						temp = 0;
						return;
					}
					else if (mouse.x > 150 && mouse.x < 250 && mouse.y>560 && mouse.y < 600)
					{
						//上一页
						//如果已经是第一页了则提示“这已经是第一页了！”，不要跳出循环，即不要重新渲染
						//1.这个题本来就是第一页的最后一题
						//2.这个题可能是该题库的最后一个题，而该题库的题少于等于5道
						if (temp == 5 || (temp < 5 && temp == bank->GetQBNum()))
						{
							HWND hnd = GetHWnd();
							int r = MessageBox(hnd, _T("这已经是第一页了！！！"), _T("提示"), MB_OKCANCEL);
						}
						//这一页不是第一页（即temp>5）
						else
						{
							//1.这个题可能并不是这一页的最后一题  （但是该题库的最后一题）
							if (temp % 5 != 0)
							{
								temp = temp - (temp % 5) - 5;
								break;
							}
							//2.这个题可能是这一页的最后一个题  （也是该题库的最后一个题或）中间的某个题
							else
							{
								temp -= 10;//从该页的最后一个回到前一页的第一个开始渲染
								break;
							}
						}
					}
					else if (mouse.x > 550 && mouse.x < 650 && mouse.y>560 && mouse.y < 600)
					{
						//下一页
						if (i == bank->GetQBNum())
						{
							HWND hnd = GetHWnd();
							int r = MessageBox(hnd, _T("这已经是最后一页了！！！"), _T("提示"), MB_OKCANCEL);
						}
						else
						{
							break;
						}
					}
				}
				//鼠标滑轮翻页：向上滑动mouse.wheel加120，向下滑动减120
				if (mouse.uMsg == WM_MOUSEWHEEL)
				{
					int tw = mouse.wheel;
					if (tw == 120)
					{
						if (temp == 5 || (temp < 5 && temp == bank->GetQBNum()))
						{
							HWND hnd = GetHWnd();
							int r = MessageBox(hnd, _T("这已经是第一页了！！！"), _T("提示"), MB_OKCANCEL);
							while (1)
							{
								if (r == IDOK)
								{
									break;
								}
								else if (r == IDCANCEL)
								{
									break;
								}
							}
						}
						else
						{
							if (temp % 5 != 0)
							{
								temp = temp - (temp % 5) - 5;
								break;
							}
							else
							{
								temp -= 10;
								break;
							}
						}
					}
					else if (tw == -120)
					{
						//下一页
						if (i == bank->GetQBNum())
						{
							HWND hnd = GetHWnd();
							int r = MessageBox(hnd, _T("这已经是最后一页了！！！"), _T("提示"), MB_OKCANCEL);
							while (1)
							{
								if (r == IDOK)
								{
									break;
								}
								else if (r == IDCANCEL)
								{
									break;
								}
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
}

void UserInteraction::AnswerQuestions(Bank* bank)
{
	//重绘题目,总循环
	while (1)
	{
		BeginBatchDraw();
		int x1 = 0, y1 = 60, w1 = 800, h1 = 540 / (bank->GetQBNum() - bank->GetFormerQBNum());
		int tx1 = 0, ty1 = 0;
		int xx1 = 500, ww1 = 150;
		cleardevice();
		IMAGE img1;
		loadimage(&img1, L"./image/xxsimage0.png", 800, 600);
		putimage(0, 0, &img1);
		int i = bank->GetFormerQBNum();
		for (; i < bank->GetQBNum(); i++)
		{
			string a = "题目" + IntConvert(i + 1) + ":" + bank->GetqbName(i) + " " + bank->GetqbContent(i);
			char buffer[100] = { 0 };
			for (int j = 0; j < a.length(); j++)
			{
				buffer[j] = a[j];
			}
			TCHAR text1[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text1, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(WHITE);
			fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
			TCHAR s1[] = _T("黑体");
			settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
			settextcolor(BLACK);
			tx1 = x1;
			ty1 = y1 + (h1 - textheight(text1)) / 2;
			outtextxy(tx1, ty1, text1);
			//每道题后面出现输入周长、输入面积按钮
			//判断用户是否输入了一个题的周长与面积，若未输入则显示输入周长、输入面积按钮，否则显示已输入的周长和面积
			if (bank->GetUserAnswerC(i + 1) == 0 && bank->GetUserAnswerS(i + 1) == 0)
			{
				TCHAR text2[100] = _T("输入周长");
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1, y1, xx1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + (ww1 - textwidth(text2)) / 2;
				outtextxy(tx1, ty1, text2);
				TCHAR text3[100] = _T("输入面积");
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1 + ww1, y1, xx1 + ww1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + ww1 + (ww1 - textwidth(text3)) / 2;
				outtextxy(tx1, ty1, text3);
			}
			else if(bank->GetUserAnswerC(i + 1) == 0 && bank->GetUserAnswerS(i + 1) != 0)
			{
				TCHAR text2[100] = _T("输入周长");
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1, y1, xx1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + (ww1 - textwidth(text2)) / 2;
				outtextxy(tx1, ty1, text2);
				string c = to_string(bank->GetUserAnswerS(i + 1));
				char buffer1[100] = { 0 };
				for (int e = 0; e < c.length(); e++)
				{
					buffer1[e] = c[e];
				}
				TCHAR text3[100];
				MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text3, 20);
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1 + ww1, y1, xx1 + ww1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + ww1 + (ww1 - textwidth(text3)) / 2;
				outtextxy(tx1, ty1, text3);
			}
			else if (bank->GetUserAnswerC(i + 1) != 0 && bank->GetUserAnswerS(i + 1) == 0)
			{
				string b = to_string(bank->GetUserAnswerC(i + 1));
				char buffer[100] = { 0 };
				for (int e = 0; e < b.length(); e++)
				{
					buffer[e] = b[e];
				}
				TCHAR text2[100];
				MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text2, 20);
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1, y1, xx1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + (ww1 - textwidth(text2)) / 2;
				outtextxy(tx1, ty1, text2);
				TCHAR text3[100] = _T("输入面积");
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1 + ww1, y1, xx1 + ww1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + ww1 + (ww1 - textwidth(text3)) / 2;
				outtextxy(tx1, ty1, text3);
			}
			else
			{
				string b = to_string(bank->GetUserAnswerC(i + 1));
				char buffer[100] = { 0 };
				for (int e = 0; e < b.length(); e++)
				{
					buffer[e] = b[e];
				}
				TCHAR text2[100];
				MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text2, 20);
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1, y1, xx1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + (ww1 - textwidth(text2)) / 2;
				outtextxy(tx1, ty1, text2);
				string c = to_string(bank->GetUserAnswerS(i + 1));
				char buffer1[100] = { 0 };
				for (int e = 0; e < c.length(); e++)
				{
					buffer1[e] = c[e];
				}
				TCHAR text3[100];
				MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text3, 20);
				setbkmode(TRANSPARENT);
				setfillcolor(RGB(215, 219, 251));
				fillroundrect(xx1 + ww1, y1, xx1 + ww1 + ww1, y1 + h1, 10, 10);
				settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
				settextcolor(BLACK);
				tx1 = xx1 + ww1 + (ww1 - textwidth(text3)) / 2;
				outtextxy(tx1, ty1, text3);
			}
			y1 += h1;//绘制完每道题后y坐标加上每道题的高度，然后绘制下一题
		}
		//完善上部显示界面：共几题 总分几分   和完成并提交
		TCHAR text4[100] = _T("完 成 并 提 交");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(211, 82, 48));
		fillroundrect(550, 0, 800, 60, 10, 10);
		TCHAR s1[] = _T("黑体");
		settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		tx1 = 550+ (250 - textwidth(text4)) / 2;
		ty1 = (60 - textheight(text4)) / 2;
		outtextxy(tx1, ty1, text4);
		TCHAR text40[100] = _T("公式");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(255, 143, 107));
		fillroundrect(0, 0, 180, 60, 10, 10);
		settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		tx1 = (180 - textwidth(text40)) / 2;
		ty1 = (60 - textheight(text40)) / 2;
		outtextxy(tx1, ty1, text40);



		string c = "共" + to_string(bank->GetQBNum()) + "题 " + "总分" + to_string(bank->GetQBNum() * 2) + "分";
		char buffer[100] = { 0 };
		for (int e = 0; e < c.length(); e++)
		{
			buffer[e] = c[e];
		}
		TCHAR text5[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text5, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s1, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		outtextxy(300, 20, text5);
		EndBatchDraw();
		//生成答题按钮   和完成并提交按钮
		while (1)
		{
			BeginBatchDraw();
			t2 = (float)clock();
			timer = (t2 - t1 - tf) / 1000.0f;
			string a = to_string((int)timer);
			char buffer[100] = { 0 };
			for (int e = 0; e < a.length(); e++)
			{
				buffer[e] = a[e];
			}
			TCHAR text[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(66,66,66));
			fillroundrect(180,0,280,60, 10, 10);
			TCHAR s[] = _T("黑体");
			settextstyle(50, 30, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(RED);
			int yy = (60 - textheight(text)) / 2;
			int xx = 180 + (100 - textwidth(text)) / 2;
			outtextxy(xx, yy, text);
			EndBatchDraw();

			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 500 && mouse.x < 650 && mouse.y>60 && mouse.y < 600)
				{
					wchar_t s[10];
					InputBox(s, 10, L"输 入 周 长");
					float r = (float)_wtof(s);
					int i0 = (mouse.y - 60) / h1 + 1 + bank->GetFormerQBNum();
					bank->SetUserAnswerC(i0 - 1, r);
					break;
				}
				else if (mouse.x > 650 && mouse.x < 800 && mouse.y>60 && mouse.y < 600)
				{
					wchar_t s[10];
					InputBox(s, 10, L"输 入 面 积");
					float r = (float)_wtof(s);
					int i0 = (mouse.y - 60) / h1 + 1 + bank->GetFormerQBNum();
					bank->SetUserAnswerS(i0 - 1, r);
					break;
				}
				else if (mouse.x > 0 && mouse.x < 180 && mouse.y>0 && mouse.y < 60)
				{
					UserInteraction::DisplayFormula();
					break;
				}
				//点击完成并提交后返回第二个主菜单
				else if (mouse.x > 550 && mouse.x < 800 && mouse.y>0 && mouse.y < 60)
				{
					return;
				}
			}
		}
	}
}

void UserInteraction::ShowMenuPartTwo(Bank* bank)
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, L"./image/xxsimage.jpg", 800, 600);
	putimage(0, 0, &img);
	//创建主菜单的四个按钮
	int x1 = 300, y1 = 130, w1 = 200, h1 = 100;
	TCHAR text1[100] = _T("查 看 排 名");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(15,200,220));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s1[] = _T("黑体");
	settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
	settextcolor(RED);
	int tx = x1 + (w1 - textwidth(text1)) / 2;
	int ty = y1 + (h1 - textheight(text1)) / 2;
	outtextxy(tx, ty, text1);
	y1 += 120;
	TCHAR text2[100] = _T("查 看 成 绩");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(215, 219, 251));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s2[] = _T("黑体");
	settextstyle(30, 0, s2, 0, 0, 1000, 0, 0, 0);
	settextcolor(RED);
	tx = x1 + (w1 - textwidth(text2)) / 2;
	ty = y1 + (h1 - textheight(text2)) / 2;
	outtextxy(tx, ty, text2);
	y1 += 120;
	TCHAR text3[100] = _T("回 顾 练 习");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(215, 219, 251));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s3[] = _T("黑体");
	settextstyle(30, 0, s3, 0, 0, 1000, 0, 0, 0);
	settextcolor(RED);
	tx = x1 + (w1 - textwidth(text3)) / 2;
	ty = y1 + (h1 - textheight(text3)) / 2;
	outtextxy(tx, ty, text3);
	y1 += 120;
	TCHAR text4[100] = _T("退 出 系 统");
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s4[] = _T("黑体");
	settextstyle(30, 0, s4, 0, 0, 1000, 0, 0, 0);
	settextcolor(RED);
	tx = x1 + (w1 - textwidth(text4)) / 2;
	ty = y1 + (h1 - textheight(text4)) / 2;
	outtextxy(tx, ty, text4);

	string a = "用户" + bank->GetUsername()+"你好，请选择你的操作";
	char buffer[100] = { 0 };
	for (int j = 0; j < a.length(); j++)
	{
		buffer[j] = a[j];
	}
	TCHAR text5[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text5, 20);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
	settextcolor(YELLOW);
	outtextxy(160, 80, text5);
	EndBatchDraw();
}

int UserInteraction::InputBoxatBeginning()
{
	cleardevice();
	wchar_t s[10];
	InputBox(s, 10, L"请输入您想要练习的题目数量");
	int r = _wtoi(s);
	int x = 200, y = 250, w = 400, h = 100;
	TCHAR text1[100] = _T("生 成 题 目 中...");
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = _T("黑体");
	settextstyle(30, 0, s1, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	int tx2 = x + (w - textwidth(text1)) / 2;
	int ty2 = y + (h - textheight(text1)) / 2;
	outtextxy(tx2, ty2, text1);
	return r;
}

void UserInteraction::DisplayFormula()
{
	float t3 = (float)clock();
	cleardevice();
	BeginBatchDraw();
	IMAGE img1;
	loadimage(&img1, L"./image/xxsformula.png", 800, 600);
	putimage(0, 0, &img1);
	TCHAR text[100] = _T("返 回");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 143, 107));
	fillroundrect(0, 0, 200, 100, 10, 10);
	TCHAR s[] = _T("黑体");
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(WHITE);
	int tx1 = (200 - textwidth(text)) / 2;
	int ty1 = (100 - textheight(text)) / 2;
	outtextxy(tx1, ty1, text);
	EndBatchDraw();
	while (1)
	{
		MOUSEMSG mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 0 && mouse.x < 200 && mouse.y>0 && mouse.y < 120)
			{
				float t4 = (float)clock();
				tf += (t4 - t3);
				return;
			}
		}
	}

}

void UserInteraction::ShowRankMenu(Bank* bank)
{
	while (1)
	{
		cleardevice();
		setfillcolor(WHITE);
		fillrectangle(0, 0, 800, 600);
		//再展示界面：用户选择跳转到正确率排名？还是用时排名？
		BeginBatchDraw();
		TCHAR text1[100] = _T("正 确 率 排 名");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(300, 160, 550, 260, 10, 10);
		TCHAR s[] = _T("黑体");
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(315, 190, text1);

		TCHAR text2[100] = _T("时 间 排 名");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(300, 350, 550, 450, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(340, 385, text2);

		TCHAR text3[100] = _T("返回");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(88, 224, 166));
		fillroundrect(0, 0, 140, 80, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		outtextxy(35, 25, text3);
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 300 && mouse.x < 550 && mouse.y>160 && mouse.y < 260)
				{
					UserInteraction::ShowRightRateRank(bank);
					break;
				}
				else if (mouse.x > 300 && mouse.x < 550 && mouse.y>350 && mouse.y < 450)
				{
					UserInteraction::ShowTimerRank(bank);
					break;
				}
				else if (mouse.x > 0 && mouse.x < 140 && mouse.y>0 && mouse.y < 80)
					return;
			}
		}
	}
}

void UserInteraction::ShowRightRateRank(Bank* bank)
{
	//先根据正确率大小对数组序号进行排序，正确率大的排前面
	struct User temp;
	for (int i = 0; i < user_number - 1; i++)
	{
		for (int j = 0; j < user_number - i - 1; j++)
		{
			if (user[j].rightrate < user[j + 1].rightrate)
			{
				temp = user[j + 1];
				user[j + 1] = user[j];
				user[j] = temp;
			}
		}
	}
	//后面依据该排序对各个用户正确率进行展示
	cleardevice();
	setfillcolor(WHITE);
	fillrectangle(0, 0, 800, 600);
	//用户名 正确率 题目数量   //有框
	//下面每一行仅用户名有框，其他直接文字
	BeginBatchDraw();
	TCHAR s[] = _T("黑体");
	TCHAR text0[100] = _T("返回");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(88, 224, 166));
	fillroundrect(0, 0, 140, 80, 10, 10);
	settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(WHITE);
	outtextxy(35, 25, text0);

	TCHAR text1[100]=_T("用户名");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(40, 100, 130, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(45, 115, text1);

	TCHAR text2[100] = _T("正确率");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(230, 100, 330, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(240, 115, text2);

	TCHAR text3[100] = _T("练习题目数量");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(430, 100, 600, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(435, 115, text3);
	int h = 0;
	int tx = 0;
	for (int i = 0; i < user_number; i++)
	{
		string n = to_string(i+1);
		char buffer0[10] = { 0 };
		for (int j = 0; j < n.length(); j++)
		{
			buffer0[j] = n[j];
		}
		TCHAR text7[10];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer0, -1, text7, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		outtextxy(5, 165 + h, text7);

		string a = user[i].name;
		char buffer1[100] = { 0 };
		for (int j = 0; j < a.length(); j++)
		{
			buffer1[j] = a[j];
		}
		TCHAR text4[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text4, 20);
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(20, 150 + h, 150, 150 + 50 + h, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		tx = 25 + (120 - textwidth(text4)) / 2;
		outtextxy(tx, 165 + h, text4);

		string b = to_string(user[i].rightrate*100)+"%";
		char buffer2[100] = { 0 };
		for (int j = 0; j < b.length(); j++)
		{
			buffer2[j] = b[j];
		}
		TCHAR text5[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer2, -1, text5, 20);
		setbkmode(TRANSPARENT);
		//setfillcolor(RGB(214, 230, 255));
		//fillroundrect(220, 150 + h, 220 + textwidth(text4), 150 + h + h, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		outtextxy(215, 165 + h, text5);

		string c = to_string(user[i].QB_num);
		char buffer3[100] = { 0 };
		for (int j = 0; j < c.length(); j++)
		{
			buffer3[j] = c[j];
		}
		TCHAR text6[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer3, -1, text6, 20);
		setbkmode(TRANSPARENT);
		//setfillcolor(RGB(214, 230, 255));
		//fillroundrect(425, 150 + h, 425 + textwidth(text4), 150 + h + h, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		outtextxy(495, 165 + h, text6);

		h += 50;
	}
	EndBatchDraw();
	while (1)
	{
		MOUSEMSG mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 0 && mouse.x < 140 && mouse.y>0 && mouse.y < 80)
			{
				return;
			}
		}
	}
}

void UserInteraction::ShowTimerRank(Bank* bank)
{
	struct User temp;
	for (int i = 0; i < user_number - 1; i++)
	{
		for (int j = 0; j < user_number - i - 1; j++)
		{
			if (user[j].timer > user[j + 1].timer)
			{
				temp = user[j + 1];
				user[j + 1] = user[j];
				user[j] = temp;
			}
		}
	}
	cleardevice();
	setfillcolor(WHITE);
	fillrectangle(0, 0, 800, 600);
	BeginBatchDraw();
	TCHAR s[] = _T("黑体");
	TCHAR text0[100] = _T("返回");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(88, 224, 166));
	fillroundrect(0, 0, 140, 80, 10, 10);
	settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(WHITE);
	outtextxy(35, 25, text0);

	TCHAR text1[100] = _T("用户名");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(40, 100, 130, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(45, 115, text1);

	TCHAR text2[100] = _T("用 时");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(230, 100, 330, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(240, 115, text2);

	TCHAR text3[100] = _T("练习题目数量");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(214, 230, 255));
	fillroundrect(430, 100, 600, 150, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(435, 115, text3);
	int h = 0;
	int tx = 0;
	for (int i = 0; i < user_number; i++)
	{
		string n = to_string(i + 1);
		char buffer0[10] = { 0 };
		for (int j = 0; j < n.length(); j++)
		{
			buffer0[j] = n[j];
		}
		TCHAR text7[10];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer0, -1, text7, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(RED);
		outtextxy(5, 165 + h, text7);

		string a = user[i].name;
		char buffer1[100] = { 0 };
		for (int j = 0; j < a.length(); j++)
		{
			buffer1[j] = a[j];
		}
		TCHAR text4[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text4, 20);
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(20, 150 + h, 150, 150 + 50 + h, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		tx = 25 + (120 - textwidth(text4)) / 2;
		outtextxy(tx, 165 + h, text4);

		string b = to_string(user[i].timer)+"秒";
		char buffer2[100] = { 0 };
		for (int j = 0; j < b.length(); j++)
		{
			buffer2[j] = b[j];
		}
		TCHAR text5[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer2, -1, text5, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		outtextxy(215, 165 + h, text5);

		string c = to_string(user[i].QB_num);
		char buffer3[100] = { 0 };
		for (int j = 0; j < c.length(); j++)
		{
			buffer3[j] = c[j];
		}
		TCHAR text6[100];
		MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer3, -1, text6, 20);
		setbkmode(TRANSPARENT);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(BLACK);
		outtextxy(495, 165 + h, text6);

		h += 50;
	}
	EndBatchDraw();
	while (1)
	{
		MOUSEMSG mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)
		{
			if (mouse.x > 0 && mouse.x < 140 && mouse.y>0 && mouse.y < 80)
			{
				return;
			}
		}
	}

}

void UserInteraction::SetBankTimer(Bank* bank)
{
	for (int i = 0; i < 50; i++)
	{
		if (bank->GetUsername() == user[i].name)
		{
			bank->SetTimer(user[i].timer);
			return;
		}
	}
}

void UserInteraction::StreamInRankText()
{
	//先载入Rank文件中的数据，存入结构体数组中:::
	//先浏览文件看看一共几行？
	FILE* pf = fopen("./UserRank.txt", "r");
	char c;
	int line = 1;
	while ((c = fgetc(pf)) != EOF)
	{
		if (c == '\n')
			line++;
	}
	fclose(pf);
	pf = NULL;
	//得知了行数，下面就可以控制行数读取读取了
	pf = fopen("./UserRank.txt", "r");
	user_number = line / 2;
	char temp[50];
	int i = 0;
	while (2 * i < line)
	{
		fgets(temp, 100, pf);
		stringstream ss;
		ss << temp;
		ss >> user[i].name;
		ss.clear();
		//读取文件数据进临时变量：每个用户在文件中占两行，读第一行——账户名
		//读第二行：时间、做题数量、正确率
		fgets(temp, 100, pf);
		ss << temp;
		ss >> user[i].timer;
		ss >> user[i].QB_num;
		ss >> user[i].rightrate;
		ss.clear();
		//将临时变量存入结构体（）一个一个人的存
		i++;
	}
}

void UserInteraction::ShowOneQuestion(Bank* bank, int i, int x1, int y1, int w1, int h1, int tx1, int ty1)
{
	string a = "题目" + IntConvert(i + 1) + ":" + bank->GetqbName(i) + " " + bank->GetqbContent(i);
	char buffer[100] = { 0 };
	for (int j = 0; j < a.length(); j++)
	{
		buffer[j] = a[j];
	}
	TCHAR text1[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text1, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	TCHAR s[] = _T("黑体");
	settextstyle(31, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	tx1 = x1;
	ty1 = y1 + (h1 - textheight(text1)) / 2;
	outtextxy(tx1, ty1, text1);
	//题目后面输出用户输入答案1
	string b = "回答" + to_string(bank->GetUserAnswerC(i + 1));// +" " + to_string(bank->GetUserAnswerS(i + 1));
	char buffer1[100] = { 0 };
	for (int j = 0; j < b.length(); j++)
	{
		buffer1[j] = b[j];
	}
	TCHAR text2[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer1, -1, text2, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 186, 0));
	fillroundrect(450, y1, 700, y1 + h1, 10, 10);//x坐标多的这一点点是为了遮住后面的白色幕布
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);

	if (bank->GetUserAnswerC(i + 1) == bank->GetRightAnswerC(i + 1))
		settextcolor(GREEN);
	else
		settextcolor(RED);
	int yy1 = y1 + (h1 - textheight(text2)) / 2;
	outtextxy(450, yy1, text2);
	//用户输入答案2
	string h = to_string(bank->GetUserAnswerS(i + 1));
	char buffer2[100] = { 0 };
	for (int j = 0; j < h.length(); j++)
	{
		buffer2[j] = h[j];
	}
	TCHAR text3[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer2, -1, text3, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 186, 0));
	fillroundrect(650, y1, 800, y1 + h1, 10, 10);
	settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
	if (bank->GetUserAnswerS(i + 1) == bank->GetRightAnswerS(i + 1))
		settextcolor(GREEN);
	else
		settextcolor(RED);
	outtextxy(650, yy1, text3);
	//在题目下面输出正确答案1
	y1 += h1;
	string c = "答案：周长" + to_string(bank->GetRightAnswerC(i + 1));
	char buffer3[100] = { 0 };
	for (int j = 0; j < c.length(); j++)
	{
		buffer3[j] = c[j];
	}
	TCHAR text4[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer3, -1, text4, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(14, 206, 116));
	fillroundrect(x1, y1, x1 + w1, y1 + h1, 10, 10);
	settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(WHITE);
	yy1 = y1 + (h1 - textheight(text4)) / 2;
	outtextxy(x1, yy1, text4);
	//输出正确答案2
	string d = "面积" + to_string(bank->GetRightAnswerS(i + 1));
	char buffer4[100] = { 0 };
	for (int j = 0; j < d.length(); j++)
	{
		buffer4[j] = d[j];
	}
	TCHAR text5[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer4, -1, text5, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(14, 206, 116));
	fillroundrect(315, y1, 540, y1 + h1, 10, 10);
	settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(WHITE);
	outtextxy(315, yy1, text5);
	//输出得分
	string e = "本题得分" + to_string(bank->Getqbscore(i + 1));
	char buffer5[100] = { 0 };
	for (int j = 0; j < e.length(); j++)
	{
		buffer5[j] = e[j];
	}
	TCHAR text6[100];
	MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer5, -1, text6, 20);
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 143, 107));
	fillroundrect(540, y1, 800, y1 + h1, 10, 10);
	settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
	settextcolor(BLACK);
	outtextxy(595, yy1, text6);
}
