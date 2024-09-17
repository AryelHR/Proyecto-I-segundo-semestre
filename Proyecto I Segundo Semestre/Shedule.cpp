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

	theaterRoom->initializeRandomSeats();
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
		printf("\033[34mSala y Horario para ver la pelicula.\n\033[0m");
		printf("Pelicula: %s\n", movie->getName().c_str());
		printf("Sala: %d\n", theaterRoom->getNumber());
		theaterRoom->displaySeats();
		printf("\033[34mHorario.\n\033[0m");
		printf("Fecha: %s\n", day.c_str());
		printf("Hora de inicio: %s\n", startTime.c_str());
		printf("Hora de fin: %s\n", endTime.c_str());
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
	scanf_s(time1.c_str(), "%d:%d", &hours1, &minutes1);
	scanf_s(time2.c_str(), "%d:%d", &hours2, &minutes2);

	int totalMinutes1 = hours1 * 60 + minutes1;
	int totalMinutes2 = hours2 * 60 + minutes2;

	return totalMinutes2 - totalMinutes1; 
}

bool Schedule::canMakeReservation() {
	string currentTime = getCurrentTime();
	string startTime = getStartTime();  

	int timeDifference = calculateTimeDifference(currentTime, startTime);

	
	return timeDifference > 30;
}

void Schedule::calculateEndTime() {
	int startHour, startMinute;

	scanf_s(startTime.c_str(), "%d:%d", &startHour, &startMinute);

	int movieDuration = this->movie->getDuration();

	int totalMinutes = (startHour * 60) + startMinute + movieDuration;

	int endHour = totalMinutes / 60;
	int endMinute = totalMinutes % 60;

	char endTimeBuffer[6];

	sprintf_s(endTimeBuffer, "%02d:%02d", endHour % 24, endMinute);

	this->endTime = std::string(endTimeBuffer);
}
