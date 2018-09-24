#include <stdio.h>

void insert(char *str, int position, char *substr)
{
  int strlen=0, sstrlen=0, i;
  while(str[strlen] != '\0') strlen++;
  while(substr[sstrlen] != '\0') sstrlen++;
  for(i=strlen; i>=position; i--) str[i+sstrlen]=str[i];
  for(i=position; i<position+sstrlen; i++) str[i]=substr[i-position];
}

int main(void)
{
  char str[100] = "a quick brown fox jumps over the  dog.", substr[100] = "lazy", position=33;
  int i=0, strlen=0, sstrlen=0;
  printf("\t::This program insert a substring in a string::\n");
  insert(str, position, substr);
  printf("\nNow the string is: %s\n", str);
  return 0;
}
