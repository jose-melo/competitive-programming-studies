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


int solve(string s, string p1, string p2, int player){

	if(s.empty()){
		if(p1 > p2) return 1;	
		if(p1 == p2) return 0;
		return -1;
	}

	string s1 = s.substr(1, s.size());
	string s2 = s.substr(0, s.size()-1);
	int val1, val2;
	if(player > 0){
		val1 = solve(s1, p1.insert(0, s[0]), p2, player*-1);
		val2 = solve(s2, p1.append(s.back()), p2, player*-1);
		
		return max(val1, val2); 
	}else{
		val1 = solve(s1, p1, p2.insert(0, s[0]), player*-1);
		val2 = solve(s2, p1, p2.append(s.back()), player*-1);
		
		return min(val1, val2); 
	}
}

int main(){

	int t;
	string s;

	cin >> t;
	while(t--){
		cin >> s;

		int result = solve(s, "", "", 1);

		if(result > 0){
			cout << "Alice\n";
		}else if(result == 0){
			cout << "Draw\n";
		}else{
			cout << "Bob\n";
		}
	}


}

