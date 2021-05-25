#include "../leetcode.h"

int romanToInt(char *s)
{
	int roman_val['X' + 1];
		roman_val['I'] = 1;
		roman_val['V'] = 5;
		roman_val['X'] = 10;
		roman_val['L'] = 50;
		roman_val['C'] = 100;
		roman_val['D'] = 500;
		roman_val['M'] = 1000;
	int i = 0, sum = 0, cur, next;

	while (s[i] != '\0') {
		cur = roman_val[s[i]];
		next = roman_val[s[i + 1]];
		if (s[i + 1] != '\0' && next > cur) {
			sum += next - cur;
			i += 2;
		} else {
			sum += cur;
			++i;
		}
	}
	return sum;
}

int main()
{
	char *s[] = {"XIV", "III", "IV", "IX", "LVIII", "MCMXCIV"};
	size_t i;

	for (i = 0; i < sizeof(s) / sizeof(*s); ++i)
		printf("%s = %i\n", s[i], romanToInt(s[i]));
	return 0;
}
