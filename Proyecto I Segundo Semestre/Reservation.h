#pragma once
#include "header.h"
class Reservation {
private:
    Movie* movie;
    TheaterRoom* room;
    Schedule* schedule;
    int* row;
    int* col;
    int ticketNumber;
    int seatCount;

public:
    Reservation() {
        movie = nullptr;
        room = nullptr;
        schedule = nullptr;
        row = nullptr;
        col = nullptr;
        ticketNumber = 0;
        seatCount = 0;
    }
    Reservation(Movie* _movie, TheaterRoom* _room, Schedule* _schedule, int* _row, int* _col, int _seatCount ,int _ticketNumber ) {
        movie = _movie;
        room = _room;
        schedule = _schedule;
        ticketNumber = _ticketNumber;
        seatCount = _seatCount;

        row = new int[seatCount];
        col = new int[seatCount];
        for (int i = 0; i < seatCount; i++) {
            row[i] = _row[i];
            col[i] = _col[i];
        }
    }
    ~Reservation() {
        delete[] row;
        delete[] col;
    }

    Movie* getMovie() const { return movie; }
    TheaterRoom* getRoom() const { return room; }
    Schedule* getSchedule() const { return schedule; }
    int* getRow() const { return row; }
    int* getCol() const { return col; }
    int getTicketNumber() const { return ticketNumber; }

    void displayReservation() {
        system("cls");
        printf("Detalles de la Reserva:\n");
        printf("Pelicula: %s\n", movie->getName().c_str());
        printf("Sala: %d\n", room->getNumber());
        printf("Horario: %s\n", schedule->getDay().c_str());
        printf("Numero de Ticket: %d\n\n", ticketNumber);
        printf("Asientos reservados:\n");
        for (int i = 0; i < seatCount; i++) {
            printf("Fila: %d, Columna: %d\n", row[i], col[i]);
        }
        room->displaySeats();
    }
};

