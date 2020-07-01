#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b, int* x, int *y){

	int div;
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	div = gcd(b % a, a, &x1, &y1);

	*x = y1 - (b/a)*x1;
	*y = x1;

	return div;
}

void solve(int a, int b, int c){

	int res1 = 0, res2 = 0;
	int aux_a = 0, aux_b = 0, aux;

	if(a < c && b < c){
		printf("-1\n");
		return;
	}

	int x, y, mdc;

	mdc = gcd(a, b, &x, &y);

	x *= c / mdc;
	y *= c / mdc;

	/*printf("x = %d y = %d\n", x, y);*/

	if(c % mdc != 0){
		printf("-1\n");
		return;
	}

	while(aux_a != c && aux_b != c){
		if(aux_a == 0){
			res1++;
			aux_a = a;
		}else{
			if(aux_b == b){
				res1++;
				aux_b = 0;
			}else{

				if(aux_a > b){
					aux_a -= b - aux_b;
					aux_b = b;
				}else{

					if(aux_b + aux_a > b){
						aux_a = aux_a - (b - aux_b);
						aux_b = b;
					}else{
						aux_b += aux_a;
						aux_a = 0;
					}
				}
				res1++;
			}
		}
	}
	
	aux_a = 0;
	aux_b = 0;

	while(aux_a != c && aux_b != c){

		if(aux_b == 0){
			res2++;
			aux_b = b;
		}else{
			if(aux_a == a){
				res2++;
				aux_a = 0;
			}else{

				if(aux_b > a){
					aux_b -= a - aux_a;
					aux_a = a;
				}else{

					if(aux_a + aux_b > a){
						aux_b = aux_b - (a - aux_a);
						aux_a = a;
					}else{
						aux_a += aux_b;
						aux_b = 0;
					}
				}
			
				res2++;
			}
		}
	}

	if(res1 < res2)
		printf("%d\n", res1);
	else
		printf("%d\n", res2);	

return;
}



int main(){

	int t, a, b, c, i, j;


	scanf("%d", &t);

	for(j = 0; j 
		< t; j++){
		scanf("%d %d %d", &a, &b, &c);
		
		if(a > b)
			solve(a, b, c);
		else
			solve(b, a, c);
	}

return 0;
}