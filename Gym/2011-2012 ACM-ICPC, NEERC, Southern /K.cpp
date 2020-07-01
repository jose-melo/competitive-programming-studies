#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_N 100000

bool eh_pontuacao(char ch){

	if(ch == '-' || ch == ':'|| ch == ','|| ch == ';')
		return true;

return false;
}

int main(){

	string s;
	int cont = 0;
	stack<char> pilha;

	getline(cin, s);

	for(int i = 0; i < (int) s.length(); i++){
		
		//printf("s[%d] = %c\n", i, s[i]);

		if(s[i] == '('){
			if(!pilha.empty() && pilha.top() == '('){
				cont++;
			}
			else{
				pilha.push(s[i]);
			}
		}else if(s[i] == ')'){
			if(!pilha.empty() && pilha.top() == '('){
				pilha.pop();
			}
			else{
				cont++;
			}
		}else if(eh_pontuacao(s[i])){
			while(!pilha.empty()){
				pilha.pop();
				cont++;			}
		}
	}

	printf("%d\n", cont);
return 0;
}


