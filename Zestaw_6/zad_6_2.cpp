
#include <iostream>


int main()
{
    auto fibo = [](int n) {
        auto inner_fibo = [](int a, const auto& impl) {
            if (a == 0) {
                return 0;
            } else if (a == 1) {
                return 1;
            } else {
                return (impl(a - 1, impl) + impl(a - 2, impl));
            }

        };

        return inner_fibo(n, inner_fibo);
    };

    for (int i = 0; i < 16; ++i) {
        std::cout << i << "-ty wyraz ciągu Fibonacciego: "  << fibo(i) << std:: endl;
    }


    return 0;
}