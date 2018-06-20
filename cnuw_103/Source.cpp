#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct label {
	int a;
	int x;
} label;

typedef struct list {
	list* next;
	label data;
} list;

void* memmap[64] = { NULL };
void** pmap = memmap;
void* allocate(unsigned size) {
	return *(pmap++) = malloc(size);
}

void gc() {
	while (*--pmap) {
		free(*pmap);
		*pmap = NULL;
	}
}

int abs(int x) {
	return x < 0 ? -x : x;
}

list* lnklist_add(list*& l, label* data) {
	if (!l)
		l = (list*)allocate(sizeof(list));
	l->data = *data;
	l->next = NULL;
	return l;
}

list* lnklist_create() {
	list* ret = (list*)allocate(sizeof(list));
	ret->next = NULL;
	return ret;
}

void lnklist_foreach(list* l, void(*processor)(list*)) {
	while (l != NULL) {
		processor(l);
		l = l->next;
	}
}

void figure(list* node) {
	// ��Ҫ�����θ���һ���ӣ���Ŷ�ʲô�������
	// ���������ô�ã���ô���ܻ����𰸵�
	// ��һ��������moodle�����������
	// ϣ�����������ε����һ���ύ
	// �ύ֮��������Ҫ����5��Accepted
	// �����㲻��Accept����ҲҪ�˷�һ��
	// ��֮���û�У������α�Ȼ�ᴷ�������ĸ�λ
	// P.S. �������������г�ʱ�������ν������ϱ��йز���
	// �������������ȡ��
	static bool first = true;
	static bool valid = false;
	if (node->data.a != 0) {
		valid = true;
		if (node->data.a < 0) {
			if (node->data.a == -1)
				putchar('-');
			else
				printf("%d", node->data.a);
		}
		else {
			if (!first)
				putchar('+');
			if (node->data.a != 1) {
				printf("%d", node->data.a);
			}
		}
		if (node->data.x != 0) {
			putchar('x');
			if (node->data.x != 1)
				printf("^%d", node->data.x);
		}
		else if (node->data.a == 1)
			putchar('1');
	}
	else if (node->next == NULL && valid == false)
		putchar('0');
	if(node->data.a != 0)
		first = false;
}

int main() {
	list* head = lnklist_create();
	list* _head = head;
	label data;
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		scanf("%d%d", &data.a, &data.x);
		if (i == 0)
			lnklist_add(head, &data);
		else {
			lnklist_add(head->next, &data);
			head = head->next;
		}
	}
	lnklist_foreach(_head, figure);
	gc();
	return 0;
}
