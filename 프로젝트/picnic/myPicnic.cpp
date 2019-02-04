#include<assert.h>
#include<iostream>

using namespace std;

int student, numOfPair;
bool areFriends[10][10];

int countPair(bool taken[]);

int main(void) {
	int cases;
	cin >> cases;
	while (cases--) {
		cin >> student >> numOfPair;
		memset(areFriends, 0, sizeof(areFriends));
		int ret = 0;
		for (int i = 0; i < numOfPair; i++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true;
		}

		bool taken[10];
		memset(taken, 0, sizeof(taken));
		cout << countPair(taken) << endl;
	}
	return 0;
}

int countPair(bool taken[]) {
	int remainIndex = -1;
	for (int i = 0; i < student; i++) {
		if (!taken[i]) {
			remainIndex = i;
			break;
		}
	}

	if (remainIndex == -1) return 1;
	int result = 0;
	for (int pairIndex = remainIndex + 1; pairIndex < student; pairIndex++) {
		if (!taken[pairIndex] && areFriends[remainIndex][pairIndex]) {
			taken[remainIndex] = taken[pairIndex] = true;
			result += countPair(taken);
			taken[remainIndex] = taken[pairIndex] = false;
		}
	}

	return result;
}
