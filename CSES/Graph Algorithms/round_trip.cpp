#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[2 * (int)1e5 + 1];
vector<int> v((int)1e5 + 1);
vector<int> f((int)1e5 + 1);
vector<int> p((int)1e5 + 1);
vector<int> path;
set<int> used;
bool done = false;
void dfs(int x){
	v[x] = 1;
	for(int y: adj[x]){
		if(p[y] == 0) p[y] = x;
		if(v[y] == 0){
			dfs(y);
		}
		else if(f[y] == 0 && !done && p[x] != y){
			//back edge
			done = true;
			int e = x;
			for(int w = x; y != w; w = p[w]){
				path.push_back(w);
			}
			path.push_back(y);
			path.push_back(e);	
		}
		if(done) return;	
	}
	f[x] = 1;	
}
 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i =1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);	
		adj[b].push_back(a);	
	}
	p[1] = -1;	
	for(int i = 1; i <=n && !done; i++){
		if(v[i] == 0){
			dfs(i);
		}	
	}		
	if(!done){
	       	cout << "IMPOSSIBLE\n";
		return 0;
	}
	int s = (int)path.size();
	int i = 0;
	cout << s << "\n";
	for(auto x: path){
		cout << x;
		if(i != s-1) cout << " ";
		++i;
	}
	cout << "\n";
		
	return 0;
}
