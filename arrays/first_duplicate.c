/**
 * first_duplicate - Finds first duplicate value with smallest index in array
 * @a: Struct containing array and its size
 *
 * Return: Duplicate value or -1 if none found
 */
int first_duplicate(arr_integer a)
{
	int i, n;

	for (i = 0; i < a.size; ++i)
	{
		n = abs(a.arr[i]);
		if (a.arr[n - 1] < 0)
			return (n);
		a.arr[n - 1] = -a.arr[n - 1];
	}
	return (-1);
}
