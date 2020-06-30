rm calc-parser.c calc-parser.h
lemon calc-parser.lemon

rm calc-scanner.c
re2c -W calc-scanner.re -o calc-scanner.c

rm calculator
gcc main.c calc-scanner.c calc-parser.c -o calculator