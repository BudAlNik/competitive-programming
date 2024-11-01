// Created by Nikolay Budin

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;

struct input_data {
	
};

istream& operator>>(istream& in, input_data& dt) {
	
	return in;
}

struct output_data {
	
};

ostream& operator<<(ostream& out, output_data const& dt) {
	
	return out;
}

output_data solve(input_data const& test) {
	
}

int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int test_count = 1;
	cin >> test_count;

#ifdef NOPARALLEL
	for (int i = 0; i < test_count; ++i) {
		input_data test;
		cin >> test;
		auto ans = solve(test);
		cout << "Case #" << i + 1 << ": " << ans;
		cerr << "test #" << i + 1 << " has finished";
	}
#else
	vector<input_data> tests(test_count);
	vector<future<output_data>> results;
	for (int i = 0; i < test_count; ++i) {
		cin >> tests[i];
		results.push_back(async(solve, tests[i]));
	}

	set<int> ready;
	do {
		for (int i = 0; i < test_count; ++i) {
			if (!ready.count(i) && results[i].wait_for(0.1s) == future_status::ready) {
				ready.insert(i);
				
				cerr << (test_count - szof(ready)) << "/" << test_count << " tests";

				if (test_count - szof(ready) <= 10 && szof(ready) < test_count) {
					cerr << " (";
					bool fl = false;
					for (int j = 0; j < test_count; ++j) {
						if (!ready.count(j)) {
							if (fl) {
								cerr << ", ";
							}
							fl = true;
							cerr << "#" << j + 1;
						}
					}
					cerr << ")";
				}

				cerr << " are left (" << "test #" << i + 1 << " is ready)" << endl;
			}
		}
	} while (szof(ready) < test_count);

	for (int i = 0; i < test_count; ++i) {
		cout << "Case #" << i + 1 << ": " << results[i].get();
	}
#endif
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}