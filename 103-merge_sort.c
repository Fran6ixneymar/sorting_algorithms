#include "sort.h"
#include <stdio.h>

void print_data(char *msg, int *a, int from, int to);
void merge(int *a, int low, int middle, int high, int *buff);
void msort(int *array, int low, int high, int *buffer);

/**
 * print_data - This prints data
 * @msg: The message
 * @a: array
 * @from: from
 * @to: to
 * Return: Don't return
 */

void print_data(char *msg, int *a, int from, int to)
{
        char *abc;
        int fig;

        printf("[%s]: ", msg);
        abc = "";

        for (fig = from; fig <= to; fig++)
        {
                printf("%s%d", abc, a[fig]);
                abc = ", ";
        }
        printf("\n");
}

/**
 * merge - The Aux function for Merge sort algorithm
 * @a: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 * Return: Don't return
 */

void merge(int *a, int low, int middle, int high, int *buff)
{
        int mid, lm, fig;

        mid = fig = low;
        lm = middle + 1;

        printf("Merging...\n");
        print_data("left", a, low, middle);
        print_data("right", a, middle + 1, high);

        while (mid <= middle && lm <= high)
        {
                if (a[mid] < a[lm])
                        buff[fig++] = a[mid++];
                else
                        buff[fig++] = a[lm++];
        }

        while (mid <= middle)
                buff[fig++] = a[mid++];

        while (lm <= high)
                buff[fig++] = a[lm++];

        for (fig = low; fig <= high; fig++)
                a[fig] = buff[fig];

        print_data("Done", a, low, high);
}

/**
 * msort -The Aux function for Merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: Don't return
 */

void msort(int *array, int low, int high, int *buffer)
{
        int mid;

        if (low < high)
        {
                mid = (low + high - 1) / 2;
                msort(array, low, mid, buffer);
                msort(array, mid + 1, high, buffer);
                merge(array, low, mid, high, buffer);
        }
}

/**
 * merge_sort -This sorts an array of integers in ascending order
 * @array: The array
 * @size: size of array
 * Return: Don't return
 */

void merge_sort(int *array, size_t size)
{
        int *buffer;

        buffer = malloc(sizeof(int) * size);
        if (!buffer)
		return;
        msort(array, 0, size - 1, buffer);
        free(buffer);
}
