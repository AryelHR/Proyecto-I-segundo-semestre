#pragma once
#include "Movies.h"
#include "TheaterRoom.h"
#include "Shedule.h"

class Cinema {
private:
    Movie** movies;       
    TheaterRoom** rooms;   
    Schedule** schedules;  
    int movieCount;       
    int roomCount;         
    int scheduleCount;    
    int capacity;   

public:
    Cinema(int _capacity);  
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
};


Cinema::Cinema(int _capacity) : capacity(_capacity), movieCount(0), roomCount(0), scheduleCount(0) {
    movies = new Movie * [capacity];   
    rooms = new TheaterRoom * [capacity];  
    schedules = new Schedule * [capacity]; 
}

Cinema::~Cinema() {
    for (int i = 0; i < movieCount; ++i) {
        delete movies[i];
    }
    delete[] movies;

    for (int i = 0; i < roomCount; ++i) {
        delete rooms[i];
    }
    delete[] rooms;

    for (int i = 0; i < scheduleCount; ++i) {
        delete schedules[i];
    }
    delete[] schedules;
}

void Cinema::addMovie(const Movie& movie) {
    if (movieCount < capacity) {
        movies[movieCount] = new Movie(movie);
        movieCount++;
    }
    else {
        printf("Capacidad maxima alcanzada. No se pueden agregar mas peliculas.\n");
    }
}

void Cinema::displayMovies() const {
    for (int i = 0; i < movieCount; ++i) {
        printf("Pelicula %d: %s\n", i + 1, (*movies[i]).getName().c_str());
        printf("Ano: %d, Duracion: %d minutos\n", (*movies[i]).getYear(), (*movies[i]).getDuration());
        printf("Precio Ticket: %f\n", (*rooms[i]).getPrice());
        printf("Pais: %s\n", (*movies[i]).getCountry().c_str());
        printf("Descripcion: %s\n", (*movies[i]).getReview().c_str());
        printf("\n");
    }
}

void Cinema::addRoom(const TheaterRoom& room) {
    if (roomCount < capacity) {
        rooms[roomCount] = new TheaterRoom(room);
        roomCount++;
    }
    else {
        printf("Capacidad maxima alcanzada. No se pueden agregar mas salas.\n");
    }
}

void Cinema::displayRooms() const {
    for (int i = 0; i < roomCount; ++i) {
        int seats= (*rooms[i]).getRows() * (*rooms[i]).getCols();
        printf("\n");
        printf("Sala #%d\n", (*rooms[i]).getNumber());
        printf("-Esta sala contiene %d\n", seats);
        printf("-El precio del ticket es de: %f\n", (*rooms[i]).getPrice());
        (*rooms[i]).displaySeats();
    }
}

void Cinema::addSchedule(const Schedule& schedule) {
    if (scheduleCount < capacity) {
        schedules[scheduleCount] = new Schedule(schedule);
        scheduleCount++;
    }
    else {
        printf("Capacidad maxima alcanzada. No se pueden agregar mas horarios.\n");
    }
}

void Cinema::displaySchedules() const {
    for (int i = 0; i < scheduleCount; ++i) {
        printf("\n");
        printf("Horario %d:\n", i + 1);
        (*schedules[i]).displaySchedule();
    }
}

int Cinema::getMovieCount() const {
    return movieCount;
}

Movie* Cinema::getMovie(int index) const {
    if (index >= 0 && index < movieCount) {
        return movies[index];
    }
    return nullptr;
}

int Cinema::getRoomCount() const {
    return roomCount;
}
TheaterRoom* Cinema::getRoom(int index) const {
    if (index >= 0 && index < roomCount) {
        return rooms[index];
    }
    return nullptr;
}