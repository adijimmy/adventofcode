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

bool check(vector<string> &v) {
    if (v.size() == 16) return true;
    if (v.size() < 14) return false;
    bool res = true;
    if (v.size() == 14) {
        for (int i = 0; i < v.size(); i += 2) {
            if (v[i] == "cid") {
                res = false;
            }
        }
    }
    return res;
}

bool checkChars(string s) {
    int n = s.length();
    if (n != 9) return false;
    for (int i = 0; i < 9; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }
    return true;
}

bool verifyHeight(string s) {
    string str = "";
    string type;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            str += s[i];
        } else {
            if (s[i] == 'c') {
                type = "cm";
            } else {
                type = "in";
            }
            break;
        }
    }
    if (type == "cm") {
        return str >= "150" && str <= "193";
    } else {
        return str >= "59" && str <= "76";
    }
    return false;
}

bool verifyHairColor(string s) {
    if (s.length() == 0 || s.length() != 7) return false;
    if (s[0] != '#') return false;
    string str = "";
    for (int i = 1; i < s.length(); i++) {
        str += s[i];
    }
    for (int i = 0; i < str.size(); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f'))) {
            return false;
        }
    }
    return true;
}

bool validate(vector<string> &v) {
    bool res = true;
    for (int i = 0; i < v.size(); i += 2) {
        string s = v[i];
        if (s == "byr") {
            res &= (v[i + 1] >= "1920" && v[i + 1] <= "2002");
        } else if (s == "iyr") {
            res &= (v[i + 1] >= "2010" && v[i + 1] <= "2020");
        } else if (s == "eyr") {
            res &= (v[i + 1] >= "2020" && v[i + 1] <= "2030");
        } else if (s == "hgt") {
            res &= verifyHeight(v[i + 1]);
        } else if (s == "hcl") {
            res &= verifyHairColor(v[i + 1]);
        } else if (s == "ecl") {
            res &= (v[i + 1] == "amb" || v[i + 1] == "blu" || v[i + 1] == "brn" || v[i + 1] == "gry" || v[i + 1] == "grn" || v[i + 1] == "hzl" || v[i + 1] == "oth");
        } else if (s == "pid") {
            res &= checkChars(v[i + 1]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    int res = 0;
    vector<string> v;
    vector<string> vv;
    string token;
    while (getline(cin, s)) {
        if (s.length() == 0) {
            for (int i = 0; i < v.size(); i++) {
                string str = v[i];
                stringstream ss(str);
                while (getline(ss, token, ':')) {
                    vv.push_back(token);
                }
            }
            if (check(vv) && validate(vv)) {
                res++;
            }
            v.clear();
            vv.clear();
        }
        stringstream ss(s);
        while (getline(ss, token, ' ')) {
            v.push_back(token);
        }
    }
    vv.clear();
    for (int i = 0; i < v.size(); i++) {
        string str = v[i];
        stringstream ss(str);
        while (getline(ss, token, ':')) {
            vv.push_back(token);
        }
    }
    if (check(vv) && validate(vv)) {
        res++;
    }
    cout << res << endl;
    return 0;
}