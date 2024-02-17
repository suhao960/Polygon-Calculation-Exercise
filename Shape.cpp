#include "Shape.h"

Shape::Shape()
{
	this->qb_score = 0;
	this->useranswer_c = 0;
	this->useranswer_s = 0;
}

void Shape::SetScore(int s)
{
	this->qb_score = s;
}

int Shape::GetScore()
{
	return this->qb_score;
}

void Shape::SetqbNum(int n)
{
	this->qb_num = n;
}

int Shape::GetqbNum()
{
	return qb_num;
}

string Shape::GetqbName()
{
	return string();
}

string Shape::GetqbContent()
{
	return string();
}

string Shape::Getqbcontent()
{
	return string();
}


float Shape::CalculateGirth()
{
	return 0;
}

float Shape::CalculateArea()
{
	return 0;
}

string Shape::GetType()
{
	return string();
}

void Shape::SetA(float a)
{
}

void Shape::SetAB(float a, float b)
{
}

void Shape::SetR(float r)
{
}

void Shape::SetABCD(float a, float b, float c, float d)
{
}

void Shape::SetABC(float a, float b, float c)
{
}

void Shape::JudgeAnswer()
{
	if (this->useranswer_c == this->CalculateGirth() && this->useranswer_s == this->CalculateArea())
	{
		this->qb_score = 2;
	}
	else if ((this->useranswer_c == this->CalculateGirth() && this->useranswer_s != this->CalculateArea()) || (this->useranswer_c != this->CalculateGirth() && this->useranswer_s == this->CalculateGirth()))
	{
		this->qb_score = 1;
	}
	else
	{
		this->qb_score = 0;
	}
}

void Shape::SetUserAnswerC(float c)
{
	this->useranswer_c = c;
}

void Shape::SetUserAnswerS(float s)
{
	this->useranswer_s = s;
}

float Shape::GetUserAnswerC()
{
	return this->useranswer_c;
}

float Shape::GetUserAnswerS()
{
	return this->useranswer_s;
}

float Shape::GetRightAnswerC()
{
	return this->rightanswer_c;
}

float Shape::GetRightAnswerS()
{
	return this->rightanswer_s;
}

Shape::~Shape()
{

}
