#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define mp make_pair

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

template<typename T>
vector<T> inputVector(int n) {
	vector<T> arr(n);
	for(auto &v: arr) {
		cin >> v;
	}
	return arr;
}

template<typename T>
void displayVector(vector<T>& arr) {
	for(auto &v: arr) {
		cout << v << ' ';
	}
	cout << '\n';
}

void solve(int testCase) {
	
}

int main() {
	setIO();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve(t);
    }
}