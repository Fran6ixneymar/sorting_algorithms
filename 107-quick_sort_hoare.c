#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - This swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * hoare_partition - This orders a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: This uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
        int driver, top, bottom;

        driver = array[right];
        for (top = left - 1, bottom = right + 1; top < bottom;)
        {
                do {
                        top++;
                } while (array[top] < driver);
                do {
                        bottom--;
                } while (array[bottom] > driver);

                if (top < bottom)
                {
                        swap_ints(array + top, array + bottom);
                        print_array(array, size);
                }
        }

        return (top);
}

/**
 * hoare_sort - This implements the quicksort algorithm through recursion.
 * @array: This is an array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: This uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
        int belong;

        if (right - left > 0)
        {
                belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
                hoare_sort(array, size, belong, right);
        }
}

/**
 * quick_sort_hoare - This sorts an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: The size of the array.
 *
 * Description: This uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        hoare_sort(array, size, 0, size - 1);
}
