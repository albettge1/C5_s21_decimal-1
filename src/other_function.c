#include "s21_decimal.c"

int s21_empty(s21_decimal value) {
  return !value.bits[0] && !value.bits[1] && !value.bits[2];
}