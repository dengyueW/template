#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//  1.0
template <typename T>
void bubbleSort1(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i = 1; i < n; i++)
            if(arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
//  �Ż�, ÿһ��Bubble Sort��������Ԫ�ط���������λ��
//  ������һ������, ����Ԫ�ؿ��Բ��ٿ���
        n--;
    } while(swapped);
}

//  2.0
template<typename T>
void bubbleSort2(T arr[], int n) {
    int newn; // ʹ��newn�����Ż�
    do {
        newn = 0;
        for(int i = 1; i < n; i++)
            if(arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
//  ��¼���һ�εĽ���λ��,�ڴ�֮���Ԫ������һ��ɨ���о�������
                newn = i;
            }
        n = newn;
    } while(newn > 0);
}
int main() {

//  ����
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort2(a, 10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

//  ����
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    bubbleSort2(b, 4);
    for(int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

//  �ַ�
    string c[4] = {"D", "C", "B", "A"};
    bubbleSort2(c, 4);
    for(int i = 0; i < 4; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}