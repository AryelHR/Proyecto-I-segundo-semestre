#include "TheaterRoom.h"
#include <cstdio>
#include <cstdlib>  
#include <ctime>    

TheaterRoom::TheaterRoom() {
    number = 0;
    seatCount = 0;
    price = 0.0;
    rows = 0;
    cols = 0;
    initializeSeats();
}

TheaterRoom::TheaterRoom(int _number, int _rows, int _cols, double _price) {
    number = _number;
    seatCount = _rows * _cols;
    price = _price;
    rows = _rows;
    cols = _cols;
    initializeSeats();
}

TheaterRoom::~TheaterRoom() {
}

void TheaterRoom::setNumber(int _number) { number = _number; }
int TheaterRoom::getNumber() const { return number; }

void TheaterRoom::setSeatcount(int _seatCount) { seatCount = _seatCount; }
int TheaterRoom::getSeatCount()const { return seatCount; }

void TheaterRoom::setPrice(int _price) { price = _price; }
double TheaterRoom::getPrice() const { return price; }

void TheaterRoom::setRows(int _rows) { rows = _rows; }
int TheaterRoom::getRows() const { return rows; }

void TheaterRoom::setCols(int _cols) { cols = _cols; }
int TheaterRoom::getCols() const { return cols; }

void TheaterRoom::initializeSeats() {
    srand((unsigned)time(0));  

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rand() % 2 == 0) {  
                seats[i][j] = 'R';
            }
            else {
                seats[i][j] = 'A';
            }
        }
    }
}

bool TheaterRoom::reserveSeat(int row, int col) {
    if (isSeatAvailable(row, col)) {
        seats[row][col] = 'I';
        return true;
    }
    return false;
}

void TheaterRoom::displaySeats() const {
    printf("Estado de la sala\n\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (seats[i][j] == 'A') {
                printf("\033[32m[ ]\033[0m ");  
            }
            else if (seats[i][j] == 'R') {
                printf("\033[31m[X]\033[0m ");  
            }
            else if (seats[i][j] == 'I') {
                printf("\033[33m[O]\033[0m ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool TheaterRoom::isSeatAvailable(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return seats[row][col] == 'A';
    }
    return false;
}
