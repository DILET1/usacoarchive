#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int t;
int n;
int p;
string s1;
string s2;

const int SIZE = 3e5+10;
pair<int,int> a1a[SIZE];
pair<int,int> a2a[SIZE];
int a1;
int a2;

string flatten(string &str) {
    string compressedStr;
    compressedStr.reserve(str.length());
    for (int i = 0; i < str.length(); ++i) {
        if (i == 0 || (str[i] != str[i - 1])) {
            compressedStr += str[i];
        }
    }
    return compressedStr;
} 

void solve(string ls1, string ls2, pair<int,int> ord, pair<int,int> *larr, int &lac) {
    if (ls1.length() == ls2.length() && ls1.length() == 1) {
        return;
    }
    if (ls1.back() == ls2.back()) {
        if (ls2.length() > ls1.length()) {
            ls2.pop_back();
            larr[++lac] = {ord.second, ord.first};
        }
        else {
            ls1.pop_back();
            larr[++lac] = {ord.first, ord.second};
        }
    }
    if (ls1.length() == ls2.length() && ls1.length() == 1) {
        return;
    }
    int flg = 0;
    if (ls1.length() > 1) {
        if (ls2.back() != ls1[0]) {
            larr[++lac] = {ord.second, 3};
            ls2.pop_back();
        }
        else {
            larr[++lac] = {ord.first, 3};
            ls1.pop_back();
        }
        for (int i = (int)ls1.length() - 1; i >= 1; --i) {
            if (ls1[i] == ls2.back()) {
                larr[++lac] = {ord.first, ord.second};
            }
            else {
                larr[++lac] = {ord.first, 3};
            }
        }
        if (ls2.back() != ls1.back()) {
            larr[++lac] = {3, ord.first};
            if (ls2.length() <= 1) {
                return;
            }
        }
        else {
            larr[++lac] = {ord.second, ord.first};
            ls2.pop_back();
            flg = 1;
            if (ls2.length() <= 1) {
                larr[++lac] = {3, ord.second};
                return;
            }
        }
    }

    if (!flg) {
        larr[++lac] = {ord.second, 3};
        ls2.pop_back();
    }
    for (int i = (int)ls2.length() - 1; i >= 1; --i) {
        if (ls1[0] == ls2[i]) {
            larr[++lac] = {ord.second, ord.first};
        }
        else {
            larr[++lac] = {ord.second, 3};
        }
    }

    if (ls2[0] != ls1[0]) {
    	larr[++lac] = {3, ord.second};

    }
    else {
    	larr[++lac] = {ord.second, ord.first};
        larr[++lac] = {3, ord.second};
    }
}
void test(){
	cin >> n >> p;
        cin >> s1 >> s2;
        s1 = flatten(s1);
        s2 = flatten(s2);
        a1 = a2 = 0;
        solve(s1,s2, make_pair(1,2), a1a, a1);
        solve(s2,s1 ,make_pair(2,1), a2a, a2);
        cout << min(a1, a2) << endl;
        if (p > 1) {
            if (a1 == min(a1, a2)) {
                for (int i = 1; i <= a1; ++i) {
                    cout << a1a[i].first << " " << a1a[i].second << endl;
                }
            }
            else {
                for (int i = 1; i <= a2; ++i) {
                    cout << a2a[i].first << " " << a2a[i].second << endl;
                }
            }
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        test();
    }
}

