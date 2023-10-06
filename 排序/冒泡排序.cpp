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
//  优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
//  所以下一次排序, 最后的元素可以不再考虑
        n--;
    } while(swapped);
}

//  2.0
template<typename T>
void bubbleSort2(T arr[], int n) {
    int newn; // 使用newn进行优化
    do {
        newn = 0;
        for(int i = 1; i < n; i++)
            if(arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
//  记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        n = newn;
    } while(newn > 0);
}
int main() {

//  整型
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort2(a, 10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

//  浮点
    float b[4] = {4.4, 3.3, 2.2, 1.1};
    bubbleSort2(b, 4);
    for(int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

//  字符
    string c[4] = {"D", "C", "B", "A"};
    bubbleSort2(c, 4);
    for(int i = 0; i < 4; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}