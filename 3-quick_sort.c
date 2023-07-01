#include "sort.h"

void _qsort(int *a, int low, int high, int size);

/**
 * quick_sort - This sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: The size of the array.
 *
 * Description: This prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        _qsort(array, 0, size - 1, size);
}

/**
 * _qsort - This sorts a subset of an array of integers in ascending order
 *          using the quicksort algorithm.
 * @a: This is the array of integers.
 * @low: This is the starting index of the subset to sort.
 * @high: This is the ending index of the subset to sort.
 * @size: The size of the array.
 *
 * Description: This prints the array after each swap of two elements.
 */
void _qsort(int *a, int low, int high, int size)
{
        int H, L, fig, temp;

        if (low < high)
        {
                H = high;
		L = low;
                for (fig = low; fig < high; fig++)
                {
                        if (a[fig] < a[H])
                        {
                                if (fig != L)
                                {
                                        temp = a[fig];
                                        a[fig] = a[L];
                                        a[L] = temp;
                                        print_array(a, size);
                                }
                        L++;
                        }
                }
                if (L != H && a[L] != a[H])
                {
                        temp = a[L];
                        a[L] = a[H];
                        a[H] = temp;
                        print_array(a, size);
                }
                _qsort(a, low, L - 1, size);
                _qsort(a, L + 1, high, size);
        }
}
