#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define INF 1000000000
#define mod 1000000007
#define ll long long int


ll f[MAX_N][2];
string s[MAX_N], r[MAX_N];
ll c[MAX_N];


void pd(int n){

	for(int i = 0; i <= n; i++){

		if(i == 0){
			f[i][0] = f[i][1] = 0;
		}else{

			if(s[i] < s[i - 1] && r[i] < s[i - 1] && s[i] < r[i - 1] && r[i] < r[i - 1]){
				f[i][0] = f[i][1] = INF;
				continue;
			}

			if(s[i] >= s[i - 1] && f[i - 1][0] != INF){
				f[i][0] = f[i - 1][0];
				f[i][1] = f[i - 1][0] + c[i];
				continue;
			}

			if(r[i] >= s[i - 1] && s[i] >= r[i - 1]){
				f[i][0] = f[i - 1][1];
				f[i][1] = f[i - 1][0] + c[i];
				continue;
			}

			if(r[i] >= s[i - 1]){
				f[i][0] = INF;
				f[i][1] = f[i - 1][0] + c[i];
				continue;
			}

			if(s[i] >= r[i - 1]){
				f[i][0] = f[i - 1][1];
				f[i][1] = INF;
				continue;
			}

			if(r[i] >= r[i - 1]){
				f[i][0] = INF;
				f[i][1] = f[i - 1][1] + c[i];
			}

		}
		
	}
}

int main(){

	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%lli", &c[i]);


	for(int i = 0; i <= n; i++)
			f[i][0] = f[i][1] = 0;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
	}

	pd(n);

	ll res = min(f[n][0], f[n][1]);


	if(res != INF)
		printf("%lli\n",res);
	else
		printf("-1\n");
return 0;
}





