#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b)	(((a)>(b))?(a):(b))
int main(){	
	vector<long long int> v;
	long long int n, num;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &num);
		v.push_back(num);
	}
	long long int best, sum, i;
	for(best = INT32_MIN, sum = 0, i = 0; i < n; i++){
		sum = MAX(v[i], sum+v[i]);
		best = MAX(best, sum);
	}
	printf("%lld\n", best);
}
