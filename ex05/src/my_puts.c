#include <unistd.h>
#include <string.h>

int my_puts(const char *s)
{
  int i;
  char c;

  i = -1;
  while (++i < strlen(s))
  {
    c = s[i];
    write(1, &c, 1);
  }
  c = '\n';
  write (1, &c, 1);
  return 0;
}
