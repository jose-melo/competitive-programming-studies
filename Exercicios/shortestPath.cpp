#include <bits/stdc++.h>
using namespace std;


char rei[2], t[2];

char troca(char ch){

	switch (ch){

		case 'D':
			return 'U';


		case 'R':
			return 'L';

		case 'U':
			return 'D';

		case 'L':
			return 'R';

	}
return 0;
}

int main(){

	int cont = 0;

	scanf(" %c %c", &rei[0], &rei[1]);

	scanf(" %c %c", &t[0], &t[1]);

	stack<pair<char, char>> pilha;



	while(t[0] != rei[0] && t[1] != rei[1]){
		/*printf("t = %c%c\nrei = %c%c\n", t[0], t[1], rei[0], rei[1]);*/
		if(t[0] != rei[0] && t[1] != rei[1]){
			if(t[1] > rei[1]){

				t[1] -= 1;
				if(t[0] > rei[0]){
					t[0] -= 1;
					pilha.push(make_pair('L','D'));
					cont++;
				}
				else{
					t[0] += 1;
					pilha.push(make_pair('R','D'));
					cont++;
				}
			}else{
				t[1] += 1;
				if(t[0] > rei[0]){
					t[0] -= 1;
					pilha.push(make_pair('L','U'));
					cont++;
				}
				else{
					t[0] += 1;
					pilha.push(make_pair('R','U'));
					cont++;
				}
			}
		}

	}


		if(t[0] == rei[0]){

			while(t[1] != rei[1]){

		/*printf("t = %c%c\nrei = %c%c\n", t[0], t[1], rei[0], rei[1]);*/
				if(t[1] > rei[1]){
					t[1] -= 1;
					pilha.push(make_pair('D',0));
					cont++;

				}
				else{
					t[1] += 1;
					pilha.push(make_pair('U',0));
					cont++;				
				}
			}
		}else{

			while(t[0] != rei[0]){
		/*printf("t = %c%c\nrei = %c%c\n", t[0], t[1], rei[0], rei[1]);*/
				if(t[1] == rei[1]){
					if(t[0] > rei[0]){

						pilha.push(make_pair('L',0));
					cont++;
						t[0] -= 1;
					}
					else{
						t[0] += 1;
						pilha.push(make_pair('R',0));
					cont++;	
					}
				}
			}
		}
		

	printf("%d\n", cont);


	while(!pilha.empty()){
		pair<char, char> aux;

		aux = pilha.top();
		pilha.pop();

		aux.first = troca(aux.first);
		aux.second = troca(aux.second);
	if(aux.second != 0)
		printf("%c%c\n",aux.first, aux.second);
	else
		printf("%c\n",aux.first);
	}

return 0;
}
