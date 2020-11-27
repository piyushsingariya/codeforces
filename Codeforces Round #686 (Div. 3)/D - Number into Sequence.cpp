#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1e9+7
#define ll long long
using namespace std;

void solve() {
	long long n;
	cin >> n;
	long long temp = n;
	vector<pair<ll, ll>> factors;

	for (ll i = 2; i * i <= n; i++) {
		int count = 0;
		while (n % i == 0) {
			count++;
			n /= i;
		}
		if (count > 0)
			factors.push_back({count, i});
	}
	if (n > 1) {
		factors.push_back({1, n});
	}
	if (factors.size() == 1 && factors[0].second == temp ) {
		cout << factors[0].first << endl;
		cout << factors[0].second << endl;
		return;
	}
	sort(factors.rbegin(), factors.rend());
	vector<long long> res;

	for (int i = 0; i < factors[0].first; i++)
		res.push_back(factors[0].second);
	long long rest = temp / (long long)pow(factors[0].second, factors[0].first);
	if (rest > 1)
		res[res.size() - 1] *= rest;
	cout << res.size() << endl;
	for (auto e : res)
		cout << e << " ";
	cout << endl;

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
