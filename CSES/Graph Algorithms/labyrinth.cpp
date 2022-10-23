#include <bits/stdc++.h>
using namespace std;
#define		in_range(x,n)		( (x) >= 0 && (x) < (n) )
int h[] = {1, 0, -1, 0};
int v[] = {0, 1, 0, -1};
 
//walking in matrix
//	   (x,y)
/*
 *	   (-1,0)
 * (0, -1)       (0, 1)
*/	   //(1,0)
#define SIZE 10001
 
char M[SIZE][SIZE]; // original map
bool V[SIZE][SIZE]; // true or false
int  D[SIZE][SIZE]; // minimum distance 
pair<int,int>  P[SIZE][SIZE]; // x and y of parent of (i,j)
char A[SIZE][SIZE]; // L, R, U or D
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ax=0, ay=0, bx = 0, by = 0;
	for(int i =0 ; i < n; i++)
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			M[i][j] = c;
			if(c=='A') {
				ax = i;
				ay = j;
			}
			if(c=='B'){
				bx = i;
				by = j;
			}
			V[i][j] = ( (c == '#') ? true:false);
		}
 
	queue<pair<int,int>> Q;
	Q.push(make_pair(ax,ay) );
	D[ax][ay] = 0;
	V[ax][ay] = true;
        P[ax][ay] = make_pair(-1,-1);	
	int flag = 0;
 
	while(!Q.empty()){
		pair<int,int> temp = Q.front();
		Q.pop();
		if( M[temp.first][temp.second] == 'B'){
			pair<int,int> pb = P[temp.first][temp.second];
			
		#define dif(a,b)	( (a) - (b) )
				if( dif(temp.first, pb.first) == -1 && dif(temp.second, pb.second) == 0 ) A[temp.first][temp.second] = 'U'; 
			else 	if( dif(temp.first, pb.first) == 1 && dif(temp.second, pb.second) == 0 ) A[temp.first][temp.second] = 'D'; 
			else 	if( dif(temp.first, pb.first) == 0 && dif(temp.second, pb.second) == -1 ) A[temp.first][temp.second] = 'L';
			else 	if( dif(temp.first, pb.first) == 0 && dif(temp.second, pb.second) == 1 ) A[temp.first][temp.second] = 'R'; 			
			//A[temp.first][temp.second] = 
			//V[temp.first][temp.second] = true;
		       	flag = 1;	
			break;
		}
		for(int i = 0; i < 4; i++){
			int x = temp.first + v[i];
			int y = temp.second + h[i];
			if( in_range(x,n) && in_range(y,m) && V[x][y] == false ){
				Q.push(make_pair(x,y));
 
					if(v[i] == -1 && h[i] == 0)  A[x][y] = 'U';
				else 	if(v[i] == 1 && h[i] == 0)   A[x][y] = 'D';
				else 	if(v[i] == 0 && h[i] == -1)  A[x][y] = 'L';
				else 	if(v[i] == 0 && h[i] == 1)   A[x][y] = 'R';
				/*if(v[i] == 0){
					if(h[i] == 1) A[x][y] = 'R';
					else A[x][y] = 'L';
				}
				else{
					if(v[i] == 1 && h[i] == 0) A[x][y] = 'D';
					else A[x][y] = 'U';
				}*/	
				D[x][y] = D[temp.first][temp.second] + 1;
				P[x][y] = make_pair(temp.first,temp.second); 	
				V[x][y] = true;
			}
		}
 
	}
	string ans;	
	//ans
	//
	
	if(flag==0){
		cout << "NO\n";
		return 0;
	}
	pair<int, int> temp;
	vector<pair<int,int>> path;
	for(int i = bx, j = by; P[i][j].first != -1 && P[i][j].second != -1; temp = P[i][j], i = temp.first, j = temp.second ){
		path.push_back(temp);
	}
	reverse(path.begin(), path.end());
	
	cout << "YES\n" << path.size() << "\n";	
	for(int i = 0; i < (int)path.size() - 1; i++){
		cout << A[path[i].first][path[i].second];
	}
	cout << A[bx][by];	
	cout << "\n";	
	return 0;
}
