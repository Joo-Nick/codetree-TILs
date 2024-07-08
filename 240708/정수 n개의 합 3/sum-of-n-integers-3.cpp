#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 500

int n, k;
int ans = INT_MIN;
int arr[MAX_N + 1][MAX_N + 1];
int sum[MAX_N + 1][MAX_N + 1];

int GetSum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2]     - sum[x1 - 1][y2] -
           sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++)
            cin >> arr[i][j];
    }
    
    sum[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
    }

    for(int i = 1; i <= n - k + 1; i++)
        for(int j = 1; j <= n - k + 1; j++)
            ans = max(ans, GetSum(i, j, i + k - 1, j + k - 1));

    cout << ans;
    return 0;
}