#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

	int board[12][12];
	int num = 1;

	while (true) {
		int b;
		cin >> b;
        if (b == -1)
            break;

		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 12; ++j) {
				board[i][j] = 0;
			}
		}

		for (int i = 0; i < 12; ++i) {
			board[0][i] = board[1][i] = board[10][i] = board[11][i] = -1;
			board[i][0] = board[i][1] = board[i][10] = board[i][11] = -1;
		}

		for (int i = 0; i < b; ++i) {
			string pos;
			cin >> pos;
			int x = pos[1] - '1' + 2;
			int y = pos[0] - 'a' + 2;
			board[x][y] = -1;
		}

		string start, end;
		cin >> start >> end;
		int sx = start[1] - '1' + 2;
		int sy = start[0] - 'a' + 2;
		int ex = end[1] - '1' + 2;
		int ey = end[0] - 'a' + 2;

		int dist[12][12] = {};
		queue<pair<int, int>> q;
		dist[sx][sy] = 1;
		q.push({sx, sy});

		while (!q.empty() && dist[ex][ey] == 0) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int k = 0; k < 8; ++k) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];
				if (board[nx][ny] != -1 && dist[nx][ny] == 0) {
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					q.push({nx, ny});
				}
			}
		}

		cout << "Board " << num++ << ":";
		if (dist[ex][ey] == 0) {
			cout << "not reachable\n";
		} else {
			cout << dist[ex][ey] - 1 << " moves\n";
		}
	}

	return 0;
}
