#include <bits/stdc++.h>
using namespace std;
int ans, n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while(n > 0){
		n /= 5;
		ans += n;
	}
	cout << ans;
	return 0;
}
