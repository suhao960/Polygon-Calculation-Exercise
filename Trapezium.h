#pragma once
#include "Shape.h"
class Trapezium:public Shape
{
	float a, b, c, d;//上底、下底、左边、右边
public:
	Trapezium();
	Trapezium(float a, float b, float c,float d);
	void SetA(float a);
	float GetA();
	void SetB(float b);
	float GetB();
	void SetC(float h);
	float GetC();
	void SetD(float d);
	float GetD();
	void SetABCD(float a, float b, float c, float d);
	void SetUserAnswer(float c, float s);

	static bool JudgeIt(float a,float b,float c,float d);

	string GetqbName();
	string GetqbContent();
	virtual string Getqbcontent();
	float CalculateGirth();//计算周长和面积，返回正确周长
	float CalculateArea();//返回正确面积
	string GetType();
	~Trapezium();
};

