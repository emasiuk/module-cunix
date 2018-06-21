#include <string.h>

unsigned int my_strlen(char *str)
{
  int counter;

  counter = 0;
  
  while(*(counter + str) != '\0')
    counter++;

  return counter;
}
