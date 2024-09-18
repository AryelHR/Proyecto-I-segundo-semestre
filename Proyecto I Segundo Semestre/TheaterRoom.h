#pragma once
#ifndef THEATERROOM_H
#define THEATERROOM_H

class TheaterRoom {
private:
	int number;
	int seatCount;
	double price;
	int rows;
	int cols;
	char seats[10][10];

public:
	TheaterRoom();
	TheaterRoom(int _number, int _rows, int _cols, double _price);

	~TheaterRoom();

	void setNumber(int _number);
	int getNumber()const;

	void setSeatcount(int _seatCount);
	int getSeatCount()const;

	void setPrice(int _price);
	double getPrice()const;

	void setRows(int _rows);
	int getRows()const;

	void setCols(int _cols);
	int getCols()const;

	void initializeNullSeats();
	void initializeRandomSeats();
	bool reserveSeat(int row, int col);
	void displaySeats() const;
	bool isSeatAvailable(int row, int col) const;
	bool isValid() const;

};

#endif