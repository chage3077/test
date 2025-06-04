#include "JudgeMarking.h"

Player::Player()
{
}

Player::~Player()
{
}

void JudgeMarking::printf_score(const vector<Player>& v)
{
	for (vector<Player>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->p_name << ",得分：" << it->p_score << endl;
		pritf_judge_score(it);
	}
	
}

void JudgeMarking::cratePlayer(vector<Player>& v)
{
	string name = "ABCDE";
	for (int i = 0; i < name.size(); i++)
	{
		string str = string("选手") + name[i];
		Player p(str, 0);
		v.push_back(p);
	}
}

void JudgeMarking::setScore(vector<Player>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		// 随机生成10个裁判的分数
		for (int i = 0; i < 10; i++)
		{
			float score = rand() % 41 + 60;
			it->p_scoreList.push_back(score);
		}

		// 排序评委的分数
		sort(it->p_scoreList.begin(), it->p_scoreList.end());
		
		// 去掉最高分和最低分
		it->p_scoreList.pop_front();
		it->p_scoreList.pop_back();
		// 计算总分
		int sum = 0;
		for (int i = 0; i < it->p_scoreList.size(); i++)
		{
			sum += it->p_scoreList[i];
		}
		float avg = sum / it->p_scoreList.size();
		it->p_score = avg;
	}
}

void JudgeMarking::pritf_judge_score(vector<Player>::const_iterator it)
{
	cout << "评委打分(已去掉最高分和最低分)：";
	// 打印评委的分数
	for (auto dit = it->p_scoreList.begin(); dit != it->p_scoreList.end(); dit++)
	{
		cout << *dit << " ";
	}
	cout << endl;
}
