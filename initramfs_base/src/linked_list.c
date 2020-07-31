#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{ /*definindo a estrutura dos nós: Um array de valores e uma lista duplamente ligada */
	int *values;
	struct node *next;
	struct node *prev;
} node_t;

void push(node_t *head)
{ /*Funcao que adiciona um nó*/
	node_t *current = (node_t *)malloc(sizeof(node_t));

	int *matrix = calloc(sizeof(int), 4096);
	current->values = matrix;

	node_t *temp;

	if (head->next == NULL)
		temp = head;
	else
		temp = head->prev;

	head->prev = current;
	temp->next = current;

	current->prev = temp;
	current->next = head;
	current->values = matrix;

	return;
}

int main()
{
	node_t *head = (node_t *)malloc(sizeof(node_t));

	for (int i = 0; i < 20000; i++)
		push(head);

	printf(".");
	sleep(10000);

	return 0;
}
