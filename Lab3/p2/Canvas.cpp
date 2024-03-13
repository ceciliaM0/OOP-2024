#include "Canvas.h"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) : lines(lines), columns(columns) {
    canvas = new char*[lines];
    for (int i = 0; i < lines; i++) {
        canvas[i] = new char[columns];
        for (int j = 0; j < columns; j++) {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < columns && y >= 0 && y < lines) {
        canvas[y][x] = value;
    }
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        char value = static_cast<char>(va_arg(args, int));
        set_pixel(x, y, value);
    }
    va_end(args);
}


void Canvas::clear() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            canvas[i][j] = ' ';
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}

