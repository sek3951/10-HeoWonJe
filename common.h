#pragma once

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define Bird_BOTTOM_Y 10
#define BIRD_BOTTOM_X 45
#define GRAVITY 3
#define CROWD_TIME 10

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