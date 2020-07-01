#include <bits/stdc++.h>
using namespace std;


int v[100100];



int main(){

	int num_chocolate, i, cont_a, cont_b, tempo, aux_a, aux_b, p, q;

	scanf("%d", &num_chocolate);


	for(i = 0; i < num_chocolate; i++)
		scanf("%d", &v[i]);
	

	p = 0;
	q = num_chocolate - 1;
	cont_b = cont_a = aux_a = aux_b = 0;


	tempo = 0;
	while(p != q){
		if(v[p] == tempo - aux_a){
			cont_a++;
			aux_a += v[p];
			if(p + 1 != q){p++;
			}else{
				cont_b++;
				break;
			}
		}

		if(v[q] == tempo - aux_b){
			cont_b++;
			aux_b += v[q];
			if(q - 1 != p){q--;
			}else{
				cont_a++;
				break;
			}
		}

		if(p == q){
		 	cont_a++;
		 	break;
		}
	tempo++;
	}
	if(p == q)cont_a++;

	printf("%d %d\n", cont_a, cont_b); 
return 0;
}

