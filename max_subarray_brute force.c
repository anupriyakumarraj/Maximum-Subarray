#include "pch.h"
#include <stdio.h>
#include <limits.h>

// brute force solution to find maximum sum subarray using

int maximum_sum(int A[], int n)
{
	int max_sum = INT_MIN;
	int sum = 0;

	// do for each subarray starting with i
	for (int i = 0; i < n - 1; i++)
	{
		// calculate sum of subarray A[i..j]

		sum = 0;	// reset sum

		// do for each subarray ending with j
		for (int j = i; j < n; j++)
		{
			sum += A[j];

			// if current subarray sum is greater than the maximum
			// sum calculated so far, update the maximum sum
			if (sum > max_sum)
				max_sum = sum;
		}
	}

	return max_sum;
}


int main(void)
{
	int arr[100], d, k;

	printf("Enter number of elements in the array:\n");
	scanf_s("%d", &d);

	printf("Enter %d integers\n", d);

	for (k = 0; k < d; k++)
	{
		scanf_s("%d", &arr[k]);
	}


	printf("The maximum sum of the subarray is %d", maximum_sum(arr, d));

	return 0;
}