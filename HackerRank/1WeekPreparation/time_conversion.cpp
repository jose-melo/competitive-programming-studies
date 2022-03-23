#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

string s;

int main(){


    getline(cin, s);

    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    int second = stoi(s.substr(6, 2));
    string format = s.substr(8, 2);

    if(format == "AM"){
        if(hour == 12)
            hour=0;

    }else{
        if(hour < 12)hour += 12;
    }
    
    printf("%02d:%02d:%02d\n", hour, minute, second);

}

