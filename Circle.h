#pragma once
#include "Shape.h"
#define PI 3.14f
class Circle:public Shape
{
	float r;
public:
	Circle();
	Circle(float r);
	void SetR(float  r);
	float GetR();
	void SetUserAnswer(float c, float s);

	static bool JudgeIt(float r);

	string GetqbName();
	string GetqbContent();
	virtual string Getqbcontent();
	float CalculateGirth();//计算周长和面积，返回正确周长
	float CalculateArea();//返回正确面积

	~Circle();
};

