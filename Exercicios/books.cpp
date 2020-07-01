#include <bits/stdc++.h>
using namespace std;


int main(){

	int num_livros, tempo, i, p = 0, q = 0, max_tempo = 0, max_livro;

	scanf("%d %d", &num_livros, &tempo);

	vector<int> livros(num_livros);


	for(i = 0; i < num_livros; i++)
		scanf("%d", &livros[i]);

	while(max_tempo <= tempo && q < num_livros){
		max_tempo += livros[q];
		q++;
	}
	if(max_tempo > tempo){
		q--;
		max_tempo -= livros[q];
	}


	max_livro = q - p;

	for(i = 1; i < num_livros; i++){
		
		if(p != q){
			max_tempo -= livros[p];
			p++;
		}else{
			p++;
			q++;
		}
		
		while(max_tempo <= tempo && q < num_livros){
			max_tempo += livros[q];
			q++;
		}
		if(max_tempo > tempo){
			q--;
			max_tempo -= livros[q];
		}
		
		if(max_livro < q - p)max_livro = q - p;
	}

	printf("%d\n", max_livro);

return 0;
}