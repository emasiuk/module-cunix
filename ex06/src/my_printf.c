#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>



long unsigned int i, j, x;
char c, np, fuck;
va_list args;

char* my_itoa(int nmb)
{
  int i, j, k;

  i = 10;
  j = 0;
  k = 0;
  while (nmb / i != 0)
  {
    i *= 10;
    j++; //nmb symb amount
  }
  char *y = malloc (sizeof (char) * j + 1);
  i = 0;
  if (nmb < 0)
  {
    nmb *= -1;
    y[0] = '-';
    k++;
    j++;
  }
  while (j >= k)
  {
    y[j] = (nmb % 10) + '0';
    nmb /= 10;
    j--;
  }
  return y;
}


void write_text_before(const char* format)
{
  i--;
  np = ' ';
  while (++i < strlen(format))
  {
    c = format[i];
    if (c == '\n')
      break;
    if (c == '%')
    {
      if (format[i + 1] == '%')
        i++;
      else
        break;
    }
    write(1, &c, 1);
  }
  i++;
}


void if_string()
{
  long unsigned int tmp;
  char* arg;

  tmp = 0;
  np = ' ';
  arg = va_arg(args, char*);
  if (x < strlen(arg))
    x = strlen(arg);
  while(++tmp <= (x - strlen(arg)))
    write(1, &np, 1);
  write(1, arg, strlen(arg));
  x = 0;
}

void if_integer()
{
  int d, arg, r;
  long unsigned int tmp;
  
  r = 0;
  d = 1;
  arg = va_arg(args, int);
  while(arg/d != 0)
  {
    r++;
    d *= 10;
  }
  tmp = 0;
  if (x == 0)
    x = r;
  while(++tmp <= (x - r))
    write(1, &np, 1);
  write(1, my_itoa(arg), r);
  x = 0;
}


int string_length(const char* format)
  {
    if (format[i] == '0')
    {
      np = '0';
      i++;
    }
    c = format[i];
    if ((c >= '1') && (c <= '9')) //x = string length
    {
      if ((format[i + 1] >= '0') && (format [i + 1] <= '9'))
      {
        x = ((format[i + 1] - '0') + (c - '0') * 10);
        i++;
      }
      else
        x = c - '0';
      i++;
    }
    return x;
  }



int my_printf(const char *format, ...)
{
  i = -1;
  fuck = '\n';
  va_start(args, format);
  while(++i < strlen(format))
  {
    write_text_before(format);
    if (format[i - 1] == '%')
    {
      string_length(format);
      if (format[i] == 's')
        if_string();
      if (format[i] == 'd')
        if_integer();
    }
  }
  write(1, &fuck, 1);
  va_end(args);
  return 0;
}
