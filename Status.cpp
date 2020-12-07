#include "common.h"

void Status::StatusInit() {
	is_jumping = false;
	is_bottom = true;
	is_crowd = 0;
}

void Status::SetIsJumping(bool jumping) {
	is_jumping = jumping;
}
void Status::SetIsBottom(bool bottom) {
	is_bottom = bottom;
}
void Status::SetIsCrowd(int time) {
	is_crowd = time;
}