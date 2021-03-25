#include <stdlib.h>

struct node *delete_from_list(struct node *list, int n)
{
	struct node *cru, *prev;
	for (cur = list, prev = NULL; cur != NULL && cur -> value != n; prev = cur, cur = cur->next);
	if(cur == NULL)
		return list;
	if(prev == NULL)
		list = list->next;
	else
		prev->next = cur->next;
	free(cur);
	return list;
}
