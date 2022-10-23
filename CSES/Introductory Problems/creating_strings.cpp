#include <bits/stdc++.h>
 
using namespace std;
 

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int main(){
	fast_io;
	int N;
	char S[9];
	set<string> perms;
	
	scanf("%s", S);
	N = strlen(S);
	
	sort(S, S+N);
	
	perms.insert(S);
	
	while(next_permutation(S, S+N)){
		perms.insert(string(S, S+N));
	}
	
	cout << perms.size() << "\n";
	for(string perm : perms)
		cout << perm << "\n";
return 0;
}
