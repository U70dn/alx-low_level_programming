#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of  listint_t list.
 * @h: header of the list_t list
 *
 * Return: the number of nodes in the list_t list.
 */

size_t print_listint(const listint_t *h)

{

	size_t count= 0 ;

	while (h != NULL; count++)
	{
		printf("%d\n", (*h).n);
		h = (*h).next;
	}
	return (count);
}
