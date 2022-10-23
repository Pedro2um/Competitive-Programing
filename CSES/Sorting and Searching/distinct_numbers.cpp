#include <bits/stdc++.h>
using namespace std;
int main(){	
	set<int> s;
	int n, x;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		s.insert(x);
	}
	printf("%d", s.size());		
	return 0;
}
