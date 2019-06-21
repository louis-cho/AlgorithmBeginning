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
	//N�� K���� ū ��� �̵��� �� �ִ� ���� 1ĭ �� �ۿ� ����.
	if (N >= K) {
		res = N - K;
	}
	//N�� K���� ���� ��� bfs�� ���� Ǯ��� 
	else {
		int pop, target = N, cnt = 0, size;
		q.push(target);
		while (!q.empty()) {
			size = q.size();				//ť ����� ������� �߿� pop()���� ���� ������ �ʵ��� �����ϱ� 
			for (int i = 0; i < size; i++) {
				pop = q.front();
				q.pop();
				if (pop == K) {
					res = cnt;
					break;
				}
				//visited�� ���������� ������ �ּҰ��� �������� �� ����.
				//���� Ȯ�ε� �ʼ� 
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
			//���� ã������ �� �̻� ������ ������ ����. 
			if (res != 0)
				break;
			cnt++;
		}
	}

	printf("%d", res);
}
