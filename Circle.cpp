#include "Circle.h"

Circle::Circle()
{
	this->qb_name = "圆 形";
}

Circle::Circle(float r)
{
	this->r = r;
	this->qb_name = "圆 形";
}

void Circle::SetR(float r)
{
	this->r = r;
}

float Circle::GetR()
{
	return this->r;
}

string Circle::GetqbName()
{
	return this->qb_name;
}

string Circle::GetqbContent()
{
	string a = "半径为" + to_string((int)this->GetR());
	return a;
}

string Circle::Getqbcontent()
{
	return to_string(this->GetR());
}

void Circle::SetUserAnswer(float c, float s)
{
	this->useranswer_c = c;
	this->useranswer_s = s;
}

bool Circle::JudgeIt(float r)
{
	if (r > 0)
		return true;
	else
		return false;
}

float Circle::CalculateGirth()
{
	this->rightanswer_c = float(2.0f * PI * this->r);
	this->rightanswer_s = float(PI * this->r * this->r);
	return this->rightanswer_c;
}

float Circle::CalculateArea()
{
	return this->rightanswer_s;
}


Circle::~Circle()
{
}
