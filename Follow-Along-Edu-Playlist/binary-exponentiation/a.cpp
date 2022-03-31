#include <bits/stdc++.h>
using namespace std;
// binary exponentiation
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;

ll slow_power_modulo(ll a, ll b, ll m){
       ll result = 1LL;
        for(ll i = 0; i < b; i++){
                result = (result*a) % m;
        }
        return result; 
}

// recursive function with both a and b being long long will result in stack overflow
// one of the many reasons for using dynamic programing
ll i_fast_power_modulo(ll a, ll b, ll m){
        ll ans = 1LL;
        while(b){
                if(b&1) ans = (ans * a) % m;
                a = (a*a) % m;
                b >>= 1LL;
        }
        return ans;
}

int  main(){
        ll x, y, MOD;
        cin >> x >> y >> MOD;
        cout << i_fast_power_modulo(x, y, MOD) << "\n";
        cout << slow_power_modulo(x, y, MOD) << "\n";
        return 0;
}
