#include <iostream>
using namespace std;

void merge(int arr[], int l, int h, int mid) {
    int lsize = mid - l + 1, rsize = h - mid;
    int larr[lsize], rarr[rsize];
    
    for (int i = 0; i < lsize; i++) {
        larr[i] = arr[l + i];
    }
    for (int i = 0; i < rsize; i++) {
        rarr[i] = arr[mid + 1 + i];
    }
    
    int i = l, j = 0, k = 0;
    while (j < lsize && k < rsize) {
        if (larr[j] < rarr[k]) {
            arr[i++] = larr[j++];
        } else {
            arr[i++] = rarr[k++];
        }
    }
    while (j < lsize) {
        arr[i++] = larr[j++];
    }
    while (k < rsize) {
        arr[i++] = rarr[k++];
    }
}

void divide(int arr[], int l, int h) {
    if (l < h) {
        int mid = l + (h - l) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        merge(arr, l, h, mid);
    }
}

int main() {
    int arr[] = {986, 45, 65, 246, 1};
    int n = 5;
    
    divide(arr, 0, n - 1);
    
    cout << "Elements After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
