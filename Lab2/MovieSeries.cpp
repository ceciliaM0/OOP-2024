#include "MovieSeriesH.h"
#include "Movieh.h"
#include<iostream>
#include<algorithm>

MovieSeries::MovieSeries() : count(0){}

void MovieSeries::init() {
	count = 0;
}

void MovieSeries::add(Movie* movie) {
	if (count < 16) {
		movies[count++] = movie;
	}	
}

void MovieSeries::print() const {
	for (int i = 0; i < count; i++) {
		std::cout << "Name: " << movies[i]->get_name() << ", Release Year: " << movies[i]->get_year()
			<< ", IMDB Score : " << movies[i]->get_score() << ", Lentgh: " << movies[i]->get_length() << "minutes" << std::endl;
	}
}

bool compare(const Movie* first, const Movie* second) {
	return first->get_passedYears() > second->get_passedYears();
}

void MovieSeries::sort() {
	std::sort(movies, movies + count, compare);
}