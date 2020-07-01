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


			//printf("### %s\n", s[i].c_str());

			if(s[i] < s[i - 1] && r[i] < s[i - 1] && s[i] < r[i - 1] && r[i] < r[i - 1]){
				//printf("1\n");
				f[i][0] = f[i][1] = INF;
				continue;
			}

			if(s[i] >= s[i - 1]){
				//printf("2\n");
				f[i][0] = min(f[i - 1][0], f[i - 1][1]);
				if(r[i] >= s[i - 1] || r[i] >= r[i - 1])
					f[i][1] = min(f[i - 1][0], f[i - 1][1]) + c[i];
				else
					f[i][1] = INF;
				continue;
			}

			if(r[i] >= s[i - 1] && s[i] >= r[i - 1]){
				//printf("3\n");
				if(f[i-1][1] != INF)
					f[i][0] = f[i - 1][1];
				else
					f[i][0] = INF;					
				f[i][1] = f[i - 1][0] + c[i];
				continue;
			}

			if(r[i] >= s[i - 1]){
				//printf("4\n");
				s[i] = r[i];
				f[i][0] = INF;
				f[i][1] = f[i - 1][0] + c[i];
				continue;
			}

			if(s[i] >= r[i - 1]){
				//printf("5\n");	
				f[i][0] = f[i - 1][1];
				f[i][1] = INF;
				r[i] = s[i];
				continue;
			}

			if(r[i] >= r[i - 1]){
				//printf("6\n");
				s[i] = r[i];
				f[i][0] = INF;
				f[i][1] = f[i - 1][1] + c[i];
				continue;
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


	//printf("%lli %lli\n", f[n][0], f[n][1]);

	if(res != INF)
		printf("%lli\n",res);
	else
		printf("-1\n");
return 0;
}





