#include <stdio.h>

int main() 
{
	int n, dc, dl;
	printf("Input value of n: ");
	scanf("%d", &n);
	dc = dl = 0;
	
	while (n > 0) {
		int i = (n % 10);
		if (i % 2 == 0) {
			dc += 1;
		} else {
			dl += 1;
		}
		n /= 10;
	}
	if (dc == dl) {
		printf("YES");
		return 0;
	}
	printf("NO");
	return 0;
}