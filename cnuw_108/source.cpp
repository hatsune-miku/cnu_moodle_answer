#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct label {
	int id;
	char name[64];
} label;
typedef struct node {
	node* last;
	label content;
} node;

void* garbage[1024];
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

int main() {
	int n;
	node* b;
	node* bb;
	b = bb = (node*)allocate(sizeof(node));
	bb->last = NULL;

	scanf("%d", &n);
	while (n--) {
		b = (node*)allocate(sizeof(node));
		scanf("%d%s", &b->content.id, b->content.name);
		b->last = bb;
		bb = b;
	}
	while (b->last) {
		printf("%d%10s\n", b->content.id, b->content.name);
		b = b->last;
	}
	gc();
	return 0;
}
