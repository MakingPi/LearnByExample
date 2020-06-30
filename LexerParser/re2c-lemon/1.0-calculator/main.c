#include <stdlib.h>
#include <stdio.h>

#include "calc-token.h"
#include "calc-parser.h"

// declared in the parser
extern void* CalculatorAlloc(void *(*mallocProc)(size_t));
extern void Calculator( void*, int, struct CalcToken );
extern void CalculatorFree( void*, void (*freeProc)(void*));
extern void CalculatorInit( void* );

// declared in the scanner
extern int lex(struct CalcToken *token );

void runTest (const char* input)
{
    //prepare first token
    struct CalcToken token;
    token.cursor = input;
    //allocate parser
    void* pCalculator = CalculatorAlloc( malloc );
    while( lex( &token ) ) // as long as there are tokens
    {
        // feed the parser each token
        Calculator(pCalculator, token.id, token);
    }
    printf(" %s ", input);
    // signal end of tokens
    Calculator(pCalculator, 0, token);
    // free parser resources
    CalculatorFree(pCalculator, free);
}

int main( int argc, char** argv)
{
    runTest("1+1=");
    runTest("(2 + 3) * 5 =");
    runTest("2+3  * 5-1=");
    runTest("2.6*3=");
    runTest("()5=");
    runTest("(+5)=");
    runTest("rabbit");
    runTest("7=99+3*3=2=33==4");
}
