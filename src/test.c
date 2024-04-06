#include <stdio.h>

typedef struct 
{
    int bits[4];
} s21_decimal;
static s21_decimal value_x[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000000, 0x00000000, 0x00000001, 0x00000000}},  // 18446744073709551616
    {{0x00000001, 0x00000000, 0x00000000, 0x00020000}},  // 0.01
    {{0b00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}},  // 4294967295
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0x00000000, 0x00000003, 0x00000007, 0x00020000}},  // 1291272085288517632
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}}};  // 79228162514264337593543950334

static s21_decimal value_y[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000000, 0x00000001, 0x00000000, 0x00000000}},  // 4294967296
    {{0x00000001, 0x00000000, 0x00000000, 0x00020000}},  // 0.01
    {{0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000}},  // 18446744069414584320
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0x000000F4, 0x00000000, 0x00000000, 0x00030000}},  // 0.244
    {{0x00000000, 0x00000003, 0x00000007, 0x00020000}},  // 1291272085288517632
    {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950334
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}}};  // 79228162514264337593543950335

int s21_is_less(s21_decimal val1, s21_decimal val2);

int main(void)
{
    printf("%d",s21_is_less(value_x[0],value_y[5]));
}

int getSign(s21_decimal val) { return !!(val.bits[3] & (1u << 31)); }
int isNull(s21_decimal val) {
  return !val.bits[0] && !val.bits[1] && !val.bits[2];
}
int s21_is_equal(s21_decimal val1, s21_decimal val2) {
  int result = 1;
  if (isNull(val1) && isNull(val2))
    result = 1;
  else if (getSign(val1) ^ getSign(val2))
    result = 0;
  else {
    for (int i = 2; i >= 0 && result; i--) {
      if (val1.bits[i] != val2.bits[i]) result = 0;
    }
  }
  return result;
}

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  int less = 0;
  if (s21_is_equal(val1, val2)) {
    less = 0;
  } else if (getSign(val1) && !getSign(val2)) {
    less = 1;
  } else if (getSign(val1) == getSign(val2)) {
    int i = 2;
    while (val1.bits[i] == val2.bits[i] && i > -1) i--;
    if (i > -1) less = val1.bits[i] < val2.bits[i];
    if (i > -1 && getSign(val1)) less = !less;
  }
  return less;
}