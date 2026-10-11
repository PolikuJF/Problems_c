#include <iostream>
#include <algorithm>
using namespace std;
int midd(int a, int b, int c){
    if ((a >= b & b >= c) || (a <= b & b <= c)){
        return b;
    }
    if ((b >= a & a >= c) || (b <= a & a <= c)){
        return a;
    }
    if ((b >= c & c >= a) || (b <= c & c <= a)){
        return c;
    }
}
int main() {
	long long t;
	std::cin >> t;
	while(t--) {
	    long long a, b, c;
	    std::cin >> a >> b >> c;
	    long long maxx = std::max({a,b,c});
	    long long minn = std::min({a,b,c});
        long long mid = midd(a, b, c);
        if (maxx - mid > mid - minn) {
            std::cout << mid - minn << '\n';
        } else {
            std::cout << maxx - mid << '\n';
        }
	}

}