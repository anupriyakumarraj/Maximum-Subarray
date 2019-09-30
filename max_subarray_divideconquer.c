#include "pch.h"
#include <limits.h>
#include <stdio.h>
// Utility function to find maximum of two numbers
int max(int x, int y) {
	return (x > y) ? x : y;
}

// Function to find maximum subarray sum using divide and conquer
int maximum_sum(int A[], int low, int high)
{
	// If array contains only one element
	if (high == low)
		return A[low];

	// Find middle element of the array
	int mid = (low + high) / 2;

	// Find maximum subarray sum for the left subarray
	// including the middle element
	int left_max = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_max)
			left_max = sum;
	}

	// Find maximum subarray sum for the right subarray
	// excluding the middle element
	int right_max = INT_MIN;
	sum = 0;	// reset sum to 0
	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_max)
			right_max = sum;
	}

	// Recursively find the maximum subarray sum for left subarray
	// and right subarray and take maximum
	int max_left_right = max(maximum_sum(A, low, mid),
		maximum_sum(A, mid + 1, high));

	// return maximum of the three
	return max(max_left_right, left_max + right_max);
}

// Maximum Sum Subarray using Divide & Conquer
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


	printf("The maximum sum of the subarray is %d",
		maximum_sum(arr, 0, d - 1));

	return 0;
}