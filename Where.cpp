#include "common.h"

void Where::WhereInit() {
	dino_y = DINO_BOTTOM_Y;
	tree_x = TREE_BOTTOM_X;
	bird_x = BIRD_BOTTOM_X;
}

void Where::SetDinoY(int y) {
	dino_y = y;
}
void Where::SetTreeX(int x) {
	tree_x = x;
}
void Where::SetBirdX(int x) {
	bird_x = x;
}
void Where::DinoYPlus(int gravity) {
	dino_y += gravity;
}
void Where::DinoYMinus(int gravity) {
	dino_y -= gravity;
}
void Where::BirdXMinus(int distance) {
	bird_x -= distance;
}
void Where::TreeXMinus(int distance) {
	tree_x -= distance;
}