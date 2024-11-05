/*
 * Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * n: the integer to convert.
 * Return: The string representing the integer;
 * NULL if the allocation fails.
 */

#include "libft.h"

static int	get_digit_count(int n)
{
    int	count;

	count = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        count++;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return (count);
}

char	*ft_itoa(int n)
{
	int	digit_count;
	int	sign;
	char	*str;

	sign = 1;
	digit_count = get_digit_count(n);
	str = (char *)malloc(digit_count + 1);
	if (!str)
		return NULL;
	str[digit_count] = '\0';
	if (n == -2147483648)
	{
		str[--digit_count] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (digit_count > 0)
	{
		digit_count--;
		str[digit_count] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
