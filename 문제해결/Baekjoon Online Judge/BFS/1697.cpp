#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 100001

int N, K;
int time[MAX];
bool visited[MAX];
queue<int> q;

int main(void) {
	int cnt = 0, res = 0;
	cin >> N >> K;
	//N이 K보다 큰 경우 이동할 수 있는 경우는 1칸 씩 밖에 없다.
	if (N >= K) {
		res = N - K;
	}
	//N이 K보다 작은 경우 bfs를 통해 풀어보기 
	else {
		int pop, target = N, cnt = 0, size;
		q.push(target);
		while (!q.empty()) {
			size = q.size();				//큐 사이즈가 진행과정 중에 pop()으로 인해 변하지 않도록 저장하기 
			for (int i = 0; i < size; i++) {
				pop = q.front();
				q.pop();
				if (pop == K) {
					res = cnt;
					break;
				}
				//visited를 설정해주지 않으면 최소값을 보장해줄 수 없다.
				//범위 확인도 필수 
				if (!visited[pop - 1] && pop - 1 > 0) {
					q.push(pop - 1);
					visited[pop - 1] = true;
				}
				if (!visited[pop + 1] && pop + 1 < MAX) {
					q.push(pop + 1);
					visited[pop + 1] = true;
				}
				if (!visited[pop * 2] && pop * 2 < MAX) {
					q.push(pop * 2);
					visited[pop * 2] = true;
				}
			}
			//답을 찾았으면 더 이상 진행할 이유가 없다. 
			if (res != 0)
				break;
			cnt++;
		}
	}

	printf("%d", res);
}
