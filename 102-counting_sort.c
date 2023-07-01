#include "sort.h"
/**
 * counting_sort - This is used to sort an array of integers in ascending order
 * @array: array
 * @size: size
 * Return: Don't return
 */
void counting_sort(int *array, size_t size)
{
        int num;
        int fig;
        int *buff, *aux1;

        if (size < 2)
                return;
        for (num = fig = 0; fig < (int)size; fig++)
                if (array[fig] > n)
                        n = array[fig];
        buff = malloc(sizeof(int) * (n + 1));
        if (!buff)
                return;
        for (fig = 0; fig <= n; fig++)
                buff[fig] = 0;
        for (fig = 0; fig < (int)size; fig++)
                buff[array[fig]] += 1;
        for (fig = 1; fig <= n; fig++)
                buff[fig] += buff[fig - 1];
        print_array(buff, (n + 1));
        aux1 = malloc(sizeof(int) * (size + 1));
        if (!aux1)
        {
                free(buff);
                return;
        }
        for (fig = 0; fig < (int)size; fig++)
        {
                aux1[buff[array[fig]] - 1] = array[fig];
		buff[array[fig]] -= 1;
        }
        for (fig = 0; fig < (int)size; fig++)
                array[fig] = aux1[fig];
        free(buff);
        free(aux1);
}
