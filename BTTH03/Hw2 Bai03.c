#include<stdio.h>

 int main() {
 	float a; 
 	printf("Input value of a: ");
 	scanf("%f", &a);
 	
 	if(a >= 9 && a < 10){
 		printf("Excellent Student");
	 } else if(a >= 8 && a < 9){
	 	printf(" Very Good Student");
	 } else if(a >= 6.5 && a < 8){
	 	printf("Good Student");
	 } else if(a >= 5 && a < 6.5){
	 	printf("Average Student");
	 } else if(a < 5){
	 	printf("Week Student");
	 } else {
	 	printf("INVALID");
	 }
	 
	 return 0;
}
