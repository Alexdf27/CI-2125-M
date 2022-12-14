///
/// fact.cxx
///

int factorial_i(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int factorial_r(int n) {
    if (n <= 0) return 1;
    return n * factorial_r(n - 1); 
}
