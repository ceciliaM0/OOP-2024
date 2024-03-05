#pragma once
class Movie {
private:
	char name[256];
	int year;
	double score;
	int length;

public:
	void set_name(const char* name);
	void set_year(int year);
	void set_score(double score);
	void set_length(int length);
	const char* get_name() const;
	int get_year() const;
	double get_score() const;
	int get_length() const;
	int get_passedYears() const;
};