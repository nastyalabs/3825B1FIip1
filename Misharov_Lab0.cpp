//#include <stdio.h>
//#include <math.h>
//void main() {
	//float v1, v2, S;
	//scanf_s("%f  %f  %f", &v1, &v2, &S);
	//float t = (S / (v1 + v2));
	//printf("time is = %f", t);
//}


//#include<stdio.h>
//#include<math.h>
//void main() {
	//float t, v1, v2;
	//scanf_s("%f %f %f", &t, &v1, &v2);
	//float S = ((t * v1) + v2);
	//printf("расстояние = %f", S);
//}


#include<stdio.h>
#include<math.h>
void main() {
	float x1, y1, r1;
	float x2, y2, r2;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	float v = sqrt(((x1 + x2) * (x1 + x2)) + ((y1 - y2) * (y1 - y2)));
	
	if (r1+r2 > v) {
		printf("совпадают");
	}
	else if (r1 + r2 < v) {
		printf("не совпадают");
	}
	else if (r1 + r2 == v) {
		printf("касаются");
	}

}