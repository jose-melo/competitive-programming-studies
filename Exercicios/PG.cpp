#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

char chares[MAX_N];

vector<int> listAdj[MAX_N];

int visitado[MAX_N];

int n, m;


void dfs(int node, char ch, int *num){

	if(visitado[node] == 1)return;

	visitado[node] = 1;
	chares[node] = ch;
	(*num)++;

	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		if(visitado[*x] == 0){
			dfs(*x, ch, num);
		}
	}
}


void dfs2(int node, int* cont){

	if(visitado[node] == 1)return;

	visitado[node] = 1;
	(*cont)++;

	for(auto x = listAdj[node].begin(); x < listAdj[node].end(); x++){
		if(visitado[*x] == 0){
			dfs2(*x, cont);
		}
	}
}

void reset(){
	int i;
	for(i = 0; i <= n;i++)
		visitado[i] = 0;
}



void imprime2(){

	int i;

	for(i = 1; i <= n; i++)
		printf("%c", chares[i]);
return;
}

int main(){

	int i, a, b, control, aha = 0, cont = 0, num_a = 0, num_c = 0, num_b = 0;
	
	scanf("%d %d", &n, &m);

	for(i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		listAdj[a].push_back(b);
		listAdj[b].push_back(a);
	}

	dfs2(1, &cont);

	reset();

	for(i = 1; i <= n; i++){
		if(listAdj[i].size() == n - 1){
			chares[i] = 'b';
			num_b++;
			visitado[i] = 1;
			aha = 1;
		}
	}

	control = 0;

	if(aha == 0 && cont == n)
		control = 4;



	for(i = 1; i <= n && control != 4; i++){
		/*printf("chares[i = %d] = %d control = %d visitado[i] = %d\n",i, chares[i], control, visitado[i]);*/
		if(visitado[i] == 0 && chares[i] == 0 && control == 0){
			dfs(i, 'a', &num_a);
			control = 1;
			/*printf("pintei o a i = %d num_a = %d\n", i, num_a);*/
		
		}

		if(visitado[i] == 0 && chares[i] == 0 && control == 1){
			dfs(i, 'c', &num_c);
			control = 2;
			/*printf("pintei o a i = %d num_c = %d\n", i, num_c);*/
			
		}

		if(control == 2 && chares[i] == 0){
			control = 4;
		}
	}


	if(aha == 0 && control == 2){
		for(i = 1; i <= n && control != 4; i++){
			if(chares[i] == 'a' && listAdj[i].size() != num_a - 1)
				control = 4;
			if(chares[i] == 'c' && listAdj[i].size() != num_c - 1)
				control = 4;
		}
	}

	if(aha == 1 && control != 4){
		for(i = 1; i <= n && control != 4; i++){
			if(chares[i] == 'a' && listAdj[i].size() != num_a + num_b - 1)
				control = 4;
			if(chares[i] == 'c' && listAdj[i].size() != num_c + num_b - 1)
				control = 4;
		}

	}



	reset();

	if(control == 4){
		printf("No\n");
	}else{
		printf("Yes\n");
		imprime2();
	}
	printf("\n");

return 0;
}







