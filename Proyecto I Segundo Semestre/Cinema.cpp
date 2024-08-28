#include "Cinema.h"

Cinema::Cinema() {
    movies = nullptr;
    rooms = nullptr;
    schedules = nullptr;
    movieCount = 0;
    roomCount = 0;
    scheduleCount = 0;
    exit = false;
}

Cinema::~Cinema() {
    delete[] movies;
    delete[] rooms;
    delete[] schedules;
}



void Cinema::addMovie(const Movie& movie) {
    if (movieCount < movieCapacity) {
        movies[movieCount] = new Movie(movie);
        movieCount++;

        printf("\033[0;34m");
        printf("Pelicula creada correctamente.\n");
        printf("\033[0m");
    }
    else {
        printf("\033[0;31m");
        printf("Capacidad maxima alcanzada. No se pueden agregar mas peliculas.\n");
        printf("\033[0m");
    }
}

void Cinema::displayMovies() const {
    for (int i = 0; i < movieCount; ++i) {
        printf("Pelicula %d: %s\n", i + 1, movies[i]->getName().c_str());
        printf("Anno: %d, Duracion: %d minutos\n", movies[i]->getYear(), movies[i]->getDuration());
        printf("Pais: %s\n", movies[i]->getCountry().c_str());
        printf("Descripcion: %s\n", movies[i]->getReview().c_str());
        printf("\n");
    }
}

void Cinema::addRoom(const TheaterRoom& room) {
    if (roomCount < roomCapacity) {
        rooms[roomCount] = new TheaterRoom(room);
        roomCount++;

        printf("\033[0;34m");
        printf("Sala creada correctamente.\n");
        printf("\033[0m");
    }
    else {
        printf("\033[0;31m");
        printf("Capacidad maxima alcanzada. No se pueden agregar mas salas.\n");
        printf("\033[0m");
    }
}

void Cinema::displayRooms() const {
    for (int i = 0; i < roomCount; ++i) {
        int seats = rooms[i]->getRows() * rooms[i]->getCols();
        printf("\n");
        printf("Sala #%d\n", rooms[i]->getNumber());
        printf("-Esta sala contiene %d asientos\n", seats);
        printf("-El precio del ticket es de: %f\n", rooms[i]->getPrice());
        rooms[i]->displaySeats();
    }
}

void Cinema::addSchedule(const Schedule& schedule) {
    if (scheduleCount < scheduleCapacity) {
        schedules[scheduleCount] = new Schedule(schedule);
        scheduleCount++;

        printf("\033[0;34m");
        printf("Horario creado correctamente.\n");
        printf("\033[0m");
    }
    else {
        printf("\033[0;31m");
        printf("Capacidad maxima alcanzada. No se pueden agregar mas horarios.\n");
        printf("\033[0m");
    }
}

