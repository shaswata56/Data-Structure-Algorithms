#include <stdio.h>

void Remove(char *str, int position, int len)
{
  int strlen=0, i;
  while(str[strlen] != '\0') strlen++;
  for(i=position; i <= strlen-len; i++) str[i]=str[i+len];
}

int main(void)
{
  char str[100] = "a quick brown fox jumps over the lazy dog.", len = 5, position=33;
  printf("\t::This program remove substring from a string::\n");
  printf("\nOriginal string was: %s\n", str);
  Remove(str, position, len);
  printf("\nNow the string is: %s\n", str);
  return 0;
}
