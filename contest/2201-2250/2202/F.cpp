#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, q;
int a[N];
set<int> pos[N];
struct Node {
  ll ans;
  set<pii> seg;
};
map<int, Node> mp;
ll get_cnt(ll d) { return (d + 1) * d / 2; }
int first(int x) {
  if (pos[x].empty()) return 0;
  return *pos[x].begin();
}
int last(int x) {
  if (pos[x].empty()) return 0;
  return *pos[x].rbegin();
}
int mxd(int x) {
  if (pos[x].size() < 2) return 0;
  return last(x) - first(x);
}
void add(int k, int p) {
  if (k < 1) return;
  pii now{p, p};
  if (!mp.count(k)) {
    mp[k] = {0, set<pii>()};
    mp[k].ans = 1;
    mp[k].seg.insert(now);
    return;
  }
  auto& seg = mp[k].seg;
  ll& ans = mp[k].ans;
  auto it2 = seg.lower_bound(now);
  auto it1 = it2;
  if (it1 != seg.begin()) it1--;
  if (it1 != seg.end() && it1->second == p - 1) {
    now.first = it1->first;
    ans -= get_cnt(it1->second - it1->first + 1);
    seg.erase(it1);
  }
  if (it2 != seg.end() && it2->first == p + 1) {
    now.second = it2->second;
    ans -= get_cnt(it2->second - it2->first + 1);
    seg.erase(it2);
  }
  ans += get_cnt(now.second - now.first + 1);
  seg.insert(now);
}
void del(int k, int p) {
  if (k < 1) return;
  auto& seg = mp[k].seg;
  ll& ans = mp[k].ans;
  auto it = seg.lower_bound(pii(p + 1, p + 1));
  it--;
  int l = it->first, r = it->second;
  ans -= get_cnt(r - l + 1);
  seg.erase(it);
  if (l < p) {
    ans += get_cnt(p - l);
    seg.insert(pii(l, p - 1));
  }
  if (r > p) {
    ans += get_cnt(r - p);
    seg.insert(pii(p + 1, r));
  } 
}
void solve() {
  cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) pos[i].clear();
  rep(i, 1, n) pos[a[i]].insert(i);
  mp.clear();
  rep(i, 1, n) {
    int d = mxd(i);
    if (d) add(d, first(i));
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    int d0 = mxd(a[i]), l0 = first(a[i]);
    pos[a[i]].erase(i);
    int d1 = mxd(a[i]), l1 = first(a[i]);
    if (d0 != d1) {
      if (d0) del(d0, l0);
      if (d1) add(d1, l1);
    }
    d0 = mxd(x), l0 = first(x);
    a[i] = x;
    pos[a[i]].insert(i);
    d1 = mxd(x), l1 = first(x);
    if (d0 != d1) {
      if (d0) del(d0, l0);
      if (d1) add(d1, l1);
    }
    while (mp.size() && mp.rbegin()->second.ans == 0) mp.erase(mp.rbegin()->first);
    if (mp.empty()) cout << 0 << ' ' << 0 << endl;
    else cout << mp.rbegin()->first << ' ' << mp.rbegin()->second.ans << endl;
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