void Cinema::displaySchedules() const {
    for (int i = 0; i < scheduleCount; ++i) {
        printf("\n");
        printf("Horario %d:\n", i + 1);
        schedules[i]->displaySchedule();
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

void Cinema::cinemaCapacity(int _movieCap, int _roomCap, int _scheduleCap) {
    delete[] movies;
    delete[] rooms;
    delete[] schedules;

    movies = new Movie * [_movieCap];
    rooms = new TheaterRoom * [_roomCap];
    schedules = new Schedule * [_scheduleCap];
    movieCapacity = _movieCap;
    roomCapacity = _roomCap;
    scheduleCapacity = _scheduleCap;
    movieCount = 0;
    roomCount = 0;
    scheduleCount = 0;
}

void Cinema::mainMenu() {
    int optionOne = 0;

    do {
        system("cls");

        printf("\033[0;34m");
        printf("BIENVENIDO A NUEVA CINEMA\n");
        printf("\033[0m");

        printf("\t1. Archivo\n");
        printf("\t2. Mantenimiento\n");
        printf("\t3. Reservas\n");
        printf("\t4. Ventas\n");

        printf("Elija una opcion: ");

        if (scanf_s("%d", &optionOne) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        else {
            switch (optionOne) {
            case 1:
                archiving();
                break;
            case 2:
                maintenance();
                break;
            case 3:
                makeReservation();
                break;
            case 4:
                makeSale();
                break;
            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }

    } while (!exit);
}

void Cinema::archiving() {
    int option = 0;
    do {
        system("cls");

        printf("1. Creador\n");
        printf("2. Menu principal\n");
        printf("3. Salir\n");

        while (true) {
            printf("Elija una opcion: ");

            if (scanf_s("%d", &option) != 1) {
                printf("Error: Por favor ingrese un numero valido.\n");

                while (getchar() != '\n');
            }
            else {
                break;
            }
        }

        switch (option) {
        case 1:
            system("cls");
            printf("\033[0;34m");
            printf("Sistema de Gestion para el cine NUEVA CINEMA\n");
            printf("\033[0m");

            printf("Creado por: Andy Hernandez Ruiz\n");
            printf("Usuario de GitHub: \n");
            printf("Fecha: 15/8/2024\n\n");
            printf("Detalles del Proyecto:\n");
            printf("- Proyecto de programacion en C++\n");
            printf("- Incluye gestion de peliculas, salas, y horarios\n");
            printf("- Usando arreglos y matrices dinamicas\n");
            printf("- Implementado usando conceptos de orientacion a objetos para la gestion de un Cine\n");
            system("pause");
            break;
        case 2:
            return;
        case 3:
            exit = true;
            break;
        default:
            printf("Opcion invalida. Por favor elija una opcion valida.\n");
            break;
        }
    } while (!exit);
}

void Cinema::maintenance() {
    int option = 0;

    do {
        system("cls");

        printf("MANTENIMIENTO\n");
        printf("1. Mostrar Detalles de las Peliculas\n");
        printf("2. Mostrar Detalles de las Salas\n");
        printf("3. Mostrar Horarios\n");
        printf("4. Gestionar Peliculas, Salas y Horarios\n");
        printf("5. Volver al Menu Principal\n");

        printf("Elija una opcion: ");

        if (scanf_s("%d", &option) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        else {
            printf("\n\n");
            switch (option) {
            case 1:
                system("cls");
                displayMovies();
                break;

            case 2:
                system("cls");
                displayRooms();
                break;

            case 3:
                system("cls");
                displaySchedules();
                break;
            case 4:
                manageMovies();
                break;
            case 5:
                return;
            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }

        system("pause");

    } while (true);
}

void Cinema::manageMovies() {
    int option = 0;

    do {
        system("cls");

        printf("GESTION DE PELICULAS\n");
        printf("1. Definir espacio del Cine\n");
        printf("2. Anadir Pelicula\n");
        printf("3. Anadir Sala\n");
        printf("4. Anadir Horario\n");
        printf("5. Volver al Menu Principal\n");

        printf("Elija una opcion: ");

        if (scanf_s("%d", &option) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        else {
            switch (option) {
            case 1: {
                system("cls");
                int movieCap, roomCap, scheduleCap;

                printf("Ingrese la capacidad deseada para peliculas: ");
                if (scanf_s("%d", &movieCap) != 1) {
                    printf("Error: Por favor ingrese un numero valido.\n");
                    while (getchar() != '\n');
                }

                printf("Ingrese la capacidad deseada para salas: ");
                if (scanf_s("%d", &roomCap) != 1) {
                    printf("Error: Por favor ingrese un numero valido.\n");
                    while (getchar() != '\n');
                }

                printf("Ingrese la capacidad deseada para horarios: ");
                if (scanf_s("%d", &scheduleCap) != 1) {
                    printf("Error: Por favor ingrese un numero valido.\n");
                    while (getchar() != '\n');
                }

                cinemaCapacity(movieCap, roomCap, scheduleCap);

                printf("\033[0;34m");
                printf("Capacidad actualizada.\n");
                printf("\033[0m");
                break;
            }
            case 2: {
                // C�digo para agregar pel�cula
                system("cls");
                string name;
                int year, duration;
                string country, review;

                printf("Ingrese el nombre de la pelicula: ");
                cin.ignore();
                getline(cin, name);

                printf("Ingrese el anno de la pelicula: ");
                scanf_s("%d", &year);

                printf("Ingrese la duracion de la pelicula (en minutos): ");
                scanf_s("%d", &duration);

                printf("Ingrese el pais de la pelicula: ");
                cin.ignore();
                getline(cin, country);

                printf("Ingrese una breve descripcion de la pelicula: ");
                cin.ignore();
                getline(cin, review);


                Movie movie(name, year, duration, country, review);
                this->addMovie(movie);

                break;
            }
            case 3: {
                // C�digo para agregar sala
                system("cls");
                int roomNumber, rows, cols;
                float price;

                printf("Ingrese el numero de la sala: ");
                scanf_s("%d", &roomNumber);

                printf("Ingrese el numero de filas de la sala: ");
                scanf_s("%d", &rows);

                printf("Ingrese el numero de columnas de la sala: ");
                scanf_s("%d", &cols);

                printf("Ingrese el precio del ticket: ");
                scanf_s("%f", &price);

                TheaterRoom room(roomNumber, rows, cols, price);
                this->addRoom(room);

                break;
            }
            case 4: {
                // C�digo para agregar horario
                system("cls");
                int movieIndex, roomIndex;
                string day, startTime, endTime;

                displayMovies();
                printf("Seleccione el numero de la pelicula para la cual agregar el horario: ");
                scanf_s("%d", &movieIndex);
                movieIndex--;

                displayRooms();
                printf("Seleccione el numero de la sala para la pelicula: ");
                scanf_s("%d", &roomIndex);
                roomIndex--;

                printf("Ingrese el dia: ");
                cin.ignore();
                getline(cin, day);

                printf("Ingrese la hora de inicio (HH:MM): ");
                getline(cin, startTime);

                printf("Ingrese la hora de fin (HH:MM): ");
                getline(cin, endTime);

                Schedule newSchedule(getMovie(movieIndex), getRoom(roomIndex), day, startTime, endTime);
                this->addSchedule(newSchedule);

                break;
            }
            case 5:
                return;
            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }

        system("pause");

    } while (true);
}

void Cinema::makeReservation() {
    int option = 0;

    do {
        system("cls");

        printf("RESERVAS\n");
        printf("1. Mostrar Peliculas\n");
        printf("2. Volver al Menu Principal\n");

        printf("Elija una opcion: ");

        if (scanf_s("%d", &option) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        else {
            switch (option) {
            case 1:
                displayMovies();
                system("pause");
                break;

            case 2:
                return;

            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }
    } while (option != 2);
}

void Cinema::makeSale() {
    int option = 0;

    do {
        system("cls");

        printf("VENTAS\n");
        printf("1. Ingresar Numero de Tickets\n");
        printf("2. Volver al Menu Principal\n");

        printf("Elija una opcion: ");

        if (scanf_s("%d", &option) != 1) {
            printf("Error: Por favor ingrese un numero valido.\n");
            while (getchar() != '\n');
        }
        else {
            switch (option) {
            case 1:
                printf("Ingrese el numero de tickets: ");
                int ticketCount;
                if (scanf_s("%d", &ticketCount) != 1) {
                    printf("Error: Por favor ingrese un numero valido.\n");
                    while (getchar() != '\n');
                }
                else {
                    printf("Numero de tickets ingresado: %d\n", ticketCount);
                }
                system("pause");
                break;

            case 2:
                return;

            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }
    } while (option != 2);
}


