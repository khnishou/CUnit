
#include "../include/ft_ping.h"
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

int try(const char *test, const char* detail, DataStruct rec, DataStruct exp)
{
    uint32_t count = 1;

    if (!datacmp(rec, exp))
        return count;

    dprintf(1, "\n\033[1;31m[FAILED]\033[0m "); // Bold Red
    dprintf(1, "\033[1;37mTest:\033[0m "); // White
    if (detail)
        dprintf(1, "%s ", detail);
    dprintf(1, "\"%s\"\n", test);

    dprintf(1, "  🔹 Expected: ");
    exp.print(&exp);
    dprintf(1, "\n");

    dprintf(1, "  🔸 Received: ");
    rec.print(&rec);
    dprintf(1, "\n");

    count += (1 << J_SHIFT);
    return count;
}

void results(const uint32_t result)
{
    uint16_t passed = (result & I_MASK) - ((result >> J_SHIFT) & I_MASK);
    uint16_t total  = result & I_MASK;
    uint16_t failed = (result >> J_SHIFT) & I_MASK;

    dprintf(1, "\n\033[1;34m[TEST RESULTS]\033[0m"); // Bold Blue Header
    dprintf(1, "\t\t✅ Passed: %u", passed);
    dprintf(1, "\t❌ Failed: %u", failed);
    dprintf(1, "\t📊 Total:  %u\n", total);
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

int main(void)
{
    is_opt_test();
    dprintf(1, "\n");
    get_opt_test();
    return 0;
}
