#include "sort.h"

/**
 * swap_ints - This swaps two integers in an array.
 * @a: This is the first integer to swap.
 * @b: This is the second integer to swap.
 *
 * Description: This swaps the values of the two
 * integers pointed to by @a and @b.
 */
void swap_ints(int *a, int *b)
{
        /* This swaps the values of the two integers */
        int temp = *a;
        *a = *b;
        *b = temp;
}

/**
 * bubble_sort - This sorts an array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: This is the size of the array.
 *
 * Description: This sorts the array of integers in ascending order
 * using the bubble sort algorithm.
 */
void bubble_sort(int *array, size_t size)
{
        size_t fig, lenght = size;
        bool bubble = false;

        if (array == NULL || size < 2)
                return;

        while (bubble == false)
        {
                bubble = true;
		for (fig = 0; fig < lenght - 1; fig++)
                {
                        if (array[fig] > array[fig + 1])
                        {
                                swap_ints(array + fig, array + fig + 1);
                                print_array(array, size);
                                bubble = false;
                        }
                }
                lenght--;
        }
}
