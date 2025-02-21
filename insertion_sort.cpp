#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int pivot = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > pivot) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = pivot;
    }
    
    cout << "Elements After Sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
