#include "header.h"

void archiving(bool& exit) {
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

void manageMovies(Cinema& cinema) {
    int option = 0;
    do {
        system("cls");
        printf("GESTIONAR PELICULAS, SALAS Y HORARIOS\n");
        printf("1. Agregar Pelicula\n");
        printf("2. Agregar Sala\n");
        printf("3. Agregar Horario\n");
        printf("4. Volver al Menu de Mantenimiento\n");
        printf("Elija una opcion: ");
        scanf_s("%d", &option);

        switch (option) {
        case 1: {
           //Agegrar una pelicula
            system("cls");
            string name, country, review;
            int year, duration;

            printf("Ingrese el nombre de la pelicula: ");
            cin.ignore();
            getline(cin, name);

            printf("Ingrese el ano: ");
            scanf_s("%d", &year);

            printf("Ingrese la duracion (en minutos): ");
            scanf_s("%d", &duration);

            printf("Ingrese el pais: ");
            cin.ignore();
            getline(cin, country);

            printf("Ingrese la descripcion: ");
            getline(cin, review);

            Movie newMovie(name, year, duration, country, review);
            cinema.addMovie(newMovie);
            break;
        }
        case 2: {
            // Agregar una sala
            system("cls");
            int number, cols, rows;
            double price;

            printf("Ingrese el numero de sala: ");
            scanf_s("%d", &number);

            printf("Ingrese la cantidad de filas: ");
            scanf_s("%d", &rows);

            printf("Ingrese la cantidad de columnas: ");
            scanf_s("%d", &cols);

            printf("Ingrese el precio del ticket: ");
            scanf_s("%lf", &price);

            TheaterRoom newRoom(number, rows, cols, price);
            cinema.addRoom(newRoom);
            break;
        }
        case 3: {
            // Agregar un horario
            system("cls");
            int movieIndex, roomIndex;
            std::string day, startTime, endTime;

            cinema.displayMovies();
            printf("Seleccione el numero de la pelicula para la cual agregar el horario: ");
            scanf_s("%d", &movieIndex);
            movieIndex--;

            cinema.displayRooms();
            printf("Seleccione el numero de la sala para la pelicula '%s': ", (*cinema.getMovie(movieIndex)).getName().c_str());
            scanf_s("%d", &roomIndex);
            roomIndex--;

            printf("Ingrese el dia: ");
            cin.ignore();
            getline(cin, day);

            printf("Ingrese la hora de inicio (HH:MM): ");
            getline(cin, startTime);

            printf("Ingrese la hora de fin (HH:MM): ");
            getline(cin, endTime);

            Schedule newSchedule(cinema.getMovie(movieIndex), cinema.getRoom(roomIndex), day, startTime, endTime);
            cinema.addSchedule(newSchedule);
            break;
        }
        case 4:
            return;
       
        default:
            printf("Opcion invalida. Por favor elija una opcion valida.\n");
        }

        system("pause");

    } while (true);
}

void maintenance(Cinema& cinema) {
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
                cinema.displayMovies();
                break;

            case 2:
                cinema.displayRooms();
                break;

            case 3: 
                cinema.displaySchedules();
                break;
            case 4:
                manageMovies(cinema);
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

int main() {
    Cinema cinema(10);  
    int optionOne = 0;
    bool exit = false;

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
                archiving(exit);
                break;
            case 2:
                maintenance(cinema);  
                break;
            case 3:
                // reservas
                break;
            case 4:
                // ventas
                break;
            default:
                printf("Opcion invalida. Por favor elija una opcion valida.\n");
                break;
            }
        }

    } while (!exit);

    return EXIT_SUCCESS;
}
