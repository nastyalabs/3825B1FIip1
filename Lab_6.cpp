#include <stdio.h>
#include <math.h>
#include <locale.h>


typedef double (*MathFunc)(double);
double my_sin(double x) { return sin(x); }
double my_cos(double x) { return cos(x); }
double my_exp(double x) { return exp(x); }
double my_ln(double x) { return log(x+1); }

typedef struct {
	double value;
	int iterations;
} Result;
typedef Result(*TaylorFunc)(double x, double acc, int N);


Result t_sin(double x, double acc, int N) {
	double summ = x;
	double a = x;
	int k=1;
	for (int i = 1; i < N; i++) {
		a = -a * x*x / (2 * i) / (2 * i + 1);
		if (fabs(a) < acc && acc != 1) {
			k += i;
			break;
		}
		summ += a;
	}
	Result res = { summ, k };
	return res;
}

Result t_cos(double x, double acc, int N) {
	double summ = 1;
	double a = 1;
	int k=1;
	for (int i = 1; i < N; i++) {
		a = -a * x * x / (2 * i) / (2 * i - 1);
		if (fabs(a) < acc && acc != 1) {
			k += i;
			break;
		}
		summ += a;
	}
	Result res = { summ, k };
	return res;
}

Result t_exp(double x, double acc, int N) {
	double summ = 1;
	double a = 1;
	int k = 1;
	for (int i = 1; i < N; i++) {
		a = a * x / (i);
		if (fabs(a) < acc && acc != 1) {
			k += i;
			break;
		}
		summ += a;
	}
	Result res = { summ, k };
	return res;
}

Result t_ln(double x, double acc, int N) {
	double summ = x;
	double a = x;
	int k = 1;
	for (int i = 1; i < N; i++) {
		a = pow(-1, i)*pow(x, i)/i;
		if (fabs(a) < acc && acc != 1) {
			k += i;
			break;
		}
		summ += a;
	}
	Result res = { summ, k };
	return res;
}

main() {
	setlocale(LC_ALL, "Rus");
	TaylorFunc taylor_func[] = { t_sin, t_cos, t_exp, t_ln };
	MathFunc math_funct[] = { my_sin, my_cos, my_exp, my_ln };
	int mode, funct;	
	double x;
	
	do{
		printf("Выберите режим: 1 - однократный расчет в заданной точке, 2 - серийный эксперимент.\n");
		scanf_s("%d", &mode);
		if (mode != 1 && mode != 2)
			printf("Ошибка, введите 1 или 2\n");
	} while (mode != 1 && mode != 2);

	do {
		printf("Выбери функцию: 1 - sin(x), 2 - cos(x), 3 - exp(x), 4 - ln(x+1)\n");
		scanf_s("%d", &funct);
		if (funct < 1 || funct > 4)
			printf("Ошибка, выберите значение от 1 до 4\n");
	} while (funct < 1 || funct > 4);
	printf("Задайте точку х\n");
	scanf_s("%lf", &x);
	

	if (mode == 1) {
		int N;
		double acc;
		do {
			printf("Задайте точность вычисления от 0.000001 и больше\n");
			scanf_s("%lf", &acc);
			if (acc >= 0.000001)
				printf("Ошибка, выберите значение от 0.000001\n");
		} while (acc >= 0.000001);
		do {
			printf("Задайте число элементов ряда от 1 до 1000\n");
			scanf_s("%d", &N);
			if (N < 1 || N>1000)
				printf("Ошибка, выберите значение от 1 до 1000\n");
		} while (N < 1 || N>1000);

		printf("Эталонное значение: %lf\n", math_funct[funct](x));
		Result a = taylor_func[funct](x, acc, N);
		printf("Вычисленная оценка значения функции: %lf\n", a.value);
		printf("Разница: %lf\n", fabs(math_funct[funct](x) - a.value));
		printf("Количество слагаемых: %d\n", a.iterations);
	}
	else if (mode == 2) {
		int Nmax = 0;
		do {
			printf("Задайте число элементов ряда от 1 до 25\n");
			scanf_s("%d", &Nmax);
			if (Nmax < 1 || Nmax>25)
				printf("Ошибка, выберите значение от 1 до 25\n");
		} while (Nmax < 1 || Nmax>25);
		printf("Эталонное значение: %lf\n", math_funct[funct](x));
		printf("Количество слагаемых | Вычисленная оценка значения | Разница между оценкой и эталонным значением\n");
		for (int i = 0; i < Nmax; i++) {
			Result a = taylor_func[funct](x, 1, i);
			printf("%d | %lf | %lf \n", i, a.value, fabs(math_funct[funct](x) - a.value));
		}
	}


	return 0;
}