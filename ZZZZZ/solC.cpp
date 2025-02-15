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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int minId = 0;
	for (int j = 0; j < m; j++) {
		cin >> b[j];
		if (b[minId] > b[j]) {
			minId = j;
		}
	}
	vector<int>lexMin;
	for (int i = minId; i < m; i++) {
		lexMin.push_back(b[i]);
	}

	for (int i = 0; i < minId; i++) {
		lexMin.push_back(b[i]);
	}
	bool found = 0;
	for (int i = 1; i < m; i++) {
		if (lexMin[0] < lexMin[i]) {
			found = 1;
			break;
		}
	}
	debug(found);
	int ptrA = 0;
	int ptrB = 0;
	int cur = -1;
	bool found1 = 0;
	int x = -1;
	debug(lexMin);
	while (ptrA < n) {
		debug(a);
		debug(a[ptrA]);
		if (a[ptrA] < lexMin[ptrB]) {
			ptrA++;
		}
		else if (a[ptrA] == lexMin[ptrB]) {
			if (ptrA > n - m)break;
			x = ptrA;
			if (ptrA == n - m) {
				while (a[ptrA] == lexMin[ptrB] && ptrA < n && ptrB < m) {
					ptrA++;
					ptrB++;
				}
			}
			else {
				while (a[ptrA] == lexMin[ptrB] && ptrA < n) {
					ptrA++;
				}
			}
			if (ptrA < n && a[ptrA] > lexMin[ptrB]) {
				found1 = true;
			}
		}
		else {
			if (found1) {
				ptrA = x;
				found1 = 0;
			}
			if (found) {
				for (int i = ptrA; i < n - m; i++) {
					a[i] = lexMin[0];
				}
				if (ptrA <= n - m) {
					int cur = 0;
					for (int i = n - m; i < n; i++) {
						a[i] = lexMin[cur];
						cur++;
					}
				}
				break;
			}
			else {
				if (n - (ptrA + m) >= 0) {
					int cur = 0;
					for (int i = ptrA; i < ptrA + m; i++) {
						a[i] = lexMin[cur];
						cur++;
					}
					ptrA += m;
				}
				else {
					break;
				}
			}
		}
	}
	for (auto it : a) {
		cout << it << " ";
	}
	cout << "\n";


}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}