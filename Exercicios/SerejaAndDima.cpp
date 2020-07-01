#include <bits/stdc++.h>
using namespace std;


int v[1100];


int main(){

	int n, p, q, i, turn, sereja, dima;


	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);


	p = 0;
	q = n - 1;
	turn = 0;
	sereja = dima = 0;

	while(p != q){
		
		if(v[p] > v[q]){
			
			if(turn == 0)
				sereja += v[p];
			else
				dima += v[p];
		
			if(turn == 0)turn = 1;
			else turn = 0;

			p++;

		}else{

			if(turn == 0)
				sereja += v[q];
			else
				dima += v[q];


			if(turn == 0)turn = 1;
			else turn = 0;
			
			q--;

		}
	}

	if(turn == 0)
		sereja += v[p];
	else
		dima += v[p];

	printf("%d %d\n", sereja, dima);

return 0;
}