#define _CRT_SECURE_NO_WARNINGS
#define size 10
#include <stdio.h>
void er_ying_zhang_de_yi_da_li_pao(int* a, int* b) {
	if (a == b) return;
	int t = *a;
	*a = *b;
	*b = t;
}
void input_now_now_now_now_rightnow(int* wherewherewhere, int howmanyhowmanyhowmany) {
	while (howmanyhowmanyhowmany--)
		scanf("%d", wherewherewhere++);
}
void shi_shi_hou_zhan_xian_zhen_zheng_de_ji_shu_le(int* whowhowho, int howmanyhowmanyhowmany) {
	for (int i = 0; i < howmanyhowmanyhowmany; i++)
		printf("%3d", whowhowho[i]);
}
void gank_gank_gank_gank_ganboom(int* gankwho, int howmanyhowmanyhowmany) {
	int min = 2147483647;
	int max = -min - 1;
	int min_index = 0;
	int max_index = 0;
	for (int i = 0; i < howmanyhowmanyhowmany; i++) {
		if (gankwho[i] > max) {
			max = gankwho[i];
			max_index = i;
		}
		if (gankwho[i] < min) {
			min = gankwho[i];
			min_index = i;
		}
	}
	er_ying_zhang_de_yi_da_li_pao(&gankwho[min_index], &gankwho[0]);
	if (max_index == 0)
		max_index = min_index;
	er_ying_zhang_de_yi_da_li_pao(&gankwho[max_index], &gankwho[howmanyhowmanyhowmany - 1]);
}
int main() {
	int arr[size];
	input_now_now_now_now_rightnow(arr, size);
	gank_gank_gank_gank_ganboom(arr, size);
	shi_shi_hou_zhan_xian_zhen_zheng_de_ji_shu_le(arr, size);
	return 0;
}
