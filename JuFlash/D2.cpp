    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long int 
    #define pii pair<int, int>
    #define INF 0x3f3f3f3f
    #define fi first
    #define mp make_pair
    #define se second
    #define FI(n) for(int i = 0; i < n; i++)
    #define FOR(i,a,n) for (int i=(a);i<(n);++i)
    #define t cout << "TESTE" << endl
    #define debug(x) if(on)cout << x << endl
    #define on true
    #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
    #define pb push_back
    #define debugv(v) for(auto x : v)cout << x << endl;
     
    int main(){
    	int n , a , b , s;
     
    	cin >> n >> a >> b >> s;
    	
    	if(n == 1){
    		if( a == b && a == s && b == s){
    			printf("YES\n");		
    		}else{
    			printf("NO\n");
    		}
    		return 0;
    	}
    	
    	if(n == 2){
    		if( a + b == s){
    			printf("YES\n");
    		}else{
    			printf("NO\n");
    		}
    		return 0;
    	}
    	
     
    	int minimo = n * a;
    	int maximo = n * b;
     
    	if(s >= minimo && s <= maximo){
    		printf("YES\n");
    	}else{
    		printf("NO\n");
    	}
     
     
     
    }
