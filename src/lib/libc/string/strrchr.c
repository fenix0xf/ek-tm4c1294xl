#include <string.h>

char* strrchr(const char* s, int c)
{
    return (char*)__memrchr(s, c, strlen(s) + 1);
}
