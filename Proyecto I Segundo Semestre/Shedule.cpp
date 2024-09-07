#include "Shedule.h"
#include "Movies.h"
#include "TheaterRoom.h"



Schedule::Schedule(){
	day = "";
	startTime = "";
	endTime = "";
	movie = nullptr;
	theaterRoom = nullptr;

}

Schedule::Schedule(Movie* _movie, TheaterRoom* _theaterRoom, const string& _day, const string& _startTime, const string& _endTime){
	movie = _movie;
	theaterRoom = _theaterRoom;
	day = _day;
	startTime = _startTime;
	endTime = _endTime;

}

Schedule::~Schedule(){
}

void Schedule::setMovie(Movie* _movie) { movie = _movie; }
Movie* Schedule::getMovie() const { return movie; }

void Schedule::setTheaterRoom(TheaterRoom* _theaterRoom) { theaterRoom = _theaterRoom; }
TheaterRoom* Schedule::getTheaterRoom() const { return theaterRoom; }

void Schedule::setDay(const string& _day) { day = _day; }
string Schedule::getDay() const { return day; }

void Schedule::setStartTime(const string& _startTime) { startTime = _startTime; }
string Schedule::getStartTime() const { return startTime; }

void Schedule::setEndTime(const string& _endTime) { endTime = _endTime; }
string Schedule::getEndTime() const { return endTime; }

void Schedule::displaySchedule() const{
	if (movie != nullptr && theaterRoom != nullptr) {
		system("cls");
		printf("\033[34mSala y Horarion para ver la pelicula.\n\033[0m");
		printf("Pelicula: %s\n", (*movie).getName().c_str());
		printf("Sala: %d\n", (*theaterRoom).getNumber());
		theaterRoom->displaySeats();
		printf("\033[34mHorario.\n\033[0m");
		printf("Fecha: %s\n", day.c_str());
		printf("Hora de inicio: %s\n", startTime.c_str());
		printf("Hora de fin: %s\n", endTime.c_str());
	}
	else {
		printf("Error: Datos incompletos en el horario.\n");
	}
}