/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/

/**
* @file   1_1.c
* @author Artem Harutyunyan (artem_at_harutyunyan.am)
* @brief  Excercise 1.1 (Cracking the Coding Interview)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

/** @brief Using a lookup table */
bool isUniqueHt(const char *input) {
  char ascii[256] = { 0 };
  unsigned int i;

  for (i = 0; i < strlen(input); ++i) {
    if (ascii[input[i]] != 0)
      return false;

    ascii[input[i]] = 1;
  }

  return true;
}

/** @brief no extra data structure */
bool isUniqueN2(const char *input) {
  unsigned int i;
  unsigned int j;
  const unsigned int len = strlen(input);

  for (i = 0; i < len; ++i) {
    for (j = i + 1; j < len; ++j) {
      if (input[i] == input[j])
        return false;
    }
  }

  return true;
}

int main() {

  char input[MAX_INPUT_SIZE];

  printf("Please enter the string: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  if (isUniqueHt(input) == true)
    printf("All characters are unique\n");
  else
    printf("Not all characters are unique\n");

  return 0;
}

