#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define courses 3 // 科目数
#define num 10 // 总人数


typedef struct person {
	char name[64];
	char gender;
	int scores[courses];
} person;

person persons[num];
person boy_best[courses], girl_best[courses];
int score_boy, score_girl;
int boy_faild, girl_faild;
int boy_num, girl_num;


int max(int a, int b, int c) {
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}


bool equals(float a, float b) {
	float abs_ = a < b ? b - a : a - b;
	return abs_ < 1e-5;
}


void answer() {
	score_boy = score_girl = 0;
	boy_faild = girl_faild = 0;
	boy_num = girl_num = 0;
	int gbest = 0, bbest = 0;

	// 输入数据的时候，顺便评选出男女各科单科最高、不及格数、人数
	for (int i = 0; i < num; i++) {
		scanf("%s%*c%c", persons[i].name, &persons[i].gender);
		if (persons[i].gender == 'f')
			girl_num++;
		else
			boy_num++;
		for (int j = 0; j < courses; j++) {
			scanf("%d", &persons[i].scores[j]);
			person* best;
			if (persons[i].gender == 'f') {
				// 妹子
				best = girl_best;
				if (persons[i].scores[j] < 60)
					girl_faild++;
				if (persons[i].scores[j] > gbest)
					gbest = persons[i].scores[j];
			}
			else { // 汉子
				best = boy_best;
				if (persons[i].scores[j] < 60)
					boy_faild++;
				if (persons[i].scores[j] > bbest)
					bbest = persons[i].scores[j];
			}
			if (persons[i].scores[j] > best[j].scores[j]) { // 第 j 门课
				best[j] = persons[i];
			}
		}
	}

	// 第一环节
	if (gbest > bbest)
		score_girl++;
	else if (gbest < bbest)
		score_boy++;
	else {
		score_girl++;
		score_boy++;
	}

	// 第二环节
	double faild_per_boy = (double)boy_faild / boy_num;
	double faild_per_girl = (double)girl_faild / girl_num;
	if (faild_per_girl < faild_per_boy)
		score_girl++;
	else if (faild_per_boy < faild_per_girl)
		score_boy++;
	else {
		score_girl++;
		score_boy++;
	}

	if (score_girl > score_boy)
		printf("girls won");
	else if (score_girl == score_boy)
		printf("both won");
	else
		printf("boys won");
}


int main() {
	answer();
	return 0;
}