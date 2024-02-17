#pragma once
#include "Shape.h"
class Square:public Shape
{
	float a;
public:
	Square();
	Square(float a);
	void SetA(float a);
	float GetA();
	void SetUserAnswer(float c, float s);

	static bool JudgeIt(float a);
	static int CompareSize(Square* s1,Square* s2);
	bool operator>(const Square& otherSquare);
	bool operator=(const Square& otherSquare);
	bool operator<(const Square& otherSquare);

	string GetqbName();
	string GetqbContent();
	virtual string Getqbcontent();
	float CalculateGirth();//计算周长和面积，返回正确周长
	float CalculateArea();//返回正确面积

	~Square();
};

