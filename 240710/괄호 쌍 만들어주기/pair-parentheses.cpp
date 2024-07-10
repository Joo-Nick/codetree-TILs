#include <iostream>
#include <string>

#define MAX_N 100000

using namespace std;

int n;
string str;
int R[MAX_N];

int main() {
    // 입력:
    cin >> str;
    n = (int) str.size();
    
    R[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(str[i] == ')' && str[i + 1] == ')')
            R[i] = R[i + 1] + 1;
        else
            R[i] = R[i + 1];
    }
    long long ans = 0;
    for(int i = 0; i < n - 2; i++) {
        if(str[i] == '(' && str[i + 1] == '(')
            ans += R[i + 2];
    }
    cout << ans;
    return 0;
}