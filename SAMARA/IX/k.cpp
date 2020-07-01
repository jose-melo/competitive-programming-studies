#include <bits/stdc++.h>
using namespace std;

string s;


int main(){

	int p, q, index, errou = 0;
	cin >> s;

	p = 0; q = s.size() - 1;

	while(p < q){

		if(s[p] == s[q]){
			p++;
			q--;
		}else{

			if(errou != 0){
				cout << "NO\n";
				return 0;
			}
			errou++;
			if(s[p+1] == s[q]){
				index = p;
				p++;
			}else if (s[p] == s[q-1]){
				index = q;
				q--;
			}else{
				cout << "NO\n";
				return 0;
			}
		}
	}

	if(errou > 1){
		cout << "NO\n";
		return 0;
	}

	if(p == q + 1){
		if(s[p] == s[q]){
			if(errou == 1){
				printf("YES\n%d\n", index+1);
				return 0;
			}else if(errou == 0){
				printf("YES\n%d\n", p+1);
				return 0;
			}
		}else{
			if(errou == 1){
				printf("NO\n");
				return 0;
			}else if(errou == 0){
				printf("YES\n%d\n", p+1);
				return 0;
			}
		}
	}

	if(p == q){
		if(errou == 1){
			printf("YES\n%d\n", index+1);
			return 0;
		}else if(errou == 0){
			printf("YES\n%d\n", p+1);
			return 0;
		}
	}
	printf("NO\n");

return 0;
}







