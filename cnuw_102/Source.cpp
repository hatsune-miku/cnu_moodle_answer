#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define size 10
#define course 3
void* garbage[1024] = { NULL };
void** pg = garbage;

typedef struct label {
	int id;
	char name[16];
	int score[course];
} label;

typedef struct list {
	list* next;
	label data;
} list;

list* newlist() {
	list* ret = (list*)(*pg++ = malloc(sizeof(list)));
	ret->next = NULL;
	return ret;
}

void gc() {
	while (*--pg)
		free(*pg);
}

double sum(label* l) {
	double ret = 0;
	for (int i = 0; i < course; i++)
		ret += l->score[i];
	return ret;
}

int main() {
	list* _head = newlist();
	list* node = _head;
	for (int i = 0; i < size; i++) {
		scanf("%d%s%*c", &node->data.id, node->data.name);
		for (int j = 0; j < course; j++)
			scanf("%d", node->data.score + j);
		node->next = newlist();
		node = node->next;
	}
	node = _head;
	label max = node->data;
	double max_sum = sum(&node->data);
	double all_sum = 0;
	while (node->next) {
		double s = sum(&node->data);
		all_sum += s;
		if (s > max_sum) {
			max_sum = s;
			max = node->data;
		}
		node = node->next;
	}
	printf("average score is %.2lf\n", all_sum / ((double)course * size));
	printf("the max score is:\n");
	printf("%5d%10s", max.id, max.name);
	for (int i = 0; i < course; i++)
		printf("%4d", max.score[i]);
	printf("\nthe max average is %.2lf\n", max_sum / (double)course);
	gc();
	return 0;
}
