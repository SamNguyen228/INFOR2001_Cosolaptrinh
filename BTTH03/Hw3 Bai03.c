#include<stdio.h>
#include<math.h>

int main() 
{
	int a = 2;
	int b = 1;
	
	while ( a <= 9) {
		printf("Multiplication Table %d: \n\n", a);
		while (b <= 10) {
			printf("%d x %d = %d\n", a, b, a * b);
			b++;
		}
		printf("\n\n");
		a++;
		b = 1; 
	}
	return 0;
}