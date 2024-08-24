#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib> 

std::vector<std::vector<char>> tablero(8, std::vector<char>(8, ' '));

void InicializarTablero() {
    tablero[3][3] = 'O';
    tablero[3][4] = 'X';
    tablero[4][3] = 'X';
    tablero[4][4] = 'O';
}

void ContarFichasEnTablero(int* contador_X, int* contador_O) {
    *contador_X = 0;
    *contador_O = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tablero[i][j] == 'X') {
                (*contador_X)++;
            }
            else if (tablero[i][j] == 'O') {
                (*contador_O)++;
            }
        }
    }
}

void ImprimirScore() {
    int contador_X, contador_O;
    ContarFichasEnTablero(&contador_X, &contador_O);

    std::cout << "+--------------------------------+\n";
    std::cout << "|              SCORE             |\n";
    std::cout << "+--------------------------------+\n";
    std::cout << "|Fichas X =" << std::setw(2) << contador_X << "   |  Fichas O = " << contador_O << "  |\n";
    std::cout << "+--------------------------------+\n";
}

void ImprimirTablero() {
    std::cout << "   1   2   3   4   5   6   7   8\n";
    std::cout << " +---+---+---+---+---+---+---+---+\n";
    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << "| ";
        for (int j = 0; j < 8; j++) {
            std::cout << tablero[i][j] << " | ";
        }
        std::cout << "\n";
        if (i < 7) {
            std::cout << " +---+---+---+---+---+---+---+---+\n";
        }
        else {
            std::cout << " +---+---+---+---+---+---+---+---+\n";
        }
    }
}

bool VoltearFichasDerecha(int fila, int columna, char jugador) {
    char oponente = (jugador == 'X') ? 'O' : 'X';
    bool fichasVolteadas = false;

    int j = columna + 1;
    while (j < 8 && tablero[fila][j] == oponente) {
        j++;
    }

    if (j < 8 && tablero[fila][j] == jugador) {
        for (int k = columna + 1; k < j; k++) {
            tablero[fila][k] = jugador;
        }
        fichasVolteadas = true;
    }

    return fichasVolteadas;
}

bool VoltearFichasIzquierda(int fila, int columna, char jugador) {
    char oponente = (jugador == 'X') ? 'O' : 'X';
    bool fichasVolteadas = false;

    int j = columna - 1;
    while (j >= 0 && tablero[fila][j] == oponente) {
        j--;
    }

    if (j >= 0 && tablero[fila][j] == jugador) {
        for (int k = columna - 1; k > j; k--) {
            tablero[fila][k] = jugador;
        }
        fichasVolteadas = true;
    }

    return fichasVolteadas;
}

bool VoltearFichasArriba(int fila, int columna, char jugador) {
    char oponente = (jugador == 'X') ? 'O' : 'X';
    bool volteadas = false;

    int i = fila - 1;
    while (i >= 0 && tablero[i][columna] == oponente) {
        i--;
    }

    if (i >= 0 && tablero[i][columna] == jugador) {
        for (int j = fila - 1; j > i; j--) {
            tablero[j][columna] = jugador;
        }
        volteadas = true;
    }
    return volteadas;
}

bool VoltearFichasAbajo(int fila, int columna, char jugador) {
    char oponente = (jugador == 'X') ? 'O' : 'X';
    bool volteadas = false;

    int i = fila + 1;
    while (i < 8 && tablero[i][columna] == oponente) {
        i++;
    }

    if (i < 8 && tablero[i][columna] == jugador) {
        for (int j = fila + 1; j < i; j++) {
            tablero[j][columna] = jugador;
        }
        volteadas = true;
    }
    return volteadas;
}

int main() {
    int contX, contO;

    InicializarTablero();
    ImprimirTablero();

    int fila, columna;
    char jugador = 'X';

    while (true) {
        std::cout << "Es el turno del jugador " << jugador << "\n";
        std::cout << "Ingrese la fila y columna (x y): ";
        std::cin >> fila >> columna;

        if (fila < 1 || fila > 8 || columna < 1 || columna > 8) {
            std::cout << "Coordenadas invalidas\n";
            continue;
        }

        if (tablero[fila - 1][columna - 1] != ' ') {
            std::cout << "Ese casillero ya esta ocupado\n";
            continue;
        }

        tablero[fila - 1][columna - 1] = jugador;

        VoltearFichasIzquierda(fila - 1, columna - 1, jugador);
        VoltearFichasDerecha(fila - 1, columna - 1, jugador);
        VoltearFichasArriba(fila - 1, columna - 1, jugador);
        VoltearFichasAbajo(fila - 1, columna - 1, jugador);

        system("cls");
        ImprimirScore();
        ImprimirTablero();

        ContarFichasEnTablero(&contX, &contO);
        if (contX + contO == 64) {
            system("cls");
            if (contX > contO) {
                std::cout << "El jugador X ha ganado con " << contX << " fichas" << std::endl;
            }
            else if (contX < contO) {
                std::cout << "El jugador O ha ganado con " << contO << " fichas" << std::endl;
            }
            else {
                std::cout << "El juego ha terminado en empate" << std::endl;
            }
            break;
        }

        jugador = (jugador == 'X') ? 'O' : 'X';
    }

    return 0;
}