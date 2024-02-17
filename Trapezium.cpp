#include "Trapezium.h"

Trapezium::Trapezium()
{
	this->qb_name = "梯 形";
}

Trapezium::Trapezium(float a, float b, float c,float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->qb_name = "梯 形";
}

void Trapezium::SetA(float a)
{
	this->a = a;
}

float Trapezium::GetA()
{
	return this->a;
}

void Trapezium::SetB(float b)
{
	this->b = b;
}

float Trapezium::GetB()
{
	return this->b;
}

void Trapezium::SetC(float h)
{
	this->c = h;
}

float Trapezium::GetC()
{
	return this->c;
}

void Trapezium::SetD(float d)
{
	this->d = d;
}

float Trapezium::GetD()
{
	return this->d;
}

void Trapezium::SetABCD(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

string Trapezium::GetqbName()
{
	return this->qb_name;
}

string Trapezium::GetqbContent()
{
	string a="上"+to_string((int)this->GetA())+"下"+to_string((int)this->GetB())+"左"+to_string((int)this->GetC())+"右"+to_string((int)this->GetD());
	return a;
}

string Trapezium::Getqbcontent()
{
	return to_string(this->GetA())+" "+to_string(this->GetB())+" "+to_string(this->GetC())+" "+to_string(this->GetD());
}

void Trapezium::SetUserAnswer(float c, float s)
{
	this->useranswer_c = c;
	this->useranswer_s = s;
}

bool Trapezium::JudgeIt(float a, float b, float c, float d)
{
	float x = a - b;
	if (x < 0) 
		x = -x;
	if (c + d > x && c + x > d && d + x > c && a > 0 && b > 0 && c > 0 && d > 0 && a < 10 && b < 10 && c < 10 && d < 10)
		return true;
	else
		return false;
}

float Trapezium::CalculateGirth()
{
	this->rightanswer_c = this->a + this->b + this->c + this->d;
	float x = this->a - this->b;
	if (x < 0)
		x = -x;
	float p = (this->c + this->d + x) / 2;
	this->rightanswer_s = (2 * (this->a + this->b) * sqrt(p * (p - this->c) * (p - this->d) * (p - x))) / x;
	return this->rightanswer_c;
}

float Trapezium::CalculateArea()
{
	return this->rightanswer_s;
}

string Trapezium::GetType()
{
	if (this->c == this->d)
	{
		return "等腰梯形";
	}
	else
	{
		return "普通梯形";
	}
}

Trapezium::~Trapezium()
{
}
