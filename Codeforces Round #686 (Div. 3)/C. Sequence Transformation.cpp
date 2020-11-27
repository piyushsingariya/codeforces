#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define SORT(v) sort(all(v))
#define itr(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ff first
#define ss second
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
using namespace std;
long long MOD = pow(2, 32);

void solve() {
	int n;
	cin >> n;
	map<int, pair<int, int>> hash;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (hash.count(x)) {
			int last_pos = hash[x].first;
			int segments = hash[x].second;
			if (i > last_pos + 1)
				segments++;
			hash[x] = {i, segments};
		} else {
			hash[x] = {i, (i == 0 ? 0 : 1)};
		}
	}

	int segments = n;
	for (auto e : hash) {
		if (e.second.second < segments) {
			segments = e.second.second + (e.second.first == n - 1 ? 0 : 1);
		}
	}
	cout << segments << endl;

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
