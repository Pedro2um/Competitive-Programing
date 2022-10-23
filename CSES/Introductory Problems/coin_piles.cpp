#include <bits/stdc++.h>
using namespace std;
 
#define fast_io     ios_base::sync_with_stdio(false);cin.tie(NULL)
int main(){
    fast_io;
    int t; cin >> t;
    int a, b;
 
    while(t--){
        cin >> a >> b;
        
        if( a > 2*b || b > 2*a || (a+b) % 3 != 0) cout  << "NO\n";
        else cout << "YES\n"; 
    
    }
 
 
return 0;
}
