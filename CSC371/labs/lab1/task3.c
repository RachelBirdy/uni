#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(int argc, char *argv[]) {
	int input;
	if (argc > 1) input = atoi(argv[1]);
	else {
		printf("No number given\n");
		return 1;
	}
	int result = fibonacci(input);
	printf("Fibonacci of %d = %d\n", input, result);
	return 0;
}
