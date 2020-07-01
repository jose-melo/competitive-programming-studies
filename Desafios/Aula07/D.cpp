#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define INF 2000000000 


pii analisa(string sinal, string val, string ans, int p, int q){

		
	if(sinal == "<"){
			if(ans == "Y")			
				return make_pair(p, stoi(val)-1);
			else
				return make_pair(stoi(val), q);
	}

 	if(sinal == ">"){
			if(ans == "Y")			
				return make_pair(stoi(val)+1, q);
			else
				return make_pair(p, stoi(val));
	}

	if(sinal ==  "<="){
			if(ans == "Y")			
				return make_pair(p, stoi(val));
			else
				return make_pair(stoi(val)+1,q);
	}
	
	if(sinal ==  ">="){
			if(ans == "Y")			
				return make_pair(stoi(val), q);
			else
				return make_pair(p, stoi(val)-1);				
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p = -INF, q = INF;
	pii aux;
	string sinal, val, ans;
	cin >> n;

	for(int i = 0; i < n; i++){
		
		cin >> sinal >> val >> ans;
	
	//	cout << sinal << " " << val << " " << ans << endl;
		aux = analisa(sinal, val, ans, p, q);

		if(aux.first > p)
			p = aux.first;
	
		if(aux.second < q)
			q = aux.second;

	}	


	if(p <= q)
		cout << p << "\n";
	else
		cout << "Impossible\n";	


return 0;
}



