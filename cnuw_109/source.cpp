#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define new_node() (node*)allocate(sizeof(node))
typedef struct label {
	int id;
} label;
typedef struct node {
	node* last;
	node* next;
	label content;
} node;

void* garbage[2048];
void** pg = garbage;
void* allocate(size_t size) {
	void* ptr = malloc(size);
	return (*pg++ = ptr);
}
void gc() {
	while (*--pg) {
		free(*pg);
		*(pg) = NULL;
	}
}

void printnode(node* n, int limit) {
	node* b = n;
	while (limit--) {
		printf("%d ", b->content.id);
		b = b->next;
	}
	putchar('\n');
}

node* node_del_process(node* n, int kill) {
	node* h = n;
	int id = 1;
	while (n != n->next) {
		if (kill == id) {
			n->next->last = n->last;
			n->last->next = n->next;
		}
		n = n->next;
		if (id++ == kill)
			id = 1;
	}
	return n;
}

int main() {
	node *head, *b, *bb;
	head = b = bb = new_node();
	head->last = NULL;
	int n, id = 1;
	scanf("%d", &n);
	while (n--) {
		bb = b;
		b->content.id = id++;
		b = new_node();
		bb->next = b;
		b->last = bb;
	}
	bb->next = head;
	head->last = bb;
	printf("%d", node_del_process(head, 3)->content.id);
	gc();
	return 0;
}
