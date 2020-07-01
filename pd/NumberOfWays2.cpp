#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 500100

int n, resposta, p, q;
ll numbers[MAX_N];

int main(){

	resposta = 0;

	ll sum, sum_a, sum_b;

	cin >> n;
	int total_sum = 0;
	for(int i = 0; i < n; i++){
		cin >> numbers[i];
		total_sum += numbers[i];
	}

	if(total_sum % 3){
		cout << "0" << endl;
		return 0;
	}
	else
		sum = total_sum / 3;
	

	sum_a = numbers[0];
	sum_b = 0;
	p = 1;
	for(; p < n-2 && sum_a < sum; p++)
		sum_a += numbers[p]; 
	p--;
	int cont = 0, k = p;
	k++;
	printf("k = %d\n", k);
	while(k < n-2 && numbers[k+1] == 0){
		k++;
		cont++;
	}

	printf("cont = %d\n", cont);

	
	q = n-1;
	if(sum_a == sum){
		for(; q > p+1; q--){
			sum_b += numbers[q];
			if(sum_b == sum)
				resposta++;
		}
	}

	cout << resposta + cont << endl;
return 0;
}


