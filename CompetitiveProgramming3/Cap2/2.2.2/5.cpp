#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){

	int a;

	scanf("%d", &a);
	int ini;
	for(ini = 0; ini < int(log2(a))+1; ini++)
		if((a&(1<<ini)) == 1)
			break;
	
	for(int bit = ini; bit < int(log2(a))+1; bit++){
		if((a & (1<<bit)) != 0){
			a &= ~(1<<bit);			
		}else{
			break;
		}
	}
	
	cout << a << endl;

return 0;
}

