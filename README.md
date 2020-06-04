# AAL_Knapsack
# Author: Przybysz Filip

Porównanie prostych algorytmów rozwiązywania problemu plecakowego z ograniczoną liczbą przedmiotów: brutalnego i prostego dynamicznego.

Implementacja w C++.
Opis projektu w "Koncepcji".
Opis programu w dokumentacji (folder doc).


Istrukcja:
Aby skompilować program należy wywołać polecenie scons.

Aby skorzystać z programu należy go uruchomić z odpowiednią komendą (i ewentualnie algorytmem):
Komendy:
-help -- pokazuje pomoc
-run -- rozwiąż problem dla podanych danych
-generate -- wygeneruj dane na podstawie podanych parametrów i rozwiąż problem
-test -- wygeneruj wiele zestawów danych na podstawie ustalonych parametrów, rozwiąż problemy i wypisz analizę czasową

Przyjmowane algorytmy:
-brutal
-dynamic

Metody wykonania:
Knapsack -help
Knapsack -run -<algorithm> -- w następnej linii wartości: pojemność plecaka, ilość obiektów, maksymalna liczba kopii; następnie pary wartości obiektu i jego wagi
Knapsack -generate -<algorithm> -- w następnej linii parametry generatora: ilość obiektów, maksymalna liczba kopii, maksymalna waga obiektu
Knapsack -test -<algorithm>
