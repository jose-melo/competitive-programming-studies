#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_STAGE 1000

typedef struct sho
{
	int start, end, gold, stage;
	
} show;

int memo[(1<<10)+10][86400];
int go[1100];
vector<show> shows;

int num_stages, num_shows;

bool comp(show a, show b){
	if(a.start < b.start)
		return true;
return false;
}

bool comp2(show a, int b){
	if(a.start < b)
		return true;
return false;
}

int pd(int stages_state, int index){
	
	//printf("stages_state = %d index = %d\n", stages_state, index);
	if(index == shows.size())
		if(stages_state != (1<<num_stages)-1 || stages_state == 0)
			return -INF;
		else
			return 0;

	if(memo[stages_state][index] != -1)
		return memo[stages_state][index];

	memo[stages_state][index] = -INF;
	//printf("pointer = %d %d %d %d\n", pointer->start, pointer->end, pointer->gold, pointer->stage);
	

	show atual = shows[index];
	int stages_state_aux = stages_state | (1<<atual.stage);	

	memo[stages_state][index]  = max(memo[stages_state][index],max(
								 pd(stages_state_aux, go[index]) + atual.gold, pd(stages_state, index+1)));
	//printf("returned %d\n", memo[stages_state][atual_time]);
return memo[stages_state][index];
}

int main(){

	int stt, ed, gd, prox_i, x_i;

	cin >> num_stages;

	for(int i = 0; i < num_stages; i++){
		cin >> num_shows;
		for(int j = 0; j < num_shows; j++){
			cin >> stt >> ed >> gd;
			show adder;
			adder.start = stt;
			adder.end = ed;
			adder.gold = gd;
			adder.stage = i;
			shows.push_back(adder);
		}
	}

	sort(shows.begin(), shows.end(), comp);

	/*printf("shows: ");
	for(int i = 0; i < shows.size(); i++)
		printf("%d ", shows[i].start);
	printf("\n");
*/

	for(int i = 0; i < shows.size(); i++)
		go[i] = shows.size();


	for(int i = 0; i < shows.size(); i++)
		for(int j = i+1; j < shows.size(); j++){
			if(shows[i].end <= shows[j].start){
				go[i] = j;
				break;
			}
		}

	/*printf("go: ");
	for(int i = 0; i < shows.size(); i++)
		printf("%d ", go[i]);
	printf("\n");*/


	for(int i = 0; i <= (1<<num_stages);i++)
		for(int j = 0; j < 1100; j++)
			memo[i][j] = -1;

	int resposta = pd(0, 0);
	if(resposta > 0)
		cout << resposta << endl;
	else
		cout << "-1" << endl;

return 0;
}







