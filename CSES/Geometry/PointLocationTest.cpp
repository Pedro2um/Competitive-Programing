#include <bits/stdc++.h>
using namespace std;
#define fast_io	ios_base::sync_with_stdio(0);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
int t;
ll cross(ll x1, ll y1, ll x2, ll y2){
	return x1*y2 - x2*y1;
}
int main(){
	fast_io;
	cin>>t;
	while(t--){
		ll x1,y1;
		ll x2,y2;
		ll x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		ll res = cross(x3-x1,y3-y1,x3-x2,y3-y2);
		if(res > 0) cout<<"LEFT\n";
		else if(res < 0) cout<<"RIGHT\n";
		else cout<<"TOUCH\n";	
		
	}
 
 
	return 0;
}
