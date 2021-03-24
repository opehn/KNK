#include <stdlib.h>

struct node {
	int value;
	struct node* next;
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Error : malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}
	new_node->value = n;
	new_node->next = list;
	return new_node;
}

struct node *read_numbers(void)
{
	struct node *first = NULL;
	int n;
	printf("Enter a series of integers (0 to terminate) :");
	for(;;)
	{
		scanf("%d", &n);
		if (n == 0)
			return first;
		first = add_to _list(first, n);
	}
}
