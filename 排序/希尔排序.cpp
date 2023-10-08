#include <iostream>
#include <string>

using namespace std;

//  д��1
template <typename T>
void shellSort1(T arr[], int n) {
    int i, j, gap;   //  gapΪ������ÿ�μ�Ϊԭ����һ�롣
    for(gap = n / 2; gap > 0; gap /= 2) {
//  ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for(i = 0; i < gap; i++) {
            for(j = i + gap; j < n; j += gap) { 
//  ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
                if(arr[j] < arr[j - gap]) {
                    T tmp = arr[j];
                    int k = j - gap;
                    while (k >= 0 && arr[k] > tmp) {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = tmp;
                }
            }
        }
    }
}

//  д��2
template <typename T>
void shellSort2(T arr[], int n){
//  ���� increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while(h < n / 3) h = 3 * h + 1;
    while(h >= 1) {
//  h-sort the array
        for(int i = h; i < n; i ++) {
//  �� arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... ʹ�ò�������
            T e = arr[i];
            int j;
            for(j = i; j >= h && e < arr[j-h]; j -= h)
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h /= 3;
    }
}

int main() {

    //  ����
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    shellSort2(a, 10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

//  ����
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    shellSort2(b, 4);
    for(int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

//  �ַ�
    string c[4] = {"D", "C", "B", "A"};
    shellSort2(c, 4);
    for(int i = 0; i < 4; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}