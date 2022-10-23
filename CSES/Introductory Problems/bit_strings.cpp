#include <bits/stdc++.h>
using namespace std;
const long long MOD	= 1e9+7; // 10**9 + 7
// O(long n) time, O(1) space
long long fastPower(long long a, long long int b){
	long long res = 1;
	while(b){
		if(b&1) 
			res = (res*a)%MOD;
		a= (a*a)%MOD; // 3² % MOD, 3⁴ % MOD, 3⁸ % MOD
		b >>= 1; // Equal to b/=2
	}	
	return res;
}
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << fastPower(2, n); 
return 0;
}
