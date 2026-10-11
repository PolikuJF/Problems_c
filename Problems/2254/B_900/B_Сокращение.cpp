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
        int count = 0;
        int count2 = 1;
        std::cin >> s;
        for (int i = 1; i < n - 1; i++) {
            if (s[i-1] != s[i] & s[i] != s[i + 1] & s[i-1] == s[i + 1]) {
                s.erase(i, 1);
                count2--;
                break;
            }
        }
        if (count2 == 1){
            for (int i = 1; i < n - 1; i++) {
                if (s[i-1] != s[i] & s[i] != s[i + 1]) {
                    s.erase(i, 1);
                    break;
                }
            }
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            }
        }
        std::cout << s.size() - count << '\n';
    }
    return 0;
}