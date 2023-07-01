#include "sort.h"

/**
 * swap_ints - This swaps two integers in an array.
 * @a: This is the first integer to swap.
 * @b: This is the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

/**
 * selection_sort - This sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: This is an array of integers.
 * @size: The size of the array.
 *
 * Description: This prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
        size_t fig, num, min_idx;

        if (array == NULL || size < 2)
                return;

        for (fig = 0; fig < size - 1; fig++)
        {
                min_idx = fig;
                for (num = fig + 1; num < size; num++)
                {
                        if (array[num] < array[min_idx])
                                min_idx = num;
                }

                if (min_idx != fig)
                {
                        swap_ints(&array[fig], &array[min_idx]);
                        print_array(array, size);
                }
        }
}
