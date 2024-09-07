#pragma once
#include "header.h"
class Reservation {
private:
    Movie* movie;
    TheaterRoom* room;
    Schedule* schedule;
    int row;
    int col;
    int ticketNumber;

public:
    Reservation(Movie* _movie, TheaterRoom* _room, Schedule* _schedule, int _row, int _col, int _ticketNumber) {
        movie = _movie;
        room = _room;
        schedule = _schedule;
        row = _row;
        col = _col;
        ticketNumber = _ticketNumber;
    }

    Movie* getMovie() const { return movie; }
    TheaterRoom* getRoom() const { return room; }
    Schedule* getSchedule() const { return schedule; }
    int getRow() const { return row; }
    int getCol() const { return col; }
    int getTicketNumber() const { return ticketNumber; }

    void displayReservation() {
        printf("Detalles de la Reserva:\n");
        printf("Pelicula: %s\n", movie->getName());
        printf("Sala: %d\n", room->getNumber());
        printf("Horario: %s\n", schedule->getDay());
        printf("Numero de Ticket: %d\n\n", ticketNumber);
        printf("Asiento: Fila %d, Columna %d\n", row, col);
        room->displaySeats();
    }
};

