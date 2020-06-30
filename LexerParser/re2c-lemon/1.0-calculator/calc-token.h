#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H

struct CalcToken
{
    const char* cursor;
    int id;
    float value;
} CalcToken;

#endif