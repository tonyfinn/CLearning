#include <stdio.h>

int main(int argc, char** argv) {
	int temp;
	int a = 1;
	int b = 2;

	int total = 0;

	while(a <= 4000000) {
		if(a % 2 == 0) {
			total += a;
			printf("Added %d\n", a);
		} else {
			printf("Ignored %d\n", a);
		}
		temp = b;
		b += a;
		a = temp;
	}

	printf("%d\n", total);
	
	return 0;
}
