#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 5010

ll f[MAX_N];
string s;

void pd(ll n){

	f[0] = 1;
	f[1] = 1;
	for(ll i = 2; i <= n; i++){		

		if(s[i-1 - 1] == '1'){
			if(s[i-1] != '0')
				f[i] = f[i-1] + f[i-2];
			else
				f[i] = f[i-2];
			continue;
		}

		if(s[i-1 - 1] == '2' && s[i-1] <= '6'){
			
			if(s[i-1] != '0')
				f[i] = f[i-1] + f[i-2];
			else
				f[i] = f[i-2];
			continue;

		}

		if(i < n){
			if(s[i] != '0'){
				f[i] = f[i-1];
				continue;
			}
		}else{
			f[i] = f[i-1];
		}
	}
}

int main(){


	getline(cin, s);

	while(s[0] != '0'){

		pd(s.size());
		printf("%lli\n", f[s.size()]);

		getline(cin, s);
	}

return 0;
}






