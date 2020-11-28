#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1e9+7
#define ll long long
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<set<int>> graph(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		graph[x].insert(y);
		graph[y].insert(x);
	}
	vector<int> val(n, 1);
	queue<int> leafs;
	for (int i = 0; i < n; i++)
		if (graph[i].size() == 1)
			leafs.push(i);
	while (!leafs.empty()) {
		int v = leafs.front();
		leafs.pop();
		int to = *graph[v].begin();
		val[to] += val[v];
		val[v] = 0;
		graph[v].clear();
		graph[to].erase(v);
		if (graph[to].size() == 1) {
			leafs.push(to);
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)val[i] * (val[i] - 1) / 2;
		ans += (ll)val[i] * (n - val[i]);
	}
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
