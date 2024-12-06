#include <iostream>  
#include <algorithm> // De su dung std::sort  
#include <numeric>   // De su dung std::accumulate  

using namespace std;

const int MAX_SIZE = 100; // Kich thuoc toi da cua mang  

int main() {
    int arr[MAX_SIZE] = { 5, 3, 8, 1, 4 }; // Mang ban dau  
    int size = 5; // Kich thuoc hien tai cua mang  

    // Hien thi mang  
    cout << "Nhap mang: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sap xep tang dan  
    sort(arr, arr + size);
    cout << "Mang sau khi sap xep tang dan: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sap xep giam dan  
    sort(arr, arr + size, greater<int>());
    cout << "Mang sau khi sap xep giam dan: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Them phan tu 10 vao mang  
    if (size < MAX_SIZE) {
        arr[size] = 10;
        size++;
        cout << "Mang sau khi them 10: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Bot phan tu 3 tu mang  
    int removeElement = 3;
    for (int i = 0; i < size; i++) {
        if (arr[i] == removeElement) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1]; // Di chuyen cac phan tu con lai  
            }
            size--; // Giam size sau khi xoa  
            break; // Thoat khoi vong lap  
        }
    }
    cout << "Mang sau khi xoa 3: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Tim vi tri phan tu lon nhat  
    if (size > 0) {
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        cout << "Vi tri phan tu lon nhat: " << maxIndex << " (" << arr[maxIndex] << ")\n";
    }

    // Tim vi tri phan tu nho nhat  
    if (size > 0) {
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        cout << "Vi tri phan tu nho nhat: " << minIndex << " (" << arr[minIndex] << ")\n";
    }

    // Tinh tong cac phan tu  
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Tong cac phan tu: " << sum << endl;

    // Tinh trung binh cac phan tu  
    double average = (size > 0) ? static_cast<double>(sum) / size : 0.0; // Tranh chia cho 0  
    cout << "Trung binh cac phan tu: " << average << endl;

    return 0;
}