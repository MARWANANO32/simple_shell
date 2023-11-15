#include "shell.h"

/**
 * added_node - the function for add the node to list
 * @header: the address of pointer for the head node
 * @str: the string field of node
 * @n: the node
 * Return: the size of the list
 */

OPPS_t *added_node(OPPS_t **header, const char *str, int n)
{
	OPPS_t *newest;

	((!header) ? (return NULL, 0) : (0));

	newest = malloc(sizeof(OPPS_t));
	((!newest) ? (return NULL, 0) : (0));

	s_memset((void *)newest, 0, sizeof(OPPS_t));
	newest->n = n;

	if (str)
	{
		newest->str = _strdup(str);
		((!newest->str) ? (free(newest), return NULL, 0) : (0));
	}
	newest->next = *header;
	*header = newest;
	return (newest);

}

/**
 * added_end_node - this function for add a node to end
 * @header: the address of pointer for the end node
 * @str: the string field
 * @n: the node
 * Return: return size of the list
 */

OPPS_t *added_end_node(OPPS_t **header, const char *str, int n)
{
	OPPS_t *newest_node;
	OPPS_t node;

	((!header) ? (return NULL, 0) : (0));

	node = *header;
	newest_node = malloc(sizeof(OPPS_t));

	((!newest_node) ? (return NULL, 0) : (0));

	s_memset((void *)newest_node, 0, sizeof(OPPS_t));
	newest_node->n = n;

	if (str)
	{
		newest_node->str = _strdup(str);
		((!newest_node->str) ? (free(newest_node), return NULL, 0) : (0));
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = newest_node;
	}
	else
	{
		*header = newest_node;
	}
	return (newest_node);

}

/**
 * prints_list - the function for prints only string element
 * @a: the pointer to first node
 * Return: the size of list
 */
size_t prints_list(const OPPS_t *a)
{
	size_t b = 0;

	while (a)
	{
		_puts((a->str) ? (a->str) : "(nil)");
		_puts("\n");
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * deleted_node - delete the node
 * @header: the address of pointer to the node
 * @end: the index node for deleted
 * Return: if true return 1, otherwise return 0
 */
int deleted_node(OPPS_t **header, unsigned int end)
{
	OPPS_t *node;
	OPPS_t *p_node;
	unsigned int a = 0;

	if (!header || !*header)
	{
		return (0);
	}
	if (!end)
	{
		node = *header;
		*header = (*header)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *header;

	while (node)
	{
		if (a == end)
		{
			p_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		a++;
		p_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_lists - the function for free all nodes
 * @header_str: address of pointer
 *
 * Return: void
 */
void free_lists(OPPS_t **header_str)
{
	OPPS_t *node;
	OPPS_t s_node;
	OPPS_t header;

	if (!header_str || !*header_str)
	{
		return;
	}
	header = *header_str;
	node = header;

	while (node)
	{
		s_node = node->next;
		free(node->str);
		free(node);
		node = s_node;
	}
	*header_str = NULL;
}
