#include <bits/stdc++.h>
using namespace std;
#define 	MAX(a,b)	(((a)>(b))?(a):(b))
typedef long long ll;
 
int T;
ll X, Y; // X column and Y row
 
ll solve(ll x, ll y);
 
int main(){	
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &X, &Y);
		printf("%lld\n", solve(X, Y));
	}
}
 
ll solve(ll x, ll y){
	ll a = MAX(x, y) - 1; // because we have 0 index matrix
	
	// is Odd?
	if(a&1){
		if(x < y) 	return ( (a*a) + x );
		else 		return ((a*a) + 2*a - y+2);
	} else {
		if(x < y)	return ((a*a) + 2*a - x+2);
		else 		return ( (a*a) + y );
	}
}
