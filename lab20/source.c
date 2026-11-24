#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>

float task1(void);
int task2(void);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int user_choise;

	printf("Выберите задание: ");
	scanf("%d", &user_choise);
	printf("\n");

	switch (user_choise) {
	case 1: printf("%f", task1()); break;
	case 2: task2(); break;
	default: printf("Такого задания нет\n"); break;
	}

	return 0;
}

float task1(void) {

	FILE* ptr_temp;

	char fname[20] = "temp.txt";

	float sum = 0;
	float a;
	int n = 0;

	if ((ptr_temp = fopen(fname, "rt")) == NULL) { printf("Ошибка открытия файла"); return -1; };

	while (fscanf(ptr_temp, "%f", &a) != EOF) {

		sum += a;
		n++;
	}

	fclose(ptr_temp);

	return sum / n;
}

int task2(void) {

	FILE* inp;
	FILE* out;

	char fname_inp[40];
	char fname_inp_without_extension[40];
	const char operation_name[] = "_arithmetic_mean_two_numbers.txt";
	char fname_out[80];

	float first, second;

	printf("Введите название файла: "); //rational_numbers.txt
	scanf("%s", fname_inp);
	printf("\n");

	if ((inp = fopen(fname_inp, "rt")) == NULL) { printf("Ошибка открытия файла"); return -1; }

	for (int i = 0; *(fname_inp + i) != '\0'; i++) {
		
		if (*(fname_inp + i) == '.') { *(fname_inp_without_extension + i) = '\0'; break; }

		*(fname_inp_without_extension + i) = *(fname_inp + i);
	}


	strcpy(fname_out, fname_inp_without_extension);
	strcat(fname_out, operation_name);

	if ((out = fopen(fname_out, "wt")) == NULL) { printf("Ошибка открытия файла"); return -1; }

	while (fscanf(inp, "%f", &first) != EOF) {

		fscanf(inp, "%f", &second);
		fprintf(out, "%f\n", (first + second) / 2);
	}

	fclose(inp);
	fclose(out);

	return 0;
}