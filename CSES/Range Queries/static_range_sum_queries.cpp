#include <bits/stdc++.h>
#define dbg(x)	cout<<" "<<#x <<" = " <<x
#define MOD	(long long)(1e9 + 7)
 
typedef long long ll;
typedef long long unsigned llu;
typedef long double ld;
using namespace std;
 
 
 
int h[]={0, 1, 1, 1, 0, -1, -1, -1};
int v[]={1, 1 , 0, -1, -1, -1, 0, 1};
 
 
void solve(){
	ll n, q;
	cin>>n>>q;
	ll prefix[n+1]={0};
	for(ll i =1; i <= n; i++){
		ll x;
		cin>>x;
		prefix[i]=prefix[i-1LL]+x;	
	}
	for(ll j =1; j <= q; j++){
		ll a, b;
		cin>>a>>b;
		cout<<prefix[b]- prefix[a-1]<<"\n";
	}
 
	
 
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);		
	/*int t;
	cin>>t;
	while(t--){
		
	}*/
 
	solve();
	return 0;
 
}
