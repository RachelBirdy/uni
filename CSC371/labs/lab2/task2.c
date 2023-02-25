// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// 
// (c) Martin Porcheron
//     m.a.w.porcheron@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "timestables.h"

int main(int argc , char *argv[]) {
	int *tables[MAX_TIMES_TABLE + 1];

	int i;
	for (i = 0; i <= MAX_TIMES_TABLE; i++) {
		tables[i] = (int*) malloc(sizeof(int*) * MAX_TABLE_SIZE);
		generateTable(i, tables[i]);
	}

	printTables(tables);

	for (i = 0; i <= MAX_TIMES_TABLE; i++) {
		free(tables[i]);
		tables[i] = NULL;
	}
	return 0;
}
