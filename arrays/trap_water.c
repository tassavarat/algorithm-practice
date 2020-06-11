#include <stdio.h>

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
		if (height[l] < height[r]) {
			if (height[l] < lmax)
				water += lmax - height[l];
			else
				lmax = height[l];
			++l;
		}
		else {
			if (height[r] < rmax)
				water += rmax - height[r];
			else
				rmax = height[r];
			--r;
		}
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
