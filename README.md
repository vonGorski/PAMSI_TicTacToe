# PAMSI_TicTacToe
Projekt gry Tic Tac Toe na zaliczenie PAMSI Krzysztof Górski


proba1-4 sa to wersje nie w pełni sprawne,
w niektóych probowałem zoptymalizować czas poprzez sprwdzanie wyranej na podstawie osatniego ruchu
przeszukiwanie odbywalo sie w poziomie, pionie i dwoch skosach ale tylko przechodzacych przez punkt ostatniego ruchu
co minimalizowalo obliczenia. Problem jednak pojawil sie w algorytmie minimax gdsy trzeba bylo ocenic stan na planszy 
niezaleznie od ostatniego ruchu i gracza ktory go wykonał. 
W probach 1/2 probowałem również wprowadzic sprawdzanie wygtranej dopiero od pewnego momentu
wynoszacego 2 x liczba pól w rzędzie potrzebnych do wygranej - 1 
funkcja dziala jednak przeszkadza w funkcjonowaniu minmaxa
