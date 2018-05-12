#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define new_node() (node*)allocate(sizeof(node))
typedef struct label {
	int id;
	char name[64];
	char sex;
	int age;
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

node* node_del(node* n, int age) {
	node* h = n;
	while (n) {
		if (n->content.age == age) {
			n->next->last = n->last;
			if (!n->last)
				h = n->next;
			else
				n->last->next = n->next;
		}
		n = n->next;
	}
	n = h;
	return h;
}

int main() {
	node *head, *b, *bb;
	head = b = bb = new_node();
	head->last = NULL;
	while (true) {
		bb = b;
		scanf("%d%s %c%d",
			&b->content.id,
			b->content.name,
			&b->content.sex,
			&b->content.age);
		if (b->content.id == 0)
			break;
		b = new_node();
		bb->next = b;
		b->last = bb;
	}
	b->next = NULL;
	b = head;
	int age;
	scanf("%d", &age);
	node* ans = node_del(head, age);
	while (ans && ans->content.id != 0) {
		printf("%d%10s%4d%2c\n",
			ans->content.id,
			ans->content.name,
			ans->content.age,
			ans->content.sex);
		ans = ans->next;
	}
	gc();
	return 0;
}
