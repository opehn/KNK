#include <stdio.h>
#include <stdlib.h>
#include "part.h"
#include "readline.h"
#define NAME_LEN 25

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(voide)
{
	char code;
	for(;;){
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n')
			;

		switch (code)
		{
			case 'i' : insert();
				   break;
			case 's' : insert();
				   break;
			case 'u' : insert();
				   break;
			case 'p' : insert();
				   break;
			case 'q' : return 0;
			default : printf("Illegal code\n");
		}
		printf("\n");
	}
}

struct part *find_part(int number)
{
	struct part *p;
	for(p = inventory; p != NULL && p->number < number; p = p->next;){

	if(p != NULL && number == p -> number)
		return p;
	}
	return NULL; 
}

void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if(new_node == NULL)
		return;
	printf("Enter part number :\n");
	scanf("%d", &new_node->number);
	
	for(cur = inventory, prev = NULL; cur != NULL && number > cur->number; prev = cur, cur = cur->next);
	if (cur != NULL && new_node->number == cur->number)
	{
		printf("Part already exists.\n");
		free(new_node);
		return;
	}
	printf("Enter part name; ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if(p != NULL)
	{
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int number, change;
	struct part *p;
	printf("Enter part number: \n");
	scanf("%d", &number);
	if(p != NULL)
	{
		printf("Enter change in quantity on hand: ");
		scnaf(&d, &change);
		p->on_hane += change;
	}
	else
		printf("Part not foune.\m");
}

void print(void)
{
	struct part *p;
	printf("Part number Part Name			"
		"Quantity on Hand\n");
	for(p = inventory; p != NULL; p = p->next)
		printf("%7d	%-25s%lld\n", p->number, p->name, p->on_hand);
}

