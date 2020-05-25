# SOI-monitors

Task 4 of Operating Systems (SOI) course at WUT FEIT.

Task description (Polish):
> Mamy bufor FIFO na liczby całkowite. Procesy A1 generują kolejne liczby parzyste modulo 100, jeżeli w buforze jest mniej niż 10 liczb parzystych. Procesy A2 generują kolejne liczby nieparzyste modulo 100, jeżeli liczb parzystych w buforze jest więcej niż nieparzystych. Procesy B1 zjadają liczby parzyste, pod warunkiem że w bufor zawiera co najmniej 3 liczby. Procesy B2 zjadają liczby nieparzyste, pod warunkiem że bufor zawiera co najmniej 7 liczb. W systemie może być dowolna liczba procesów każdego z typów. Zakładamy, że bufor FIFO poza standardowym put i get ma tylko metodę umożliwiającą sprawdzenie liczby na wyjściu (bez wyjmowania) oraz posiada metody zliczające elementy parzyste i nieparzyste.



Compile with:
```
g++ main.cpp -pthread
```

