#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    long long ans = 0;
    for (int i = 1; i <= 10000; i++) ans += i * i;
    std::cout << ans << std::endl;
    return 1;
}