#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define INF 100000000000000000
#define ll long long int


ll f[MAX_N][2];
string s[MAX_N], r[MAX_N];
ll c[MAX_N];


void pd(ll n){


	for(ll i = 0; i <= n; i++){

		if(i == 0){
			f[i][0] = f[i][1] = 0;
		}else{

			if(s[i-1]<=s[i])
	            f[i][0]=f[i-1][0];

	        if(s[i]>=r[i-1])
	            f[i][0]=min(f[i][0],f[i-1][1]);

	        if(r[i]>=s[i-1])
	            f[i][1]=f[i-1][0]+c[i];

	        if(r[i]>=r[i-1])
				f[i][1]=min(f[i][1],f[i-1][1]+c[i]);

		}
		
	}
}

int main(){

	ll n, i;

	scanf("%lli", &n);

	for(i = 1; i <= n; i++)
		scanf("%lli", &c[i]);


	for(i = 0; i <= n; i++){
			f[i][0] = INF;
			f[i][1] = INF;
	}
	for(i = 1; i <= n; i++){
		cin >> s[i];
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
	}

	pd(n);

	ll res = min(f[n][0], f[n][1]);


	//printf("%lli %lli\n", f[n][0], f[n][1]);

	if(res != INF)
		printf("%lli\n",res);
	else
		printf("-1\n");
return 0;
}





