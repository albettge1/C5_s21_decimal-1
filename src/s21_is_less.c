#include "s21_decimal.c"

int s21_is_less(s21_decimal a, s21_decimal b)
{
    int less = 0;
    if(s21_is_equal(a,b))
    less = 0;
    if(s21_empty(a) && s21_empty(b))
    less = 0;
}