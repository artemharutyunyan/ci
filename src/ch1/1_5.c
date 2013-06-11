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
* @file   1_5.c
* @author Artem Harutyunyan (artem_at_harutyunyan.am)
* @brief  Excercise 1.3 (Cracking the Coding Interview)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

/** @brief read a line */
void readln(char *input) {
  printf("Please enter string: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  input[strlen(input) - 1] = '\0';
}

/** @brief stretch a given string */
bool stretch(char *input, const int n) {

  const unsigned int len = strlen(input);
  if (len + n > MAX_INPUT_SIZE)
    return false;

  int i;
  for (i = len + n; (i - n) >= 0; --i)
    input[i] = input[i - n];

  return true;
}

/** @brief substitute spaces with '%20' */
bool percencode(char *input) {

  unsigned int i = 0;
  while (input[i] != '\0') {
    if (input[i] == ' ') {
      if (stretch(&input[i], 2) != true) {
        printf("Error: ran out of memory limit.");
        return false;
      }
      input[i] = '%';
      input[i + 1] = '2';
      input[i + 2] = '0';
      i += 3;
    } else
      ++i;
  }

  return true;
}

int main() {
  char input[MAX_INPUT_SIZE] = { '0' };

  /* Read the string */
  readln(input);

  /* Substitute spaces with '%20' */
  if (percencode(input) == true)
    printf("'%s'", input);

  return 0;
}

