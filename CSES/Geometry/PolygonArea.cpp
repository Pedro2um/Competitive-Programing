#include <bits/stdc++.h>
using namespace std;
#define fast_io	ios_base::sync_with_stdio(0);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
int n;
 
ll cross(pair<ll,ll> a, pair<ll,ll> b){
	return (  ( (a.first)*(b.second) ) -  ( (b.first)*(a.second) ) );
}
 
int main(){
	fast_io;
	cin>>n;
	vector<pair<ll,ll>> p(n+1);
 
	for(int i = 1; i <= n ; i++){
		ll x, y;	
		cin>>x>>y;
		p[i].first = x;
		p[i].second = y;
	}
	
	ll area = 0;
 
	for(int i = 1; i <= n-1; i++){
		area += (cross(p[i],p[i+1]));
	}
 
	area += (cross(p[n], p[1]));
	
	if(area < 0) area *= -1LL;
	cout<<area<<"\n";	
	return 0;
}
