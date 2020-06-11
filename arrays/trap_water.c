#include <stdio.h>

/**
 * calc_water - find trapped water at specified index and updates max height
 * @height: array of height values
 * @i: index for height
 * @max: pointer to left or right max height
 *
 * Return: trapped water
 */
int calc_water(int *height, int i, int *max)
{
	int water = 0;

	if (height[i] < *max)
		water = *max - height[i];
	else
		*max = height[i];
	return water;
}

/**
 * trap - compute how much water can be trapped
 * @height: array of height values
 * @heightSize: size of height array
 *
 * Return: amount of water able to be trapped
 */
int trap(int *height, int heightSize)
{
	int l, r, lmax, rmax, water;

	l = water = lmax = rmax = 0, r = heightSize - 1;

	while (l < r) {
		if (height[l] < height[r])
			water += calc_water(height, l++, &lmax);
		else
			water += calc_water(height, r--, &rmax);
	}
	return water;
}

int main()
{
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int *b = NULL;;

	printf("%i\n", trap(a, sizeof(a) / sizeof(*a)));
	printf("%i\n", trap(b, 0));
	return 0;
}
