#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	get_num_len(int num);

char	*itoa(int num)
{
	int		len;
	char	*res;

	len = get_num_len(num);
	if (num == 0)
		return ("0");
	res = malloc(len + 1);
	res[len] = 0;
	len--;
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		res[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (res);
}

int	get_num_len(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i += 1;
	while (num != 0 && ++i)
		num /= 10;
	return (i);
}

int	get_str_len(const int *args, size_t n)
{
	size_t	i;
	size_t	j;
	int		range;
	int		len;

	i = 0;
	j = 1;
	range = 1;
	len = 1;
	while (j < n || range != 1)
	{
		if (j != n - 1 && args[j] - args[i] == (int)(j - i))
			range++;
		else
		{
			if (range > 2)
			{
				len += get_num_len(args[i]) + 1 + get_num_len(args[j - 1]);
				if (j != n - 1)
					len += 1;
			}
			else
			{
				while (i < j)
				{
					len += get_num_len(args[i]);
					if (j != n - 1)
						len += 1;
					i++;
				}
			}
			range = 1;
			i = j;
		}
		j++;
	}
	return (len);
}

char	*range_extraction(const int *args, size_t n)
{
	char	*res;
	int		len;
	size_t		i;
	size_t		j;
	int		range;

	len = get_str_len(args, n);
	res = malloc(len * sizeof(char));
	res[len - 1] = 0;
	i = 0;
	j = 1;
	range = 1;
	while (j < n || range != 1)
	{
		if (j != n - 1 && args[j] - args[i] == (int)(j - i))
			range++;
		else
		{
			if (j == n - 1 && args[j] - args[i] == (int)(j - i))
				range++;
			if (range > 2)
			{
				res = strcat(res, itoa(args[i]));
				res = strcat(res, "-");
				if (j != n - 1)
					res = strcat(res, itoa(args[j - 1]));
				else
					res = strcat(res, itoa(args[j]));
				if (j != n - 1)
					res = strcat(res, ",");
			}
			else
			{
				while (i < j)
				{
					res = strcat(res, itoa(args[i]));
					if (i != n - 1)
						res = strcat(res, ",");
					i++;
				}
			}
			range = 1;
			i = j;
		}
		j++;
	}
	printf("strlen: %lu\n", strlen(res));
	return (res);
}

int	main(int ac, char **av)
{
	int	arr[ac - 1];
	int	i;

	i = 0;
	while (++i < ac)
		arr[i - 1] = atoi(av[i]);
	printf("%s\n", range_extraction(arr, (size_t)(ac - 1)));
	return (0);
}
