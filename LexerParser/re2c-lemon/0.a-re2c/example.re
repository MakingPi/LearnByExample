#include <stdbool.h>
#include <stdio.h>

/*!re2c                                // start of re2c block
    digit         = [0-9];             //   define 'digit'
    number        = digit+;            //   define 'number'
    letter        = [a-zA-Z];          //   define 'letter'
    word          = letter+;           //   define 'word'
    alpha_numeric = (letter | digit)+; //   define 'alpha_numeric'
    spaces        = " "+;              //   define 'spaces'
*/                                     // end of re2c block

static int lex(const char *start)
{
    printf( "lexing [%s]: ", start );
    const char *YYCURSOR = start;    // YYCURSOR is defined as a function parameter
    const char *YYMARKER;            // YYMARKER is defined as a local variable

    while(true) {                    // keep lexing for all matches
        do {                         // defining a block/scope for re-entering lexer
            /*!re2c                                                 // start of re2c block
            re2c:define:YYCTYPE = char;                             //   configuration that defines YYCTYPE
            re2c:yyfill:enable  = 0;                                //   configuration that turns off YYFILL

                                                                    // rules with 'break' will re-enter the outer loop
                                                                    // rules with 'return' will exit the lex function

            *             { printf("err/eof/eoi\n");   return 0; }  //   default rule (also ends outer while loop)
            word          { printf("word ");           break; }     //   word rule
            number        { printf("number ");         break; }     //   number rule
            alpha_numeric { printf("alpha_numeric ");  break; }     //   al-num rule
            spaces        { printf("spaces ");         break; }     //   spaces rule
            
            */                                                      // end of re2c block
        } while (false);
    }
}
 
int main()
{
    lex("1");
    lex("10");
    lex("10      24");
    lex("A");
    lex("x");
    lex("Tomato");
    lex("22 Cars");
    lex("4 . 6");
    lex("!23 bad input");
    lex("s3cr3t PA55W0RD");

    return 0;
}