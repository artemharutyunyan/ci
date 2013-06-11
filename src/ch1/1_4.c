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
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

void readln(char *input) {
  printf("Please enter the first string: ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  input[strlen(input) - 1] = '\0';
}

bool areAnagrams(const char *str1, const char *str2) {
  int lookup[256] = { 0 };
  const unsigned int len = strlen(str1);

  /* just in case :-) */
  if (strlen(str2) != len)
    return false;

  unsigned int i;
  for (i = 0; i < len; ++i) {
    ++lookup[str1[i]];
    --lookup[str2[i]];
  }

  for (i = 0; i < len; ++i)
    if (lookup[i] != 0)
      return false;

  return true;
}

int main() {
  char input[2][MAX_INPUT_SIZE];
  readln(input[0]);
  readln(input[1]);

  if (areAnagrams(input[0], input[1]))
    printf("String are anagrams\n");
  else
    printf("Strings are not anagrams\n");

  return 0;
}

