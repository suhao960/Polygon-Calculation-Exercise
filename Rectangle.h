#pragma once
#include "Shape.h"
class Rectangle:public Shape
{
	float a, b;
public:
	Rectangle();
	Rectangle(float a, float b);
	void SetA(float a);
	float GetA();
	void SetB(float b);
	float GetB();
	void SetAB(float a, float b);
	void SetUserAnswer(float c, float s);

	static bool JudgeIt(float a,float b);

	string GetqbName();
	string GetqbContent();
	virtual string Getqbcontent();
	float CalculateGirth();//计算周长和面积，返回正确周长
	float CalculateArea();//返回正确面积

	~Rectangle();
};

