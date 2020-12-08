#pragma once
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//constant
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define Bird_BOTTOM_Y 10
#define BIRD_BOTTOM_X 45
#define GRAVITY 3
#define CROWD_TIME 10
#define LEADER_BOARD_MAX 5

//function
void SetConsoleView();
void GoToXY(int x, int y);
int GetKeyDown();
void DrawDino(int dino_y);
void DrawTree(int tree_x);
void DrawDinoCrowd();
void DrawGameOver(const int score);
bool IsTreeCollision(const int tree_x, const int dino_y);
void DrawBird(int bird_x);
bool IsBirdCollision(const int bird_x, const int dino_y, const int is_crowd);
bool IsCoinCollision(const int coin_x, const int dino_y);
bool IsLifeCollision(const int life_x, const int dino_y);
bool Cmp(int a, int b);

//class
class Status {
private:
	bool is_jumping;
	bool is_bottom;
	int is_crowd;
public:
	bool GetIsJumping() { return is_jumping; }
	bool GetIsBottom() { return is_bottom; }
	int GetIsCrowd() { return is_crowd; }
	void StatusInit();
	void SetIsJumping(bool);
	void SetIsBottom(bool);
	void SetIsCrowd(int);
};

class Where {
private:
	int dino_y;
	int tree_x;
	int bird_x;
public:
	int GetDinoY() { return dino_y; }
	int GetTreeX() { return tree_x; }
	int GetBirdX() { return bird_x; }
	void WhereInit();
	void SetDinoY(int);
	void SetTreeX(int);
	void SetBirdX(int);
	void DinoYPlus(int);
	void DinoYMinus(int);
	void BirdXMinus(int);
	void TreeXMinus(int);
};

class LeaderBoard {
private:
	vector<int>leader_board;
public:
	void LeaderBoardPush(int);
	void ShowLeaderBoard();
	void LeaderBoardSort();
};
