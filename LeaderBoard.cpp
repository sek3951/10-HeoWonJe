#include "common.h"

void LeaderBoard::LeaderBoardPush(int score) {
	leader_board.push_back(score);
}

void LeaderBoard::ShowLeaderBoard() {
	cout << "===== L E A D E R B O A R D =====";
	if (leader_board.size() < LEADER_BOARD_MAX) {
		for (int i = 0; i < leader_board.size(); i++) {
			GoToXY(16, 12 + i);
			cout << "RANK " << i + 1 << " : " << leader_board[i];
		}
	}
	else {
		for (int i = 0; i < LEADER_BOARD_MAX; i++) {
			GoToXY(16, 12 + i);
			cout << "RANK " << i + 1 << " : " << leader_board[i];
		}
	}
	cout << "\n\n\n\n\n\n";
	system("pause");
}

void LeaderBoard::LeaderBoardSort() {
	sort(leader_board.begin(), leader_board.end(), Cmp);
}