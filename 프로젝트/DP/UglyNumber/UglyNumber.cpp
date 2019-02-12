#include<iostream>

int main()
{
	int ugly[1000] = { 0 };
	int j = 0;
	int temp = 0;
	for (int i = 0; i < 10000; i++) {
		temp = i + 1;
		while (temp % 2 == 0) {
			temp /= 2;
		}
		while(temp % 3 == 0) {
			temp /= 3;
		}
		while (temp % 5 == 0) {
			temp /= 5;
		}
		
		if (temp == 1) {
			ugly[j++] = i + 1;
		}
	}

	int index = 0;
	int res = 1;
	while ((res = scanf("%d", &index)) != 0) {
		printf("\nOutput : %d\n\n", ugly[index-1]);
	}
}