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
 
bool intersect(P p1, P p2, P p3, P p4){
	if( (p2 - p1) * (p4 - p3) ==0){
		if(p1.triangle(p2,p3) != 0){
			return false;
		}
		for(int rep = 0; rep < 2; ++rep){
			if( max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y) ){
				return false;
			}
			swap(p1,p3);
			swap(p2,p4);
 
		}
		return true;
	}
	
	for(int rep = 0; rep < 2; ++rep){
		ll sign1 = (p2 - p1) * (p3 - p1);
		ll sign2 = (p2 - p1) * (p4 - p1);
		if( (sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0) ){
			return false;
		}
		swap(p1,p3);
		swap(p2,p4);
	}
	
	return true;
}
 
bool segment_contains(P a, P b, P c){
	if(a.triangle(b, c) == 0){
		return  min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && 
			min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
	}
	return false;//non collinear
}
int main(){
	fast_io;	
	int n, m;
	cin>>n>>m;
	vector<P> polygon(n);
	for(P& p : polygon){
		p.read();
	}
	//const int INF = 4'000'000'001;
 
	for(int rep = 0; rep < m; ++rep){
		P p;
		p.read();
		P out = P{p.x + 1, 2000000001LL};
 
		bool is_on_boundary = false;
	        int count = 0;
 
		for(int i = 0; i < n; ++i){
			int j = (i == n - 1? 0 : i+1);
			if( segment_contains(polygon[i], polygon[j], p) ){
				is_on_boundary = true;
				break;
			}
			if( intersect(p, out, polygon[i], polygon[j]) ){
				count++;
			}
		}
		if(is_on_boundary){
			cout<<"BOUNDARY\n";
		}
		else if(count%2 == 0){
			cout<<"OUTSIDE\n";
		}
		else{
			cout<<"INSIDE\n";
		}
 
	}
	//point in polygon in O(n) ( can be done faster)
	//P(3,7)
	//(4,inf) ray
		
	return 0;
}
