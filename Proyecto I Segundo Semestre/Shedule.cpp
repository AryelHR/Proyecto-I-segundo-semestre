#include "Shedule.h"
#include "Movies.h"
#include "TheaterRoom.h"



Schedule::Schedule() {
	day = " ";
	startTime = " ";
	endTime = " ";
	movie = nullptr;
}

Schedule::Schedule(Movie* _movie, TheaterRoom _theaterRoom, const string& _day, const string& _startTime, const string& _endTime) {
	movie = _movie;
	theaterRoom = _theaterRoom;
	day = _day;
	startTime = _startTime;
	endTime = _endTime;
	theaterRoom.initializeRandomSeats();
}

Schedule::~Schedule() {
}

void Schedule::setMovie(Movie* _movie) { movie = _movie; }
Movie* Schedule::getMovie() const { return movie; }

void Schedule::setTheaterRoom(TheaterRoom _theaterRoom) { theaterRoom = _theaterRoom; }
TheaterRoom& Schedule::getTheaterRoom() { return theaterRoom; }

void Schedule::setDay(const string& _day) { day = _day; }
string Schedule::getDay() const { return day; }

void Schedule::setStartTime(const string& _startTime) { startTime = _startTime; }
string Schedule::getStartTime() const { return startTime; }

void Schedule::setEndTime(const string& _endTime) { endTime = _endTime; }
string Schedule::getEndTime() const { return endTime; }

void Schedule::displaySchedule() const {
	if (movie != nullptr && theaterRoom.isValid()){
		printf("\033[34mDatos para ver la Pelicula\n\033[0m");
		printf("Pelicula: %s\n", movie->getName().c_str());
		printf("Sala: %d\n", theaterRoom.getNumber());
		printf("Fecha: %s\n", day.c_str());
		printf("Hora de inicio: %s\n", startTime.c_str());
		printf("Hora de fin: %s\n", endTime.c_str());
		theaterRoom.displaySeats();
		printf("\n");
	}
	else {
		printf("Error: Datos incompletos en el horario.\n");
	}
}

string Schedule::getCurrentTime() {
	time_t now = time(0);
	struct tm localTime;
	localtime_s(&localTime, &now);

	char buffer[6];
	strftime(buffer, sizeof(buffer), "%H:%M", &localTime);

	return string(buffer);
}

int Schedule::calculateTimeDifference(const string& time1, const string& time2) {
	int hours1, minutes1, hours2, minutes2;
	char colon;
	std::istringstream ss1(time1);
	std::istringstream ss2(time2);

	ss1 >> hours1 >> colon >> minutes1;
	ss2 >> hours2 >> colon >> minutes2;

	int totalMinutes1 = hours1 * 60 + minutes1;
	int totalMinutes2 = hours2 * 60 + minutes2;

	
	if (totalMinutes2 < totalMinutes1) {
		totalMinutes2 += 24 * 60;  
	}

	return totalMinutes2 - totalMinutes1;
}

bool Schedule::canMakeReservation() {
	string currentTime = getCurrentTime();
	string startTime = getStartTime();
	int timeDifference = calculateTimeDifference(currentTime, startTime);
	return timeDifference >= 30;  
}

int Schedule::convertToMinutes(const string& time) {
	int hours, minutes;
	char colon;
	std::istringstream ss(time);
	ss >> hours >> colon >> minutes;
	return hours * 60 + minutes;
}
