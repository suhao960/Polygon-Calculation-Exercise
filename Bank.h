#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include"Shape.h"
#include"Square.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Trapezium.h"
#include"Triangle.h"
#include<fstream>
class Bank
{
private:
	string QB_name;//题库名称
	int QB_number;//题目数量
	int QB_score;//题库总分数
	float QB_averagescore;//每道题的平均分数
	int formerQB_num;
	vector<Shape*> v_qb;
	vector<Shape*>::iterator vv;
	string username;
	float timer;
	

public:
	Bank();
	void InitBank(int i);//随机创建题库，输入练习题目数量
	void SetQBName(string name);
	string GetQBName();
	void SetQBNum(int num);
	int GetQBNum();
	int GetFormerQBNum();
	void SetUserAnswerC(int i, float c);
	void SetUserAnswerS(int i, float s);
	float GetUserAnswerC(int i);
	float GetUserAnswerS(int i);
	float GetRightAnswerC(int i);
	float GetRightAnswerS(int i);
	int GetQBScore();
	string GetqbName(int i);
	string GetqbContent(int i);
	int Getqbscore(int i);
	float GetAverageSco();//返回平均成绩
	void SetUsername(string un);
	string GetUsername();
	void SetTimer(float timer);
	float GetTimer();
	float GetRightRate();

	void AccumulateEveryandAllandAveragescore();//计算每个题的成绩   和题库总成绩   和每道题的平均成绩
	void SquareQuestion(int qbnum);
	void RectangleQuestion(int qbnum);
	void CircleQuestion(int qbnum);
	void TrapeziumQuestion(int qbnum);
	void TriangleQuestion(int qbnum);

	void AddQuestion(int i);
	void DeleteQuestion(int i);

	void SaveQuestionForLogonWay();
	void SaveOnlyForLogon();

	//登录系统
	void IniteeBank(int i, string type);
	void SetFangXingLength(int i,float a);
	void SetFangXingLength(int i, float a, float b);
	void SetFangXingLength(int i, float a, float b,float c);
	void SetFangXingLength(int i, float a, float b,float c,float d);
	void SetYuanXingRadius(int i,float r);
	void SetUserAnswer(int i, float uc, float us);
	~Bank();
};

