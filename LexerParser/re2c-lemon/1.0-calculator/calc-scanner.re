#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "calc-token.h"
#include "calc-parser.h"

/*!re2c                                    // start of re2c block
    digit         = [0-9];                 //   define 'digit'
    float         = digit+ ("." digit+)? ; //   define decimal point number
    l_paren       = "(";                   //   define open parenthesis
    r_paren       = ")";                   //   define close parenthesis
    plus          = "+";                   //   define addition
    minus         = "-";                   //   define subtraction
    multiply      = "*";                   //   define multiply
    divide        = "/";                   //   define divide
    equals        = "=";                   //   define equality
    spaces        = " "+;                  //   define 'spaces'
*/                                         // end of re2c block

int lex(struct CalcToken *token )
{
    //printf( "lexing [%s]: ", token->cursor );
    const char *YYCURSOR = token->cursor;    // YYCURSOR is defined as a local variable
    const char *YYMARKER;                    // YYMARKER is defined as a local variable

    while(true) {                            // defining a block/scope for re-entering lexer
        /*!re2c                                                 // start of re2c block
        re2c:define:YYCTYPE = char;                             //   configuration that defines YYCTYPE
        re2c:yyfill:enable  = 0;                                //   configuration that turns off YYFILL

                                                                // rules with 'break' will re-enter the outer loop
                                                                // rules with 'return' will exit the lex function

        * {                                                     //   default rule (also ends outer while loop)
            //printf("err/eof/eoi\n");
            return 0;
        }
        float    { 
            token->id = CALC_NUMBER;
            token->value = atof(token->cursor);
            //printf("as_float==%f", token->value);
            break;
        }
        l_paren  {
            token->id = CALC_L_PAREN;
            break;
        }
        r_paren  {
            token->id = CALC_R_PAREN;
            break;
        }
        plus     {
            token->id = CALC_PLUS;
            break;
        }
        minus    {
            token->id = CALC_MINUS;
            break;
        }
        multiply {
            token->id = CALC_MULTIPLY;
            break;
        }
        divide   {
            token->id = CALC_DIVIDE;
            break;
        }
        equals   {
            token->id = CALC_EQUALS;
            break;
        }
        spaces   {
            continue;
        }
        */                                                      // end of re2c block
    };

    token->cursor = YYCURSOR;
    return 1;
}
