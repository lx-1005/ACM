/*
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
#include <bits/stdc++.h>
using namespace std;
// namespace R = std::ranges;
// namespace V = std::ranges::views;
using ll = long long;
using i128 = __int128;
#define rep(i,a,n) for(int i = a; i<n; i++)
#define per(i,a,n) for(int i = n-1; i>= a; i--)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define bitcnt(x) __builtin_popcountll(x) // 返回x的二进制1的个数
#define lowbit(x) ((x) & (-(x)))          // 返回x的最低位1表示的数
#define bitcnt_tailzero(x) __builtin_ctz(x) // 返回x的二进制末尾0的数量，等价于x的最低位1是第几位
#define bitcnt_headzero(x) (__builtin_clz(x)) // 返回x的二进制开头0的数量
#define sz(x) (int)(x.size())
#define IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
template <typename T1, typename T2> T1 quick_mod(T1 a, T2 m) { return (T1)(a % m + m) % m; } // 求 a%m 
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     // a和b的最小公倍数
ll quick_power(ll x, ll y, ll mod) { ll res = 1, cur = x; while (y) { if (y & 1) res = res * cur % mod; cur = cur * cur % mod; y >>= 1; } return (res % mod + mod) % mod; }
inline int combination(int n, int k) { int sum = 0; if (n == k || k == 0) { return 1; } else { return combination(n - 1, k) + combination(n - 1, k - 1); } }
ll ceilDiv(ll n, ll m) { if (n >= 0) return (n + m - 1) / m; return n / m; }
ll floorDiv(ll n, ll m) { if (n >= 0) return n / m; return (n - m + 1) / m; }
const int inf = 0x3f3f3f3f;
// const int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*



*/
const int N = 100010;
int a[N], b[N];

void merge_sort(int l, int r) {
    if (r - l <= 0) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid), merge_sort(mid+1, r);
    int i = l, j = mid + 1, k = 0;
    for (; i <= mid && j <= r; )  {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (k = 0, i = l; i <= r; ) a[i++] = b[k++];
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

