
int find(int arr[], int n, int target) {
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        } else if (arr[mid] > target) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int greaterThan(int arr[], int n, int target) {
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        } else if (arr[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int lessThan(int arr[], int n, int target) {
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi) {
        mid = (hi + lo) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        } else if (arr[mid] > target) {
            hi = mid - 1;
        } else {
            hi = mid - 1;
        }
    }

    return hi;
}