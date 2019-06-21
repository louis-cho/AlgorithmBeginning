#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int N;
queue<int> q;	//N을 만들기 위해 남은 수를 저장하는 큐

int getSquareNum();

int main(void) {
	int res;
	cin >> N;
	res = getSquareNum();
	printf("%d", res);
	while (getchar() != 'q');
}

int getSquareNum() {
	int num, pop, size, cnt = 0;

	size = sqrt(N);
	//1단계 숫자들 큐에 넣기
	for (int i = size; i >= 1; --i) {
		q.push(N - (int)pow(i, 2));
	}

	//만족하는 최상의 경우를 찾을 때까지 무한 반복
	while (true) {
		++cnt;
		//이번 레벨의 큐 사이즈만큼 돌기 위해 세팅
		size = q.size();
		for (int i = 0; i < size; ++i) {
			pop = q.front();
			q.pop();
			//남은 수가 없다는 것은 주어진 수에 대한 제곱수를 구한 경우
			if (pop == 0) {
				return cnt;
			}
			//남은 수에 대한 sprt()
			num = (int)sqrt(pop);
			//나올 수 있는 범위 내에서 큐에 후보군을 넣기
			for (int i = num; i > 0; --i) {
				q.push(pop - (int)pow(i, 2));
			}
		}
	}
	return -1;
}