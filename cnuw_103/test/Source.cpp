//
//  link_list_build_1.c
//  link_list_build_1
//
//  Created by LiYanxi on 15/6/23.
//  Copyright (c) 2015 LiYanxi. All rights reserved.
//
//  Mac OS x,Xcode 6.2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(muleqt)
typedef struct muleqt {
	int a, n;
	struct muleqt *next;
}muleqt;
//a1x^n1+a2x^n2...
muleqt *build(int n) {
	int i;
	muleqt *p1, *p2, *head;
	head = (muleqt*)malloc(LEN);
	p1 = p2 = head;
	for (i = 1; i<n; i++) {
		scanf("%d %d", &p1->a, &p1->n);
		p2 = (muleqt*)malloc(LEN);
		p1->next = p2;
		p1 = p2;
	}
	if (n != 0) scanf("%d %d", &p1->a, &p1->n);
	p1->next = NULL;
	return head;
}
void print(muleqt *head) {
	muleqt *p = head;
	for (; p->a == 0; p = p->next);
	if (p->a != 0 && p->n != 0) {
		if (p->a != 1)printf("%dx^%d", p->a, p->n);
		else printf("x^%d", p->n);
	}
	else if (p->n == 0) printf("%d", p->a);
	p = p->next;
	while (p != NULL) {
		if (p->a != 0) {
			if (p->a<0) printf("%dx", p->a);
			else if (p->a == 1) {
				if (p->n != 0) printf("+x");
				if (p->n == 0) printf("+1");
			}
			else if (p->a>1) printf("+%dx", p->a);
			if (p->n != 0 && p->n != 1) printf("^%d", p->n);
		}
		p = p->next;
	}
}
int main() {
	int n;
	muleqt *head;
	scanf("%d", &n);
	head = build(n);
	print(head);
	return 0;
}