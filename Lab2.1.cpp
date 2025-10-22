#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int mode1() {
	srand((unsigned)time(NULL));
	int x = 1 + rand() % 1001, s=-1;
	while (s != x) {
		printf("Введите число: ");
		scanf_s("%d", &s);
		if (s < x)
			printf("Загаданное число больше\n");
		else if (s > x)
			printf("Загаданное число меньше\n");
		else
			printf("Угадали");
	}
	return 0;
}

int mode2() {
	char h = '?';
	int a = 500, i = 2, k[2] = { 1, 1000 };
	printf("%d\n", a);
	scanf_s(" %c", &h, 1);
	while (h != '=') {
		if (h == '<') {
			k[1] = a;
			a = (k[0]+k[1])/2;
		}
		else if (h == '>') {
			k[0] = a;
			a = (k[0] + k[1]) / 2;
		}
		else {
			printf("Неправильный ввод, введите '<', '>', '='\n");
		}
		printf("%d\n", a);
		scanf_s(" %c", &h, 1);
	}
	return 0;
}

int main() {
	int m = 1;
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим:\n");
	scanf_s("%d", &m);
	if (m == 1)
		mode1();
	else if (m == 2)
		mode2();
	else
		printf("Неправильный ввод, введите число 1 или 2");
}