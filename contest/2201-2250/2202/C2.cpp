#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  stack<int> st;
  ll ans = 0;
  rep(i, 1, n) {
    while (st.size() && a[st.top()] + 1 != a[i]) st.pop();
    int x = st.size() ? i - st.top() : i;
    int y = n + 1 - i;
    ans += 1ll * x * y;
    st.push(i);
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