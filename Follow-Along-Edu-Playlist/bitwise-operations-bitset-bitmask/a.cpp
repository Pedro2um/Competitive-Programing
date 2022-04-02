#include <bits/stdc++.h>
using namespace std;

//These are four important built-in functions in GCC compiler

// __builtin_popcount(x) int, __builtin_popcountll(x), long long
// counting number of 1s in binary of x

// _builtin_parity(x) int, _builtin_parityll(x), long long
// return 1 for odd parity, 0 for even parity

// __builtin_clz(x) int, __builtin_clzll(x), long long
// couting leading zeros (0s before the last non zero bit of the number)
// counting left to right (most significant to less)
// example: 16
// 00000000 00000000 00000000 00010000
// __builtin_clz(16) = 27

// __builtin_ctz(x) int, __builtin_ctzll(x), long long 
// couting trailing zeros (0s after the last non zero bit of the number)
// counting right to left (less significant to most)
// example: 16
// 00000000 00000000 00000000 00010000
// __builtin_ctz(16) = 4

#define         fast_io                 ios_base::sync_with_stdio(false);cin.tie(NULL)

#define         get_kth_bit_1(x,k)      (x&(1ULL<<k))          
#define         get_kth_bit_2(x,k)      ((x>>i)&1)

#define         MAX_D                   365
#define         MAX_N                   5000


typedef           long long ll;
typedef unsigned long long ull;


void print_binary_representation(int a){
       for(int i = 31; i >= 0; i--){
                if(get_kth_bit_2(a, i)){
                        //printf("%d ", i);
                        printf("1");
                }
                else printf("0"); 
        } 
}

//P2.Knapsack
/*      You are give N <= 1000, each with some weight w[i].
        Is there a subset with total weight exactly W? W <= 10^6
*/
/*      Subset sum:
        You are given N numbers. 
        Check if there is a subset of them,
        with the sum equal to target value S.
        N <= 20
*/

// time complexity O( (2^N) * N)
// vector, Sum target, number of elements
bool solution_for_subset_sum(vector<int>& a, int S, int N){

        for(int mask = 0; mask < (1 << N); mask++){

                long long sum_of_this_subset = 0;

                for(int i = 0; i < N; i++){

                        if(get_kth_bit_2(mask, i)){
                                sum_of_this_subset += a[i];
                        }

                }
                if(sum_of_this_subset == S){
                        return true;
                }
        }
        return false;
}


// Bitsets
// There are N <= 5000 workers. Each is available during some days of this month.
// Find two workers with maximum intersection of their schedules.
// Example:
//  W1  {2,3,5,6,8}
//  W2  {2,4,5,8}
//  W3  {1,2,10,12,14,16}
//  Brute force solution will take O( (N^2)*D) // D days
//
//      From what we know now, you can use binary representation of a number for,
//      representing schedule.
//      Example:
//              For days 1,2,3,...,and so on, represented by a bit in this numbers
//              Schedules of workers
//              For W1 ->  011011010000000000000000000000
//              For W2 ->  010110010000000000000000000000
//              For W3 ->  110000000101010100000000000000
//     Intersection of days will be a simple &(a.k.a AND) operation
//     __buildin_popcount(x); - for int
//     __builtin_popcoutll(x); - for long long or unsigned long long
//     for(a)
//        for(b)
//            __builtin_popcount(a&b);
//            // both & and "popcount" work in O(1) time complexity, constant time
//
//     If the problem was change for year insted of month - D = 30 will be D = 365
//     D will not fit in a int, but we can store every month in a diferent int, having 12 ints for worker


const int K = (MAX_D / 64) + 1;
unsigned long long x[MAX_N][K];
//This will take O( (N^2)*D/W ) - W is word size
int instersection_solution_1(int i, int j){
        int total = 0;
        for(int z = 0; z < K; z++){
                total += __builtin_popcountll(x[i][z] & x[j][z]);
        }
        return total;
}

