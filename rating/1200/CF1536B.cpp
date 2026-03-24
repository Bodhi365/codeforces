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

string bfs() {
	queue<string> q;
	q.push("");
	while (true) {
		string now = q.front();
		q.pop();
		for (char c = 'a'; c <= 'z'; c++) {
			now.push_back(c);
			if (s.find(now) == string::npos) return now;
			q.push(now);
			now.pop_back();
		}
	}
	return "";
}
void solve() {
  cin >> n;
  cin >> s;
  cout << bfs() << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}