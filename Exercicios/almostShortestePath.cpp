#include <bits/stdc++.h>
using namespace std;

#define ii pair<long long int, int>
#define INF 1000000000000000000
#define MAX_N 1000
#define NILL -1

vector<ii> listAdj[MAX_N];

long long int d[MAX_N];
vector<int> pais[MAX_N];

map<ii, ii> arestas;

int V, E, S, D, melhor;

int initialize(){
	for(int i = 0; i <= V; i++){
		d[i] = INF;
	}
}

void imp(set<ii> pq){

	set<ii> aux = pq;

	while(!aux.empty()){
		printf("(%lli %d ) ", (aux.begin())->first, (aux.begin())->second);
		aux.erase(aux.begin());
	}

}

void Dijkstra(int orig){


	set<ii> pq;

	initialize();


	ii s;
	s.first = 0;
	s.second = orig;


	d[orig] = 0;
	pq.insert(s);

	while(!pq.empty()){

		//printf("INICIO DO WHILE\n");
		//printf("\n");

		ii x = *(pq.begin());
		pq.erase(pq.begin());
		//printf("SEGUNDA IMPRESSAO");imp(pq);
		int node = x.second;

		//printf("node = %d\n", node);

		for(int p = 0; p <= V; p++){
			//if(node == 6)printf("BOGA\n");
			auto y = arestas.find({node, p});

			int u = (y->second).first;
			int v = (y->second).second;

			if(y != arestas.end()){
				if(d[u] >= d[node] + v){
				//	printf("achei (%d, %d) (y->first).first = %lli (y->first).second = %d (y->second).first = %lli (y->second).second = %d\n",node, p, (y->first).first, (y->first).second, (y->second).first, (y->second).second);

					pq.erase(ii(d[u], u));
					if(d[u] > d[node] + v)
						if(!pais[u].empty())pais[u].erase(pais[u].end() - 1);
					pais[u].push_back(node);
					d[u] = d[node] + v;
					pq.insert(make_pair(d[u], u));
				}
			}

			//if(pq.empty())printf("CUTUAR TEU BOGA\n");
		}
	}
}


int main(){

	int a, b, c;

	scanf("%d %d", &V, &E);

	while(V != 0 && E != 0){
		scanf("%d %d", &S, &D);

		for(int i = 0; i < E; i++){
			scanf("%d %d %d", &a, &b, &c);
			arestas[{a, b}] = make_pair(b, c);
		}


		Dijkstra(S);


		melhor = d[D];


		int aux = D;
		while(aux != S && !pais[aux].empty()){

			for(auto h = pais[aux].begin(); h < pais[aux].end();h++)
				arestas.erase(make_pair(*h, aux));
			if(!pais[aux].empty())aux = pais[aux][0];
		}

		//auto y = arestas.find({3, 6});

		//if(y == arestas.end()){printf("bhu\n");return 0;}

		while(d[D] == melhor){

			Dijkstra(S);

			int aux = D;
			while(aux != S){

				for(auto h = pais[aux].begin(); h < pais[aux].end(); h++)
					arestas.erase(make_pair(*h, aux));
				if(!pais[aux].empty())aux = pais[aux][0];
			}
		}

	if(d[D] != INF)
		printf("%lli\n", d[D]);
	else
		printf("-1\n");
	arestas.clear();

	for(int j = 0; j <= V; j++){
		pais[j].clear();
	}

	initialize();

		scanf("%d %d", &V, &E);
	}
}

