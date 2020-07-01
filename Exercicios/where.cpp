#include <bits/stdc++.h>
using namespace std;


void resolvenduo( int ax, int ay, int bx, int by, int cx, int cy){

	if((1ll * (by - ay) * (cx - bx)) == (1ll * (cy - by) * (bx - ax)))
			printf("TOWARDS\n");
		else {
			long long v = (1ll * (bx - ax) * (cy - ay)) - (1ll * (cx - ax) * (by - ay));
			if(v > 0)
				printf("LEFT\n");
			else
				printf("RIGHT\n");
		}
return;
}




int main() {
	int ax, ay, bx, by, cx, cy;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

	resolvenduo(ax, ay, bx, by, cx, cy);

return 0;
}