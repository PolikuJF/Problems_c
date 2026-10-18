#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--) {
        int a;
        std::cin >> a;
        int *arr = new int[a];
        bool flag = true;
        
        for(int i = 0; i < a; i++) {
            std::cin >> arr[i];
        }
        
        std::sort(arr, arr + a, std::greater<int>());
        
        for(int i = 0; i < a - 2; i++) {
            if (arr[i] % arr[i + 1] != arr[i + 2]) {
                flag = false;
                break;
            }
        }
        
        if (!flag) {
            std::cout << "-1" << '\n';
        } else {
            std::cout << arr[0] << ' ' << arr[1] << '\n';
        }
        
        delete[] arr;
    }
    return 0;
}