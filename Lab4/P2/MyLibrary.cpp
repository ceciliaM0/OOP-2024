#include "MyLibrary.h"
#include <iostream>
#include <sstream>
#include <random>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(&output_stream), books_count(-1), books(nullptr) {
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books)
    : output_stream(&output_stream), books_count(books_count) {
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(&output_stream), books_count(books_count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max - 1);

    books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i) {
        books[i] = dist(gen);
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(&output_stream) {
    std::stringstream ss(books_values);
    int value;
    books_count = 0;
    char separator;
    while (ss >> value) {
        ++books_count;
        ss >> separator;
    }

    books = new int[books_count];
    ss.clear();
    ss.seekg(0);
    for (unsigned i = 0; i < books_count; ++i) {
        ss >> books[i];
        ss >> separator;
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...)
    : output_stream(&output_stream), books_count(books_count) {
    books = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; ++i) {
        books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v)
    : output_stream(&std::cout), books_count(v.size()), books(new int[v.size()]) {
    std::copy(v.begin(), v.end(), books);
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() {
    if (books_count == -1) {
        *output_stream << "Found -1 books" << std::endl;
        return;
    }
    *output_stream << "Found " << books_count << " books";
    *output_stream << ": ";
    for (unsigned i = 0; i < books_count; ++i) {
        *output_stream << books[i];
        if (i != books_count - 1)
            *output_stream << ", ";
    }
    *output_stream << std::endl;
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < books_count) {
        books[book_index] = book_id;
    }
}
