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

	struct Constituency *copy = copyConstituencies(constituencies,
		numConstituencies);
	for (int i = 0; i < numConstituencies; i++) {
		destructConstituency(&constituencies[i]);
	}

  	for(int i = 0; i < numConstituencies; i++) {
		printConstituency(&copy[i]);
		printf("\n");
		if((&copy[i])->numNeighbours > maxNeighbours) {
			maxNeighbours = (&copy[i])->numNeighbours;
			maxNeighboursConstituency = i;
		}
		if((&copy[i])->numNeighbours < minNeighbours) {
                        minNeighbours = (&copy[i])->numNeighbours;
                        minNeighboursConstituency = i;
                }

	}

	printf("%s has the most bordering constituencies:\n",
		(&copy[maxNeighboursConstituency])->name);
	for(int i = 0; i < maxNeighbours; i++) {
		printf("  %s\n", (&copy[(&copy[maxNeighboursConstituency])->neighbours[i]])->name);
	}

	printf("%s has the least bordering constituencies:\n",
                (&copy[minNeighboursConstituency])->name);
        for(int i = 0; i < minNeighbours; i++) {
                printf("  %s\n", (&copy[(&copy[minNeighboursConstituency])->neighbours[i]])->name);
        }


	for(int i = 0; i < numConstituencies; i++) {
		destructConstituency(&copy[i]);
	}

  return 0;
}
