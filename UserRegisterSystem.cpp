#include "UserRegisterSystem.h"

int UserRegisterSystem::FirstMenu(Bank* bank)
{
	while (1)
	{
		cleardevice();
		setfillcolor(WHITE);
		fillrectangle(0, 0, 800, 600);
		BeginBatchDraw();
		TCHAR text0[100] = _T("登 录");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(300, 130, 500, 200, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(300 + textwidth(text0), 130 + textheight(text0), text0);

		TCHAR text1[100] = _T("注 册");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(300, 250, 500, 320, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(300 + textwidth(text1), 250 + textheight(text1), text1);

		TCHAR text2[100] = _T("退 出");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(214, 230, 255));
		fillroundrect(300, 370, 500, 440, 10, 10);
		settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(300 + textwidth(text2), 370 + textheight(text2), text2);
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 300 && mouse.x < 500 && mouse.y>130 && mouse.y < 200)
				{
					//登录
					int p = UserRegisterSystem::Register(bank);
					if (p == 0)
						break;
					else if (p == 1)
						return 2;
				}
				else if (mouse.x > 300 && mouse.x < 500 && mouse.y>250 && mouse.y < 320)
				{
					//注册
					int p = UserRegisterSystem::Logon(bank);
					if (p == 0)
						break;
					else if (p == 1)
						return 1;
				}
				else if (mouse.x > 300 && mouse.x < 500 && mouse.y>370 && mouse.y < 440)
				{
					return 0;
				}
			}
		}
	}
}

int UserRegisterSystem::Register(Bank* bank)
{
	ifstream ifs;
	ifs.open("./UserBank.txt", ios::in);
	char c;
	if ((c = ifs.get()) == EOF)
	{
		HWND hnd = GetHWnd();
		MessageBox(hnd, _T("登录失败！文件中不存在任何用户！"), _T("注意"), MB_OKCANCEL);
		ifs.close();
		return 0;
	}
	string username;
	long long int password = 0;
	while (1)
	{
		cleardevice();
		setfillcolor(WHITE);
		fillrectangle(0, 0, 800, 600);
		BeginBatchDraw();
		TCHAR text0[100] = _T("登 录");
		setbkmode(TRANSPARENT);
		settextstyle(60, 35, s, 0, 0, 100, 0, 0, 0);
		settextcolor(RGB(255, 143, 107));
		outtextxy(315, 60, text0);
		TCHAR text1[100] = _T("用户名：");
		setbkmode(TRANSPARENT);
		settextstyle(35, 10, s, 0, 0, 100, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(150, 250, text1);
		if (username.length() == 0)
		{
			TCHAR text11[100] = _T("    点击输入正确的用户名 ");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			//fillroundrect(150 + textwidth(text1), 250, 600, 250 + textheight(text1), 10, 10);
			fillroundrect(242, 250, 600, 285, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text1), 255, text11);
		}
		else
		{
			char buffer[100] = { 0 };
			for (int j = 0; j < username.length(); j++)
			{
				buffer[j] = username[j];
			}
			TCHAR text11[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text11, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			fillroundrect(242, 250, 600, 285, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text1), 255, text11);
		}
		TCHAR text2[100] = _T(" 密 码：");
		setbkmode(TRANSPARENT);
		settextstyle(35, 10, s, 0, 0, 100, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(150, 300 + textheight(text1), text2);
		if (password == 0)
		{
			TCHAR text21[100] = _T("     点击输入正确的密码 ");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			//fillroundrect(150 + textwidth(text2), 300 + textheight(text1), 600, 300 + textheight(text1) + textheight(text2), 10, 10);
			fillroundrect(242, 335, 600, 370, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text2), 342, text21);
		}
		else
		{
			string text21 = to_string(password);
			char buffer[100] = { 0 };
			for (int j = 0; j < text21.length(); j++)
			{
				buffer[j] = text21[j];
			}
			TCHAR text5[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text5, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			fillroundrect(242, 335, 600, 370, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text2), 342, text5);
		}

		TCHAR text3[100] = _T("返回");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(88, 224, 166));
		fillroundrect(300, 460, 370, 500, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		outtextxy(305, 465, text3);

		TCHAR text4[100] = _T("登录");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(88, 224, 166));
		fillroundrect(450, 460, 520, 500, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		outtextxy(455, 465, text4);
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 242 && mouse.x < 600 && mouse.y>250 && mouse.y < 285)
				{
					wchar_t s[10];
					InputBox(s, 10, L"输入用户名中（注意：禁止输入中文字符！）");
					//InputBox获取的wchar_t转换为char*
					char* usern;
					usern = WCharToChar(s);
					//
					username = (string)usern;
					break;
				}
				else if (mouse.x > 242 && mouse.x < 600 && mouse.y>335 && mouse.y < 370)
				{
					wchar_t s[17];
					InputBox(s, 17, L"输入密码中（注意：请输入数字！不能少于1位也不能超过16位！）");
					while (!(JudgeInput(s)))
					{
						HWND hnd = GetHWnd();
						MessageBox(hnd, _T("输入含有非法字符，重新输入！"), _T("注意"), MB_OKCANCEL);
						InputBox(s, 17, L"输入密码中（只能输入数字！不能超过16位！）");
					}
					password = stoi(s);
					break;
				}
				else if (mouse.x > 300 && mouse.x < 370 && mouse.y>460 && mouse.y < 500)
				{
					return 0;
				}
				else if (mouse.x > 450 && mouse.x < 520 && mouse.y>460 && mouse.y < 500)
				{
					if (username.length() != 0 && password != 0)
					{
						//登录检测及题库赋值操作
						Account* ac = new Account(username, password);
						if (ac->CheckAccount(bank))
						{
							HWND hnd = GetHWnd();
							MessageBox(hnd, _T("登录成功！"), _T("提示"), MB_OKCANCEL);
							bank->SetUsername(username);
							delete ac;
							return 1;
						}
						else
						{
							HWND hnd = GetHWnd();
							MessageBox(hnd, _T("输入用户名或密码有误，请尝试重新输入！"), _T("注意"), MB_OKCANCEL);
						}
					}
					else
					{
						HWND hnd = GetHWnd();
						MessageBox(hnd, _T("请填写用户名和密码！"), _T("注意"), MB_OKCANCEL);
					}
				}
			}
		}
	}
}

