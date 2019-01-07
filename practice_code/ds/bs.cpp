// Example program
#include <iostream>
#include <string>
using namespace std;
int findpivot(int a[], int low, int high) {
    if (high < low)  return -1;
    if (low == high) return low;
    int mid = low + (high-low)/2;
    if ((mid > low) && (a[mid] < a[mid-1])) {
        return (mid - 1);
    }
    if ((mid < high) && (a[mid] > a[mid+1])) {
        return mid;
    }

    if (a[low] <= a[mid])
        return findpivot(a, mid+1, high);

    return findpivot(a, low, mid-1);
}

int findpivot2(int a[], int low, int high) {
    while (low <= high) {
        int mid = low + (high-low)/2;
        if ((mid > low) && (a[mid] < a[mid-1])) {
            return (mid - 1);
        }
        if ((mid < high) && (a[mid] > a[mid+1])) {
            return mid;
        }
        if (a[low] <= a[mid]) {
            low = mid + 1;
        } else {
            high  = mid -1;
        }
    }
    return -1;
}

int binarysearch(int a[], int n, int x, bool searchfirst) {
    int low = 0, high = n-1, result = -1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if (a[mid] == x) {
            result = mid;
            if (searchfirst) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (x > a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int a[] = {1,2,3,4};
    int size = sizeof(a)/sizeof(int);
    int pivot_index = findpivot2(a, 0, size-1);
    cout << "pivot index " << pivot_index << endl;
    cout << "index = " << binarysearch(a, size, 2, true) << endl;
    cout << "index = " << binarysearch(a, size, 2, false) << endl;
}
