// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2022/23)
// 
// (c) Lin Yuanbo Wu
//    l.y.wu@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include "constituency.h"

int main() {
	const int numConstituencies = 5;
	struct Constituency constituencies[numConstituencies];

	constructConstituency(
		&constituencies[0], "Swansea East",
		(unsigned int[]){1, 2, 3, 4}, 4);
	constructConstituency(
                &constituencies[1], "Swansea West",
                (unsigned int[]){0, 2}, 2);
	constructConstituency(
                &constituencies[2], "Gower",
                (unsigned int[]){0, 1, 3}, 3);
	constructConstituency(
                &constituencies[3], "Neath",
                (unsigned int[]){0, 2, 4}, 3);
	constructConstituency(
                &constituencies[4], "Aberavon",
                (unsigned int[]){0, 3}, 2);

	int maxNeighbours = 0;
	int maxNeighboursConstituency;

	int minNeighbours = INT_MAX;
	int minNeighboursConstituency;

  	for(int i = 0; i < numConstituencies; i++) {
		printConstituency(&constituencies[i]);
		printf("\n");
		if((&constituencies[i])->numNeighbours > maxNeighbours) {
			maxNeighbours = (&constituencies[i])->numNeighbours;
			maxNeighboursConstituency = i;
		}
		if((&constituencies[i])->numNeighbours < minNeighbours) {
                        minNeighbours = (&constituencies[i])->numNeighbours;
                        minNeighboursConstituency = i;
                }

	}

	printf("%s has the most bordering constituencies:\n",
		(&constituencies[maxNeighboursConstituency])->name);
	for(int i = 0; i < maxNeighbours; i++) {
		printf("  %s\n", (&constituencies[(&constituencies[maxNeighboursConstituency])->neighbours[i]])->name);
	}

	printf("%s has the least bordering constituencies:\n",
                (&constituencies[minNeighboursConstituency])->name);
        for(int i = 0; i < minNeighbours; i++) {
                printf("  %s\n", (&constituencies[(&constituencies[minNeighboursConstituency])->neighbours[i]])->name);
        }


	for(int i = 0; i < numConstituencies; i++) {
		destructConstituency(&constituencies[i]);
	}

  return 0;
}
