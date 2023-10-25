#include<stdio.h>
#include<math.h>

int main() 
{
	int N; 
	printf("Input value of N: ");
	scanf("%d", &N);
	if(N < 0){
		printf("INVALID Number");
		return 0;
	} 
	for(int i = 2; i <= sqrt((float)N); i++){
		if (N % i == 0){
			printf("N is not a prime number !");
			return 0;
		}
	}
	printf("N is a prime number !");
	return 0;
}