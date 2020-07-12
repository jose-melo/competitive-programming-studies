#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

int t;

int main(){

	cin >> t;

	while(t--){

		string s, resp;
	
		cin >> s;

		int cR=0, cP=0, cS=0;
		

		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R')cR++;
			if(s[i] == 'P')cP++;
			if(s[i] == 'S')cS++;
		}

		int n = s.size();
		if(cR >= cP && cR >= cS){

			for(int i = 0; i < n; i++)
				resp.pb('P');
			cout << resp << endl;
			continue;
		}


		if(cP >= cR && cP >= cS){

			for(int i = 0; i < n; i++)
				resp.pb('S');
			cout << resp << endl;
			continue;
		}

		if(cS >= cP && cS >= cR){

			for(int i = 0; i < n; i++)
				resp.pb('R');
			cout << resp << endl;
			continue;
		}


	}



}

