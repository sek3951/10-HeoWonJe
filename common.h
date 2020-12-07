#pragma once

//constant
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define Bird_BOTTOM_Y 10
#define BIRD_BOTTOM_X 45
#define GRAVITY 3
#define CROWD_TIME 10

//function
void SetConsoleView();
void GoToXY(int x, int y);
int GetKeyDown();
void DrawDino(int dino_y);
void DrawTree(int tree_x);
void DrawDinoCrowd();
void DrawGameOver(const int score, const int leader_board[]);
bool IsTreeCollision(const int tree_x, const int dino_y);
void DrawBird(int bird_x);
bool IsBirdCollision(const int bird_x, const int dino_y, const int is_crowd);
bool IsCoinCollision(const int coin_x, const int dino_y);
bool IsLifeCollision(const int life_x, const int dino_y);

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