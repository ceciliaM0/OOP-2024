#include <iostream>
#include "Math.h"

int main() {
    Math math;
    printf("%d\n", math.Add(2, 3));
    printf("%d\n", math.Add(2, 32, 5));
    printf("%d\n", math.Add(2.3, 3.5));
    printf("%d\n", math.Add(5.2, 2.3, 2.5));
    printf("%d\n", math.Mul(2, 3));
    printf("%d\n", math.Mul(2, 32, 5));
    printf("%d\n", math.Mul(2.3, 3.5));
    printf("%d\n", math.Mul(5.2, 2.3, 2.5));
    printf("%d\n", math.Add(2, 3, 5, 2, 3, 5, 2));
    printf("%s\n", math.Add("ana", "Maria"));
    return 0;
}
