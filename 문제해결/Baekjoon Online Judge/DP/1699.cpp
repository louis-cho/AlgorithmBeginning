#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 100001

using namespace std;

int N;
int dp[MAX];

int main(void) {
	cin >> N;
	fill_n(dp, MAX, MAX);

	//�ʱ� �ܰ迡�� 1���� ���� ���� �������� 1�� �ʱ�ȭ ���ѳ���
	for (int i = 1; i <= sqrt(N); i++) {
		dp[i*i] = 1;
	}

	//���Ŀ��� ��ȭ���� ���� dp �ϼ��ϱ�
	//�־��� ������ Ư���� �̿��Ѵ�. 
	//(�־��� N�� ���� ū � ���� ������ ������ ������ ������ ������ �̷���� �ִ�.)
	for (int i = 1; i < N; i++) {
		for (int j = 1; j*j+i <= N; j++) {
			//25�� ���� ���� ������ �ʿ�� ���� 
			//(5�� ������ ���� 1��, 3�� ������ 4�� ������ ���� ���� 2��)
			//�� �ּ� ���� ������ �ǵ��� ��� ���´�.
			dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
 		}
	}

	cout << dp[N];
	while (getchar() != 'q');
}