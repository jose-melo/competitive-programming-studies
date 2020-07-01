//https://codeforces.com/problemset/problem/466/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 500010

ll sum_array[MAX_N];
ll numbers[MAX_N];
int n, p, q, mid, resposta, l, r;

int main(){

	resposta = 0;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> numbers[i];

	sum_array[0] = 0;
	sum_array[1] = numbers[0];
	for(int i = 2; i <= n; i++)
		sum_array[i] = sum_array[i-1] + numbers[i-1];

	int sum;
	for(p = 1; p < n; p++){
		
		sum = sum_array[p];
		l = p;
		r = n;
		while(r - l > 1){
			q = (l + r) / 2;
			//printf("p = %d q = %d\n", p, q);
			if(sum_array[q] - sum_array[p] > sum){
				r = q;
			}
			else if(sum_array[q] - sum_array[p] < sum){
				l = q;
			}
			if(sum_array[q] - sum_array[p] == sum){
				while(sum_array[n] - sum_array[q] == sum){
					resposta++;
					q++;
				}
				break;
			}
		}

	}

	cout << resposta << endl;
return 0;
}




