#include <bits/stdc++.h>
using namespace std;
 
vector<bool> v((int)1e5 + 1);
vector<int> adj[2 * (int)1e5 + 1];
vector<int> d((int)1e5 + 1, INT_MAX);
vector<int> p((int)1e5 + 1, -1);
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	queue<int> q;
	
	q.push(1);	
	
	v[1] = true;
	d[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
 
		if(u == n){
			v[u] = true;
			break;
		}
		for(int x: adj[u]){
			if(v[x] == false){
				q.push(x);
				v[x] = true;
				d[x] = d[u] + 1;
				p[x] = u;
			}
		}
	}
	
	if(v[n] == false){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << d[n]+1 << "\n";
	vector<int> path;
	for(int a = n; a != -1; a = p[a]){
		path.push_back(a);
	}
	reverse(path.begin(), path.end());
	for(int x: path){
		cout << x << " ";	
	}
	cout << "\n";
	
}
