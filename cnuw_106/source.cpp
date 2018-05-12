#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define num 2
typedef struct label {
	int id;
	char name[64];
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

node* node_dec(node* a, node* b) {
	node *ret, *rr, *r, *bh;
	bh = b;
	ret = rr = r = (node*)allocate(sizeof(node));
	while (a) {
		bool contains = false;
		while (b) {
			if (b->content.id == a->content.id) {
				contains = true;
				break;
			}
			b = b->next;
		}
		b = bh;
		if (!contains) {
			rr = r;
			r->content = a->content;
			r = (node*)allocate(sizeof(node));
			rr->next = r;
		}
		a = a->next;
	}
	rr->next = NULL;
	r = ret;
	return ret;
}

int main() {
	node* head[2];
	node* b[2];
	node* bb[2];
	for(int i = 0; i < 2; i++) {
		int id;
		head[i] = b[i] = bb[i] = (node*)allocate(sizeof(node));
		while (true) {
			bb[i] = b[i];
			scanf("%d%s", &id, b[i]->content.name);
			if (id == 0)
				break;
			b[i]->content.id = id;
			b[i] = (node*)allocate(sizeof(node));
			bb[i]->next = b[i];
		}
		bb[i]->next = NULL;
		b[i] = head[i];
	}
	node* ans = node_dec(head[0], head[1]);
	while (ans) {
		printf("%d %s\n", ans->content.id, ans->content.name);
		ans = ans->next;
	}
	gc();
	return 0;
}
