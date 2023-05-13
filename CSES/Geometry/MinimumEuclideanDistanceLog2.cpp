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
//bad, but simple, O(N^2)
ll brute_force(vector<P>& points){
	ll best= 2LL * ( INT_MAX * (long long)INT_MAX );
	//pair<P,P> best_points = { P{0,0}, P{INT_MAX,INT_MAX} };
	for(P& A: points){
		for(P& B: points){
			if(A == B) continue;
			ll dist = A.euclidian_distance_sq(B);
			best = min(dist, best);
		}
	}
	return best;
}
 
//O(N^2/4) can be done better!
ll naive_divide_and_conquer(vector<P>& points){
	if(points.size() == 2){
		return points[0].euclidian_distance_sq(points[1]);
	}
	else if(points.size() == 3){
		ll dist1 = points[0].euclidian_distance_sq(points[1]);
		ll dist2 = points[0].euclidian_distance_sq(points[2]);
		ll dist3 = points[1].euclidian_distance_sq(points[2]);
		return min(min(dist1, dist2), dist3);
	}
	vector<P> left;
	vector<P> right;
	int size = points.size();
	for(int i = 0, m =  ( (int)points.size()/2); i < (int)points.size(); i++){
		if(i < m || ( (size%2)&&(i==m) ) ) left.push_back(points[i]);
		else right.push_back(points[i]);
	}
	ll d1 = naive_divide_and_conquer(left);
	ll d2 = naive_divide_and_conquer(right);
	ll d = min(d1, d2);
	for(P a: left){
		for(P b: right){
			d = min(d, a.euclidian_distance_sq(b));
		}
	}	
	//cout<<d<<"\n";
	return d;
}
 
bool cmp_y(const P& a, const P& b){
	return a.y < b.y;
}
// O(N * log^2(N)) can be donne better!
ll better_divide_and_conquer(vector<P>& points){	
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
	/*for(int i = 0, m =  ( (int)points.size()/2); i < (int)points.size(); i++){
		if(i < m || ( (size%2)&&(i==m) ) ) left.push_back(points[i]);
		else right.push_back(points[i]);
	}*/
	
	ll d1 = better_divide_and_conquer(left);
	ll d2 = better_divide_and_conquer(right);
	ll d = min(d1, d2);
	#define SQ(a) ((a)*(a))
	vector<P> stripe;
	ll middle_x =left.back().x;	
	for(P a: left)	{
		if( SQ(a.x-middle_x) < d){
			stripe.push_back(a);
		}
	}
	for(P b: right)	{
		if( SQ(b.x-middle_x) < d){
			stripe.push_back(b);
		}
	}	
	sort(stripe.begin(), stripe.end(), [&](const P& a, const P& b){
		return a.y < b.y;
	});
	for(int i = 0; i < (int)stripe.size(); i++){
		/*for(int j = i-1; j >= 0 && stripe[j].y > stripe[i].y - d; --j){
			d = min(d, stripe[i].euclidian_distance_sq(stripe[j]));
		}*/
		// lemma says that the following for-loop is O(1)
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
	cout << better_divide_and_conquer(points)<<"\n";
	return 0;
}
