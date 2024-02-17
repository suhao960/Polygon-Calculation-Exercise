#include "Triangle.h"

Triangle::Triangle()
{
	this->qb_name = "三角形";
}

Triangle::Triangle(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->qb_name = "三角形";
}

void Triangle::SetSideLengthA(float a)
{
	this->a = a;
}

float Triangle::GetSideLengthA()
{
	return this->a;
}

void Triangle::SetSideLengthB(float b)
{
	this->b = b;
}

float Triangle::GetSideLengthB()
{
	return this->b;
}

void Triangle::SetSideLengthC(float c)
{
	this->c = c;
}

float Triangle::GetSideLengthC()
{
	return this->c;
}

void Triangle::SetABC(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

string Triangle::GetqbName()
{
	return this->qb_name;
}

string Triangle::GetqbContent()
{
	string a = "三边为" + to_string((int)this->GetSideLengthA()) + "  " + to_string((int)this->GetSideLengthB()) + "  " + to_string((int)this->GetSideLengthC());
	return a;
}

string Triangle::Getqbcontent()
{
	return to_string(this->GetSideLengthA())+" "+to_string(this->GetSideLengthB())+" "+to_string(this->GetSideLengthC());
}

void Triangle::SetUserAnswer(float c, float s)
{
	this->useranswer_c = c;
	this->useranswer_s = s;
}

bool Triangle::JudgeIt(float a, float b, float c)
{
	if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0 && a < 10 && b < 10 && c < 10)
		return true;
	else
		return false;
}

float Triangle::CalculateGirth()
{
	this->rightanswer_c = this->a + this->b + this->c;
	float p;
	p = (this->a + this->b + this->c) / 2.0f;
	this->rightanswer_s = (float)sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
	return this->rightanswer_c;
}

float Triangle::CalculateArea()
{
	return this->rightanswer_s;
}

string Triangle::GetType()
{
	if (this->a * this->a + this->b * this->b > this->c * this->c)
	{
		return "锐角三角形";
	}
	else if (this->a * this->a + this->b * this->b == this->c * this->c)
	{
		return "直角三角形";
	}
	else
	{
		return "钝角三角形";
	}
}


Triangle::~Triangle()
{
}
