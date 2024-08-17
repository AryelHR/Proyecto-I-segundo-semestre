#pragma once
#include <string>
#include <cstdio>
using namespace std;


class Movie;
class TheaterRoom;

class Schedule {
private:
    Movie* movie;
    TheaterRoom* theaterRoom;
    string day;
    string startTime;
    string endTime;
public:
    Schedule();
    Schedule(Movie* _movie, TheaterRoom* _theaterRoom, const string& _day, const string& _startTime, const string& _endTime);

    ~Schedule();

    void setMovie(Movie* _movie);
    Movie* getMovie() const;

    void setTheaterRoom(TheaterRoom* _theaterRoom);
    TheaterRoom* getTheaterRoom() const;

    void setDay(const string& _date);
    string getDay() const;

    void setStartTime(const string& _startTime);
    string getStartTime() const;

    void setEndTime(const string& _endTime);
    string getEndTime() const;

    void displaySchedule() const;
};



