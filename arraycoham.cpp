#include <iostream>  
#include <algorithm> // De su dung std::sort  
#include <numeric>   // De su dung std::accumulate  

using namespace std;

const int MAX_SIZE = 100; // Kich thuoc toi da cua mang  

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Ham sap xep mang tang dan  
void sortAscending(int arr[], int size) {
    sort(arr, arr + size);
}

// Ham sap xep mang giam dan  
void sortDescending(int arr[], int size) {
    sort(arr, arr + size, greater<int>());
}

// Ham them mot phan tu vao mang  
int addElement(int arr[], int& size, int element) {
    if (size < MAX_SIZE) {
        arr[size] = element;
        size++;
        return 1; // Thao tac thanh cong  
    }
    return 0; // Khong the them phan tu  
}

// Ham bot mot phan tu tu mang  
int removeElement(int arr[], int& size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            break;
        }
    }

    if (i < size) {
        // Di chuyen cac phan tu con lai ve ben trai  
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--; // Giam size sau khi xoa  
        return 1; // Thao tac thanh cong  
    }
    return 0; // Khong tim thay phan tu de xoa  
}

// Ham tim vi tri cua phan tu lon nhat  
int findMax(const int arr[], int size) {
    if (size == 0) return -1; // Tra ve -1 neu mang rong  
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Ham tim vi tri cua phan tu nho nhat  
int findMin(const int arr[], int size) {
    if (size == 0) return -1; // Tra ve -1 neu mang rong  
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Ham tinh tong cua mang  
int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Ham tinh trung binh cua mang  
double averageArray(const int arr[], int size) {
    if (size == 0) return 0.0; // Tranh chia cho 0 neu mang rong  
    return static_cast<double>(sumArray(arr, size)) / size;
}

int main() {
    int arr[MAX_SIZE] = { 5, 3, 8, 1, 4 };
    int size = 5; // Kich thuoc hien tai cua mang  

    cout << "Nhap mang: ";
    displayArray(arr, size);

    sortAscending(arr, size);
    cout << "Mang sau khi sap xep tang dan: ";
    displayArray(arr, size);

    sortDescending(arr, size);
    cout << "Mang sau khi sap xep giam dan: ";
    displayArray(arr, size);

    if (addElement(arr, size, 10)) {
        cout << "Mang sau khi them 10: ";
        displayArray(arr, size);
    }
    else {
        cout << "Khong the them phan tu.\n";
    }

    if (removeElement(arr, size, 3)) {
        cout << "Mang sau khi xoa 3: ";
        displayArray(arr, size);
    }
    else {
        cout << "Khong tim thay phan tu de xoa.\n";
    }

    int maxIndex = findMax(arr, size);
    if (maxIndex >= 0) {
        cout << "Vi tri phan tu lon nhat: " << maxIndex << " (" << arr[maxIndex] << ")\n";
    }

    int minIndex = findMin(arr, size);
    if (minIndex >= 0) {
        cout << "Vi tri phan tu nho nhat: " << minIndex << " (" << arr[minIndex] << ")\n";
    }

    cout << "Tong cac phan tu: " << sumArray(arr, size) << endl;
    cout << "Trung binh cac phan tu: " << averageArray(arr, size) << endl;

    return 0;
}