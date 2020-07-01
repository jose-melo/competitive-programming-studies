#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define INF 1000000000
#define mod 1000000007
#define ll long long int


int main(){

	string a, b;

	getline(cin, a);

	printf("%s\n", a.c_str());

	if(b.empty())printf("teste\n");

	if(a > b)printf("OI\n");

	reverse(a.begin(), a.end());

	printf("%s\n", a.c_str());

return 0;
}