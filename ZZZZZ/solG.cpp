#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long
#define N 2e5+5
vector<bool>isPrime(N, true);
vector<bool>isSemiPrime(N, true);

void solve() {
	int n;
	cin >> n;
	map<int, int>freq;
	set<int>st1;
	set<int>st2;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (isPrime[x]) {
			st1.insert(x);
			cnt++;
		}
		else if (isSemiPrime[x]) {
			st2.insert(x);
		}
		freq[x]++;
	}
	// debug(freq);
	// debug(st1, st2);
	map<int, bool>vis;
	for (int pn1 : st1) {
		for (int pn2 : st2) {
			if (pn2 % pn1 == 0) {
				ans += freq[pn2] * freq[pn1];
				// debug(pn2);
				// debug(pn1);
				// debug(ans);
			}
		}
		int y  = freq[pn1];
		ans -= (y * (y - 1)) / 2;
	}
	for (auto it : st2) {
		ans += freq[it] + (freq[it] * (freq[it] - 1)) / 2;
	}
	cout << (ans + (cnt * (cnt - 1)) / 2) << "\n";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(0);
	cin.tie(0);

	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < N; j += i) {
				isPrime[j] = 0;
			}
		}
	}

	isSemiPrime[0] = isSemiPrime[1] = 0;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			isSemiPrime[i] = 0;
			for (int j = i * i; j < N; j += i) {
				if (!isPrime[j / i]) {
					isSemiPrime[j] = 0;
				}
			}
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}