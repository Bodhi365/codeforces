#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], pos[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  vector<pii> res;
  stack<int> st;
  rep(i, 1, n) {
    int mn = (st.empty() || a[st.top()] > a[i]) ? i : st.top();
    while (st.size() && a[st.top()] < a[i]) {
      res.push_back({a[st.top()], a[i]});
      st.pop();
    } 
    st.push(mn);
  }
  if (st.size() > 1) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for (auto p : res) cout << p.first << ' ' << p.second << endl;
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