#pragma once
#ifndef FORMATO_H
#define FORMATO_H

#include <iostream>
#include <windows.h>
#include <cstring>

#define MAX_MENU_ITEMS 10
#define MAX_ITEM_LENGTH 100

class Formato {
private:
    int nuevaMatrix[10][45];
    int cinemaMatrix[12][57];

    void printCenteredMatrix(int* matrix, int rows, int cols, int offsetY = 0) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        int consoleWidth = csbi.dwSize.X;
        int startX = (consoleWidth - cols) / 2;

        for (int i = 0; i < rows; i++) {
            COORD coord;
            coord.X = startX;
            coord.Y = csbi.dwCursorPosition.Y + offsetY + i;
            SetConsoleCursorPosition(hConsole, coord);

            for (int j = 0; j < cols; j++) {
                if (*(matrix + i * cols + j) == 1) {
                    SetConsoleTextAttribute(hConsole, 7);
                    std::cout << (char)219;
                }
                else {
                    std::cout << " ";
                }
            }
        }

        SetConsoleTextAttribute(hConsole, 7);
    }

    void printCenteredText(char character, int repetitions = 5, int offsetY = 0) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        int consoleWidth = csbi.dwSize.X;

        std::string text;
        for (int i = 0; i < repetitions; ++i) {
            text += character;
            if (i < repetitions - 1) {
                text += ' ';
            }
        }
        text += " 100%";

        int startX = (consoleWidth - text.length()) / 2;

        COORD coord;
        coord.X = startX;
        coord.Y = csbi.dwCursorPosition.Y + offsetY;
        SetConsoleCursorPosition(hConsole, coord);

        SetConsoleTextAttribute(hConsole, 7);
        std::cout << text;

        SetConsoleTextAttribute(hConsole, 7);
    }

    void printCenteredText(const char* text, int offsetY = 0) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        int consoleWidth = csbi.dwSize.X;
        int textLength = strlen(text);
        int startX = (consoleWidth - textLength) / 2;

        COORD coord;
        coord.X = startX;
        coord.Y = csbi.dwCursorPosition.Y + offsetY;
        SetConsoleCursorPosition(hConsole, coord);

        SetConsoleTextAttribute(hConsole, 7);
        printf("%s", text);
    }

    void printChar(char c, int count) {
        for (int i = 0; i < count; ++i) {
            putchar(c);
        }
    }

public:
    Formato() {
       
        int tempNuevaMatrix[10][45] =
        { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0},
        {0,1,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0},
        {0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0},
        {0,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0},
        {0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,0,1,0},
        {0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0},
        {0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

        // Copiar tempNuevaMatrix a nuevaMatrix
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 45; ++j)
                nuevaMatrix[i][j] = tempNuevaMatrix[i][j];

        // Inicializar cinemaMatrix
        int tempCinemaMatrix[12][57] =
        {
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,1},
        {1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1},
        {1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,0,1},
        {1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1},
        {1,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1},
        {1,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1},
        {1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0} };

        // Copiar tempCinemaMatrix a cinemaMatrix
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 57; ++j)
                cinemaMatrix[i][j] = tempCinemaMatrix[i][j];
    }

    void imprimirTodo() {
        printCenteredMatrix((int*)nuevaMatrix, 10, 45, 0);
        printCenteredMatrix((int*)cinemaMatrix, 12, 57, 1);
        std::cout << "\n\n";
        printCenteredText(254);
        std::cout << "\n\n\n\n";
        system("pause");
    }

    void imprimirMenuRectangular(const char* menuItems[], int itemCount, const char* title) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        int consoleWidth = csbi.dwSize.X;
        int maxLength = strlen(title);
        for (int i = 0; i < itemCount; ++i) {
            int itemLength = strlen(menuItems[i]);
            if (itemLength > maxLength) {
                maxLength = itemLength;
            }
        }

        int boxWidth = maxLength + 4;  // 2 espacios de padding a cada lado
        int startX = (consoleWidth - boxWidth) / 2;

        // Imprimir la parte superior del rectángulo
        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(startX), csbi.dwCursorPosition.Y });
        putchar('+');
        printChar('-', boxWidth - 2);
        putchar('+');

        // Imprimir el título
        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(startX), static_cast<SHORT>(csbi.dwCursorPosition.Y + 1) });
        printf("| %s", title);
        printChar(' ', boxWidth - strlen(title) - 3);
        putchar('|');

        // Imprimir una línea separadora
        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(startX), static_cast<SHORT>(csbi.dwCursorPosition.Y + 2) });
        putchar('+');
        printChar('-', boxWidth - 2);
        putchar('+');

        // Imprimir los elementos del menú
        for (int i = 0; i < itemCount; ++i) {
            SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(startX), static_cast<SHORT>(csbi.dwCursorPosition.Y + 3 + i) });
            printf("| %s", menuItems[i]);
            printChar(' ', boxWidth - strlen(menuItems[i]) - 3);
            putchar('|');
        }

        // Imprimir la parte inferior del rectángulo
        SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(startX), static_cast<SHORT>(csbi.dwCursorPosition.Y + 3 + itemCount) });
        putchar('+');
        printChar('-', boxWidth - 2);
        putchar('+');

        // Mover el cursor debajo del rectángulo
        SetConsoleCursorPosition(hConsole, { 0, static_cast<SHORT>(csbi.dwCursorPosition.Y + 4 + itemCount) });
    }
    void imprimirTitulo(const char* titulo) {
        int largoTitulo = strlen(titulo);
        int ancho = 40; // Ancho total de la caja (ajusta según sea necesario)

        // Calculamos los espacios necesarios para centrar el título
        int paddingIzquierda = (ancho - largoTitulo) / 2;
        int paddingDerecha = ancho - largoTitulo - paddingIzquierda;

        // Secuencias ANSI para el color amarillo
        printf("\033[1;33m");

        // Imprimir la caja con bordes
        printf("+----------------------------------------+\n");
        printf("|%*s%s%*s|\n", paddingIzquierda, "", titulo, paddingDerecha, "");
        printf("+----------------------------------------+\n");

        // Restablecer el color a su valor predeterminado
        printf("\033[0m");
    }
};

#endif // FORMATO_H