/*https://codeforces.com/contest/1114/problem/B*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define INF 0x3f3f3f3f
#define ll long long int

int n, m, k, num_subarrays;
ll num[MAX];
ll num_aux[MAX];
ll soma;

int main(){

	cin >> n >> m >> k;

	int index[MAX];

	for(int i = 1; i <= n; i++){
		scanf("%lld", &num[i]);
		num_aux[i] = num[i];
	}

	sort(num_aux, num_aux + (n+1));
	ll min = num_aux[n - m*k];

	int conta_iguais = 0;
	for(int i = n - (m*k); i <= n; i++)
		if(num_aux[i] == min)
			conta_iguais++;

	int cont = 0, cortes_idx = 0;
	soma = 0, num_subarrays = 1;
	for(int idx = 1; idx <= n; idx++){
	
		if(num[idx] == min){
			if(conta_iguais == 0){
				if(cont == m){
					if(num_subarrays < k){
						index[cortes_idx++] = idx-1;
						cont = 0;
						num_subarrays++;
						}
				}
				continue;
			}
		}

		if(num[idx] > min || (num[idx] == min && conta_iguais != 0)){
			if(num[idx] == min && conta_iguais != 0)conta_iguais--;
			if(cont < m){
				cont++;
				soma += num[idx];
			}else{
				if(num_subarrays < k){
					idx--;
					index[cortes_idx++] = idx;
					cont = 0;
					num_subarrays++;
				}
			}
		}else{

			if(cont == m){
				if(num_subarrays < k){
					index[cortes_idx++] = idx-1;
					cont = 0;
					num_subarrays++;
				}
			}
		}
	}

	printf("%lld\n", soma);
	for(int i = 0; i < cortes_idx; i++)
		printf("%d ", index[i]);
	printf("\n");
return 0;
}






