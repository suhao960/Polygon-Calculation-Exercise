#pragma once
#include<math.h>
#include<iostream>
#include<string>
using namespace std;

class Shape
{
protected:
	int qb_num;
	int qb_score;//每个题目的分数
	string qb_name;//每个题目的类型(名字)
	float useranswer_c;
	float useranswer_s;
	float rightanswer_c;
	float rightanswer_s;
public:
	Shape();
	void SetScore(int s);
	int GetScore();
	void SetqbNum(int n);
	int GetqbNum();
	void SetUserAnswerC(float c);
	void SetUserAnswerS(float s);
	float GetUserAnswerC();
	float GetUserAnswerS();
	float GetRightAnswerC();
	float GetRightAnswerS();
	
	void JudgeAnswer();//判断每道题的分数、判断的同时也能设置每道题的正确答案
	virtual string GetqbName();//获取题目形状
	virtual string GetqbContent();//获取题目内容
	virtual string Getqbcontent();//仅获取题目的数字，以字符串返回
	virtual float CalculateGirth();//计算周长、面积并返回正确周长
	virtual float CalculateArea();//返回正确面积
	virtual string GetType();//返回三角形或梯形的具体形状

	virtual void SetA(float a);
	virtual void SetAB(float a, float b);
	virtual void SetR(float  r);
	virtual void SetABCD(float a, float b, float c, float d);
	virtual void SetABC(float a, float b, float c);
	~Shape();
};

