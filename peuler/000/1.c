#include <stdio.h>

int main(int argc, char** argv) {
	int total;
	int i;

	total = 0;

	for(i = 3; i <= 1000; i++) {
		if((i % 5 == 0) || (i % 3 == 0)) {
			total += i;
		}
	}
	printf("%d", total);
}
