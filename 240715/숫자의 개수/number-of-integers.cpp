#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n, m;
int arr[MAX_N];

int LowerBound(int target) {
    int left = 0, right = n - 1;
    int min_idx = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] >= target) {
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else
            left = mid + 1;
    }

    return min_idx;
}

int UpperBound(int target) {
    int left = 0, right = n - 1;
    int min_idx = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] > target) {
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else
            left = mid + 1;
    }

    return min_idx;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        
        int count = UpperBound(x) - LowerBound(x);
        cout << count << endl;
    }
    return 0;
}