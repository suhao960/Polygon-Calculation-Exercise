#include "Account.h"

Account::Account(string un, long long ps)
{
    this->username = un;
    this->password = ps;
}

bool Account::CheckAccount(Bank* bank)
{
    char c;
    string checkun;
    string checkps;
    FILE* pf = fopen("./UserBank.txt", "r");
    while ((c = fgetc(pf)) != EOF)
    {
        if (c == '$')
        {
            while ((c = fgetc(pf)) != '#')
            {
                checkun += c;
            }
            while ((c = fgetc(pf)) != '\n')
            {
                checkps += c;
            }
            if ((this->username == checkun) && (checkps == to_string(this->password)))
            {
                //匹配成功则进行信息流入操作
                char temp[50];
                int i = 0;
                fgets(temp, 100, pf);
                string pp = "***\n";
                while (temp != pp)//读取一行内容
                {
                    stringstream ss;
                    int key = 0;
                    ss << temp;//temp流入ss，ss默认以空格分隔
                    string str;//str储存空格分隔的字符串
                    while (ss >> str)
                    {
                        if (key == 1)
                        {
                            float a = stof(str);
                            bank->SetFangXingLength(i, a);
                            ss >> str;
                            float uc = stof(str);
                            ss >> str;
                            float us = stof(str);
                            bank->SetUserAnswer(i, uc, us);
                        }
                        else if (key == 2)
                        {
                            float a = stof(str);
                            ss >> str;
                            float b = stof(str);
                            bank->SetFangXingLength(i, a, b);
                            ss >> str;
                            float uc = stof(str);
                            ss >> str;
                            float us = stof(str);
                            bank->SetUserAnswer(i, uc, us);
                        }
                        else if (key == 3)
                        {
                            float a = stof(str);
                            bank->SetYuanXingRadius(i, a);
                            ss >> str;
                            float uc = stof(str);
                            ss >> str;
                            float us = stof(str);
                            bank->SetUserAnswer(i, uc, us);
                        }
                        else if (key == 4)
                        {
                            float a = stof(str);
                            ss >> str;
                            float b = stof(str);
                            ss >> str;
                            float c = stof(str);
                            ss >> str;
                            float d = stof(str);
                            bank->SetFangXingLength(i, a, b, c, d);
                            ss >> str;
                            float uc = stof(str);
                            ss >> str;
                            float us = stof(str);
                            bank->SetUserAnswer(i, uc, us);
                        }
                        else if (key == 5)
                        {
                            float a = stof(str);
                            ss >> str;
                            float b = stof(str);
                            ss >> str;
                            float c = stof(str);
                            bank->SetFangXingLength(i, a, b, c);
                            ss >> str;
                            float uc = stof(str);
                            ss >> str;
                            float us = stof(str);
                            bank->SetUserAnswer(i, uc, us);
                        }
                        else if (key == 0)
                        {
                            if (str == "Z")
                            {
                                bank->IniteeBank(i, "正方形");
                                key = 1;
                            }
                            else if (str == "C")
                            {
                                bank->IniteeBank(i, "长方形");
                                key = 2;
                            }
                            else if (str == "Y")
                            {
                                bank->IniteeBank(i, "圆 形");
                                key = 3;
                            }
                            else if (str == "T")
                            {
                                bank->IniteeBank(i, "梯 形");
                                key = 4;
                            }
                            else if (str == "S")
                            {
                                bank->IniteeBank(i, "三角形");
                                key = 5;
                            }
                        }
                    }
                    ss.clear();
                    fgets(temp, 100, pf);
                    i++;
                }
                fclose(pf);
                pf = NULL;
                return true;
            }
        }
        checkun = "";
        checkps = "";
    }
    fclose(pf);
    pf = NULL;
    return false;
}

void Account::AssignOldBankToNewBank(Bank* bank)
{
    
}
