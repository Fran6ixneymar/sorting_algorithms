#include "sort.h"

void sort_list(listint_t **list);
void dec_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void inc_sort(listint_t **ptr, listint_t **limit, listint_t **list);

/**
 * swap_list - This swaps the elements of the list
 *
 * @ptr1: The first pointer
 * @ptr2: The second pointer
 * @n: This is 0 for increase, and 1 for decrease
 * Return: Don't return
 */

void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
        listint_t *start, *temp;

        start = *ptr1;
        temp = *ptr2;

        start->next = temp->next;
        temp->prev = start->prev;

        if (temp->next)
                temp->next->prev = start;

        if (start->prev)
                start->prev->next = temp;

        start->prev = temp;
        temp->next = start;

        if (n == 0)
                *ptr1 = temp;
        else
	       	*ptr2 = start;
}

/**
 * inc_sort - This moves bigger numbers to the end
 *
 * @ptr: Pointer that points to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: Don't return
 */

void inc_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
        listint_t *start;

        start = *ptr;

        while (start != *limit && start->next != *limit)
        {
                if (start->n > start->next->n)
                {
                        swap_list(&start, &(start->next), 0);
                        if (start->prev == NULL)
                                *list = start;
                        print_list(*list);
                }
                start = start->next;
        }

        *limit = new;
        *ptr = new;
}

/**
 * dec_sort - moves smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */

void dec_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
        listint_t *new;

        new = *ptr;

        while (new != *limit && new->prev != *limit)
        {
                if (new->n < new->prev->n)
                {
                        swap_list(&(new->prev), &new, 1);
                        if (new->prev->prev == NULL)
                                *list = new->prev;
                        print_list(*list);
                }
                new = new->prev;
        }

        *limit = new;
        *ptr = new;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order
 *
 * @list: head of the linked list
 * Return: no return
 */

void cocktail_sort_list(listint_t **list)
{
        listint_t *limit, *limit_1, *ptr;

        if (list == NULL)
                return;

        if (*list == NULL)
                return;

        limit = limit_1 = NULL;
        ptr = *list;

        do {
                inc_sort(&ptr, &limit, list);
                dec_sort(&ptr, &limit_1, list);
        } while (limit != limit_1);
}
