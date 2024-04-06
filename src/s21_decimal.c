
typedef struct 
{
    int bits[4];
} s21_decimal;

int s21_is_less(s21_decimal rez, s21_decimal rez1);
int s21_is_less_or_equal(s21_decimal rez, s21_decimal rez1);
int s21_is_greater(s21_decimal rez, s21_decimal rez1);
int s21_is_greater_or_equal(s21_decimal rez, s21_decimal rez1);
int s21_is_equal(s21_decimal rez, s21_decimal rez1);
int s21_is_not_equal(s21_decimal rez, s21_decimal rez1);
int s21_empty(s21_decimal value);