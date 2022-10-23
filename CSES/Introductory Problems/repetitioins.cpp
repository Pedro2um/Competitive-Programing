#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX     (((a)>(b))?(a):(b))
 
const int maxSize = 1e6+5;
 
char s[maxSize];
 
int main(){
 
	scanf("%s", s);
 
    int n = strlen(s);
	int best = 1, current = 1;
 
	for(int i = 1; i < n; i++){
		if(s[i-1] == s[i]) current++;
        else current = 1;
        best = max(best, current);
	}
	
	printf("%d\n", best);
	
	
 
return 0;
}
