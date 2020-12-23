#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll getFact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

int getValue(string s) {
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
    }
    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return neg ? -1 * res : res;
}

const int N = 93;
const int M = 97;
char a[94][98];
char b[94][98];

void copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}

bool isSame() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

bool ok(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int Y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 'L') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int ni = i + X[k];
                        int nj = j + Y[k];
                        while (ok(ni, nj)) {
                            if (a[ni][nj] == 'L') break;
                            if (a[ni][nj] == '#') {
                                cnt++;
                                break;
                            }
                            ni += X[k];
                            nj += Y[k];
                        }
                    }
                    if (cnt == 0) {
                        b[i][j] = '#';
                    } else {
                        b[i][j] = a[i][j];
                    }
                } else if (a[i][j] == '#') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int ni = i + X[k];
                        int nj = j + Y[k];
                        while (ok(ni, nj)) {
                            if (a[ni][nj] == 'L') break;
                            if (a[ni][nj] == '#') {
                                cnt++;
                                break;
                            }
                            ni += X[k];
                            nj += Y[k];
                        }
                    }
                    if (cnt >= 5) {
                        b[i][j] = 'L';
                    } else {
                        b[i][j] = a[i][j];
                    }
                } else {
                    b[i][j] = a[i][j];
                }
            }
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << b[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl << endl;
        if (isSame()) break;
        copy();
    }
    copy();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '#') {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}