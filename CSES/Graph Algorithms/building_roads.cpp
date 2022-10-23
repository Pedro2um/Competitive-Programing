#include <bits/stdc++.h>
using namespace std;
 
vector<bool> v((int)1e5);
vector<int> adj[2 * (int)1e5];
vector<int> c;
 
void dfs(int a){
	v[a] = true;	
	for(int x: adj[a])
		if(v[x] == false)
			dfs(x);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		c.push_back(i+1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> cc;	
	int cnt = 0;
	for(int x: c){
		if(v[x] == false){
			cc.push_back(x);	
			cnt++;
			dfs(x);
		}			
	}
	cout << cnt - 1 << "\n";
	if(cnt!=0)
		for(int i = 0; i+1 < (int)cc.size(); i++)
			cout << cc[0] << " " << cc[i+1] << "\n";
	
	
}
