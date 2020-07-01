#include <bits/stdc++.h>
using namespace std;


#define  ii pair <int, int>
#define MAX_N 10500
#define INF 100000000

int V, E, T, S;

vector<ii> listAdj[MAX_N];

int d[MAX_N];

void initialize(){

	for(int i = 0; i <= V; i++)
		d[i] = INF;

}



void Dijkstra(int orig){


	set<ii> pq;

	ii s;

	s.second = orig;
	s.first = 0;

	initialize();

	d[orig] = 0;
	pq.insert(s);

	while(!pq.empty()){

		set<ii> :: iterator it;
		it = pq.begin();
		int node = it->second;

		pq.erase(pq.begin());

		/*printf("node = %d\n",node);*/

		for(auto u = listAdj[node].begin(); u < listAdj[node].end(); u++){

			/*printf("u = (%d, %d)\n", u->first, u->second);*/

			if(d[u->second] > d[node] + u->first){
				/*printf("BONGA\n");*/
				d[u->second] = d[node] + u->first;
				pq.insert(make_pair(d[u->second], u->second));
			}
		}
	}
}


/*void imp(){

	int i;

	printf("\n");
	for(i = 1; i <= V; i++)
		printf("d[%d] = %d", i, d[i]);
	printf("\n");
return;
}*/

int main(){

	int i, a, b, c, cont = 0;

	scanf("%d %d %d %d", &V, &S, &T, &E);

	for(i = 0; i < E; i++){
		scanf("%d %d %d", &a, &b, &c);
		listAdj[b].push_back(make_pair(c, a));
	}


	Dijkstra(S);

	/*imp();*/

	sort(d + 1, d + V + 1);

	/*imp();*/

	for(i = 1; d[i] <= T; i++)
		cont++;


	printf("%d\n", cont);
return 0;
}






