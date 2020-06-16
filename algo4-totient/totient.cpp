#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/**
 * Various implementations of the Euler-Totient function.
 * For details, view the respective video.
 * (c) 2020 SoftwareEngenius
 */

// Euclidean Algorithm GCD, O(logn)
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Algorithm #1: Brute force, O(nlogn)
int phiBruteForce(int n) {
    int result = n - 1;
    for(int x = 1; x <= n - 1; x++) {
        if (gcd(n, x) != 1) {
            result--;
        }
    }
    return result;
}

// Algorithm #2: Optimized, O(sqrt(N))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    // Handles edge case where the number is prime
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

// Algorithm #3: Sieve, O(nlognlogN)
std::vector<int> phiSieve(int n) {
    std::vector<int> phi (n+1);
    for (int x = 0; x <= n; x++) {
        phi[x] = x;
    }
    
    for (int x = 2; x < n; x++) {
        if (phi[x] == x) {
            for (int y = x; y <= n; y+=x) {
                phi[y] -= phi[y] / x;
            }
        }
    }
    return phi;
}

// Algorithm #4: Gauss's Theorem, O(nlogn)
std::vector<int> phiGauss(int n) {
    std::vector<int> phi (n+1);
    
    phi[0] = 0;
    phi[1] = 1;
    for (int x = 2; x <= n; x++) {
        phi[x] = x - 1;
    }
    
    for (int x = 2; x <= n; x++) {
        for (int y = x * 2; y <= n; y += x) {
            phi[y] -= phi[x];
        }
    }
    return phi;
}

// Simple sanity test
void test() {
    for (int x = 2; x <= 1 << 10; x++) {
        int bruteForce = phiBruteForce(x);
        int optimized = phi(x);
        if (bruteForce != optimized) {
            std::cerr << "Error: Invalid singular match for " << x << "\n";
        }
    }
    
    auto sieve = phiSieve(1000);
    auto sieve2 = phiGauss(1000);
    for (int x = 0; x < 1000; x++) {
        if (sieve[x] != sieve2[x]) {
            std::cerr << "Error: Invalid array match for " << x << "\n";
        }
    }
}


int main(int argc, char *argv[]) {
    test();
    return 0;
}