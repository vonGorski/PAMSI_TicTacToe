//// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//// Krzysztof Górski 245079
//
//
//
//#include <iostream>
//#include <cstdlib>
//
//struct move {
//    int x, y;
//};
//
//
//class Game {
//private:
//    int** field;
//    int size;
//    int victory_condition;
//    int moves=0;
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
//    bool check_victory(int x, int y, int player);
//    bool draw();
//    int Move(int player);
//    void victory(int player) {
//        int x;
//        std::cout << "wygrywa " << player;
//        std::cin >> x;
//    };
//    move moveHM();
//    move moveAI(int player);
//    //int result();
//    move minimax(int player, int** tfield);
//    int Max(int player, int** tfield);
//    int Min(int player, int** tfield);
//    int alternative_check_vin();
//    bool is_vin();
//};
//
//bool Game::quick_check(int x, int y,int size) {
//    if (x >= size || x < 0)  return true;
//    if (y >= size || y < 0) return true;
//    if (field[x][y] != 0) return true;
//    return false;
//}
//
//void Game::generate(){
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
//    std::cout << "ABC";
//    system("cls");
//    
//    std::cout << "   \t";
//    for (int l=0; l < size; l++) { std::cout << "-" << l << "-\t"; }
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
//bool Game::check_victory(int x, int y, int player) {
//    int count = 0;
//    for (int i = 0; i < size; i++) {
//        
//        if (field[x][i] == player) count++;
//        else count = 0;
//        if (count == victory_condition) return true;
//    }
//    count = 0;
//    for (int i = 0; i < size; i++) {
//
//        if (field[i][y] == player)  count++;
//        else count = 0;
//        if (count == victory_condition) return true;
//    }
//    count = 0;
//    int x0=0, y0=0;
//    int xM = size - 1, yM = size - 1;
//    if (x > y) {
//        count = 0;
//        for (int i = x - y; i < size; i++, y0++) { // w dol
//            if (field[i][y0] == player) count++;
//            else count = 0;
//            if (count == victory_condition) return true;
//        }
//        count = 0;
//        for (int i = labs(x + y - size + 1); i < size; i++, xM--) { // w gore
//            if (field[xM][i] == player) count++;
//            else count = 0;
//            if (count == victory_condition) return true;
//        }
//            }
//    x0 = 0, y0 = 0;
//    if (y > x) {
//        count = 0;
//        for (int i = y - x; i < size; i++, x0++) { // w dol
//            if (field[x0][i] == player) count++;
//            else count = 0;
//            if (count == victory_condition) return true;
//        }
//        count = 0;
//        for (int i = labs(x + y - size + 1); i >= 0; i--, y0++) { // w gore
//            if (field[i][y0] == player) count++;
//            else count = 0;
//            if (count == victory_condition) return true;
//        }
//                 }
//
//    if (x == y) {
//        count = 0;
//        for (int i = 0; i < size; i++) { // w dol
//            if (field[i][i] == player) count++;
//            else count = 0;
//            if (count == victory_condition) return true;
//        }
//        if (x < size / 2) { // w gore 1/2
//            for (int i = labs(x + y - size + 1); i >= 0; i--, y0++ ) {
//                if (field[i][y0] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return true;
//            }
//                    }
//        if (x >= size / 2) { // w gore 2/2
//            for (int i = labs(x + y - size + 1); i < size; i++, xM--) {
//                if (field[xM][i] == player) count++;
//                else count = 0;
//                if (count == victory_condition) return true;
//            }
//        }
//    }
//
//    return false;
//}
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
//int Game::Move(int player) {
//    move current_move;
//    int temp;
//    print();
//
//    // moves++;
//    if (player == 1) {
//        current_move = moveHM();
//    }
//
//    //  field[current_move.x][current_move.y] = player;
//    //  print();
//   //   if (check_victory(current_move.x, current_move.y, player)) victory(player);
//
//    if (player == -1)
//    {
//        current_move = moveAI(player);
//    }
//
//    // Move(1);
//
//    field[current_move.x][current_move.y] = player;
//    print();
//    if (is_vin())
//    {
//      //  victory(alternative_check_vin()/10); 
//      //  return 0;
//    }
//    else if (moves == size * size) { std::cout << "Draw"; return 0; }
//    if (player == 1) { Move(-1); }
//    if (player == -1) { Move(1); }
//}
//
//
//
//
//move Game::moveHM() {
//    moves++;
//    int x, y;
//        do {
//            std::cout << std::endl;
//            std::cout << "podaj wiersz:";
//            std::cin >> x;
//            std::cout << "podaj kolumne:";
//            std::cin >> y;
//
//        } while (quick_check(x, y, size));
//    
//    move HMmove;
//    HMmove.x = x;
//    HMmove.y = y;
//    return HMmove;
//}
//
//move Game::moveAI(int player) {
//    moves++;
//    move temp;
//    temp = minimax(player, field);
//        return temp;
//}
////
////move Game::minimax(int player,int ** t_field) {
////   
////    int bestMS = -100;
////    move BestM;
////    int count_depth = 0;
////    for (int i = 0; i < size; i++) {
////        for (int j = 0; j < size; j++) {
////            if (field[i][j] == 0) {
////                field[i][j] = player;
////               // if (check_victory(i, j, player)) {
////               //     BestM.x = i;
////               //         BestM.y = j;
////               //         return BestM;
////               // }
////                
////                int temp_MS = Max(player * (-1), field, count_depth + 1);
////                if (temp_MS >= bestMS) {
////                    bestMS = temp_MS;
////                    BestM.x = i;
////                    BestM.y = j;
////                }
////                field[i][j] = 0;
////            }
////        }
////    }
////    return BestM;
////}
////
////int Game::Max(int player, int** t_field, int count_depth) {
////  // if(draw(field)) return -5;
////  //  if (count_depth == Depth) return 0;
////    if (is_vin()) return alternative_check_vin();
////    move BestM;
////    int bestMS = 0;
////    for (int i = 0; i < size; i++) {
////        for (int j = 0; j < size; j++) {
////            if (field[i][j] == 0) {
////                field[i][j] = player;
////             //   if (check_victory(i, j, player)) { field[i][j] = 0; bestMS= -10; }
////                int temp_MS = Min(player * (-1), field, count_depth + 1);
////                if (temp_MS >= bestMS) {
////                    bestMS = temp_MS;
////                    BestM.x = i;
////                    BestM.y = j;
////                }
////                field[i][j] = 0;
////            }
////        }
////    }
////    return bestMS;
////}
////
////int Game::Min(int player, int** t_field, int count_depth) {
////  //  if (draw(field)) return 5;
////  //  if (count_depth == Depth) return 0;
////    if (is_vin()) return alternative_check_vin();
////    move BestM;
////    int bestMS = 0;
////    for (int i = 0; i < size; i++) {
////        for (int j = 0; j < size; j++) {
////            if (field[i][j] == 0) {
////                field[i][j] = player;
////              //  if (check_victory(i, j, player)) { field[i][j] = 0; bestMS = 10; }
////                int temp_MS = Max(player * (-1), field, count_depth + 1);
////                if (temp_MS <= bestMS) {
////                    bestMS = temp_MS;
////                    BestM.x = i;
////                    BestM.y = j;
////                }
////                field[i][j] = 0;
////            }
////        }
////    }
////    return bestMS;
////}
//
////int Game::result() {
////    if (check_victory(1)) { return 10; }
////    else if (check_victory(-1) { return -10; }
////    
////    return 0; // draw
//
//
//move Game::minimax(int player, int **tfield) {
//    int bestMoveScore = 100; // -100 is arbitrary
//    move bestMove;
//
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (tfield[i][j] == 0) {
//                tfield[i][j] = player;
//                int tempMoveScore = Max(player * (-1), tfield);
//                if (tempMoveScore <= bestMoveScore) {
//                    bestMoveScore = tempMoveScore;
//                    bestMove.x = i;
//                    bestMove.y = j;
//                }
//                tfield[i][j] = '-';
//            }
//        }
//    }
//
//    return bestMove;
//}
//
//int Game::Max(int player, int** tfield) {
//    if (is_vin()) return alternative_check_vin();
//    move bestMove;
//
//    int bestMoveScore = -1000;
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (tfield[i][j] == player){
//                tfield[i][j] = player;
//                int tempMoveScore = Min(player*(-1),tfield);
//                if (tempMoveScore >= bestMoveScore) {
//                    bestMoveScore = tempMoveScore;
//                    bestMove.x = i;
//                    bestMove.y = j;
//                }
//                tfield[i][j] = '-';
//            }
//        }
//    }
//
//    return bestMoveScore;
//}
//
//int Game::Min(int player, int** tfield) {
//    if (is_vin()) return alternative_check_vin();
//    move bestMove;
//
//    int bestMoveScore = 1000;
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (tfield[i][j] == 0) {
//                tfield[i][j] = player;
//                int tempMove = Max(player * (-1), tfield);
//                if (tempMove <= bestMoveScore) {
//                    bestMoveScore = tempMove;
//                    bestMove.x = i;
//                    bestMove.y = j;
//                }
//                tfield[i][j] = '-';
//            }
//        }
//    }
//
//    return bestMoveScore;
//}
//
//
//
//
//
//
//
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
//            int j=0; // w dol
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
//    //szukanie remisu
//    if (draw()) return 0;
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
////
////int main()
////{
////    int nsize = 3;
////    std::cout << "Hello World!\n";
////    Game ThisGame;
////    ThisGame.set_size(nsize);
////    ThisGame.generate();
////    ThisGame.reset();
////   // ThisGame.print();
////    ThisGame.set_vc(3);
////    ThisGame.set_sc();
////    ThisGame.set_ec();
////    ThisGame.set_d(3);
////    ThisGame.Move(1);
////    ThisGame.alternative_check_vin();
////
////}
//
//
//
//
//
//
//
//
//
//
//
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
