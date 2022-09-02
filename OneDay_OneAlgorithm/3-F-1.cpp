#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper;
int n, ret = -987654321;
string s;

int calc(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void func(int idx, int calcRet)
{
    if (idx >= num.size() - 1)
    {
        ret = max(ret, calcRet);
        return;
    }
    int temp = calc(oper[idx], calcRet, num[idx + 1]);
    func(idx + 1, temp);
    if (idx + 2 <= num.size() - 1)
    {
        int tem = calc(oper[idx + 1], num[idx + 1], num[idx + 2]);
        func(idx + 2, calc(oper[idx], calcRet, tem));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)num.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    }
    func(0, num[0]);
    cout << ret << "\n";
    return 0;
}