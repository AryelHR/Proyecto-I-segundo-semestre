
#include "Movies.h"
#include <cstdio>


Movie::Movie(){
	name = "Desconocido";
	year = 0;
	duration = 0;
	country = "Desconocido";
	review = "Sin review";
}

Movie::Movie(string _name, int _year, int _duration, string _country, string _review){
	name = _name;
	year = _year;
	duration = _duration;
	country = _country;
	review = _review;
}

Movie::~Movie(){
}

void Movie::displayInfo() const {
	printf("Nombre: %s\n", name.c_str());
	printf("Anio: %d\n", year);
	printf("Duracion: %d minutes\n", duration);
	printf("Pais: %s\n", country.c_str());
	printf("Review: %s\n", review.c_str());

}

void Movie::setName(const string& _name) { name = _name; }
string Movie::getName() const { return name; }

void Movie::setYear(int _year) { year = _year; }
int Movie::getYear() const { return year; }

void Movie::setDuration(int _duration) { duration = _duration; }
int Movie::getDuration() const { return duration; }

void Movie::setCountry(const string& _country) { country = _country; }
string Movie::getCountry() const { return country; }

void Movie::setReview(const string& _review) { review = _review; }
string Movie::getReview() const { return review; }


