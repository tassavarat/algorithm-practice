#include "../leetcode.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int *digits_plus = malloc((digitsSize + 1) * sizeof(*digits_plus));
	int i = digitsSize - 1;

	*digits_plus = 0;
	++digits[i];
	while (i > -1) {
		if (digits[i] == 10) {
			digits[i] = 0;
			if (i > 0)
				++digits[i - 1];
			else
				++digits_plus[i];
		}
		digits_plus[i + 1] = digits[i];
		--i;
	}
	if (*digits_plus != 0) {
		*returnSize = digitsSize + 1;
		return digits_plus;
	}
	else {
		*returnSize = digitsSize;
		return digits_plus + 1;
	}
}

void print_array(int *array, int size)
{
	int i;

	putchar('[');
	for (i = 0; i < size - 1; ++i)
		printf("%i, ", array[i]);
	printf("%i", array[i]);
	puts("]");
}

void print_free(int *array, size_t size)
{
	int return_size;
	int *digits_plus;

	print_array(array, size);
	digits_plus = plusOne(array, size, &return_size);
	print_array(digits_plus, return_size);
	if (return_size > size)
		free(digits_plus);
	else
		free(digits_plus - 1);
}

int main()
{
	int digits1[] = {1, 2, 3};
	int digits2[] = {4, 3, 2, 1};
	int digits3[] = {9};
	int digits4[] = {9, 9, 9};

	print_free(digits1, sizeof(digits1) / sizeof(*digits1));
	print_free(digits2, sizeof(digits2) / sizeof(*digits2));
	print_free(digits3, sizeof(digits3) / sizeof(*digits3));
	print_free(digits4, sizeof(digits4) / sizeof(*digits4));
	return 0;
}
