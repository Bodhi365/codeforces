#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 505;

int n, m;
int a[N];
int f[N * N];

int get_ans(int mx) {
  int sum = 0;
  stack<int> st;
  int k = 1;
  per(i, n, 1) {
    int j = min(n, mx / i);
    while (k <= j) st.push(k++);
    if (st.empty()) return -1;
    sum += i * st.top();
    st.pop();
  }
  return sum - mx;
}
void solve() {
  cin >> n;
  rep(i, 1, n * n) f[i] = 0;
  rep(i, 1, n) rep(j, 1, n) f[i * j] = 1;
  int ans = 0;
  rep(i, 1, n * n) {
    if (!f[i]) continue;
    ans = max(ans, get_ans(i));
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}