int UserRegisterSystem::Logon(Bank* bank)
{//RGB(214,230,255)
	string username;
	long long int password = 0;
	while (1)
	{
		cleardevice();
		setfillcolor(WHITE);
		fillrectangle(0, 0, 800, 600);
		BeginBatchDraw();
		TCHAR text0[100] = _T("注 册");
		setbkmode(TRANSPARENT);
		settextstyle(60, 35, s, 0, 0, 100, 0, 0, 0);
		settextcolor(RGB(255, 143, 107));
		outtextxy(315, 60, text0);
		TCHAR text1[100] = _T("用户名：");
		setbkmode(TRANSPARENT);
		settextstyle(35, 10, s, 0, 0, 100, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(150, 250, text1);
		if (username.length() == 0)
		{
			TCHAR text11[100] = _T("    点击输入用户名 ");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			//fillroundrect(150 + textwidth(text1), 250, 600, 250 + textheight(text1), 10, 10);
			fillroundrect(242, 250, 600, 285, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text1), 255, text11);
		}
		else
		{
			char buffer[100] = { 0 };
			for (int j = 0; j < username.length(); j++)
			{
				buffer[j] = username[j];
			}
			TCHAR text11[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text11, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			fillroundrect(242, 250, 600, 285, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text1), 255, text11);
		}
		TCHAR text2[100] = _T(" 密 码：");
		setbkmode(TRANSPARENT);
		settextstyle(35, 10, s, 0, 0, 100, 0, 0, 0);
		settextcolor(GREEN);
		outtextxy(150, 300 + textheight(text1), text2);
		if (password == 0)
		{
			TCHAR text21[100] = _T("     点击输入密码 ");
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			//fillroundrect(150 + textwidth(text2), 300 + textheight(text1), 600, 300 + textheight(text1) + textheight(text2), 10, 10);
			fillroundrect(242, 335, 600, 370, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text2), 342, text21);
		}
		else
		{
			string text21 = to_string(password);
			char buffer[100] = { 0 };
			for (int j = 0; j < text21.length(); j++)
			{
				buffer[j] = text21[j];
			}
			TCHAR text5[100];
			MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, buffer, -1, text5, 20);
			setbkmode(TRANSPARENT);
			setfillcolor(RGB(214, 230, 255));
			fillroundrect(242, 335, 600, 370, 10, 10);
			settextstyle(25, 0, s, 0, 0, 1000, 0, 0, 0);
			settextcolor(GREEN);
			outtextxy(150 + textwidth(text2), 342, text5);
		}

		TCHAR text3[100] = _T("返回");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(88, 224, 166));
		fillroundrect(300, 460, 370, 500, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		outtextxy(305, 465, text3);

		TCHAR text4[100] = _T("注册");
		setbkmode(TRANSPARENT);
		setfillcolor(RGB(88, 224, 166));
		fillroundrect(450, 460, 520, 500, 10, 10);
		settextstyle(30, 0, s, 0, 0, 1000, 0, 0, 0);
		settextcolor(WHITE);
		outtextxy(455, 465, text4);
		EndBatchDraw();
		while (1)
		{
			MOUSEMSG mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x > 242 && mouse.x < 600 && mouse.y>250 && mouse.y < 285)
				{
					wchar_t s[10];
					InputBox(s, 10, L"输入用户名中（禁止输入中文字符！）");
					//InputBox获取的wchar_t转换为char*
					char* usern;
					usern = WCharToChar(s);
					//
					username = (string)usern;
					break;
				}
				else if (mouse.x > 242 && mouse.x < 600 && mouse.y>335 && mouse.y < 370)
				{
					wchar_t s[17];
					InputBox(s, 17, L"输入密码中（注意：请输入数字！不能少于1位也不能超过16位！）");
					while (!(JudgeInput(s)))
					{
						HWND hnd = GetHWnd();
						MessageBox(hnd, _T("输入含有非法字符，重新输入！"), _T("注意"), MB_OKCANCEL);
						InputBox(s, 17, L"输入密码中（注意：只能输入数字！不能超过16位！）");
					}
					password = stoi(s);
					break;
				}
				else if (mouse.x > 300 && mouse.x < 370 && mouse.y>460 && mouse.y < 500)
				{
					return 0;
				}
				else if (mouse.x > 450 && mouse.x < 520 && mouse.y>460 && mouse.y < 500)
				{
					int zsh = 1;
					char c;
					string checkit;
					FILE* pf = fopen("./UserBank.txt", "r");
					while ((c = fgetc(pf)) != EOF)
					{
						if (c == '$')
						{
							while ((c = fgetc(pf)) != '#')
							{
								checkit += c;
							}
							if (checkit == username)
							{
								zsh = 0;
								break;
							}
							else
							{
								checkit = "";
							}
						}
					}
					if (username.length() != 0 && password != 0 && zsh)
					{
						//Bank文件填入账户信息
						ofstream ofs;
						ofs.open("./UserBank.txt", ios::out | ios::ate | ios::app);
						ofs << "$" << username;
						ofs << "#" << password << "\n";
						ofs.close();
						//Rank文件填入账户信息
						ofstream ofs1;
						ofs1.open("./UserRank.txt", ios::out | ios::ate | ios::app);
						ofs1 << username << endl;
						ofs1.close();
						HWND hnd = GetHWnd();
						int r = MessageBox(hnd, _T("注册成功！！！"), _T("提示"), MB_OKCANCEL);
						bank->SetUsername(username);
						return 1;
					}
					else if (zsh == 0)
					{
						HWND hnd = GetHWnd();
						MessageBox(hnd, _T("已存在该用户！请输入其他用户名。"), _T("注意"), MB_OKCANCEL);
					}
					else
					{
						HWND hnd = GetHWnd();
						MessageBox(hnd, _T("请填写用户名和密码！"), _T("注意"), MB_OKCANCEL);
					}
				}
			}
		}
	}
}

bool UserRegisterSystem::JudgeInput(wchar_t s[])
{
	for (int i = 0; i < wcslen(s); i++)
	{
		if (!(isdigit(s[i])))
		{
			return false;
		}
	}
	return true;
}

char* UserRegisterSystem::WCharToChar(const wchar_t* s)
{
	char* m_char;
	int len = WideCharToMultiByte(CP_ACP, 0, s, (int)wcslen(s), NULL, 0, NULL, NULL);
	m_char = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, s, (int)wcslen(s), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	return m_char;
}
