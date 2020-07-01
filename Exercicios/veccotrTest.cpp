#include <bits/stdc++.h>
using namespace std;


#define MAX_N 1000000
#define ll long long int

string a, b, c;


int main(){


	int n, aux;

	getline(cin, a);
	//cout << a << "\n";

	/*for(int i = 0; i < n; i++){
		scanf("%d", &aux);
		a.push_back(aux);
	}*/


	getline(cin, b);
	//cout << b << "\n";


	/*for(int i = 0; i < n; i++){
		scanf("%d", &aux);
		b.push_back(aux);
	}*/

	/*printf("a: ");
	for(auto i = a.begin(); i < a.end(); i++)
		printf("%d ", *i);
	printf("\n");*/

	/*printf("b: ");
	for(auto i = b.begin(); i < b.end(); i++)
		printf("%d ", *i);
	printf("\n");*/

	a.append(b);
	

	cout << a << "\n";

	string :: iterator it = a.begin();
	it++;
	printf("TESTE: %c\n",a.at(4 - 1));


	/*printf("a: ");
	for(auto i = a.begin(); i < a.end(); i++)
		printf("%d ", *i);
	printf("\n");*/


return 0;
}
