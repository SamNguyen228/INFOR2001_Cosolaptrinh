#include<stdio.h>

int main()
{
	int n, i, k; 
	printf("Input value of n: ");
	scanf("%d", &n);
	i = 1;
	k = 0;
	while (i <= n) {
		k += i;
		i += 2;
	}
	printf("Sum is: %d", k);
	return 0;
}
