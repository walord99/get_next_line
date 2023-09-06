#include <stdbool.h>

areBoolEquals(bool bool1, bool bool2);

int compareBool(bool bool1, bool bool2)
{
    areBoolEquals(bool1, bool2);
}

static int areBoolEquals(bool bool1, bool bool2)
{
    if(bool1 == bool2)
        return true;
    return false;
}