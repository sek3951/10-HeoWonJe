#pragma once

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define Bird_BOTTOM_Y 10
#define Bird_BOTTOM_X 45

void SetConsoleView();
void GoToXY(int x, int y);
int GetKeyDown();
void DrawDino(int dinoY);
void DrawTree(int treeX);
void DrawGameOver(const int score);
bool IsCollision(const int treeX, const int dinoY);
void DrawBird(int birdX);
bool IsBirdCollision(const int birdX, const int dinoY);