#include <bits/stdc++.h>
using namespace std;
 
#define MAX		(int)1e6
 
 
int arr[MAX + 1];
 
void init(){
	for(int i = 1; i <= MAX; i++)
		for(int j = i; j <= MAX; j+=i)
			arr[j]++; 
}
 
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();		
	int n; 
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		cout << arr[num] << "\n";
	}
 
return 0;
}
