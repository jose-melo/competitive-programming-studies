#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int matrizAdj[110][110];
int caminho[110];
int n, m;
int dist[110];
int visitado[110];	
int aux[110][110];
int dist2[110];


void BFS(int x){
   
	queue<int> fila;
    visitado[x] = 1;
	dist[x] = 0;

	fila.push(x);	
    while(!fila.empty()){
    	int v = fila.front();
        fila.pop();
        for (int i = 1; i <= n; i++){
			if(aux[v][i] == 0)continue;
			if (visitado[i] == 0){
                visitado[i] = 1;
                fila.push(i);
			
				if(dist[i] > dist[v] + 1)
					dist[i] = dist[v] + 1;
			}
        }
    }
}

void atualiza(){
	
	for(int i = 0; i <= n; i++){
		dist[i] = INF;
		visitado[i] = 0;
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			aux[i][j] = matrizAdj[i][j];

}



int main(){

	cin >> n;
	string s;
	for(int i = 1; i <= n; i++){
			cin >> s;	
			for(int j = 0; j < s.size(); j++){
				matrizAdj[i][j+1] = s[j] - '0';
				aux[i][j+1] = matrizAdj[i][j+1];
			}
	}

	cin >> m;
	for(int i = 1; i <= m; i++)	
		cin >> caminho[i];

	for(int i = 1; i <= m; i++)
		dist2[i] = dist[i];
	vector<int> resp;
	resp.pb(caminho[1]);
	for(int i = 2; i < m; i++){
		atualiza();

		for(int j = 1; j <= n; j++){
			aux[caminho[i]][j] = 0;
			aux[j][caminho[i]] = 0;
		}
		BFS(caminho[1]);

		if(dist[caminho[i+1]] < dist2[caminho[i]] + 1)
			resp.pb(caminho[i]);
	}

	resp.pb(caminho[m]);
		
	cout << resp.size() << endl;

	for(auto x : resp)
		cout << x << " ";
	cout << "\n";



return 0;
}




