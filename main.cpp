#include <iostream>
#include <cstdlib>
#include <windows.h> 
#include <algorithm>

struct move { // struktura zawierajaca wspolrzedne ruchu
    int x, y;
};

class Game {
private:
    int field[100][100]; // tablica nie jest w pe³ni wykorzystwana, ale pozwala to na tworzenie kopii
                            //  poprzez przekazywanie do funkcji po wartosci
                            // dla tablic dynamicznych nie ma takiej mozliwosci
    int size;
    int victory_condition;
    int moves = 0;
    int start_condition; // 2x-1
    int end_condition; 
    int Depth; // glebokosc
public:
    // funkcje ustawien i dostepu
    void set_size(int newsize) { size = newsize; }
    void set_vc(int newvc) { victory_condition = newvc; }
    void set_sc() { start_condition = 2 * victory_condition - 1; }
    void set_ec() { end_condition = size * 2; }
    void set_d(int new_depth) { Depth = new_depth; }
    void reset();
    // funkcje wyswietlania i interakcji
      void print();
      void moveHM();
    // funkcje sprawdzania
    bool draw();
    bool quick_check(int x, int y, int size);
    int is_vin();
    //
    int MinMaxAlgorytm(int depth, bool max, int alpha, int beta);
    void AImove();
    // incjacja rozgrywki
    void Play();
};
// metoda sprawdzajaca poprawnosc wpisanych wspolrzednych przez urzytkownika
bool Game::quick_check(int x, int y, int size) {
    if (x >= size || x < 0)  return true;
    if (y >= size || y < 0) return true;
    if (field[x][y] != 0) return true;
    return false;
}
// metoda resetujaca pola, ustawiajac wartosc 0 - puste pole
void Game::reset() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = 0;
        }
    }
}
// metoda wysweitlajaca plansze
void Game::print() {

    system("cls");

    std::cout << "   \t";
    for (int l = 0; l < size; l++) { std::cout << "-" << l << "-\t"; }
    for (int i = 0; i < size; i++) {
        std::cout << std::endl;

        std::cout << " " << i << " \t";

        //std::cout << "|";
        for (int j = 0; j < size; j++) {
            switch (field[i][j])
            {
            case 1:
                std::cout << "  O |\t";
                break;

            case -1:
                std::cout << "  X |\t";
                break;

            default:
                std::cout << "    |\t";
                break;
            }
        }
        std::cout << std::endl;
        std::cout << "   \t";
        for (int l = 0; l < size; l++) { std::cout << "----\t"; }


    }

}
// metoda sprawdzajaca wygrana
int Game::is_vin() {
    int counter;
    int players[2] = { 1,-1 };

        for (int player : players) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    // Sprawdzanie w poziomie
                    counter = 0;
                    for (int k = 0; k < victory_condition; k++) {
                        if (j + k == size) break;
                        if (field[i][j + k] == player) counter++;
                    }
                    // Sprawdzanie w pionie
                    if (counter == victory_condition) return player;
                    counter = 0;
                    for (int k = 0; k < victory_condition; k++) {
                        if (j + k == size) break;
                        if (field[j + k][i] == player) counter++;
                    }
                    // Sprawdzanie skosu lewego
                    if (counter == victory_condition) return player;
                    counter = 0;
                    for (int k = 0; k < victory_condition; k++) {
                        if (i + k == size) break;
                        if (j + k == size) break;
                        if (field[i + k][size - j - k - 1] == player) counter++;
                    }
                    // Sprawdzanie skosu prawego
                    if (counter == victory_condition) return player;
                    counter = 0;
                    for (int k = 0; k < victory_condition; k++) {
                        if (i + k == size) break;
                        if (j + k == size) break;
                        if (field[i + k][j + k] == player) counter++;
                    }
                    if (counter == victory_condition) return player;
                }
            }
        }
        return 0;
}
// ruch gracza
void Game::moveHM() {
    moves++;
    int x, y;
    do {
        std::cout << std::endl;
        std::cout << "podaj wiersz:";
        std::cin >> x;
        std::cout << "podaj kolumne:";
        std::cin >> y;

    } while (quick_check(x, y, size));

    field[x][y] = -1;
}
// ruch komputera
void Game::AImove() {
    int value = 0;
    int best_move = -2147483647;
    int best_move_x = 0;
    int best_move_y = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] == 0) {
                field[i][j] = 1;
                if (is_vin() == 1) value = 2147483647;
                else value = MinMaxAlgorytm( 0, false, -2147483647, 2147483647);
                field[i][j] = 0;
                if (value > best_move) {
                    best_move = value;
                    best_move_x = i;
                    best_move_y = j;
                }
            }
            else;
        }
    }
    // Wyliczony najlepszy ruch dla komputera
    field[best_move_x][best_move_y] = 1;
}
// Algorytm alpha-beta - ulepszony minimax
int Game::MinMaxAlgorytm(int depth, bool max, int alpha, int beta) {
    int value;
    int temp = is_vin();

    if (temp == -1) return -1000 / depth;
    if (temp == 1) return 1000 / depth;

    if (depth == Depth) return temp;

    if (max) {
        int best_value = -2147483647;
        // Sekwencja MAX
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (field[i][j] == 0) {
                    field[i][j] = 1;
                    value = MinMaxAlgorytm(depth + 1, false, alpha, beta);
                    field[i][j] = 0;
                    best_value = max(value, best_value);
                    alpha = max(alpha, value);
                    if (beta <= alpha) break;
                }
            }
        }
        return best_value;
    }
    else {
        // Sekwencja MIN
        int best_value = 2147483647;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (field[i][j] == 0) {
                    field[i][j] = -1;
                    value = MinMaxAlgorytm( depth + 1, true, alpha, beta);
                    field[i][j] = 0;
                    best_value = min(value, best_value);
                    beta = min(beta, value);
                    if (beta <= alpha) break;
                }
            }
        }
        return best_value;
    }
}

void Game::Play() {
    bool tura = true;
    int temp;
    std::cout << "Witaj w grze toc tac toe!" << std::endl;
    std::cout <<" podaj rozmiar planszy (np. 3 - gra wygeneruje plansze 3x3)" << std::endl;
    std::cin >> temp;
    set_size(temp);
    std::cout << " podaj glebokosc poszukiwan algorytmu (np. 6)" << std::endl;
    std::cin >> temp;
    set_d(temp);
    std::cout << " podaj liczbe znakow w rzedzie potrzebnych do wygranej" << std::endl;
    do {
        std::cin >> temp;
    } while (temp<0 || temp>size);
            set_vc(temp);
            set_ec();
            set_sc();
            reset();
    
    while (is_vin() == 0 || moves == size * size) {
        print();
        moves++;
        if (tura == true) { AImove(); tura = false; }
            else { moveHM(); tura = true; }
        print();
    }

    switch (is_vin()) {
    case 1:
        std::cout << "Zwycieza gracz nr 1!!!";
        break;
    case -11:
        std::cout << "Zwycieza gracz nr 2!!!";
        break;
    case 0:
        std::cout << "Remis";
        break;
    }
}


int main()
{
   
    Game ThisGame;
    ThisGame.Play();
   

}
