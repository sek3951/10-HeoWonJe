#pragma once

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define Bird_BOTTOM_Y 10
#define BIRD_BOTTOM_X 45

void SetConsoleView();
void GoToXY(int x, int y);
int GetKeyDown();
void DrawDino(int dino_y);
void DrawDinoCrowd(int dino_y);
void DrawTree(int tree_x);
void DrawBird(int bird_x);
void DrawGameOver(const int score);
bool IsTreeCollision(const int tree_x, const int dino_y);
bool IsBirdCollision(const int bird_x, const int dino_y);
bool IsCoinCollision(const int coin_x, const int dino_y);
bool IsLifeCollision(const int life_x, const int dino_y);