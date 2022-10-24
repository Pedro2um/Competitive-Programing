#include <bits/stdc++.h>
using namespace std;
 
vector<int> adj[2 * (int)1e5 + 1];
vector<int> numero((int)1e5 + 1);
vector<int> f((int)1e5 + 1);
vector<int> p((int)1e5 + 1);
vector<int> v((int)1e5 + 1);
 
bool flag = false;
void dfs_top(int x, int* num){
	v[x] = 1;
	for(int w: adj[x]){
		if(v[w] == 0){
			dfs_top(w, num);
		}
		else if(f[w] == 0){
			cout << "IMPOSSIBLE\n";
			flag = true;
			return;
		}
	}
	f[x] = 1;
	numero[x] = *num;
	*num = (*num) - 1;	
}
 
 
void top_sort(int n){
	int* num = new int;
        *num = n;
	for(int i  = 1; i<=n; i++){
		if(v[i] == 0){
			dfs_top(i, num);
		}
	
	}
	delete num;
}
 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i =1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);	
	}
	top_sort(n);
	if(flag) return 0;	
	vector<pair<int,int>> ans;	
	for(int i = 1; i <= n; i++){
		ans.push_back( make_pair(numero[i],i) );
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); i++){
		cout << ans[i].second;
		if(i != n-1 ){
			cout << " ";
		}
	}
	cout << "\n";
	
	return 0;
}
