#include <stdio.h>
#include <stdarg.h>
#include "mocks.h"

int PrintfInputParam[3];
int call_printf= 0;

int stub_printf(const char *format , ...)
{
  int arg_count = 3;
  int arg;
  va_list arg_list;
  va_start(arg_list,format);
  PrintfInputParam[0] = va_arg(arg_list, int);
  PrintfInputParam[1] = va_arg(arg_list, int);
  PrintfInputParam[2] = va_arg(arg_list, int);
  call_printf++;
  return 1;
}

void Reset_mocks(void)
{
    PrintfInputParam[0] = 0;
    PrintfInputParam[1] = 0;
    PrintfInputParam[2] = 0;
    call_printf= 0;
}