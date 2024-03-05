#include "globalH.h"
#include <string.h>

int movie_compare_name(const Movie& first, const Movie& second) {
    if (first.get_name() > second.get_name())
        return 1;
    else if (first.get_name() < second.get_name())
        return -1;
    else
        return 0;
}


int movie_compare_year(const Movie& first, const Movie& second) {
    if (first.get_year() < second.get_year())
        return -1;
    else if (first.get_year() > second.get_year())
        return 1;
    else 
        return 0;
}

int movie_compare_score(const Movie& first, const Movie& second) {
    if (first.get_score() < second.get_score())
        return -1;
    else if (first.get_score() > second.get_score())
        return 1;
    else 
        return 0;
}

int movie_compare_length(const Movie& first, const Movie& second) {
    if (first.get_length() < second.get_length())
        return -1;
    else if (first.get_length() > second.get_length())
        return 1;
    else 
        return 0;
}

int movie_compare_passed_years(const Movie& first, const Movie& second) {
    if (first.get_passedYears() < second.get_passedYears())
        return -1;
    else if (first.get_passedYears() > second.get_passedYears())
        return 1;
    else
        return 0;
}