#pragma once
#include "header.h"

class Cinema {
private:
    Movie** movies;       
    TheaterRoom** rooms;   
    Schedule** schedules;  
    Reservation* reservation;
    int movieCount;       
    int roomCount;         
    int scheduleCount;    
    int capacity;  
    int movieCapacity;  
    int roomCapacity;
    int scheduleCapacity;
    bool exit;

public:
    Cinema();  
    ~Cinema();              
  
    void addMovie(const Movie& movie);
    void displayMovies() const;

   
    void addRoom(const TheaterRoom& room);
    void displayRooms() const;

    
    void addSchedule(const Schedule& schedule);
    void displaySchedules() const;

    int getMovieCount() const;
    Movie* getMovie(int index) const;

    int getRoomCount() const;
    TheaterRoom* getRoom(int index) const; 

    void setCurrentReservation(Reservation* reservation);
    Reservation* getCurrentReservation() const;

    void cinemaCapacity(int _movieCap, int _roomCap, int _scheduleCap);
    void mainMenu();
    void archiving(); 
    void maintenance();
    void manageMovies();
    void makeReservation();
    void makeSale();
    void randomTicket(int& ticket);
};


