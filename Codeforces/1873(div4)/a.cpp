#ifdef LOCAL
#pragma clang diagnostic ignored "-Weverything"
#include "/Users/lixu26/work/ACM/dbg.hpp"
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll = long long;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define all(a) begin(a), end(a)
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x) // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x)) // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
#define log2(x) log(x) / log(2)
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
template <typename T1, typename T2> T1 MOD(T1 a, T2 m) { return (T1)(a % m + m) % m; } // 求 a%m
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     // a和b的最小公倍数
ll quick_power(ll x, ll y, ll mod) { ll res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; } return (res % mod + mod) % mod; }
inline int combination(int n, int k) { int sum = 0; if (n == k || k == 0) { return 1; } else { return combination(n - 1, k) + combination(n - 1, k - 1); } }
inline int read() { int x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * f; }
inline void write(int x) { if (x < 0) putchar('-'), x = -x; if (x > 9) write(x / 10); putchar(x % 10 + '0'); return; }
const int inf = 0x3f3f3f3f;
// const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*



*/


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    
    ll sum = 0;
    set<ll> st = {0};
    for (int i = 0; i < n; ++i) {
        a[i] *= ((i & 1) ? (-1) : 1);
        sum += a[i];
        if (st.count(sum)) {
            cout << "YES\n";
            return;
        }
        st.insert(sum);
    }
    cout << "NO\n";
}

int main() {
#ifdef LOCAL
    clock_t start_time=clock();
#endif
    
    IO;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }







#ifdef LOCAL
    clock_t end_time=clock();
    freopen("/Users/lixu26/work/ACM/error.txt", "w", stderr);
    cerr<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
#endif
    
    return 0;
}