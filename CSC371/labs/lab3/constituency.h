#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

struct Constituency {
	char *name;
	unsigned int *neighbours;
	unsigned int numNeighbours;
};

void constructConstituency(struct Constituency *obj,
			char const *constituencyName,
			unsigned int* const neighbours,
			unsigned int const numNeighbours);

void destructConstituency(struct Constituency *constituency);

void printConstituency(const struct Constituency const *constituency);

struct Constituency *copyConstituencies(struct Constituency oldConstituencies[], const unsigned int numConstituencies);

#endif
