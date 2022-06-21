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

int	partition(int *nums, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = nums[end];
	i = start;
	j = start - 1;
	while (++j < end)
	{
		if (nums[j] <= pivot)
		{
			swap(&nums[j], &nums[i]);
			i++;
		}
	}
	swap(&nums[i], &nums[end]);
	return (i);
}

void	quick_sort(int *nums, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(nums, start, end);
	quick_sort(nums, start, pivot - 1);
	quick_sort(nums, pivot + 1, end);
}

int largestPerimeter(int* nums, int numsSize)
{
	quick_sort(nums, 0, numsSize - 1);
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
