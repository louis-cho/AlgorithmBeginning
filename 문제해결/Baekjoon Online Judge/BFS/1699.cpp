#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int N;
queue<int> q;	//N�� ����� ���� ���� ���� �����ϴ� ť

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
	//1�ܰ� ���ڵ� ť�� �ֱ�
	for (int i = size; i >= 1; --i) {
		q.push(N - (int)pow(i, 2));
	}

	//�����ϴ� �ֻ��� ��츦 ã�� ������ ���� �ݺ�
	while (true) {
		++cnt;
		//�̹� ������ ť �����ŭ ���� ���� ����
		size = q.size();
		for (int i = 0; i < size; ++i) {
			pop = q.front();
			q.pop();
			//���� ���� ���ٴ� ���� �־��� ���� ���� �������� ���� ���
			if (pop == 0) {
				return cnt;
			}
			//���� ���� ���� sprt()
			num = (int)sqrt(pop);
			//���� �� �ִ� ���� ������ ť�� �ĺ����� �ֱ�
			for (int i = num; i > 0; --i) {
				q.push(pop - (int)pow(i, 2));
			}
		}
	}
	return -1;
}