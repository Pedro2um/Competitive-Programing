#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[2 * (int)1e5 + 1];
vector<int> t((int)1e5 + 1);
vector<int> p((int)1e5 + 1);
set<pair<int,int>> s;
void dfs(int x){
	t[x] = ( ( t[ p[x] ] == 1)? 2: 1); 
	for(auto y: adj[x]){
		p[y] = x;
		if(t[y] == 0){
			dfs(y);
		}
	}	
}
 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i =1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		s.insert(make_pair(a,b));
		s.insert(make_pair(b,a));
	}
	
	for(int i = 1; i <= n; i++){
		for(auto y: adj[i]){
			for(auto w: adj[y]){
				pair<int,int> temp = {i, w};
				if( s.count(temp) ){
					cout << "IMPOSSIBLE\n";
					return 0;
				}
			}
		}
	}
	
	p[1] = 1;	
	for(int i =1; i<=n; i++){
		if(t[i] == 0){
			dfs(i);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << t[i];
		if(i!=n) cout << " ";
	}
	cout << "\n";
	return 0;
}
