#include "sort.h"
#include <stdio.h>

void sort_d(int *arr, int low, int high);
void sort_up(int *arr, int low, int high);
void print_bitonic(int *arr, int i, int limit);
void recursion(int *arr, int low, int high, int bool, size_t size);

/**
 * print_bitonic - This prints the array modified by bitonic algorithm
 * @arr: The input array
 * @i: The first index
 * @limit: The last index
 * Return: Don't return
 */

void print_bitonic(int *arr, int i, int limit)
{
        char *abc;

        for (abc = ""; i < limit; i++)
        {
                printf("%s%d", abc, arr[i]);
                abc = ", ";
        }
        printf("\n");
}

/**
 * sort_up - This sorts the array in UP mode
 *
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * Return: Don't return
 */

void sort_up(int *arr, int low, int high)
{
        int fig, num, max;

        for (fig = low; fig < high; fig++)
        {
                max = fig;

                for (num = fig + 1; num < high; num++)
                {
                        if (arr[max] > arr[num])
                                max = num;
                }

                if (max != fig)
                {
                        arr[fig] = arr[fig] + arr[max];
                        arr[max] = arr[fig] - arr[max];
                        arr[fig] = arr[fig] - arr[max];
                }
        }
}

/**
 * sort_dn - This sorts the array in DOWN mode
 *
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * Return: Don't return
 */
void sort_dn(int *arr, int low, int high)
{
        int fig, num, max;

        for (fig = low; fig < high; fig++)
        {
                max = fig;

                for (num = fig + 1; num < high; num++)
                {
                        if (arr[max] < arr[num])
                                max = num;
                }

                if (max != fig)
                {
                        arr[fig] = arr[fig] + arr[max];
                        arr[max] = arr[fig] - arr[max];
                        arr[fig] = arr[fig] - arr[max];
                }
        }
}

/**
 * recursion - This is the recursive function that executes the bitonic sort
 * algorithm
 * @arr: The input array
 * @low: The first index
 * @high: The last index
 * @bool: UP or DOWN
 * @size: The size of the array
 * Return: Don't return
 */

void recursion(int *arr, int low, int high, int bool, size_t size)
{
        char *opt;

        if (high - low < 2)
                return;

        opt = (bool == 0) ? "UP" : "DOWN";
        printf("Merging [%d/%ld] (%s):\n", high - low, size, opt);
        print_bitonic(arr, low, high);

        if (high - low == 2)
                return;

        recursion(arr, low, (high + low) / 2, 0, size);
        sort_up(arr, low, (high + low) / 2);
        printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
        print_bitonic(arr, low, (high + low) / 2);

        recursion(arr, (high + low) / 2, high, 1, size);
        sort_dn(arr, (high + low) / 2, high);
        printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
        print_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - This executes the bitonic_sort algorithm
 *
 * @array: The input array
 * @size: The size of the array
 * Return: Don't return
 */
void bitonic_sort(int *array, size_t size)
{
        if (!array || size < 2)
                return;

        recursion(array, 0, size, 0, size);
        sort_up(array, 0, size);
        printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
        print_bitonic(array, 0, size);
}
