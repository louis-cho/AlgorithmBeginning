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

	//초기 단계에서 1개의 항을 갖는 제곱수는 1로 초기화 시켜놓기
	for (int i = 1; i <= sqrt(N); i++) {
		dp[i*i] = 1;
	}

	//이후에는 점화식을 통해 dp 완성하기
	//주어진 문제의 특성을 이용한다. 
	//(주어진 N은 가장 큰 어떤 수의 제곱과 나머지 수들의 제곱의 합으로 이루어져 있다.)
	for (int i = 1; i < N; i++) {
		for (int j = 1; j*j+i <= N; j++) {
			//25와 같은 수를 걱정할 필요는 없다 
			//(5의 제곱은 항이 1개, 3의 제곱과 4의 제곱의 합은 항이 2개)
			//즉 최소 항의 개수가 의도한 대로 나온다.
			dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
 		}
	}

	cout << dp[N];
	while (getchar() != 'q');
}