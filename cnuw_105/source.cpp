#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define num 2
typedef struct label {
	int id;
	int score;
} label;
typedef struct node {
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

node* mergeNode(node* a, node* b) {
	node* head;
	node* outb;
	head = outb = (node*)allocate(sizeof(node));
	head->next = NULL;
	outb = head;
	while (a && b) {
		if (a->content.id > b->content.id) {
			outb->next = b;
			outb = b;
			b = b->next;
		}
		else {
			outb->next = a;
			outb = a;
			a = a->next;
		}
	}
	if (a)
		outb->next = a;
	else
		outb->next = b;
	return head;
}

int main() {
	int id, score;
	node* a[num];
	node* aa[num];
	node* head[num];
	for (int i = 0; i < num; i++) {
		head[i] = aa[i] = a[i] = (node*)allocate(sizeof(node));
		while (true) {
			scanf("%d%d", &id, &score);
			if (id == 0)
				break;
			aa[i] = a[i];
			a[i]->content.id = id;
			a[i]->content.score = score;
			a[i] = (node*)allocate(sizeof(node));
			aa[i]->next = a[i];
		}
		aa[i]->next = NULL;
		a[i] = head[i];
	}
	node* out = NULL;
	out = mergeNode(a[0], a[1]);
	out = out->next;
	while (out) {
		printf("%d %d\n", out->content.id, out->content.score);
		out = out->next;
	}
	gc();
	return 0;
}
