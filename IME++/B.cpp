#include <bits/stdc++.h>
using namespace std;
string a, b;
vector <int> la[30];
vector <int> lb[30];

int memo[1010][1010];

int pd (int p , int q){	

	if(p == a.size() || q == b.size() )
		return 0;
	
	
	if(memo[p][q] == -1){

		int ind =  a[p] - 'a' ;
		int pos = -1;

		for(int i = 0 ; i < lb[ ind ].size() ; i++){
			if(lb[ind][i] >= q){
				pos = lb[ind][i];
				break;
			}
		}

		int a = -1, b = -1;

		if( pos != -1)
			a = pd(p+1, pos+1) + 1 ;
		 b = pd(p+1, q);
		
		memo[p][q] = max(a,b);
	}

	return memo[p][q];

}


int main (){
	cin >> a;
	cin >> b;
	
	for(int i = 0 ; i < a.size() ; i++)
		la[a[i] - 'a'].push_back(i);
	
	for(int i = 0 ; i < b.size() ; i++)
		lb[b[i] - 'a'].push_back(i);
	


	for(int i = 0 ; i <= 1000 ; i++ )
		for(int j = 0 ; j <= 1000 ; j++)
			memo[i][j] = -1;

	printf("%d\n", pd(0, 0));
	
}
