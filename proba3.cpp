//#include <iostream>
//#include <cstdlib>
//#include <windows.h> 
//#include <algorithm>
//
//struct move {
//    int x, y;
//};
//
//class Game {
//private:
//    int** field;
//    int size;
//    int victory_condition;
//    int moves = 0;
//    int start_condition; // 2x-1
//    int end_condition;
//    int Depth;
//public:
//    void set_size(int newsize) { size = newsize; }
//    void set_vc(int newvc) { victory_condition = newvc; }
//    void set_sc() { start_condition = 2 * victory_condition - 1; }
//    void set_ec() { end_condition = size * 2; }
//    void set_d(int new_depth) { Depth = new_depth; }
//
//    bool quick_check(int x, int y, int size);
//    void generate();
//    void reset();
//    void print();
//
//    bool draw();
//
//    move moveHM();
//    move moveAI(int player);
//    void Play(int player);
//
//    int minimax(int depth, int player);
//    int Max(int player);
//    int Min(int player);
//    int alternative_check_vin();
//    bool is_vin();
//    move findBestMove(int player);
//};
//
//bool Game::quick_check(int x, int y, int size) {
//    if (x >= size || x < 0)  return true;
//    if (y >= size || y < 0) return true;
//    if (field[x][y] != 0) return true;
//    return false;
//}
//void Game::generate() {
//    field = new int* [size];
//    for (int i = 0; i < size; i++) field[i] = new int[size];
//}
//void Game::reset() {
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            field[i][j] = 0;
//        }
//    }
//}
//void Game::print() {
//
//    system("cls");
//
//    std::cout << "   \t";
//    for (int l = 0; l < size; l++) { std::cout << "-" << l << "-\t"; }
//    for (int i = 0; i < size; i++) {
//        std::cout << std::endl;
//
//        std::cout << " " << i << " \t";
//
//        //std::cout << "|";
//        for (int j = 0; j < size; j++) {
//            switch (field[i][j])
//            {
//            case 1:
//                std::cout << "  O |\t";
//                break;
//
//            case -1:
//                std::cout << "  X |\t";
//                break;
//
//            default:
//                std::cout << "    |\t";
//                break;
//            }
//        }
//        std::cout << std::endl;
//        std::cout << "   \t";
//        for (int l = 0; l < size; l++) { std::cout << "----\t"; }
//
//
//    }
//
//}
//
//bool Game::draw() {
//    int count = size * size;
//    for (int i = 0; i < size;i++) {
//        for (int j = 0; j < size; j++) {
//            if (field[i][j] != 0) count--;
//        }
//    }
//    if (count == 0) return true;
//    else return false;
//}
//
//void Game::Play(int player) {
//
//    move temp;
//    while (is_vin() != true) {
//        print();
//        if (player == -1) temp = moveHM();
//        if (player == 1) temp = moveAI(player);
//
//        field[temp.x][temp.y] = player;
//        print();
//        if (player == 1) { player = -1; }
//        else { player = 1; }
//
//    }
//
//
//}
//
//move Game::moveHM() {
//    moves++;
//    int x, y;
//    do {
//        std::cout << std::endl;
//        std::cout << "podaj wiersz:";
//        std::cin >> x;
//        std::cout << "podaj kolumne:";
//        std::cin >> y;
//
//    } while (quick_check(x, y, size));
//
//    move HMmove;
//    HMmove.x = x;
//    HMmove.y = y;
//    return HMmove;
//}
//
//move Game::moveAI(int player) {
//    move AImove;
//    AImove = findBestMove(player);
//    return AImove;
//}
//
//
//int Game::alternative_check_vin() {
//    int players[2] = { -1, 1 }; // tablica graczy
//    // szukanie zwyciestwa
//    for (int player : players) {
//
//
//        for (int i = 0; i < size; i++) {
//            // w szerz
//            int count = 0;
//            for (int j = 0; j < size; j++) {
//                if (field[i][j] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return player * 10;
//            }
//            // wzdluz
//            count = 0;
//            for (int j = 0; j < size; j++) {
//                if (field[j][i] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return player * 10;
//            }
//        }
//        //skosy
//        for (int k = 0; k < size; k++) {
//            int count = 0;
//            int j = 0; // w dol
//            for (int i = k; i < size; i++, j++) {
//                if (field[i][j] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return player * 10;
//            }
//            count = 0;
//            j = 0; // w gore
//            for (int i = k; j >= 0; i++, j--) {
//                if (field[i][j] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return player * 10;
//            }
//        }
//
//
//    }
//
//    return 0;
//}
//
//bool Game::is_vin() {
//    int players[2] = { -1, 1 }; // tablica graczy
//// szukanie zwyciestwa
//    for (int player : players) {
//
//
//        for (int i = 0; i < size; i++) {
//            // w szerz
//            int count = 0;
//            for (int j = 0; j < size; j++) {
//                if (field[i][j] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return true;
//            }
//            // wzdluz
//            count = 0;
//            for (int j = 0; j < size; j++) {
//                if (field[j][i] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return true;
//            }
//        }
//        //skosy
//        for (int k = 0; k < size; k++) {
//            int count = 0;
//            int j = 0; // w dol
//            for (int i = k; i < size; i++, j++) {
//                if (field[i][j] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return true;
//                j = 0; // w gore
//                count = 0;
//                for (int i = k; j >= 0; i++, j--) {
//                    if (field[i][j] == player) count++;
//                    else count = 0;
//                    if (count == victory_condition) return true;
//                }
//            }
//
//        }
//
//    }
//    if (draw()) return true;
//    return false;
//}
//
//
//
//
//int Game::minimax(int depth, int player)
//{
//    if (is_vin()) return alternative_check_vin();
//    // If this maximizer's move 
//    if (player==-1)
//    {
//        int best = -1000;
//
//        // Traverse all cells 
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < size; j++)
//            {
//                // Check if cell is empty 
//                if (field[i][j] == 0)
//                {
//                    // Make the move 
//                    field[i][j] = player;
//
//                    // Call minimax recursively and choose 
//                    // the maximum value 
//                    best = max(best,
//                        minimax(depth + 1, -player));
//
//                    // Undo the move 
//                    field[i][j] = 0;
//                }
//            }
//        }
//        return best;
//    }
//
//    // If this minimizer's move 
//    else
//    {
//        int best = 1000;
//
//        // Traverse all cells 
//        for (int i = 0; i < size; i++)
//        {
//            for (int j = 0; j < size; j++)
//            {
//                // Check if cell is empty 
//                if (field[i][j] == 0)
//                {
//                    // Make the move 
//                   field[i][j] = player;
//
//                    // Call minimax recursively and choose 
//                    // the minimum value 
//                    best = min(best,
//                        minimax(depth + 1, -player));
//
//                    // Undo the move 
//                    field[i][j] = 0;
//                }
//            }
//        }
//        return best;
//    }
//}
//
//// This will return the best possible move for the player 
//move Game::findBestMove(int player)
//{
//    int bestVal = -1000;
//    move bestMove;
//    bestMove.x = -1;
//    bestMove.y = -1;
//
//   
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            // Check if cell is empty 
//            if (field[i][j] == 0)
//            {
//                // Make the move 
//                field[i][j] = player;
//
//                // compute evaluation function for this 
//                // move. 
//                int moveVal = minimax(0, -player);
//
//                // Undo the move 
//                field[i][j] = 0;
//
//                // If the value of the current move is 
//                // more than the best value, then update 
//                // best/ 
//                if (moveVal > bestVal)
//                {
//                    bestMove.x = i;
//                    bestMove.y = j;
//                    bestVal = moveVal;
//                }
//            }
//        }
//    }
//    return bestMove;
//}
//
//int main()
//{
//    int nsize = 4;
//    //  std::cout << "Hello World!\n";
//    Game ThisGame;
//    ThisGame.set_size(nsize);
//    ThisGame.generate();
//    ThisGame.reset();
//    // ThisGame.print();
//    ThisGame.set_vc(3);
//    ThisGame.set_sc();
//    ThisGame.set_ec();
//    ThisGame.set_d(3);
//    ThisGame.Play(-1);
//    // ThisGame.Move(1);
//   //  ThisGame.alternative_check_vin();
//
//}
//
//
//
//
//
