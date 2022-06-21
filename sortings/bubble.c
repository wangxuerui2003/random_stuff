#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    swap(int *i, int *j)
{
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}

void	bubble_sort(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nums[i] > nums[i + 1])
		{
			swap(&nums[i], &nums[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int largestPerimeter(int* nums, int numsSize)
{
	bubble_sort(nums, numsSize - 1);
    for (int k = 0; k < numsSize; k++)
        printf("%d,", nums[k]);
	printf("\n");
	return (0);
}

int	main(int ac, char **av)
{
	printf("%lu\n", clock());
	int	i;

	i = -1;
	int	*arr = malloc((ac - 1) * sizeof(int));
	while (++i < ac - 1)
		arr[i] = atoi(av[i + 1]);
	largestPerimeter(arr, ac - 1);
	printf("%lu\n", clock());
}
