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


string A, B;

int main(){

	fastio;

	cin >> A >> B;
	
	int tamA = A.size(), tamB = B.size();

	int x = 0, y = tamB - 1;

	vector<ll> preffix(m, -1), suffix(m, -1);

	int q = 0;
	for(int p = 0; p < B.size(); p++){
		
		int cont = 1;
		while(q < A.size() && A[q] != B[p]){
			q++;
			cont++;
		}

		if(q < A.size())
			preffix[p+1] = preffix[p] + cont;
		q++;

		x = min(p + 1, tamB - 1);
	}

	if(preffix[tamB - 1] != -1){
		cout << B << "\n";
		return 0;
	}

	
	q = A.size() - 1;
	for(int p = B.size() - 1; p >= 0; p--){
		
		int cont = 1;
		while(q >= 0 && A[q] != B[p]){
			q--;
			cont++;
		}

		if(q >= 0)
			suffix[B.size() - p] = suffix[B.size() - p - 1] + cont;
		else
			suffix[B.size() - p] = INF;

		q--;
	}
	sort(suffix, suffix + B.size());
/*

	cout << "preffix = ";
	FOR(i, 0, B.size()+1)
		cout << preffix[i] << " ";
	cout << "\n";

	cout << "suffix = ";
	FOR(i, 0, B.size()+1)
		cout << suffix[i] << " ";
	cout << "\n";*/
	int idx1 = -1, idx2 = -1;

	int maxx = -1;
	
	for(int i = 0; i < B.size()+1; i++){
		int l, r, mid, val;
		
		val = A.size() - preffix[i];

		l = 0, r = B.size() + 1;
		while(l < r){

			mid = (l + r) / 2;

			if(suffix[mid] <= val)
				l = l + 1;
			else
				r = mid;
		}

		l--;

		if(l == -1)continue;	

//		cout << "i = " << i << " val = " << val << " l = " << l << endl;	
		if(suffix[l] + preffix[i] <= A.size()){

			if(l + i > maxx){
				
				idx1 = i;
				idx2 = l;
				maxx = idx1 + idx2;
			}
		}

	}	

	if(idx1 + idx2 > B.size()){
		cout << B << "\n";
		return 0;
	}

	if(idx1 == 0 && idx2 == 0){
		cout << "-\n";
		return 0;
	}

	for(int i = 0; i < idx1; i++)	
		cout << B[i];

	for(int i = B.size() - idx2; i < B.size(); i++)
		cout << B[i];	

	cout << "\n";
return 0;
}






