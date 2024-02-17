#include "Bank.h"
#include<thread>
#include<chrono>
Bank::Bank()
{
	this->QB_name = "小学生多边形计算练习题";
	this->QB_number = 0;
	this->formerQB_num = 0;
	this->vv = v_qb.begin();
	this->username = "";
	this->timer = 0;
	this->QB_score = 0;
}

void Bank::InitBank(int i)
{
	this->formerQB_num = this->QB_number;
	this->QB_number += i;
	//its purpose is randomly forming questions
	srand((unsigned)time(NULL));
	for (int a = 0; a < i; a++)
	{
		int tem = rand() % 5 + 1;
		switch (tem)
		{
		case 1: SquareQuestion(a+1); break;
		case 2: RectangleQuestion(a+1); break;
		case 3: CircleQuestion(a+1); break;
		case 4: TrapeziumQuestion(a+1); break;
		case 5: TriangleQuestion(a+1); break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));//充分体现随机
	}
}

void Bank::SetQBName(string name)
{

	this->QB_name = name;
}

string Bank::GetQBName()
{
	return this->QB_name;
}

void Bank::SetQBNum(int num)
{
	this->QB_number = num;
}

int Bank::GetQBNum()
{
	return this->QB_number;
}

void Bank::AccumulateEveryandAllandAveragescore()
{
	/*//计算并存储每个题目的成绩和正确答案
	for (this->vv = this->v_qb.begin()+this->formerQB_num; this->vv != this->v_qb.end(); this->vv++)
	{
		(*this->vv)->JudgeAnswer();
	}
	//计算题库总成绩
	for (this->vv = this->v_qb.begin()+this->formerQB_num; this->vv != this->v_qb.end(); this->vv++)
	{
		this->QB_score = this->QB_score + (*this->vv)->GetScore();
	}
	this->QB_averagescore = (float)this->QB_score / (float)this->QB_number;*/

	//计算并存储每个题目的成绩和正确答案
	for (this->vv = this->v_qb.begin(); this->vv != this->v_qb.end(); this->vv++)
	{
		(*this->vv)->JudgeAnswer();
	}
	//计算题库总成绩
	for (this->vv = this->v_qb.begin(); this->vv != this->v_qb.end(); this->vv++)
	{
		this->QB_score = this->QB_score + (*this->vv)->GetScore();
	}
	this->QB_averagescore = (float)this->QB_score / (float)this->QB_number;
}

int Bank::Getqbscore(int i)
{
	this->vv = this->v_qb.begin() + i - 1;
	int a = (*vv)->GetScore();
	this->vv = this->v_qb.begin();
	return a;
}

float Bank::GetAverageSco()
{
	return this->QB_averagescore;
}

void Bank::SetUsername(string un)
{
	this->username = un;
}

string Bank::GetUsername()
{
	return this->username;
}

void Bank::SetTimer(float timer)
{
	this->timer = timer;
}

float Bank::GetTimer()
{
	return this->timer;
}

float Bank::GetRightRate()
{
	return (this->QB_score / ((float)this->QB_number * 2.0f));
}

int Bank::GetQBScore()
{
	return this->QB_score;
}

void Bank::SetUserAnswerC(int i,float c)
{
	this->vv = this->v_qb.begin() + i;
	(*this->vv)->SetUserAnswerC(c);
	this->vv = this->v_qb.begin();

	//v_qb.at(i)->SetUserAnswerC(c);
}

void Bank::SetUserAnswerS(int i,float s)
{
	this->vv = this->v_qb.begin() + i ;
	(*this->vv)->SetUserAnswerS(s);
	this->vv = this->v_qb.begin();
}

string Bank::GetqbName(int i)
{
	return this->v_qb[i]->GetqbName();
}

float Bank::GetUserAnswerC(int i)
{
	this->vv = this->v_qb.begin() + i - 1;
	float a = (*vv)->GetUserAnswerC();
	this->vv = this->v_qb.begin();
	return a;
}

int Bank::GetFormerQBNum()
{
	return this->formerQB_num;
}

