#include <bits/stdc++.h>
using namespace std;
#define fast_io	ios_base::sync_with_stdio(0);cin.tie(NULL)
typedef long long ll;
typedef long double ld;
//complext library is slow, only use for hard problems
struct P{
	long long x, y;
	void read(){ cin>>x>>y;};
	P operator-(const P& b) const{
		return P{x - b.x, y - b.y};
	}
	void operator-=(const P& b){
		x -= b.x;
		y -= b.y;
	}
	//cross product
	ll operator *(const P& b) const{
		return (ll)x*b.y - (ll)b.x*y;
	}
	ll triangle(const P& b, const P& c) const{
		return (b - *this) * (c - *this);
	}
};
int main(){
	fast_io;	
	int n;
	cin>>n;
	vector<P> polygon(n);
	for(P& p : polygon){
		p.read();
	}
	long long boundary = 0;
	for(int i = 0; i < n; i++){
		int j = (i+1) % n;
		P diff = polygon[j] - polygon[i];
		int g = __gcd(abs(diff.x), abs(diff.y) );
		boundary += g;
	}	
	//cout<<boundary<<"\n";
	
	long long area = 0;
	for(int i =0; i < n; i++){
		area += polygon[i] * polygon[(i+1)%n];
	}
	area = abs(area);//twice the Area without the signal
	
	long long interior = (area - boundary + 2)/2;
	//Pick's theorem A = i + b/2 - 1
	cout << interior << " "<<boundary<<"\n";
	return 0;
}
