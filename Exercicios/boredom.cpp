#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 100100
#define INF 1000000000

typedef struct {
	
	ll num;
	ll freq;

} par;

ll f[2][MAX_N];

par num[MAX_N];

/*void pd(ll n){


	f[0][0] = f[1][0] = 0;
	num[0].freq = 0;
	for(ll i = 1; i <= n; i++){

		if(num[i-1].num + 1 == num[i].num){
			f[1][i] = f[0][i-1] + num[i].num*num[i].freq;
			f[0][i] = max(f[1][i-1], f[0][i-1]);
		}else{
			f[1][i] = max(f[1][i-1], f[0][i-1]) + num[i].num*num[i].freq;
			f[0][i] = max(f[1][i-1], f[0][i-1]);
		}
	}
}*/

ll memoization(ll peguei, ll i){

	if(i > 0){

		if(f[peguei][i] != 0)
			return f[peguei][i];

		ll aux1 = memoization(1, i-1), aux2 = memoization(0, i-1);

		if(num[i-1].num + 1 == num[i].num){
			if(peguei == 1)f[peguei][i] = aux2 + num[i].num*num[i].freq;
			if(peguei == 0)f[peguei][i] = max(aux1, aux2);
		}else{
			if(peguei == 1)f[peguei][i] = max(aux1,aux2) + num[i].num*num[i].freq;
			if(peguei == 0)f[peguei][i] = max(aux1, aux2);
		}

	return f[peguei][i];
	}
return 0;
}






int main(){


	ll n, a, cont;
	ll input[MAX_N];

	scanf("%lli", &n);

	cont = 0;
	num[cont].num = -1;

	for(ll i = 1; i <= n; i++)
		scanf("%lli", &input[i]);

	sort(input, input + n + 1);

	for(ll i = 1; i <= n; i++){

		a = input[i];

		if(a == num[cont].num){
			num[cont].freq += 1;
		}else{
			cont++;
			num[cont].num = a;
			num[cont].freq = 1;
		}
	}

	/*printf("num: ");
	for(ll i = 0; i <= n; i++)
		printf("(%lli %lli)", num[i].num, num[i].freq);
	printf("\n");*/

	//pd(cont);

	f[0][0] = f[1][0] = 0;
	num[0].freq = 0;

	printf("cont = %d\n", cont);

	ll aux1 = memoization(1, cont), aux2 = memoization(0, cont);

	printf("f[0]: ");
	for(ll i = 0; i <= cont; i++)
		printf("%lli ", f[0][i]);
	printf("\n");
	printf("f[1]: ");
	for(ll i = 0; i <= cont; i++)
		printf("%lli ", f[1][i]);
	printf("\n");

	printf("%lli\n", max(memoization(0, cont), memoization(1, cont)));


}









