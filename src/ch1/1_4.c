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
* @file   1_3.c
* @author Artem Harutyunyan (artem_at_harutyunyan.am)
* @brief  Excercise 1.3 (Cracking the Coding Interview)
*/

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/** @brief remove the first characater from a given string */
void shrink(char *input) {
  unsigned int i = 0;
  const unsigned int last = strlen(input);
  char c;

  while (i < last) {
    input[i] = input[i + 1];
    ++i;
  }
}

void dedup(char *input) {
  unsigned char lookup[256] = { 0 };

  unsigned int i = 0;
  while (input[i] != '\0') {
    if (lookup[input[i]] != 0)
      /* remove duplicate by shrinking the string */
      shrink(&input[i]);
    else {
      lookup[input[i]] = 1;
      ++i;
    }
  }
}

int main() {
  char input[MAX_INPUT_SIZE];

  /* Read the string */
  printf("Please enter the string: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  /* Remove the newline */
  input[strlen(input) - 1] = '\0';
  dedup(input);
  printf("The deduplicated string is: %s\n", input);

  /* Test cases */
  char test[][10] = { "aaaaa", "bsbsbs", "asdfdsa", "qwert", "" };
  unsigned int i = 0;
  while (strlen(test[i]) > 0) {
    printf("Deduplicated version of '%s' is ", test[i]);
    dedup(test[i]);
    printf("'%s'\n", test[i]);
    ++i;
  }

  return 0;
}

