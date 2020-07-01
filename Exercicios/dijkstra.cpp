#include <bits/stdc++.h>
using namespace std;


#define ii pair<long long int, int>
#define INF 1000000000000000000
#define MAX_N 101000
#define NILL -1

vector<ii> listAdj[MAX_N];

vector<int> resp;

long long int d[MAX_N];
int pais[MAX_N];

int V, E;

void initialize(){
	int i;
	for(i = 1; i <= V; i++){
		d[i] = INF;
		pais[i] = NILL;
	}
}

void Dijkstra(int orig){

	initialize();

	set<ii> pq;

	ii s;
	s.first = 0;
	s.second = orig;

	d[orig] = 0;
	
	pq.insert(s);

	while(!pq.empty()){

		ii x = *(pq.begin());
		pq.erase(pq.begin());

		int node = x.second;

		for(auto u = listAdj[node].begin(); u < listAdj[node].end(); u++){
		

			if(d[u->second] > d[node] + u->first){

				pq.erase(ii(d[u->second], u->second));
				d[u->second] = d[node] + u->first;
				
				pais[u->second] = node;
				pq.insert(make_pair(d[u->second], u->second));
			}
		}
	}
}

void Path(int orig, int dest, int *control){

	if(orig == dest){
		resp.push_back(orig);
		return;
	}
	
	if(pais[dest] == NILL){
		*control = 1;
		return;
	}
	Path(orig, pais[dest], control);
	resp.push_back(dest);
return;
}

int main(){

	int a, b, control = 0;
	long long int c;

	scanf("%d %d", &V, &E);

	for(int i = 0; i < E; i++){
		scanf("%d %d %lli", &a, &b, &c);
		listAdj[a].push_back(make_pair(c, b));
		listAdj[b].push_back(make_pair(c, a));
	}


	Dijkstra(1);

	resp.clear();

	Path(1, V, &control);
	
	if(control == 0){
		for(auto x = resp.begin(); x < resp.end(); x++){
			printf("%d ", *x);			
		}
		printf("\n");
	}else{
		printf("-1\n");
	}


return 0;
}











