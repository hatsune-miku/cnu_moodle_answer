#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 10
#define buffer 1024
struct worker {
	char name[buffer];
	int id;
};
worker w[size];
void strcpy(char* dst, char* src) {
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}
void swap(worker* a, worker* b) {
	char c[buffer];
	strcpy(c, a->name);
	strcpy(a->name, b->name);
	strcpy(b->name, c);
	int id = a->id;
	a->id = b->id;
	b->id = id;
}
void bubblesort(worker* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j].id > arr[j + 1].id) {
				swap(&arr[j], &arr[j + 1]);
			}
}
void task1() {
	for (int i = 0; i < size; i++) {
		scanf("%s %d", w[i].name, &w[i].id);
	}
}

void task2() {
	bubblesort(w, size);
}

void printarr(worker* _w, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", _w[i].name, _w[i].id);
	}
}

int task3(worker* _w, int id, int l, int r) {
	int mid = (l + r) / 2;
	if (_w[mid].id == id)
		return mid;
	if (r - l == 1)
		return -1;
	if (_w[mid].id > id)
		return task3(_w, id, 0, mid);
	return task3(_w, id, mid, r);
}

int main() {
	task1();
	task2();
	int id;
	scanf("%d", &id);
	printarr(w, size);
	int index = task3(w, id, 0, size);
	if (index == -1)
		printf("NO");
	else
		printf("%s", w[index].name);
	return 0;
}