string Bank::GetqbContent(int i)
{
	return this->v_qb[i]->GetqbContent();
}

float Bank::GetUserAnswerS(int i)
{
	this->vv = this->v_qb.begin() + i - 1;
	float a = (*vv)->GetUserAnswerS();
	this->vv = this->v_qb.begin();
	return a;
}

void Bank::SquareQuestion(int qbnum)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		float a = (float)(rand() % 10 + 1);
		if (Square::JudgeIt(a))//judge whether it can consist to a square,yes in
		{
			Shape* s = new Square(a);
			s->SetqbNum(qbnum);
			s->SetScore(0);
			v_qb.push_back(s);
			s = NULL;
			break;
		}
	}
}

float Bank::GetRightAnswerC(int i)
{
	this->vv = this->v_qb.begin() + i - 1;
	float a = (*vv)->GetRightAnswerC();
	this->vv = this->v_qb.begin();
	return a;
}

float Bank::GetRightAnswerS(int i)
{
	this->vv = this->v_qb.begin() + i - 1;
	float a = (*vv)->GetRightAnswerS();
	this->vv = this->v_qb.begin();
	return a;
}

void Bank::RectangleQuestion(int qbnum)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		float a = (float)(rand() % 10 + 1);
		float b = (float)(rand() % 10 + 1);
		if (Rectangle::JudgeIt(a, b))
		{
			Shape* s = new Rectangle(a, b);
			s->SetqbNum(qbnum);
			s->SetScore(0);
			v_qb.push_back(s);
			s = NULL;
			break;
		}
	}
}

void Bank::CircleQuestion(int qbnum)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		float r = (float)(rand() % 10 + 1);
		if (Circle::JudgeIt(r))
		{
			Shape* s = new Circle(r);
			s->SetqbNum(qbnum);
			s->SetScore(0);
			v_qb.push_back(s);
			s = NULL;
			break;
		}
	}
}

void Bank::TrapeziumQuestion(int qbnum)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		float a = (float)(rand() % 10 + 1);
		float b = (float)(rand() % 10 + 1);
		float c = (float)(rand() % 10 + 1);
		float d = (float)(rand() % 10 + 1);
		if (Trapezium::JudgeIt(a, b, c, d))
		{
			Shape* s = new Trapezium(a, b, c, d);
			s->SetqbNum(qbnum);
			s->SetScore(0);
			v_qb.push_back(s);
			s = NULL;
			break;
		}
	}
}

void Bank::TriangleQuestion(int qbnum)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		float a = (float)(rand() % 10 + 1);
		float b = (float)(rand() % 10 + 1);
		float c = (float)(rand() % 10 + 1);
		if (Triangle::JudgeIt(a, b, c))
		{
			Shape* s = new Triangle(a, b, c);
			s->SetqbNum(qbnum);
			s->SetScore(0);
			v_qb.push_back(s);
			s = NULL;
			break;
		}
	}
}

void Bank::AddQuestion(int i)
{
	this->QB_number += i;
	srand((unsigned)time(NULL));
	for (int a = 0; a < i; a++)
	{
		int tem = rand() % 5 + 1;
		switch (tem)
		{
		case 1: SquareQuestion(a + 1); break;
		case 2: RectangleQuestion(a + 1); break;
		case 3: CircleQuestion(a + 1); break;
		case 4: TrapeziumQuestion(a + 1); break;
		case 5: TriangleQuestion(a + 1); break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));//充分体现随机
	}
}

void Bank::DeleteQuestion(int i)
{
	delete this->v_qb[i - 1];
	v_qb.erase(v_qb.begin() + i-1);
	this->QB_number--;
}

