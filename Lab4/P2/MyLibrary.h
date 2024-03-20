#pragma once

#include <ostream>
#include <initializer_list>
#include <cstdarg>

class MyLibrary {
    std::ostream* output_stream;
    unsigned books_count;
    int* books;

  public:
    MyLibrary(std::ostream& output_stream);
    MyLibrary(std::ostream& output_stream, unsigned books_count, int* books);
    MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max);
    MyLibrary(std::ostream& output_stream, const char* books_values);
    MyLibrary(std::ostream& output_stream, unsigned books_count, ...);
    MyLibrary(std::initializer_list<int> v);
    ~MyLibrary();

    void print_books();
    void update_book_id_by_index(unsigned book_index, int book_id);

    unsigned get_books_count() const {
        return books_count;
    }

    int get_book_id_by_index(unsigned index) const {
        if (index < books_count)
            return books[index];
        else
            return -1;
    }

    MyLibrary(const MyLibrary& other) {
        output_stream = other.output_stream;
        books_count = other.books_count;
        books = new int[books_count];
        for (unsigned i = 0; i < books_count; ++i) {
            books[i] = other.books[i];
        }
    }
};
