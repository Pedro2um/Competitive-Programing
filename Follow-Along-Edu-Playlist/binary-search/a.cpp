#include <bits/stdc++.h>
using namespace std;
// binary exponentiation
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x)          x.begin(),x.end()
typedef long long ll;
typedef long double ld;

bool    my_i_binary_search(vector<ll>& a, ll target){        
        ll l = 0, r = a.size()-1;
        while(l <= r){
                ll m = l + ((r-l)/2);

                if(a[m] == target){
                        return true;
                }
                else if(a[m] < target){
                        l = m + 1;
                }
                else {
                        r = m - 1;
                } 
        }
        return false;  
}

bool    has_integer_sqrt(ll a){
        ll l = 0, r = a/2; 
        while( l <= r){
                ll m = l + ((r - l)/2);
                ll res = m * m;
                if(res == a) return true;
                else if(res < a){
                        l = m + 1;
                }
                else {
                        r = m - 1;
                }

        }
        return false;
   
}

//return first value that is greater then target
ll      my_lower_bound(vector<ll>& a, ll target){
        ll l = 0, r = a.size()-1;
        ll ans = (ll)INFINITY;
        while(l <= r){
                ll m = l + ((r-l)/2);

                if(a[m] >= target){
                        ans = a[m]; // for position, put m
                        r = m - 1;
                }
                else {
                        l = m + 1;
                }
        }
        return ans;
}
//return first value that is smaller then target
ll      my_upper_bound(vector<ll>& a, ll target){
        ll l = 0, r = a.size()-1;
        ll ans = (ll)INFINITY;
        while(l <= r){
                ll m = l + ((r-l)/2);

                if(a[m] <= target){
                        ans = a[m]; // for position, put m
                        r = m - 1;
                }
                else {
                        l = m + 1;
                }
        }
        return ans;
}

/*example of original sorted array
  2, 3, 6, 7, 9, 15, 19
  shift left
  6, 7, 9, 15, 19, 2, 3
  shift right
  19, 15, 2, 3, 6, 7, 9
*/
ll      smallest_in_shifted(vector<ll>& a){
        ll l = 0, r = a.size()-1;
        ll ans = (ll)INFINITY;
        while(l <= r){
                ll m = l + ((r-l)/2);

                // the idea is to find the first false, then look to the left to find a better answer
                if( m == 0 || a[m] <= a[0] ){
                        ans = a[m]; // for position, put m insted
                        r = m - 1; // look to the left
                }
                else {
                        l = m + 1; // look to the right
                }
        }
        return ans;
}

// the array need to increase and then decrease
// return INFINITY if has no maximum
ll      find_peak(vector<ll>& a){
        ll l = 0, r = a.size()-1;
        ll ans = (ll)INFINITY;
        while(l <= r){
                ll m = l + ((r-l)/2);

                
                if( m == 0 || a[m] > a[m-1] ){
                        ans = a[m]; 
                        l = m + 1; // look to the right
                }
                else {
                        r = m - 1; // look to the left
                }
        }
        return ans;
}

//fast but not precise enough
ld      find_sqrt_with_precison(ld x, const ld eps){
        ld l = 0, r = x/2;
        while( r - l > eps){
                ld m = l + ((r-l)/2);

                if( m*m < x ){
                        l = m; // look to the right
                }
                else {
                        r = m; // look to the left
                }
        }
        return (l + ((r-l)/2));
}

ld sqrt_newton(ld n) {
    const ld eps = 1E-15;
    double x = 1;
    for (;;) {
        ld nx = (x + n / x) / 2;
        if (abs(x - nx) < eps)
            break;
        x = nx;
    }
    return x;
}

int  main(){
        fast_io;
        ld n;
        cin >> n;

        cout << setprecision(15) << sqrt(n) << "\n";
        cout << setprecision(15) << find_sqrt_with_precison(n, 1e-15) << "\n";
        cout << setprecision(15) << sqrt_newton(n) << "\n";

        return 0;
}