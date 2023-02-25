#include "constituency.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void constructConstituency(struct Constituency * const obj,
			char const *constituencyName,
			unsigned int* const neighbours,
			unsigned int const numNeighbours)
{
	obj->name = NULL;
	obj->neighbours = NULL;
	obj->numNeighbours = 0;

	int nameLength = strlen(constituencyName) + 1;

	obj->name = malloc(sizeof(char) * nameLength);
	obj->numNeighbours = numNeighbours;

	memcpy(obj->name,
		constituencyName,
		nameLength * sizeof(char));

	if (numNeighbours > 0) {
		obj->neighbours = malloc(sizeof(int) * numNeighbours);
		memcpy(obj->neighbours, neighbours, numNeighbours * sizeof(int));
	} else {
		obj->neighbours = NULL;
	}
}

void destructConstituency(struct Constituency *obj) {
	if(obj->name != NULL) {
		free(obj->name);
		obj->name = NULL;
	}

	if(obj->neighbours != NULL) {
		free(obj->neighbours);
		obj->neighbours = NULL;
	}

	obj->numNeighbours = 0;
}

void printConstituency(const struct Constituency const *obj) {
	printf("%s | %d neighbours",
		obj->name,
		obj->numNeighbours);

	if(obj->numNeighbours > 0) {
		printf(" | [ ");
		for(int i = 0; i < obj->numNeighbours; i++) {
			printf("%d ", obj->neighbours[i]);
		}
		printf("]");
	}
}

struct Constituency *copyConstituencies(struct Constituency oldConstituencies[],
	const unsigned int numConstituencies) {
	struct Constituency *newConstituencies;
	newConstituencies = malloc(sizeof(struct Constituency) * numConstituencies);
	for(int i = 0; i < numConstituencies; i++) {
		int nameLength = strlen(oldConstituencies[i].name) + 1;
		newConstituencies[i].name = malloc(sizeof(char) * nameLength);
		memcpy(newConstituencies[i].name, oldConstituencies[i].name, nameLength * sizeof(char));

		newConstituencies[i].numNeighbours = oldConstituencies[i].numNeighbours;

		newConstituencies[i].neighbours = malloc(sizeof(int) * oldConstituencies[i].numNeighbours);
		memcpy(newConstituencies[i].neighbours,
			oldConstituencies[i].neighbours,
			oldConstituencies[i].numNeighbours * sizeof(int));
	}
	return newConstituencies;
}



