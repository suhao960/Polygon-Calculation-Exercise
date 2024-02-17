#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->qb_name = "长方形";
}

Rectangle::Rectangle(float a, float b)
{
	this->a = a;
	this->b = b;
	this->qb_name = "长方形";
}

void Rectangle::SetA(float a)
{
	this->a = a;
}

float Rectangle::GetA()
{
	return this->a;
}

void Rectangle::SetB(float b)
{
	this->b = b;
}

float Rectangle::GetB()
{
	return this->b;
}

void Rectangle::SetAB(float a, float b)
{
	this->a = a;
	this->b = b;
}

string Rectangle::GetqbName()
{
	return this->qb_name;
}

string Rectangle::GetqbContent()
{
	string a = "长" + to_string((int)this->GetA()) + "  宽" + to_string((int)this->GetB());
	return a;
}

string Rectangle::Getqbcontent()
{
	return to_string(this->GetA())+" "+to_string(this->GetB());
}

void Rectangle::SetUserAnswer(float c, float s)
{
	this->useranswer_c = c;
	this->useranswer_s = s;
}

bool Rectangle::JudgeIt(float a,float b)
{
	if (a > 0 && b > 0 && a != b)
		return true;
	else
		return false;
}

float Rectangle::CalculateGirth()
{
	this->rightanswer_c = this->a + this->a + this->b + this->b;
	this->rightanswer_s = this->a * this->b;
	return rightanswer_c;
}

float Rectangle::CalculateArea()
{
	return this->rightanswer_s;
}


Rectangle::~Rectangle()
{
	
}
