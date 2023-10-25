#include<stdio.h>

int main()
{
	int n, dc, dl;
	printf("Input value of n: ");
	scanf("%d", &n);
	dc = dl = 0;
	
	while (n > 0) {
		int i = (n % 10);
		if (i % 2 == 0) {
			dc += i;
		} else {
			dl += i;
		}
		n /= 10;
	}
	printf("%d %d", dc, dl);
	return 0;
}