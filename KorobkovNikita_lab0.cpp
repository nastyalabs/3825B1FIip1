#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int x1,y1,r1,x2,y2,r2;
	scanf_s("%d,%d,%d,%d,%d,%d", &x1, &y1, &r1, &x2, &y2, &r2);
	int dx = x2 - x1;
	int dy = y2 - y1;
	int ds= sqrt(dx*dx + dy*dy);
	if (x1 = x2, y1 = y2) {
		printf("libo ravni, libo odin vnutry drugogo");
		exit(0);
	}
	if (ds < r1 + r2) {
		printf("peresekaytsya");
		exit(0);
	}if (ds > r1 + r2) {
		printf("ne peresekayutsya");
		exit(0);
	}if (ds = r1 + r2) {
		printf("Kasanie");
		exit(0);
	}
	return 0;
}