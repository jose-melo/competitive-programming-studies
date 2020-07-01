

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

string getTitle(string a){
	
	string s = a.substr(a.find('\"'), a.substr(a.find('\"')+1, a.size()).find('\"')+2);

	return s;
}

string getAuthor(string a){
	string s = a.substr(a.find("by ")+3,a.size());
	return s;
}

int main(){

	vector<string> v;

	string s, a;

	getline(cin, a);
	


	while(s != "END"){
		v.pb(s);
		cin >> s;
	}


	sort(v.begin(), v.end(), func);






}


