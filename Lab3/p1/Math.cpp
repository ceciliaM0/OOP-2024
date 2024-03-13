#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Math.h"
#include <stdarg.h>

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return x + y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int s = 0;
    int* p = &count + 1;
    for (int i = 0; i < count; i++) {
        s += *p;
        ++p;
    }
    return s;
}

char* Math::Add(const char* x, const char* y) {
    if (x == nullptr || y == nullptr)
        return nullptr;
    size_t len1 = strlen(x);
    size_t len2 = strlen(y);
    char* result = new char[len1 + len2 + 1];
    strcpy(result, x);
    strcat(result, y);
    return result;
}