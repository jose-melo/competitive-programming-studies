#include <bits/stdc++.h>
using namespace std;


#define  ii pair <int, int>
#define MAX_N 10500
#define INF 100000000

int V, E;

vector<ii> listAdj[MAX_N];

int d[MAX_N];

void initialize(){

	int i;
	for(i = 0; i <= V; i++)
		d[i] = INF;
}

void Dijkstra(int orig){

	/*printf("INICIO DO DIJKSTRA\n");
*/
	set<ii> pq;

	ii s;
	s.first = 0;
	s.second = orig;

	initialize();

	d[orig] = 0;
	pq.insert(s);

	while(!pq.empty()){

		set<ii> :: iterator x = pq.begin();

		int x_id = x->second;

		pq.erase(pq.begin());

		/*printf("x = (%d, %d)\n",x->first, x->second);*/


		for(int u = 0; u < listAdj[x_id].size(); u++){

			/*printf("x->second = %d u = %d\n",x->second, u);

			printf("### u = (peso até x %d, %d) d[u] = %d \n",listAdj[x_id][u].first, listAdj[x_id][u].second, d[listAdj[x_id][u].second]);
*/
			if(d[listAdj[x_id][u].second] > d[x_id] + listAdj[x_id][u].first){
				d[listAdj[x_id][u].second] = d[x_id] + listAdj[x_id][u].first;
				/*printf("###### insert (%d, %d)\n",d[listAdj[x_id][u].second], listAdj[x_id][u].second);*/
				pq.insert(make_pair(d[listAdj[x_id][u].second], listAdj[x_id][u].second));
			}
		}
	}
}

int main(){

	int i, num, j, a, b, c, x, y;

	ii aux;

	scanf("%d", &num);

	for(i = 0; i < num; i++){

		scanf("%d %d", &V, &E);

		for(j = 0; j < E; j++){
			scanf("%d %d %d", &a, &b, &c);
			
			aux.first = c;
			aux.second = b;
			listAdj[a].push_back(aux);
		}

		scanf("%d %d", &x, &y);

		/*printf("BUNGA\n");
		for(int u = 0; u < listAdj[1].size(); u++)
			printf("%d ", listAdj[1][1].second);
		printf("\n");*/

		Dijkstra(x);

	if(d[y] != INF)
		printf("%d\n",d[y]);
	else
		printf("NO\n");

	for(int k = 0; k < V; k++)
		listAdj[k].clear();

	}

return 0;
}


