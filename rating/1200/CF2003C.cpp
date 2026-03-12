#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
string s;
int cnt[128];
struct Node {
  int cnt;
  char c;
  bool operator<(const Node& o) const {
    if (cnt != o.cnt) return cnt < o.cnt;
    else return c > o.c;
  }
};
void solve() {
  cin >> n;
  cin >> s;
  memset(cnt, 0, sizeof(cnt));
  for (char c : s) cnt[c]++;
  priority_queue<Node> pq;
  rep(c, 'a', 'z') if (cnt[c]) pq.push({cnt[c], (char)c});
  string ans;
  while (pq.size() >= 2) {
    Node x = pq.top();
    pq.pop();
    Node y = pq.top();
    pq.pop();
    ans.push_back(x.c), ans.push_back(y.c);
    if (--x.cnt) pq.push(x);
    if (--y.cnt) pq.push(y);
  }
  if (pq.size()) {
    Node x = pq.top();
    while (x.cnt--) ans.push_back(x.c);
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