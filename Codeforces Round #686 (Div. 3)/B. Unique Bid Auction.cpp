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
	vector<int> count(n + 1, 0);
	vector<int> index(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		count[x]++;
		index[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (count[i] == 1) {
			cout << index[i] << endl;
			return;
		}
	}
	cout << -1 << endl;

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
