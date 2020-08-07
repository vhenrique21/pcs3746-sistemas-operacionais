#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct node
{ /*definindo a estrutura dos nós: Um array de valores e uma lista duplamente ligada */
	int *values;
	struct node *next;
	struct node *prev;
} node_t;

void push(node_t *head)
{ /*Funcao que adiciona um nó*/
	node_t *current = (node_t *)malloc(sizeof(node_t));

	int *matrix = calloc(sizeof(int), 1024);
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

void print_counter(int i, int push_counter)
{
	if (i % 1000 == 0 || i == (push_counter))
		{
			printf("\r Push Counter: %d", i);
			fflush(stdout);
		}
}

int main(int argc, char *argv[])
{
	int pid = getpid();
	printf("[PID: %d]\n\n", pid);

	if (argc <= 2)
	{
		printf("Missing arguments");
		return -1;
	}

	int push_counter = atoi(argv[1]);
	int debug_mode = atoi(argv[2]);

	node_t *head = (node_t *)malloc(sizeof(node_t));

	int i = 1;
	for (; i <= push_counter / 2; i++)
	{
		push(head);
		print_counter(i, push_counter);
	}

	if (debug_mode == 1)
		sleep(10);

	for (; i <= push_counter; i++)
	{
		push(head);
		print_counter(i, push_counter);		
	}
	printf("\n\nFim\n");

	if (debug_mode == 1)
		sleep(100);

	return 0;
}
