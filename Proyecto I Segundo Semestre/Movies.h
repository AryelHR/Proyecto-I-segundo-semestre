#pragma once
#include <string>
#ifndef PELICULA_H
#define PELICULA_H

using namespace std;

class Movie {

private:
	string name;
	int year;
	int duration;
	string country;
	string review;

public:
	Movie();
	Movie(string _name, int _year, int _duration, string _country, string _review);

	~Movie();

	void displayInfo()const;

	void setName(const string& _name);
	string getName() const;

	void setYear(int _year);
	int getYear()const;

	void setDuration(int _duration);
	int getDuration()const;

	void setCountry(const string& _country);
	string getCountry()const;

	void setReview(const string& _review);
	string getReview()const;

};


#endif

