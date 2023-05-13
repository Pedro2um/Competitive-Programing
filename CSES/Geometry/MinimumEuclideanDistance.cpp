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
	bool operator==(const P& b){
		return x==b.x && y==b.y;
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
	ll euclidian_distance_sq(const P& b){
		return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
	}
};
 
ll better_divide_and_conquer(vector<P>& points, vector<P>& points_by_y){	
	if(points.size() == 2){
		return points[0].euclidian_distance_sq(points[1]);
	}
	else if(points.size() == 3){
		ll dist1 = points[0].euclidian_distance_sq(points[1]);
		ll dist2 = points[0].euclidian_distance_sq(points[2]);
		ll dist3 = points[1].euclidian_distance_sq(points[2]);
		return min(min(dist1, dist2), dist3);
	}
		
	int size = points.size();
	vector<P> left = vector<P>(points.begin(), points.begin()+ size/2);
	vector<P> right = vector<P>(points.begin()+ size/2, points.end());
	vector<P> left_by_y, right_by_y;
	for(P p: points_by_y){
		if( make_pair(p.x,p.y) <= make_pair(left.back().x, left.back().y) ) {
			left_by_y.push_back(p);
		}
		else {
			right_by_y.push_back(p);
		}
	}
	
	ll d1 = better_divide_and_conquer(left, left_by_y);
	ll d2 = better_divide_and_conquer(right, right_by_y);
	ll d = min(d1, d2);
	#define SQ(a) ((a)*(a))
	vector<P> stripe;
	ll middle_x =left.back().x;
	
	for(P a: points_by_y){
		if(SQ(a.x - middle_x) < d){
			stripe.push_back(a);
		}
	}	
	
	for(int i = 0; i < (int)stripe.size(); i++){
		
		for(int j = i+1; j < (int)stripe.size() && SQ(stripe[j].y - stripe[i].y) < d; ++j){
			d = min(d, stripe[i].euclidian_distance_sq(stripe[j]));
		}//considering from points sorted by y, only look to points at most, y+d distant from me	
	}
	return d;
}
 
int main(){
	fast_io;	
	int n;
	cin>>n;
	vector<P> points(n);
	for(int i = 0; i < n; i++){
		points[i].read();
	}
	
	//cout << brute_force(points)<<"\n";	
	sort(points.begin(), points.end());//sorted by x, ties by y
	//cout << naive_divide_and_conquer(points)<<"\n";
	vector<P> points_by_y = points;
	sort(points_by_y.begin(), points_by_y.end(), [&](const P& a, const P& b){
		return a.y < b.y;
	});	
	cout << better_divide_and_conquer(points, points_by_y)<<"\n";
	return 0;
}
