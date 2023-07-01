#include "sort.h"
/**
 * radix_sort - This sorts arrays of integers in ascending order
 * @array: the input array
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
        int flag = 1, n = 10;
        size_t fig, num;

        if (!array || size == 1)
                return;
        while (flag)
        {
                flag = 0;
                for (fig = 1, num = 1; fig <  size; fig++, num++)
                {
                        if ((array[fig - 1] % (n * 10)) / ((n * 10) / 10) > 0)
                                flag = 1;
                        if (((array[fig - 1] % n) / (n / 10)) > ((array[fig] % n) / (n / 10)))
                        {
                                array[fig - 1] = array[fig - 1] + array[fig];
                                array[fig] = array[fig - 1] - array[fig];
                                array[fig - 1] = array[fig - 1] - array[fig];
                                if ((fig - 1) > 0)
                                        fig = fig - 2;
                        }
                }
                print_array(array, size);
                n = n * 10;
        }
}
