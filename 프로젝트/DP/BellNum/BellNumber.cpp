#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int** arr = NULL;
	int temp;
	printf("Calculate Nth Bell Number? >> ");
	scanf("%d", &temp);

	int n = temp - 1;
	arr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*(i + 1));
	}
	arr[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				arr[i][0] = arr[i - 1][i - 1];
			}
			arr[i][j] = arr[i - 1][j - 1] + arr[i][j-1];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		} printf("\n");
	}
	printf("\n\nBell Number is %d\n", arr[n-1][n-1]);
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
