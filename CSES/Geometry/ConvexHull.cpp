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
	bool operator <(const P& b){
		return  ( make_pair(x,y) < make_pair(b.x,b.y) );
	}
};

//using Graham's scan O(nlogn) insted of Jarvis/Wrapping algorithm O(n^2)
int main(){
	fast_io;	
	int n;
	cin>>n;
	vector<P> points(n);
	for(int i = 0; i < n; i++){
		points[i].read();
		//cout<<points[i].x << " "<<points[i].y<<"\n";
	}
	sort(points.begin(), points.end());//sort from left to right
	vector<P> hull;
	for(int rep = 0; rep < 2; ++rep){
		const int S = hull.size();	
		for(P C : points){
			while((int)hull.size() - S >= 2){
				P A = hull.end()[-2];//trick
				P B = hull.end()[-1];
				if(A.triangle(B,C) <= 0){//B on the left from C, or collinear
					//good, don't do anything	
					break;
				}
				hull.pop_back();//remove B
			}
			hull.push_back(C);
		}
		hull.pop_back();//remove rightmost point
		reverse(points.begin(), points.end());//now build bottom hull
	}
	cout<<hull.size()<<"\n";	
	for(P p : hull){
		cout<< p.x << " " << p.y << "\n";
	}
	
	return 0;
