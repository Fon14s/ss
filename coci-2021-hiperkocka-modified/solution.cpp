#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
constexpr int N = 55;
int n, a[N], cnt;
vector<int> to[N];
void dfs(int u, int pa) {
    for (int v : to[u])
        if (v != pa)
            a[v] = a[u] ^ (1 << (cnt++)), dfs(v, u);
}
int main() {
    cin >> n;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(0, -1);
    cout << (1 << (n - 1)) << '\n';

    For(s, 0, (1 << n) - 1) if (__builtin_parity(s))
        For(i, 0, n) cout << (s ^ a[i]) << " \n"[i == n];

    return 0;
}
