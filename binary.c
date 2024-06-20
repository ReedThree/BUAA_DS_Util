 
int find(int arr[], int n, int target)
{
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (arr[mid] < target)
        {
            lo = mid + 1;
        }
        else if (arr[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int equalOrGreaterThan(int arr[], int n, int target)
{
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (arr[mid] < target)
        {
            lo = mid + 1;
        }
        else if (arr[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (lo < 0)
    {
        return 0;
    }
    return lo;
}

int equalOrLessThan(int arr[], int n, int target)
{
    int hi = n - 1;
    int lo = 0;
    int mid = (hi + lo) / 2;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (arr[mid] < target)
        {
            lo = mid + 1;
        }
        else if (arr[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (hi < 0)
    {
        return 0;
    }
    return hi;
}
