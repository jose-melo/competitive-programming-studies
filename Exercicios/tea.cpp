#include <bits/stdc++.h>
using namespace std;

#define MAX 21;

void solve(int n, int control, char orig, char aux, char dest, int *cont){

	if(n >= 1){
		solve(n - 1, control, orig, dest, aux, cont);
		if(control == 1)printf("%c %c\n", orig, dest);	
		/*printf("cont = %d\n", *cont);*/
		(*cont)++;
		solve(n - 1, control, aux, orig, dest, cont);
	}
}


int main(){

	int num_barcos, num_viagens, min = 0, i;

	scanf("%d %d", &num_barcos, &num_viagens);

	solve(num_barcos, 0, 'A', 'B', 'C', &min);
	printf("min = %d\n", min);

	if(num_viagens >= min && num_viagens != min + 1){
		min = 0;
		printf("Y\n");
		solve(num_barcos, 1, 'A', 'B', 'C', &min);	
		num_viagens -= min;
		if(num_viagens != 0 && num_viagens % 2 == 0){
			for(i = 0; i < num_viagens / 2; i++){
				printf("C B\n");
				printf("B C\n");
			}
		}else{
			if(num_viagens != 0){
				while(num_viagens > 3){
					printf("C B\n");
					printf("B C\n");
					num_viagens -= 2;
				}
				printf("C A\n");
				printf("A B\n");
				printf("B C\n");
			}
		}
	}else{
		printf("N\n");
	}

return 0;
}