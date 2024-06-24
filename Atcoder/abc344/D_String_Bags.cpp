#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// namespace R = std::ranges;
// namespace V = std::ranges::views;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
using ll = long long;
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a)          memset(x, a, sizeof(x))
#define bitcnt(x)          __builtin_popcountll(x)  // 返回x的二进制1的个数
#define lowbit(x)          ((x) & (-(x)))           // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x)         // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x))       // 返回x的二进制开头0的数量
#define len(x)             (int)(x.size())
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
ll power(int a, ll b, ll p) {  // (a^b)%p
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) res = 1LL * res * a % p;
    }
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int combination(int n, int k) { return (n == k || !k) ? 1 : combination(n - 1, k) + combination(n - 1, k - 1); }
ll ceilDiv(ll n, ll m) { return n >= 0 ? (n + m - 1) / m : n / m; }
ll floorDiv(ll n, ll m) { return n >= 0 ? n / m : (n - m + 1) / m; }
const int inf = 0x3f3f3f3f;
// const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*



*/

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string>> a(n);
    vector<vector<bool>> st(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        st.resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> dp(len(t) + 1, inf);  // 凑到t[:i-1]的最少花费
    dp[0] = 0;
    for (int i = 1; i <= len(t); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < len(a[i][j]); k++) {
                if ()
                    dp[i] = min(dp[i], );
            }
        }
    }

    cout << (dfs(len(t)) >= inf ? -1 : ans[len(t)]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start_time = clock();

    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    auto end_time = clock();
#ifdef LOCAL
    std::cerr << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms"
              << "\n";  // 输出运行时间
#endif

    return 0;
}