void Bank::SaveQuestionForLogonWay()
{
	//存题库
	ofstream ofs;
	ofs.open("./UserBank.txt", ios::out | ios::ate | ios::app);
	for (int i = 0; i < this->GetQBNum(); i++)
	{
		//存不了中文，明天想想其他办法！
		//ofs << this->v_qb[i]->GetqbName() << "\t" << this->v_qb[i]->GetqbContent() << "\t";
		if (this->v_qb[i]->GetqbName() == "正方形")
		{
			ofs << "Z " << this->v_qb[i]->Getqbcontent() << " " << this->v_qb[i]->GetUserAnswerC() << " " << this->v_qb[i]->GetUserAnswerS() << endl;
		}
		else if (this->v_qb[i]->GetqbName() == "长方形")
		{
			ofs << "C " << this->v_qb[i]->Getqbcontent() << " " << this->v_qb[i]->GetUserAnswerC() << " " << this->v_qb[i]->GetUserAnswerS() << endl;
		}
		else if (this->v_qb[i]->GetqbName() == "圆 形")
		{
			ofs << "Y " << this->v_qb[i]->Getqbcontent() << " " << this->v_qb[i]->GetUserAnswerC() << " " << this->v_qb[i]->GetUserAnswerS() << endl;
		}
		else if (this->v_qb[i]->GetqbName() == "梯 形")
		{
			ofs << "T " << this->v_qb[i]->Getqbcontent() << " " << this->v_qb[i]->GetUserAnswerC() << " " << this->v_qb[i]->GetUserAnswerS() << endl;
		}
		else if (this->v_qb[i]->GetqbName() == "三角形")
		{
			ofs << "S " << this->v_qb[i]->Getqbcontent() << " " << this->v_qb[i]->GetUserAnswerC() << " " << this->v_qb[i]->GetUserAnswerS() << endl;
		}
		else
		{
			cout << "error happen" << endl;
		}
	}
	ofs << "***" << endl;
	ofs.close();
	//存时间、做题数量、正确率(存小数，显示时再处理)
	ofstream ofs1;
	ofs1.open("./UserRank.txt", ios::out | ios::ate | ios::app);
	ofs1 << this->GetTimer() << " " << this->GetQBNum() << " " << this->GetRightRate() << endl;
	ofs1.close();
}

void Bank::SaveOnlyForLogon()
{
	ofstream ofs;
	ofs.open("./UserBank.txt", ios::out | ios::ate | ios::app);
	ofs << "***" << endl;
	ofs.close();

	ofstream ofs1;
	ofs1.open("./UserRank.txt", ios::out | ios::ate | ios::app);
	int a = 0;
	ofs1 << this->GetTimer() << " " << this->GetQBNum() << " " << a << endl;
	ofs1.close();
}

void Bank::IniteeBank(int i, string type)
{
	this->formerQB_num++;
	this->QB_number++;
	if (type == "正方形")
	{
		Shape* s = new Square();
		v_qb.push_back(s);
		s = NULL;
	}
	else if (type == "长方形")
	{
		Shape* s = new Rectangle();
		v_qb.push_back(s);
		s = NULL;
	}
	else if (type == "圆 形")
	{
		Shape* s = new Circle();
		v_qb.push_back(s);
		s = NULL;
	}
	else if (type == "梯 形")
	{
		//this->v_qb[i] = new Trapezium();
		
		Shape* s = new Trapezium();
		//s->SetScore(0);
		v_qb.push_back(s);
		s = NULL;
	}
	else if (type == "三角形")
	{
		Shape* s = new Triangle();
		v_qb.push_back(s);
		s = NULL;
	}
}

void Bank::SetFangXingLength(int i, float a)
{
	this->v_qb[i]->SetA(a);
}

void Bank::SetFangXingLength(int i, float a, float b)
{
	this->v_qb[i]->SetAB(a, b);
}

void Bank::SetFangXingLength(int i, float a, float b, float c)
{
	this->v_qb[i]->SetABC(a,b,c);
}

void Bank::SetFangXingLength(int i, float a, float b, float c, float d)
{
	this->v_qb[i]->SetABCD(a,b,c,d);
}

void Bank::SetYuanXingRadius(int i,float r)
{
	this->v_qb[i]->SetR(r);
}

void Bank::SetUserAnswer(int i, float uc, float us)
{
	this->v_qb[i]->SetUserAnswerC(uc);
	this->v_qb[i]->SetUserAnswerS(us);
}

Bank::~Bank()
{
	v_qb.clear();
}

