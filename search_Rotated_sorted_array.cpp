#include<iostream>
using namespace std;

void binary_search(int arr[], int l, int h, int tar) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == tar) {
            cout << tar << " Found in the Given array...\n";
            return;
        } else if (arr[mid] < tar) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    cout << tar << " NOT found in the given array..\n";
}

void search(int arr[], int l, int h, int tar) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        
        if (arr[mid] == tar) {
            cout << tar << " Found in the Given array...\n";
            return;
        }

        // Check if the left half is sorted
        if (arr[l] <= arr[mid]) {
            if (arr[l] <= tar && tar < arr[mid]) {
                binary_search(arr, l, mid - 1, tar); // Use binary search on the sorted half
                return;
            } else {
                l = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < tar && tar <= arr[h]) {
                binary_search(arr, mid + 1, h, tar); // Use binary search on the sorted half
                return;
            } else {
                h = mid - 1;
            }
        }
    }
    cout << tar << " NOT found in the given array..\n";
}

int main() {
    int arr[] = {12, 15, 18, 2, 5, 6, 8, 9}; // Proper rotated sorted array
    int tar;
    cout << "Element to be Searched: ";
    cin >> tar;
    search(arr, 0, 7, tar);
    return 0;
}
