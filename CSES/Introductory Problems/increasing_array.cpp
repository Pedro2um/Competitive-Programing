#include <bits/stdc++.h>
using namespace std;
 
int main(){
	
	long long int n, num, counter = 0, max_num= 0;
	scanf("%lld", &n);
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num >= max_num){
			max_num = num;
		} else {
			counter += (max_num - num);
		}
		
		v.push_back(num); 
	}
	
	printf("%lld\n", counter);
		
	return 0;
}
