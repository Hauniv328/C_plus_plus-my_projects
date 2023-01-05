#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int finding(char);
string list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    long long n, m;
    string x;
    bool ok = true;

    cout << "N진수 X를 M진수로 변환할 때" << "\n";
    cout << "N = ", cin >> n;
    cout << "X = ", cin >> x;
    cout << "M = ", cin >> m;
    cout << "-----------------------" << endl;

    int cycle = x.length();

    long long a = 0, b = 0, mem = 0;

    reverse(x.begin(), x.end());
    for (int i = 0; i < cycle; i++) {
        a = pow(n, i);
        b = finding(x[i]);
        if (b < n) {
            mem += a * b;
        }
        else {
            cout << "잘 못 된 수 입니다.";
            ok = false;
            break;
        }
    }

    if(n == 10 && ok) {
        reverse(x.begin(), x.end());
        mem = stoi(x);
    }

    string out;
    while (true) {
        a = mem % m;
        mem /= m;

        out += list[a];
        if(mem == 0) break;
    }

    if(ok) {
        reverse(out.begin(), out.end());
        cout << "변환된 값: " << out << endl;
    }
    return 0;
}

int finding(char target) {
    int rtn = 0;
    for (int i = 0; i < 36; i++) {
        if(list[i] == target) {
            rtn = i;
            break;
        }
    }

    return rtn;
}
