#include <stdio.h>
#include <stdlib.h>

/**
 * original leetcode costs array is dynamically allocated
 */
int compare(const void *pa, const void *pb)
{
	/* const int *a = *(const int **) pa; */
	/* const int *b = *(const int **) pb; */
	const int *a = pa;
	const int *b = pb;

	return (a[0] - a[1])  - (b[0] - b[1]);
}

/**
 * twoCitySchedCost - find minimum cost to fly everyone to two cities
 * @costs: 2-D array containing cost to fly to city A and B
 * @costsSize: size of costs array
 * @costsColSize: size of columns of costs
 *
 * People must be evenly distributed between the two cities
 *
 * Return: minimum cost
 */
int twoCitySchedCost(int costs[6][2], int costsSize, int *costsColSize)
{
	int i, min_cost;

	qsort(costs, costsSize, *costsColSize * sizeof(**costs), compare);
	min_cost = 0;
	for (i = 0; i < costsSize / 2; ++i)
		min_cost += costs[i][0];
	while (i < costsSize)
		min_cost += costs[i++][1];
	return min_cost;
}

int main()
{
	int costs1[4][2] = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
	int costs2[4][2] = {{1, 2}, {2, 7}, {5, 9}, {4, 5}};
	int costs3[6][2] = {{259, 770}, {448, 54}, {926, 667}, {184, 139}, {840, 118}, {577, 469}};
	int costsColSize = sizeof(*costs1) / sizeof(**costs1);

	printf("Got: %i\tExpected: 110\n",
			twoCitySchedCost(costs1, sizeof(costs1) / sizeof(*costs1), &costsColSize));
	printf("Got: %i\t\tExpected: 14\n",
			twoCitySchedCost(costs2, sizeof(costs2) / sizeof(*costs2), &costsColSize));
	printf("Got: %i\tExpected 1859\n",
			twoCitySchedCost(costs3, sizeof(costs3) / sizeof(*costs3), &costsColSize));
	return 0;
}
