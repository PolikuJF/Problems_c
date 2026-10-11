#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::string s2;
        int count = 0;
        std::cin >> s;
        std::cin >> s2;
        int b = n - n % 3;
        for (int i = 0; i < b / 3; i +=3) {
            if (s[i] == s2[i + 2] & s[i + 1] == s2[i + 1] & s[i + 2] == s2[i]) {
                count+=3;
            }
        }
        for (int i = n; i > b; i--) {
            if (s[i] == s2[i]) {
                count++;
            }
        }
        if (count == s.size()) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}