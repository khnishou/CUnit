
#include "CUnit.h"

int datacmp(const DataStruct d1, const DataStruct d2)
{
    if (d1.type == d2.type)
    {
        if (d1.type == INT_TYPE)
            return (!(d1.data.intValue == d2.data.intValue));
        if (d1.type == CHAR_TYPE)
            return (!(d1.data.charValue == d2.data.charValue));
        if (d1.type == STRING_TYPE)
            return (strcmp(d1.data.stringValue ,d2.data.stringValue));
        if (d1.type == BOOL_TYPE)
            return (!(d1.data.boolValue == d2.data.boolValue));
    }
    // type not the same
    return (1);
}

void print_int(DataStruct *d) {
    dprintf(1, "%d", d->data.intValue);
}

void print_char(DataStruct *d) {
    dprintf(1, "%c", d->data.charValue);
}

void print_string(DataStruct *d) {
    if (!d->data.stringValue)
        dprintf(1, "NULL");
    else if (!d->data.stringValue[0])
        dprintf(1, "empty string");
    else
        dprintf(1, "<%s>", d->data.stringValue);
}

void print_bool(DataStruct *d)
{
    dprintf(1, d->data.boolValue ? "true" : "false");
}

DataStruct set_int(int value)
{
    DataStruct ret;

    ret.data.intValue = value;
    ret.type = INT_TYPE;
    ret.print = &print_int;
    return (ret);
}

DataStruct set_char(char value)
{
    DataStruct ret;

    ret.data.charValue = value;
    ret.type = CHAR_TYPE;
    ret.print = &print_char;
    return (ret);
}

DataStruct set_string(char *value)
{
    DataStruct ret;

    ret.data.stringValue = value;
    ret.type = STRING_TYPE;
    ret.print = &print_string;
    return (ret);
}

DataStruct set_bool(bool value)
{
    DataStruct ret;

    ret.data.boolValue = value;
    ret.type = BOOL_TYPE;
    ret.print = &print_bool;
    return (ret);
}