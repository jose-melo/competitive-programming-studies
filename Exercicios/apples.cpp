#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4000
#define INF 1000000000

int pesos[MAX_N];
int custos[MAX_N];
int f[MAX_N][MAX_N];


void dp(int n, int kg){



	for(int pack = 1; pack <= n; pack++){
		for(int kgi1 = 1; kgi <= kg; kgi++){

			
			if(pack == 0 || kgi == 0){
				f[pack][kgi] = 0;
			}else{

				int min = INF;

				for(int kgi2 = 1; kg2 <= kg; kgi2++){
					if(kgi + kgi2 <= kg){
						if(f[pack - 1][kgi + kg2] < min)
							min = f[pack - 1][kg2];
					}

				}

			}
		}
	}



}



f[n][kg]





