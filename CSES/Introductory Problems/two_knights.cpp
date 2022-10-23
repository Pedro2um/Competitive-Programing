#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int main(){
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++){
                ll nCr = ( (i*i) * ( (i * i) - 1) )/2;
                ll inv_p = 4 * (i-1)*(i-2);
                ll ans = nCr - inv_p;
                printf("%lld\n", ans);
        }
        return 0;
}
