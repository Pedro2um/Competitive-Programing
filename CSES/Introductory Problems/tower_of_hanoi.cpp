#include <bits/stdc++.h>
using namespace std;
 
int total;
void _move(int n, int s, int t){
 
	if(n == 1){
		printf("%d %d\n", s, t);
		return;
	}
	int aux = 6 - s - t; // pois o algoritmo se baseia em toh de 2 discos, o caso de n=1 
			     // já foi tratado
	_move(n-1, s, aux);
	printf("%d %d\n", s, t);
	_move(n-1, aux, t);	
}
 
int main(){
	
	int n;
	scanf("%d", &n);
	printf("%d\n", (1<<n)-1);
	_move(n, 1, 3);
return 0;
}
