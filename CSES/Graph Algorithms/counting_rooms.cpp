#include <bits/stdc++.h>
using namespace std;
#define		in_range(w, z)		(w >= 0 && w < z)
int h[] = {0, 1, 0, -1}; // j
int v[] = {-1, 0, 1, 0}; // i
 
char visited[1001][1001];
int n, m;
 
void dfs(int i, int j){
	visited[i][j] = true;	
	for(int k = 0; k < 4; k++){
		int y = h[k]+j;
		int x = v[k]+i; 
		if( in_range(y, m) && in_range(x, n) && visited[x][y] == false){
			dfs(x,y);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){	
			char x;
			cin >> x;
			visited[i][j] = (x=='.'?false:true);
		}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j]==false){
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
 
}
