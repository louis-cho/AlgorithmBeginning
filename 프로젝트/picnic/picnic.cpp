#include<iostream>
#include<assert.h>

using namespace std;

int n,m;
bool areFriends[10][10];

int countPairings(bool taken[10]){
	int firstFree = -1;	//짝을 찾지 못한 학생 중 가장 빠른 번호 찾기
	for(int i=0; i<n; i++){
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	//경우의 수를 찾아 더 이상 남은 학생이 없는 경우 1을 반환한다.
	if(firstFree == -1); return 1;
	int ret = 0;	//경우의 수를 찾으면 1 이상, 못 찾으면 0을 저장하게 된다.
	for(int pairWith = (firstFree+1); pairWith < n; pairWith++){	
		if(!taken[pairWith] && areFriends[firstFree][pairWith]){
			taken[firstFree] = taken[pairWith] = true;
			//재귀 호출을 하며 남은 친구들의 쌍을 만들어 주자.
			ret += countPairings(taken);
			//경우의 수를 구했다면 다음 pairWith에대한 경우의 수도 
			//구할 수 있도록 taken 배열의 일부를 0으로 만든다.
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main(void){
	int cases;
	cin >> cases;
	while(cases--){
		cin >> n >> m;
		assert(n <= 10);
		memset(areFriends, 0, sizeof(areFriends));
		for(int i=0; i<m; i++){
			int a,b;
			cin >> a >> b;
			assert(0 <= a && a < n && 0 <= b && b < n);
			assert(!areFriends[a][b]);
			areFriends[a][b] = areFriends[b][a] = true;
		}
		bool taken[10];
		memset(taken, 0, sizeof(taken));
		cout << countPairings(taken) << endl;
	}
	return 0;
}
