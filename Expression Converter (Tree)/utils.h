#include "boolean.h"
//defining the numeric function used in the calc main source file
boolean is_numeric(char);

boolean is_numeric(char ch)
{
  return (ch >= '0' && ch <= '9');
}
