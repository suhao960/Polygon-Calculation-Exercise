#pragma once
#include "Shape.h"
class Triangle:public Shape
{
	float a, b, c;
public:
	Triangle();
	Triangle(float a, float b, float c);
	void SetSideLengthA(float a);
	float GetSideLengthA();
	void SetSideLengthB(float b);
	float GetSideLengthB();
	void SetSideLengthC(float c);
	float GetSideLengthC();
	void SetABC(float a, float b, float c);
	void SetUserAnswer(float c, float s);

	static bool JudgeIt(float a,float b,float c);

	string GetqbName();
	string GetqbContent();
	virtual string Getqbcontent();
	float CalculateGirth();//计算周长和面积，返回正确周长
	float CalculateArea();//返回正确面积
	string GetType();
	~Triangle();
};

