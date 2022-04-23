#include <bits/stdc++.h>
using namespace std;

//#define         fast_io         ios_base::sync_with_stdio(false);cin.tie(NULL)
#warning  TODO: Remember about bigger N
const int MAX_N = 1e6 + 5; //
int a[MAX_N];
int main(){
        //fast_io;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
                scanf("%d", &a[i]);
        }
        sort(a + 1, a+n+1);
        printf("%d\n", a[2]);
        return 0;
}