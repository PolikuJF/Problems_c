#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--) {
        long long a;
        std::cin >> a;
        if (a == 10) {
            std::cout << "-1"<< '\n';
        } else if (a % 12 == 10) {
            std::cout << 22 << ' ' << a - 22 << '\n';
        } else {
            std::cout << a % 12 << ' ' << a - a % 12 << '\n';
        }
    }    
    return 0;
}