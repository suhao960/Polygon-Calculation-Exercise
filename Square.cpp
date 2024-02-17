#include "Square.h"

Square::Square()
{
	this->qb_name = "正方形";
}

Square::Square(float a)
{
	this->a = a;
	this->qb_name = "正方形";
}

void Square::SetA(float a)
{
	this->a = a;
}

float Square::GetA()
{
	return this->a;
}

string Square::GetqbName()
{
	return this->qb_name;
}

string Square::GetqbContent()
{
	string a = "边长" + to_string((int)this->GetA());
	return a;
}

string Square::Getqbcontent()
{
	return to_string(this->GetA());
}

void Square::SetUserAnswer(float c, float s)
{
	this->useranswer_c = c;
	this->useranswer_s = s;
}

bool Square::JudgeIt(float a)
{
	if (a > 0)
		return true;
	else
		return false;
}

//运算符重载————————————————————
int Square::CompareSize(Square* s1, Square* s2)
{
	if (s1 > s2) return 1;
	else if (s1 < s2) return -1;
	else return 0;
}

bool Square::operator>(const Square& otherSquare)
{
	if (this->a > otherSquare.a) return true;
	else return false;
}

bool Square::operator=(const Square& otherSquare)
{
	if (this->a == otherSquare.a) return true;
	else return false;
}

bool Square::operator<(const Square& otherSquare)
{
	if (this->a < otherSquare.a) return true;
	else return false;
}
//——————————————————————————
float Square::CalculateGirth()
{
	this->rightanswer_c = 4 * a;
	this->rightanswer_s = a * a;
	return this->rightanswer_c;
}

float Square::CalculateArea()
{
	return rightanswer_s;
}

Square::~Square()
{
}
