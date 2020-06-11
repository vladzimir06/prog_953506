#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>


int main() {
	int n = 0, m = 0, numb = 0, count = 0, count2 = 0;
	char** a;

	printf("Enter size of the array(n m): \n");
	scanf("%d", &n);
	scanf("%d", &m);
	a = (char**)malloc(n * sizeof(char*));
	
	for (int i = 0; i < n; i++) {
		a[i] = (char*)malloc(m * sizeof(char));
	}

	printf("Enter array size from ");
	printf("%d", n);
	printf(" to ");
	printf("%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", &a);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '0' || a[i][j] == 'x') {
				numb++;
			}
		}
	}
	if (numb == m * n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'x' && a[i + 1][j] == 'x' && a[i + 2][j] == 'x' && a[i + 3][j] == 'x' && a[i + 4][j] == 'x') {
					printf("X win \n");
					count++;
					goto a;
				}
				if (a[i][j] == 'x' && a[i][j + 1] == 'x' && a[i][j + 2] == 'x' && a[i][j + 3] == 'x' && a[i][j + 4] == 'x') {
					printf("X win \n");
					count++;
					goto b;

				}
				if (a[i][j] == 'x' && a[i + 1][j + 1] == 'x' && a[i + 2][j + 2] == 'x' && a[i + 3][j + 3] == 'x' && a[i + 4][j + 4] == 'x') {
					printf("X win \n");
					count++;
					goto c;

				}
				if (a[i][j] == 'x' && a[i + 1][j - 1] == 'x' && a[i + 2][j - 2] == 'x' && a[i + 3][j - 3] == 'x' && a[i + 4][j - 4] == 'x') {
					printf("X win \n");
					count++;
					goto d;
				}

			}
		}
	}

	else {
		printf("\t ERROR \n");
		printf("You should enter only 0 or x");
		count2++;
	}
a: b: c: d:
	if (count == 0 && count2 == 0) {
		printf("X lose \n");
	}
	return 0;
}
