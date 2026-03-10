#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, t;
int a[N];
struct Node {
  int x, cnt;
};
void solve() {
  cin >> n >> m >> t;
  rep(i, 1, n) cin >> a[i];
  if (m == 1) {
    cout << t - a[n] << endl;
  } else { 
    multiset<int> st;
    rep(i, 1, n) {
      int k = min(n + 2 - i, m);
      int now = a[i] - a[i - 1];
      while (st.size() < k) st.insert(0);
      while (now--) {
        auto it = st.begin();
        int x = *it;
        st.erase(it);
        st.insert(x + 1);
      }
      auto it = st.end();
      st.erase(--it);
    }
    int now = t - a[n];
    int ans = *st.begin() + now;
    cout << ans << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}