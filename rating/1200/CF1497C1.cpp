#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, k;
int a[N];

void solve() {
  cin >> n >> k;
  if (n & 1) {
  	cout << n / 2 << ' ' << n / 2 << ' ' << 1 << endl;
  } else if (n % 4 == 0) {
  	cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
  } else {
  	cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << endl; 
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