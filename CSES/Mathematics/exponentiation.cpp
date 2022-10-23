#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD	( (int)1e9 + 7)
 
ll fast_power(ll a, ll b){
	
	ll ans = 1LL;
 
	while(b){
		if( b & 1) ans = (ans * a) % MOD;
		a = (a * a)%MOD;
		b >>=1LL;
	}
	return ans;
}
 
int main(){
	int n;	
	scanf("%d", &n);
	while(n--){
		ll a, b;
		scanf("%lld %lld",&a, &b);
		printf("%lld\n", fast_power(a,b));
	}
 
	return 0;
}
