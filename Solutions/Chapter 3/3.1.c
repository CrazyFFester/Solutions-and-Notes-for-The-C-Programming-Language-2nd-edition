

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low;
    int high;
    int mid;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x == v[mid]) /* found match */
            return mid;

        (x < v[mid]) ? (high = mid - 1) : (low = mid + 1);
    }
    return -1; /* no match */
}
