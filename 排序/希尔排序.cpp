#include <iostream>
#include <string>

using namespace std;

//  写法1
template <typename T>
void shellSort1(T arr[], int n) {
    int i, j, gap;   //  gap为步长，每次减为原来的一半。
    for(gap = n / 2; gap > 0; gap /= 2) {
//  共gap个组，对每一组都执行直接插入排序
        for(i = 0; i < gap; i++) {
            for(j = i + gap; j < n; j += gap) { 
//  如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
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

//  写法2
template <typename T>
void shellSort2(T arr[], int n){
//  计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while(h < n / 3) h = 3 * h + 1;
    while(h >= 1) {
//  h-sort the array
        for(int i = h; i < n; i ++) {
//  对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
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

    //  整型
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    shellSort2(a, 10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

//  浮点
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    shellSort2(b, 4);
    for(int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

//  字符
    string c[4] = {"D", "C", "B", "A"};
    shellSort2(c, 4);
    for(int i = 0; i < 4; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}