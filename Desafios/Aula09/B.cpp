#include <bits/stdc++.h>
using namespace std;

int main(){

	int T, n, p, q;
	string s;	

	cin >> T;
	while(T--){
		cin >> n;
		cin >> s;
		
		p = 0;
		q = n-1;
		int ok = 1;
		while(p < q && ok){
			if(abs(s[p]-s[q]) > 2 || abs(s[p]-s[q]) == 1)
				ok = 0;

			p++;
			q--;
		}
		
		if(ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

return 0;
}



