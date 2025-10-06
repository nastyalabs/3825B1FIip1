#include <stdio.h>
#include <math.h>
#include <locale.h>



void main() {
	setlocale(LC_ALL, "Russian");
	/*
	float a, b, c;
	scanf_s("%f %f %f", &a, &b, &c);
	if (a < 0 || b < 0 || c < 0) {
		printf("Треугольник не существует");
	}
	else {
		if (a + b < c || c + b < a || c + a < b) {
			printf("НЕ треугольник");
		}

		else {
			if ((a * a + b * b == c * c) || (c * c + b * b == a * a) || (a * a + c * c == b * b)) {
				printf("Прямоугольный треугольник");
			}
			else if ((a * a + b * b > c * c) || (c * c + b * b > a * a) || (a * a + c * c > b * b)) {
				printf("Остроугольный треугольник");
			}
			else if ((a * a + b * b < c * c) || (c * c + b * b < a * a) || (a * a + c * c < b * b)) {
				printf("Тупоугольный треугольник");
			}
		};
	};
	*/
	 /* float a, b, c;
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0) {
		printf("Не квадратное уравнение");
	}
	else {
		float D, x1, x2;
		D = b * b - 4 * a * c;
		if (D < 0) {
			printf("Решений нет");
		}
		if (D == 0) {
			x1 = -(b) / (2 * a);
			printf("%f", x1);
		}
		if (D > 0) {
			x1 = (-(b)+sqrt(D)) / (2 * a);
			x2 = (-(b)-sqrt(D)) / (2 * a);
			printf("%f %f", x1, x2);
		}

	}
	*/
	float stena_h, stena_w, stena_t, bok1_h, bok1_d, bok1_t, bok2_h, bok2_d, bok2_t, krv_w, krv_d,
};