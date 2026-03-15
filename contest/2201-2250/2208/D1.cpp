#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 505;

int n, m;
string s[N];
int cnt[N], a[N];
int get(string& s) {
  int res = 0;
  for (char c : s) res += c - '0';
  return res;
}
bool cmp(int x, int y) { return cnt[x] < cnt[y]; }
bool contains(string& s, string t) {
  rep(i, 0, n - 1) {
    if (t[i] == '1' && s[i] != '1') return false;
    if (t[i] == '1') s[i] = '0';
  }
  return true;
}
int f[N];
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) f[fy] = fx;
}
bool check(vector<pii>& ans) {
  rep(i, 1, n) f[i] = i;
  for (auto p : ans) {
    merge(p.first, p.second);
  }
  int cnt = 0;
  rep(i, 1, n) if (f[i] == i) cnt++;
  return cnt == 1;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> s[i];
  rep(i, 1, n) cnt[i] = get(s[i]);
  rep(i, 1, n) a[i] = i;
  sort(a + 1, a + n + 1, cmp);
  vector<pii> ans;
  rep(i, 1, n) {
    int u = a[i];
    string now = s[u];
    per(j, i - 1, 1) {
      int v = a[j];
      if (now[v - 1] == '1') {
        if (!contains(now, s[v])) {
          cout << "NO" << endl;
          return;
        }
        ans.push_back(pii(u, v));
      }
    }
    bool fail = false;
    rep(j, 1, n) {
      if (j == u && now[j - 1] != '1') fail = true;
      if (j != u && now[j - 1] == '1') fail = true;
    }
    if (fail) {
      cout << "NO" << endl;
      return;
    }
  }
  if (ans.size() != n - 1 || !check(ans)) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (auto p : ans) cout << p.first << ' ' << p.second << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}