#include <bits/stdc++.h>
#define dbg(x)	cout<<" "<<#x <<" = " <<x
#define MOD	(long long)(1e9 + 7)
 
typedef long long ll;
typedef long long unsigned llu;
typedef long double ld;
using namespace std;
 
 
 
int h[]={0, 1, 1, 1, 0, -1, -1, -1};
int v[]={1, 1 , 0, -1, -1, -1, 0, 1};
 
const int MAX_N = 2 * 1e5 + 1;
const int LOG = 18;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i...i+2^j-1]
 
int query(int L, int R){
	int length = R - L + 1;
	int k = 31 - __builtin_clz(length);
	return min(m[L][k], m[R-(1<<k)+1][k]);
}
 
 
 
void solve(){
	
	int n, q;
	cin>>n>>q;	
	//1) read input
	for(int i=1; i <= n; i++){
		cin>>a[i];
		m[i][0] = a[i];
	}
	//2) preprocessing , O(N*log(N))
	for(int k =1; k < LOG; k++){
		
		for(int i = 1; i + (1<<k) - 1 <= n; i++){
			
			m[i][k]= min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
 
		}
 
	} 
	//3) answer queries	
	for(int i=1; i <= q; i++){
		
		int L, R;
		cin>>L>>R;
		cout<<query(L,R)<<"\n";
 
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
