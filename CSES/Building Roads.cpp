CSES
p1yu5h0 —  
CSES Problem Set
Building Roads
TASK SUBMIT RESULTS STATISTICS HACKING
Submission details
Task:	Building Roads
Sender:	p1yu5h0
Submission time:	2021-10-20 14:10:20
Language:	C++17
Status:	READY
Result:	ACCEPTED
Test results
test	verdict	time	
#1	ACCEPTED	0.01 s	details
#2	ACCEPTED	0.01 s	details
#3	ACCEPTED	0.01 s	details
#4	ACCEPTED	0.01 s	details
#5	ACCEPTED	0.01 s	details
#6	ACCEPTED	0.12 s	details
#7	ACCEPTED	0.12 s	details
#8	ACCEPTED	0.12 s	details
#9	ACCEPTED	0.12 s	details
#10	ACCEPTED	0.12 s	details
#11	ACCEPTED	0.13 s	details
#12	ACCEPTED	0.01 s	details
Compiler report
input/code.cpp: In function 'void solve()':
input/code.cpp:150:21: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
Code
#include<bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcount
#define sz(x) (int)(x.size())
#define tc(t)  while(t--)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define w(t)            int t; cin>>t; while(t--)
#define fs(x) fixed<<setprecision(x)
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll>	pl;
typedef pair <int,int> pii;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef priority_queue<int, vector<int>, greater<int>> min_heap32;
typedef priority_queue<ll, vector<ll>, greater<ll>> min_heap64;
typedef priority_queue<int> max_heap32;
typedef priority_queue<ll> max_heap64;
typedef unordered_map<int, int> umap32;
typedef unordered_map<ll, ll> umap64;
 
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
//#include<ext/pb_ds/assocnt_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
int cmp(int a,int b){return a>b;}
int isprime(int N){if(N<2 || (!(N&1) && N!=2))return 0;for(int i=3; i*i<=N; i+=2){if(!(N%i))return 0;}return 1;}
int bin_pow(int ind, int power){if(power == 0){return 1;}if(power & 1){return ind * bin_pow(ind,power - 1) % MOD;}else{return bin_pow((ind * ind) % MOD , power / 2) % MOD;}}
//ll fact(ll n);
//ll nCr(ll n, ll r){return fact(n) / (fact(r) * fact(n - r));}
//ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i;return res;}
//"KADANE'S ALGORITHM" //iski time complexity o(n) hn i.e the smallest possible
long long maxsubarraysum(long long *array,long long n){long long best = 0, sum = 0;for (long long  k = 0; k < n; k++) {sum = max(array[k],sum+array[k]);best = max(best,sum);}return  best ;}
void printBinary(int num){for(int i=10;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}
//int nPr(int n, int r){return fact(n)/fact(n-r);}
//bool areDigitsSame(int n){vector<int> a;while(n>0){int m=n%10;n=n/10;a.pb(m);}for(int i=0;i<a.size()-1;i++){if(a[i]!=a[i+1]){return false;}}return true;}
//int binarySearch( vector<int>& arr, int l, int r, int x){while (l <= r) {int m = l + (r - l) / 2;if (arr[m] == x) {return m + 1;}if (arr[m] < x) {l = m + 1;}else {r = m - 1;}}int min = arr[l] > x ? l : r;++min;return min;}
// Method to calculate xor
int computeXOR(int n){if (n % 4 == 0)return n;if (n % 4 == 1)return 1;if (n % 4 == 2)return n + 1;return 0;}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
void dfs(int node, vector<int>& vis, vector<int> adj[]){
    vis[node] = 1;
 
    for(auto child : adj[node]){
        if(vis[child] == 0){
            dfs(child, vis, adj);
        }
    }
}
 
void solve() {
    int n, m;
    cin>>n>>m;
    int x, y;
    vector<int> ans;
    vector<int> adj[n+1];
    while(m--){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> vis(n+1, 0);
    for(int i = 1; i<=n; i++){
        if(vis[i]==0){
            dfs(i, vis, adj);
            ans.pb(i);
        }
    }
 
    cout<<ans.size()-1<<endl;
    for(int i = 1; i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
}
 
 
int main() {
    fastio();
 
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    auto start1 = high_resolution_clock::now();
    /* Piyush Agrawal*/
    ll tc=1;
//    cin>>tc;
    while(tc--) {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
    return 0;
}
/* stuff you should look for
* stack/set/gcd/palindrome/twopointer/slidingwindow
prefix sum/range query/ patterns/matrices/string
lexographicaly/xoor/subsequence subarray/overlapping intervals
factors(rootn)   primefactorisation  vectorofallfactors dfs bfs msdfs
 
availaible snip-dfs,mint,quadraticformula,2dvector
mytemp,negativemod,primefactorisation
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
*/
Share code to others
Test details
Test 1
Verdict: ACCEPTED

input
10 10
2 5
5 6
1 4
6 8
...

correct output
2
1 2
2 7

user output
2
1 2
2 7

Test 2
Verdict: ACCEPTED

input
10 10
3 9
6 8
9 10
7 8
...

correct output
2
1 4
4 5

user output
2
1 4
4 5

Test 3
Verdict: ACCEPTED

input
10 10
7 9
1 7
1 3
3 4
...

correct output
0

user output
0

Test 4
Verdict: ACCEPTED

input
10 10
4 8
5 9
4 9
2 7
...

correct output
1
1 3

user output
1
1 3

Test 5
Verdict: ACCEPTED

input
10 10
4 9
2 4
7 10
1 8
...

correct output
0

user output
0

Test 6
Verdict: ACCEPTED

input
100000 200000
7233 22146
94937 96203
6133 10731
98737 99193
...

correct output
4785
1 2
2 3
3 4
4 5
...

user output
4785
1 2
2 3
3 4
4 5
...

Test 7
Verdict: ACCEPTED

input
100000 200000
92950 93575
24401 88897
41796 99364
47106 50330
...

correct output
4868
1 2
2 7
7 9
9 15
...

user output
4868
1 2
2 7
7 9
9 15
...

Test 8
Verdict: ACCEPTED

input
100000 200000
15637 76736
79169 98809
4382 86557
73383 77029
...

correct output
4683
1 9
9 20
20 27
27 28
...

user output
4683
1 9
9 20
20 27
27 28
...

Test 9
Verdict: ACCEPTED

input
100000 200000
47932 66981
86401 99942
4353 27841
60492 67345
...

correct output
4807
1 6
6 7
7 11
11 12
...

user output
4807
1 6
6 7
7 11
11 12
...

Test 10
Verdict: ACCEPTED

input
100000 200000
6554 44548
76413 98555
5447 59589
70166 74434
...

correct output
4786
1 2
2 18
18 21
21 27
...

user output
4786
1 2
2 18
18 21
21 27
...

Test 11
Verdict: ACCEPTED

input
100000 1
1 2

correct output
99998
1 3
3 4
4 5
5 6
...

user output
99998
1 3
3 4
4 5
5 6
...

Test 12
Verdict: ACCEPTED

input
10 9
2 5
5 6
1 4
6 8
...

correct output
2
1 2
2 7

user output
2
1 2
2 7

Graph Algorithms
Counting Rooms
Labyrinth
Building Roads
Message Route
Building Teams
Round Trip
Monsters
Shortest Routes I
...
Your submissions
2021-10-20 14:10:20
