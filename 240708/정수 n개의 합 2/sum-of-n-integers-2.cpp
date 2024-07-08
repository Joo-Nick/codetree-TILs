#include <iostream>
#include <climits>

using namespace std;

#define Max_N 100001

int n, k, z;
int ans = INT_MIN;
int arr[Max_N] = {};
int sum[Max_N] = {};
int GetSum(int s, int e) {
    return sum[e] - sum[s - 1];
}

int main() {

    cin >> n >> k;

    sum[0] = arr[0];
    for(int i = 1; i <= n; i++){
        cin >> z;
        arr[i] = z;
    }
    
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 1; i <= n - k + 1; i++)
    ans = max(ans, GetSum(i, i + k - 1));

    cout << ans;
    return 0;
}