//Bitset handles bitwise operations and bit_shifts
bitset<MAX_D> y[MAX_N]; // count is equivalent to __buildin_popcountll(y);
//This will also take  O( (N^2)*D/W ) - W is word size
int intersection_solution_2(int i, int j){
        return (y[i] & y[j]).count();
}

//P1.Different numbers
//You are given N <= 10^7 numbers, each between 0 and 10^9.
//How many different values appear in the sequence?
//      Example:
//              input = [3,5,6,3,3,9,5]
//              answer = 4
//              There are four different values: 3, 5, 6, 9
//      Possible but inconvinient solution      
//      bool vis[10^9+1];
//      but each bool cost us 1 byte,
//      and 10^9 + 1 * 1 byte == 1000000001 bytes == 1GB
//      
//      bitset<10^9+1>vis;
//      With a bit set, we will take a bit insted of a byte,
//      Using 8 times less memory; around 128mb
//      10^9 bits = 10^9/8 bytes = 128 mb

bitset<(ull)10E9+1> visited;
//this take O(V/32 + N)
void solution_to_different_nums_1(){
        ull ans=0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                int z;
                cin >> z;
                if(!visited[z]){
                        visited[z] = true;
                        ans++;
                }
        }
        printf("%llu", ans);
        puts("");
}

void solution_to_different_nums_2(){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                int z;
                cin >> z;
                visited[z] = true;
        }
        cout << visited.count() << "\n";
        // This takes O(V/32)
}

// Obs: Any of this solutions does not work if each number can be from 0 to 10^18

//bool can[(ull)1e6];
bitset<(ull)1e6> Can;
int main(){
        fast_io;
       

        //P2.Knapsack
        // In O(N*W) Dp solution
        // for n = 8 and W = 7, will result in 8*7 = 56 iterations
        int n, W;
        cin >> n >> W;
        //solution with bool array
        /*can[0] = true; // because we can make a empty subset with sum = 0
        for(int id = 0; id < n; id++){
                int X;
                cin >> X;
                for(int i = W; i >= X; i--){
                        if(can[i-X]) can[i] = true;
                }
        }
        puts(can[W] ? "YES-correct-ans" : "NO-correct-ans");
        */

        // using bitset, 8 times less memory, bool is 1 byte == 8 bits
        // is faster, O(N*W/32)
        Can[0]=true;
        for(int id = 0; id < n; id++){
                int X;
                cin >> X;
                Can |= (Can<<X);
        }
        puts(Can[W] ? "YES-correct-ans" : "NO-correct-ans");



        vector<int> a;
        int n2, X2, W2; 
        cin >> n2 >> W2;
        for(int i = 0; i < n2; i++){
                cin >> X2;
                a.push_back(X2);
        }
        // will take O( (2^N) * W ) - VERY SLOW!!!
        // for n2 = 8 and W = 7, will result in 3584 iterations

        if( solution_for_subset_sum(a, W2, n2) ){
                puts("YES-my-ans");
        }
        else {
                puts("NO-my-ans");
        }
        

        //P3.Triangles in a graph
        /*      Adjancency list for every vertex
                is a set of vertices
                1:{2,4,5} - can be represented as 010110
                2:{1,3,4,6} - ||               as 101101 
                3:{2}       - ||               as 010000 
                4:{1,2,5,6} - ||               as 110011
                5:{1,4,6}   - ||               as 100101
                6:{2,4,5}   - ||               as 010110
                // Doing &(a.k.a AND) operation you can check
                // if two vertices are connected
                // Doing from the representations before describe 1 & 2 == 000100
                // This is not a triangle, you need at least two
                //
                //The algorithm should be:
                // for every pair of vertices, U and V
                // if U are connected by a direct edge,
                // compute bitwise AND of adjacency and add their popcount to answer
                // In the end, you should devide answer by 3, 
                //  because you are computing every triangle three times
                // For triangle ABC you will compute;
                //      For AB -> C will be detected
                //      For AC -> B will be detected
                //      For BC -> A will be detected
                //
        */

        return 0;
}