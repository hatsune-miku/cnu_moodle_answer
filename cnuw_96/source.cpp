#define _CRT_SECURE_NO_WARNINGS
#define height 5
#define width 5
#include <stdio.h>
struct point {
	int index;
	int value;
};
point arr[height*width];
int arrr[height*width];
void swap(point* a, point* b) {
	point t = *a;
	*a = *b;
	*b = t;
}
void swapr(int* a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void bubblesort(point* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j].value > arr[j + 1].value)
				swap(&arr[j], &arr[j + 1]);
}
point getpoint(int index) {
	point p;
	p.index = index;
	p.value = arr[index].value;
	return p;
}
int main() {
	for (int i = 0; i < height*width; i++) {
		int n;
		scanf("%d", &n);
		arr[i].value = n;
		arr[i].index = i;
		arrr[i] = n;
	}
	bubblesort(arr, height*width);
	swapr(&arrr[arr[0].index], &arrr[getpoint(0).index]);
	if (arr[1].index == getpoint(0).index)
		arr[1].index = arr[0].index;
	swapr(&arrr[arr[1].index], &arrr[getpoint(4).index]);
	if (arr[2].index == getpoint(4).index)
		arr[2].index = arr[1].index;
	swapr(&arrr[arr[2].index], &arrr[getpoint(20).index]);
	if (arr[3].index == getpoint(20).index)
		arr[3].index = arr[2].index;
	swapr(&arrr[arr[3].index], &arrr[getpoint(24).index]);
	if (arr[height*width-1].index == getpoint(24).index)
		arr[height*width].index = arr[3].index;
	swapr(&arrr[arr[height*width-1].index], &arrr[getpoint(12).index]);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%3d", arrr[i*height + j]);
		}
		putchar('\n');
	}
	return 0;
}
