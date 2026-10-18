#include <iostream>
using namespace std;
const int MAXN = 1005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--) {
        int a, b,c;
        std::cin >> a >> b >> c;
        if (a + b == c) {
            std::cout << '+'<< '\n';
        } else {
            std::cout << '-' << '\n';
        }
    }    
    return 0;
}