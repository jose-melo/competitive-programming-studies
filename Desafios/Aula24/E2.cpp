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
int preffix[112345], suffix[112345];

int main(){


	cin >> A >> B;

	int tamA = A.size(), tamB = B.size();

	int idxA = 0;
	preffix[0] = 0;
	FOR(idxB, 0, tamB){
		
		while(idxA < tamA && A[idxA] != B[idxB])
			idxA++;

		if(idxA < tamA)
			preffix[idxB + 1] = idxA + 1;
		else
			preffix[idxB + 1] = INF;
		idxA++;

	}

	suffix[0] = 0;
	idxA = tamA - 1;
	for(int idxB = tamB - 1; idxB >= 0; idxB--){

		while(idxA >= 0 && A[idxA] != B[idxB])
			idxA--;

		if(idxA >= 0)
			suffix[tamB - idxB] = tamA - idxA;
		else
			suffix[tamB - idxB] = INF;	

		idxA--;
	}


	int x, y, mx = -1;
	FOR(idxP, 0, tamB+1){

		int* it = lower_bound(suffix, suffix + tamB, tamA - preffix[idxP]);

		if(it != suffix + tamB){
			if(*it + preffix[idxP] <= tamA && *it + preffix[idxP] > mx){
				x = it - suffix;
				y = idxP;
				mx = *it + preffix[idxP];

			} 

		}
	}

	if(x == 0 && y == 0){
		cout << "-\n";
		return 0;
	}


	for(int i = 0; i < y; i++)
		cout << B[i];

	for(int i = tamB - x; i < tamB; i++)
		cout << B[i];





}


