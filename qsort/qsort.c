#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int unsorted[10] = {5, 23, 1, 200, 42, 7, 3, 64, 32000, 20000};
	int *sorted;
	int i;

	for(i = 0; i < 10; i++)
		printf("unsorted[%i] is %i\n", i, unsorted[i]);

	sorted = qsort2(unsorted, 10);

	for(i = 0; i < 10; i++)
		printf("sorted[%i] is %i\n", i, sorted[i]);

	return 0;
}

int *qsort2(int *unsorted, int array_size) {
	int split, i;
	int *lesser;
	int lesser_size;
	int *greater;
	int greater_size;
	int *sorted;

	if(array_size <= 1) {
		return unsorted;
	}
	split = array_size / 2;

	lesser = malloc(array_size * sizeof(int));
	lesser_size = 0;
	greater = malloc(array_size * sizeof(int));
	greater_size = 0;

	for(i = 0; i < array_size; i++) {
		if(unsorted[i] < unsorted[split]) {
			lesser[lesser_size] = unsorted[i];
			lesser_size++;
		} else if(unsorted[i] > unsorted[split]) {
			greater[greater_size] = unsorted[i];
			greater_size++;
		}
	}

	sorted = malloc(array_size * sizeof(int));
	sorted = qsort2(lesser, lesser_size);
	sorted[lesser_size] = unsorted[split];
	greater = qsort2(greater, greater_size);
	for(i = 0; i < greater_size; i++)
		sorted[lesser_size + 1 + i] = greater[i];

	return sorted;
}
