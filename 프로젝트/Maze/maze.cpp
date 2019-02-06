//출처 https://blockdmask.tistory.com/182

#include<iostream>
#include<queue>
#pragma warning (disable:4996)

using namespace std;

int n, m;

bool maze[100][100];
int pass[100][100];
int way[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };	//4 direction (up down right left)

void Input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int b;
			scanf("%1d", &b);

			if (b == 1) {
				maze[i][j] = true;
			}
		}
	}
}

void Output(int num) {
	printf("%d\n", num);
}

bool isInside(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < m);
}

int bfs() {
	int cur_y = 0, cur_x = 0;			//시작점의 좌표

	queue<pair<int, int>> q;				//bfs를 위한 pair<int, int> 큐 생성
	q.push(pair<int, int>(cur_y, cur_x));	//현재 좌표 집어넣기
	pass[cur_y][cur_x] = 1;					//이동 횟수 1회 증가

	while (!q.empty()) {					//지나온 점이 있을 때 동안 반복
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		if ((cur_y == n - 1) && (cur_x == m - 1)) break;		//큐에서 꺼낸 점이 종점이라면 끝낸다.

		for (int i = 0; i < 4; i++) {							//상,하,좌,우 이동
			int next_y = cur_y + way[i][0];
			int next_x = cur_x + way[i][1];

			if(isInside(next_y, next_x) && pass[next_y][next_x] == 0 && maze[next_y][next_x]){	//좌표가 2차원 배열 안에 존재하고, 지나오지 않았으며, 미로의 길이 있다면
				pass[next_y][next_x] = pass[cur_y][cur_x] + 1;									//이동 횟수를 1회 늘리고
				q.push(pair<int, int>(next_y, next_x));											//큐에 집어넣는다.
			}
		}
	}
	return pass[n - 1][m - 1];
}

int main(void) {
	Input();
	Output(bfs());
	return 0;
}
