#include <bits/stdc++.h>
using namespace std;

int matriz[3][3];
int input[3][3];

bool eh_valida(int i, int j){

	if(0 <= i && i <= 2 && 0 <= j && j <= 2)
		return true;
return false;
}

int main(){


	for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){ 
			cin >> input[i][j];
		}


	for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) 
    		matriz[i][j] = 1; 
	

    for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){ 
			for(int k = 0; k < input[i][j]; k++){
				for(int p = i-1; p <= i+1; p++){
                    for(int q = j-1; q <= j+1; q++){
					if(eh_valida(p, q)){
				//			printf("p = %d q = %d\n", p, q);
							if(matriz[p][q] == 1){
								matriz[p][q] = 0;
							}
							else
								matriz[p][q] = 1;
					    	
					}
                    }
                }/*
				for(int i = 0; i < 3; i++){
						for(int j = 0; j < 3; j++){ 
							printf("%d", matriz[i][j]);
						}
						printf("\n");
					}	
				printf("------------------------\n");*/
            }
		}	


	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){ 
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}	
	

return 0;
}
