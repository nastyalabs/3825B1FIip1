#include <stdio.h>
#include <math.h>
#include <clocale>
//void main() {
//	setlocale(LC_ALL, "RU");
//	float w, d, h, mass = 0;
//	printf("������� ������ ����� � ����������� �� 180 �� 220: ");
//	scanf_s("%f", &h);
//	printf("������� ������ ����� � ����������� �� 80 �� 120: ");
//	scanf_s("%f", &w);
//	printf("������� ������� ����� � ����������� �� 50 �� 90: ");
//	scanf_s("%f", &d);
//	if ((220 < h) || (h < 180) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) {
//		printf("������������ ������");
//	}
//	else {
//		//��������� ����� �� ���������
//		float dsp = 650, dvp = 800, wood = 800;
//		h = h / 100;
//		w = w / 100;
//		d = d / 100;
//		mass = mass + (h * w * 0.005 * dvp);
//		mass = mass + (2 * h * d * 0.015 * dsp);
//		mass = mass + (2 * d * w * 0.015 * dsp);
//		mass = mass + (2 * h * (w / 2) * 0.01 * wood);
//		int polki = (int)(h * 100) / 40;
//		mass = mass + (polki * d * w * 0.015 * dsp);
//		printf("����� �����: %f", mass);
//	}
//}
void main() {
	setlocale(LC_ALL, "RU");
	int x1, x2, y1, y2;

	printf("������� ���������� K1 �� 1 �� 8 (������� x, ����� y): ");
	scanf_s("%d %d", &x1, &y1);
	printf("������� ���������� K2 �� 1 �� 8 (������� x, ����� y): ");
	scanf_s("%d %d", &x2, &y2);


	int figura;
	printf("�������� ������ (1-����, 2-�����, 3-�����, 4-����, 5-������): ");
	scanf_s("%d", &figura);
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	
	int status = 0;
	switch (figura) {
	case 1:
		if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) status = 1; break;
	case 2:
		if (dx == 0 || dy == 0) status = 1; break;
	case 3:
		if (dx == 0 || dy == 0 || dx == dy) status = 1; break;
	case 4:
		if (dx == dy) status = 1; break;
	case 5:
		if (dx <= 1 && dy <= 1) status = 1; break;
	} 

	int n = 0;
	const char* figuri[] = {"����", "�����", "�����", "����", "������"};
	if (status) {
		printf("����� ������� �� 1 ���");
	}
	else {
		printf("�� ����� �������\n");
		printf("����� �������: ");
		if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
			printf(" ���� ");
			n++;
		}
		if (dx == 0 || dy == 0) {
			printf(" ����� ");
			n++;
		}
		if (dx == 0 || dy == 0 || dx == dy) {
			printf(" ����� ");
			n++;
		}
		if (dx == dy) {
			printf(" ���� ");
			n++;
		}
		if (dx <= 1 && dy <= 1) {
			printf(" ������ ");
			n++;
		}
		if (n == 0) {
			printf("�� ���� ������ �� ����� �������");
		}
	}
}