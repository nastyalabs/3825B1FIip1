#include <stdio.h>
#include <math.h>

//float main() {
	//float S, V1, V2;
	//scanf_s("%f %f %f", &S, &V1, &V2);
	//float t = S / (V1 + V2);
	//printf("time is %f", t);
//}
//void main() {
//	float v1, v2, t = 1.5;
//	scanf_s("%f %f", &v1, &v2);
//	float S = (v1 + v2) * t;
//	printf("S is %f", S);
//}

void main() {
	float r1, r2,x1,x2,y1,y2;
	scanf_s("first cir %f %f", &x1, &y1);
	scanf_s("second cir %f %f", &x2, &y2);
	scanf_s("%f %f", &r1,&r2);
	float d = sqrt((x2-x1)* (x2 - x1) +(y2-y1)* (y2 - y1));
	if (r1 + r2 > d) {
		printf("peresec");
	}
	else if (r1 + r2 < d) {
		printf("ne per");
	}
	else if (r1 + r2 == d) {
		printf("kas");
	}
	



}