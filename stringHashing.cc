#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 9;
const int p = 29, mod = 1e9 + 7;

int pw[N];
void precal () {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = (1LL * pw[i - 1] * p) % mod;
    }
}

int getHash (string str) {
    int hash = 0;
    for (int i = 0; i < str.size(); i++) {
        hash += (1LL * pw[i] * (str[i] - 'a' + 1)) % mod;
        hash %= mod;
    }

    return hash;
}

int32_t main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    precal();
    string a, b;
    cin >> a >> b;

    cout << getHash(a) << ' ' << getHash(b) << endl;          

    return 0;
}
