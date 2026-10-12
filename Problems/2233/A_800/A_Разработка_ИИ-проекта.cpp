#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--) {
        long long a, b, c, d;
        std::cin >> a >> b >> c >> d;
        long long count1 = (long long)ceil((double)a / (b + c));
        long long count2 = (long long)ceil((double)(a + 10 * c * d)/ (b + 10 * c ));
        if (count1 < count2) {
            std::cout << count1 << '\n';
        } else {
            std::cout << count2 << '\n';
        }
    }    
    return 0;
}