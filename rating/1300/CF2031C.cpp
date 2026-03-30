#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  if (!(n & 1)) {
  	rep(i, 1, n / 2) cout << i << ' ' << i << ' ';
  	cout << endl;
  } else {
  	if (n < 27) {
  		cout << -1 << endl;
  	} else {
  		a[1] = a[10] = a[26] = 1;
  		a[23] = a[27] = 2;
  		a[24] = a[25] = 3;
  		int k = 4;
  		for (int i = 2; i < 10; i += 2) a[i] = a[i + 1] = k++;
  		for (int i = 11; i < 23; i += 2) a[i] = a[i + 1] = k++;
  		for (int i = 28; i < n; i += 2) a[i] = a[i + 1] = k++;
  		rep(i, 1, n) cout << a[i] << ' ';
  		cout << endl;
  	}
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