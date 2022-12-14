///
/// main.cxx
///

#include "fact.h"

#include <stdio.h>

int main() {
    int n;
    fprintf(stdout, "N: ");
    fflush(stdout);
    fscanf(stdin, "%d", &n);

    int fact_i = factorial_i(n);
    int fact_r = factorial_r(n);

    fprintf(stdout, "fact_i == %d\n", fact_i);
    fprintf(stdout, "fact_r == %d\n", fact_r);

    if (fact_i != fact_r) {
        fprintf(stderr, "HORROR!\n");
        return 4;
    }

    return 0;
}
