#include "ssafy_shell_lib.h"

void tolower_str(char *str, int len)
{
    while (*str && len--)
    {
        *str = tolower(*str);
        ++str;
    }
}