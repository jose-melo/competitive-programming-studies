#include <bits/stdc++.h>
using namespace std;


#define ii pair<int, int>
#define INF 1000000000
#define MAX_N 100000


vector<ii> listAdj[MAX_N];

int d[MAX_N];
int pais[MAX_N];

int V, E;

void initialize(){
	int i;
	for(i = 0; i <= V; i++){
		d[i] = INF;
		pais[i] = NULL;
	}
}

bool comparator(){


}


void Dijkstra(int orig){

	initialize();

	priority_queue<int, vector<ii>, greater<int>> pq;

	ii s;
	s.first = 0;
	s.second = orig;

	d[orig] = 0;
	
	pq.push(s);


	while(!pq.empty()){

		ii x = pq.top();
		pq.pop();

		int node = x.second

		for(auto u = listAdj[node].begin(); u < listAdj[node].end(); u++){
			if(d[u->second] > d[node] + u->first){
				d[u->second] = d[node] + u->first;
				pais[u->second] = node;

				pq.push(make_pair(d[u->second], u->second));
			}
		}
	}
}

void printPath(int orig, int dest){

	if(orig == dest){
		printf("%d ", orig);
		return;
	}
	
	if(pais[dest] == NULL)return;

	printPath(orig, pais[dest]);
	printf("%d ", dest);
return;
}

int main(){

	int a, b, c;

	scanf("%d %d", &V, &E);

	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &a, &b, &c);
		listAdj[a].push_back(make_pair(c, b));
		listAdj[b].push_back(make_pair(c, a));
	}


	Dijkstra(1);

	printf("\n");
	printPath();
	printf("\n");

return 0;
}











