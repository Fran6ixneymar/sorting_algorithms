#include "sort.h"

void mysort(int *a, int size, int n);

/**
 * shell_sort - This is a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 *
 * @array: This is the array to be sorted
 * @size: The size of the array
 * Return: Don't return
 */

void shell_sort(int *array, size_t size)
{
        size_t focus = 1;

        while (focus < size)
                focus = (focus * 3) + 1;

        while ((focus = (focus - 1) / 3) > 0)
                mysort(array, size, focus);
}

/**
 * mysort - This is the auxi function for shell_sort function
 * @a: The input array
 * @size: The size of the array
 * @n: intervale
 * Return: Don't return
 */

void mysort(int *a, int size, int n)
{
        int temp, fig, num;

        for (num = 0; (num + n) < size; num++)
		{
                for (num = fig + n; (num - n) >= 0; num = num - n)
                {
                        if (a[num] < a[num - n])
                        {
                                temp = a[num];
                                a[num] = a[num - n];
                                a[num - n] = temp;
                        }
                }
        }
        print_array(a, size);
}
