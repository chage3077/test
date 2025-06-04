#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;
class Player
{
public:
	Player();
	~Player();
	string p_name;
	float p_score;
	deque<float> p_scoreList; // 评委打分的表

	Player(string& name, float score) :p_name(name), p_score(score)
	{
		
	}
	
private:

};
class JudgeMarking
{
public:
	void printf_score(const vector<Player>& v);
	void cratePlayer(vector<Player>& v);
	void setScore(vector<Player>& v);
	void pritf_judge_score(vector<Player>::const_iterator it);
};