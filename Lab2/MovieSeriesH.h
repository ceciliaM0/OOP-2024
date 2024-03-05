#pragma once
#include "Movieh.h"

class MovieSeries {
private:
	Movie* movies[16];
	int count;
public:
	MovieSeries();
	void init();
	void add(Movie* movie);
	void print() const;
	void sort();
};