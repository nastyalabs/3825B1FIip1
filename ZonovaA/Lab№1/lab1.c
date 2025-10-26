#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

//������ 1
void main() {
	double h, d, w;
	double const pDSP = 0.735;    //� �/��^2
	double const pDVP = 0.8;    //� �/��^2
	double const pderev = 0.6;  //� �/��^2
	double const tol_st = 0.5;  //� ��
	double const tol_bok = 1.5;  //� ��
	double const tol_cr = 1.5;  //� ��
	double const tol_dv = 1;  //� ��
	double const tol_pol = 0.5;  //� ��


	printf("Cabinet weight counter\n");
	printf("----------------------\n");

	printf("Enter the desired cabinet height h(180-220 cm): ");
	scanf("%lf", &h);

	printf("Enter the desired cabinet width w(80-120 cm): ");
	scanf("%lf", &w);

	printf("Enter the desired cabinet depth d(50-90 cm): ");
	scanf("%lf", &d);

	if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90) {
		printf("The entered parameters do not meet the requirements!\n");
		return 1;
	}

	double mas_st = (h * tol_st * w) * pDVP;
	double mas_bok = 2 * (h * tol_bok * d) * pDSP;
	double mas_cr = 2 * (d * tol_cr * w) * pDSP;
	double mas_dv = (h * tol_dv * w) * pderev;
	double mas_pol = (d * tol_pol * w) * pDSP;   //����� ����� �����

	double mas_res = mas_st + mas_bok + mas_cr + mas_dv + floor((h - 2 * tol_cr) / 40.5) * mas_pol;  //�� ������ �� 180 �� 220 �� - ������� ������ ������ � ����� �������� �� ������� ����� � ���������� ����� ����
	printf("Total weight = %lf", mas_res / 1000);  //����� � ��

}


//������ 2
// ��� ����� ����� ������� ������, � ���� �� ������ (������, ��������, ����� - �����, ����, ����) ���� 8*8
void main() {
	// ��������� ����������: Ox1, Oy1; �������� ����������: Ox2, Oy2
	printf("Enter the initial position of the shape (A = 1, B = 2...): \n");

	int Ox1 = 0, Oy1 = 0;

	printf("Ox1(A(1)-H(8)) = "); scanf("%d", &Ox1);
	printf("Oy1(1-8) = "); scanf("%d", &Oy1);

	printf("Enter the final position of the shape (A = 1, B = 2...): \n");

	int Ox2 = 0, Oy2 = 0;

	printf("Ox2(A(1)-H(8)) = "); scanf("%d", &Ox2);
	printf("Oy2(1-8) = "); scanf("%d", &Oy2);

	//����� ������: (������ - 1, �������� - 2, ����� - 3, ���� - 4, ���� - 5
	printf("Choose a shape (King - 1, Queen - 2, Rook - 3, Bishop - 4, Knight - 5): \n");

	int shape = 0;

	printf("Shape = "); scanf("%d", &shape);

	//������� ���������
	int Ox = abs(Ox2 - Ox1);
	int Oy = abs(Oy2 - Oy1);

	//������������ ������� ���� ������
	enum shape {
		King = 1,
		Queen = 2,
		Rook = 3,
		Bishop = 4,
		Knight = 5,
	};

	//��������
	if (Ox1 < 1 || Ox2 < 1 || Oy1 < 1 || Oy2 < 1 || Ox1 > 8 || Ox2 > 8 || Oy1 > 8 || Oy2 > 8 || shape < 1 || shape > 5) {
		printf("Incorrect input, try again");
		return 0;
	}
	else if (Ox == 0 && Oy == 0) {
		printf("The starting and ending positions are the same, and the shapes cannot move in this way, try again");
		return 0;
	}

	//������������ ������
	else if (Ox == 0 || Oy == 0 || Ox == Oy) {
		if (shape == Queen) {
			printf("Chosen shape can move to that space\n");
		}
		else {
			printf("Queen can move to that space\n");
		}


		if (Ox <= 1 && Oy <= 1) {
			if (shape == King) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("King can move to that space\n");
			}
		}

		if (Ox == 0 || Oy == 0) {
			if (shape == Rook) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Rook can move to that space\n");
			}
		}

		if (Ox == Oy) {
			if (shape == Bishop) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Bishop can move to that space\n");
			}
		}

		if ((Ox == 2 && Oy == 1) || (Ox == 1 && Oy == 2)) {
			if (shape == Knight) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Knight can move to that space\n");
			}
		}
	}

	else {
		printf("No piece can reach that position in one move.\n");
	}
}
