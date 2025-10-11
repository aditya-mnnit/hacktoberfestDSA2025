#include <iostream>
#include <vector>

std::vector<int> memo;

int fib_memo(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int main() {
    int n = 10;
    memo.resize(n + 1, -1);

    std::cout << "Fibonacci(" << n << ") using Memoization is: " << fib_memo(n) << std::endl;
    return 0;
}
