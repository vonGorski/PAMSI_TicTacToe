// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Krzysztof Górski 245079



#include <iostream>
#include <cstdlib>

class Game {
private:
    int** field;
    int size;
    int victory_condition;
    int moves=0;
    int start_condition; // 2x-1
    int end_condition;
public:
    void set_size(int newsize) { size = newsize; }
    void set_vc(int newvc) { victory_condition = newvc; } 
    void set_sc() { start_condition = 2 * victory_condition - 1; }
    void set_ec() { end_condition = size * 2; }

    bool quick_check(int x, int y, int size);
    void generate();
    void reset();
    void print();
    bool check_victory(int x, int y, int player);
    void move(int player);
    void victory(int player) { std::cout << "wygrywa " << player; };
};

bool Game::quick_check(int x, int y,int size) {
    if (x >= size || x < 0)  return true;
    if (y >= size || y < 0) return true;
    if (field[x][y] != 0) return true;
    return false;
}

void Game::generate(){
    field = new int* [size];
    for (int i = 0; i < size; i++) field[i] = new int[size];
}
void Game::reset() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = 0;
        }
    }
}
void Game::print() {
    std::cout <<" X->  Y ^ "<< std::endl;
    for (int l=0; l < size; l++) { std::cout << "--"; }
    for (int i = 0; i < size; i++) {
        std::cout << std::endl;
        std::cout << "|";
        for (int j = 0; j < size; j++) {
            switch (field[i][j])
            {
            case 1:
                std::cout << "O|";
                break;

            case -1:
                std::cout << "X|";
                break;

            default:
                std::cout << " |";
                break;
            }
        }
        std::cout << std::endl;
        for (int l=0; l < size; l++) { std::cout << "--"; }
    }

}
bool Game::check_victory(int x, int y, int player) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        
        if (field[x][i] == player) count++;
        else count = 0;
        if (count == victory_condition) return true;
    }
    count = 0;
    for (int i = 0; i < size; i++) {

        if (field[i][y] == player)  count++;
        else count = 0;
        if (count == victory_condition) return true;
    }
    count = 0;
    int x0=0, y0=0;
    int xM = size - 1, yM = size - 1;
    if (x > y) {
        count = 0;
        for (int i = x - y; i < size; i++, y0++) { // w dol
            if (field[i][y0] == player) count++;
            else count = 0;
            if (count == victory_condition) return true;
        }
        count = 0;
        for (int i = x + y - size + 1; i < size; i++, xM--) { // w gore
            if (field[xM][i] == player) count++;
            else count = 0;
            if (count == victory_condition) return true;
        }
            }
   // x0 = 0, y0 = 0;
    if (y > x) {
        count = 0;
        for (int i = y - x; i < size; i++, x0++) { // w dol
            if (field[x0][i] == player) count++;
            else count = 0;
            if (count == victory_condition) return true;
        }
        count = 0;
        for (int i = x + y; i >= 0; i--, y0++) { // w gore
            if (field[i][y0] == player) count++;
            else count = 0;
            if (count == victory_condition) return true;
        }
                 }

    if (x == y) {
        count = 0;
        for (int i = 0; i < size; i++) { // w dol
            if (field[i][i] == player) count++;
            else count = 0;
            if (count == victory_condition) return true;
        }
        if (x < size / 2) { // w gore 1/2
            for (int i = labs(x + y - size + 1); i >= 0; i--, y0++ ) {
                if (field[i][y0] == player) count++;
                else count = 0;
                if (count == victory_condition) return true;
            }
                    }
        if (x >= size / 2) { // w gore 2/2
            for (int i = labs(x + y - size + 1); i < size; i++, xM--) {
                if (field[xM][i] == player) count++;
                else count = 0;
                if (count == victory_condition) return true;
            }
        }
    }

    return false;
}
void Game::move(int player) {
    print();
    int x, y;
    moves++;
    do {
        std::cout << "podaj X:";
        std::cin >> x;
        std::cout << "podaj Y:";
        std::cin >> y;
     
    } while (quick_check(x, y, size));

        field[x][y] = player;
   // if (moves > start_condition) {
        if (check_victory(x, y, player)) { 
            victory(player); }
    //}

    move(1);
  //  if (player == 1) { move(-1); }
  //  if (player == -1) { move(1); }

}

int main()
{
    int nsize = 3;
    std::cout << "Hello World!\n";
    Game ThisGame;
    ThisGame.set_size(nsize);
    ThisGame.generate();
    ThisGame.reset();
   // ThisGame.print();
    ThisGame.set_vc(3);
    ThisGame.set_sc();
    ThisGame.set_ec();
    ThisGame.move(1);

}












// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
