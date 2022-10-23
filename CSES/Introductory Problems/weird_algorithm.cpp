#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
	long long unsigned int n = 0;
 
    scanf("%lli", &n);
    printf("%lli ", n);
 
   for(; n != 1 ;){
 
       if(n % 2 == 0){
           n /= 2;
       } else {
           n = (n*3) + 1;
       }
 
       printf("%lli ", n);
   }
 
return 0;
}
