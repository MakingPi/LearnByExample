#include <stdlib.h>
#include "example.h"

extern void* CalculatorAlloc(void *(*mallocProc)(size_t));
extern void Calculator( void*, int, float );
extern void CalculatorFree( void*, void (*freeProc)(void*));
extern void CalculatorInit( void* );

int main( int argc, char** argv)
{
    void* pCalculator = CalculatorAlloc( malloc );
    // 1 + 1
    Calculator(pCalculator, CALC_NUMBER, 1);
    Calculator(pCalculator, CALC_PLUS,   0); // 0 not useful here
    Calculator(pCalculator, CALC_NUMBER, 1);
    Calculator(pCalculator, 0, 0);

    // (2 + 3) * 5
    CalculatorInit(pCalculator); // reset calculator
    Calculator(pCalculator, CALC_L_PAREN,  0);
    Calculator(pCalculator, CALC_NUMBER,   2);
    Calculator(pCalculator, CALC_PLUS,     0);
    Calculator(pCalculator, CALC_NUMBER,   3);
    Calculator(pCalculator, CALC_R_PAREN,  0);
    Calculator(pCalculator, CALC_MULTIPLY, 0);
    Calculator(pCalculator, CALC_NUMBER,   5);
    Calculator(pCalculator, 0, 0);

    // 2 + 3 * 5 - 1
    CalculatorInit(pCalculator); // reset calculator
    Calculator(pCalculator, CALC_NUMBER,   2);
    Calculator(pCalculator, CALC_PLUS,     0);
    Calculator(pCalculator, CALC_NUMBER,   3);
    Calculator(pCalculator, CALC_MULTIPLY, 0);
    Calculator(pCalculator, CALC_NUMBER,   5);
    Calculator(pCalculator, CALC_MINUS,    0);
    Calculator(pCalculator, CALC_NUMBER,   1);
    Calculator(pCalculator, 0, 0);

    // 2.6 * 3
    CalculatorInit(pCalculator); // reset calculator
    Calculator(pCalculator, CALC_NUMBER,   2.6);
    Calculator(pCalculator, CALC_MULTIPLY, 0);
    Calculator(pCalculator, CALC_NUMBER,   3);
    Calculator(pCalculator, 0, 0);

    // ()5
    CalculatorInit(pCalculator); // reset calculator
    Calculator(pCalculator, CALC_L_PAREN,  70);
    Calculator(pCalculator, CALC_R_PAREN,  91);
    Calculator(pCalculator, CALC_NUMBER,   5);
    Calculator(pCalculator, 0, 0);

    // (+ 5)
    CalculatorInit(pCalculator); // reset calculator
    Calculator(pCalculator, CALC_L_PAREN,  2.6);
    Calculator(pCalculator, CALC_PLUS,     12);
    Calculator(pCalculator, CALC_NUMBER,   7);
    Calculator(pCalculator, CALC_R_PAREN,  2.6);
    Calculator(pCalculator, 0, 0);

    CalculatorFree(pCalculator, free);
}
