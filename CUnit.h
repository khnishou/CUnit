
#pragma once

#define I_MASK  0xFFFF
#define J_SHIFT 16

typedef struct DataStruct DataStruct;

typedef enum
{
    INT_TYPE,
    CHAR_TYPE,
    STRING_TYPE,
    BOOL_TYPE
} DataType;

typedef union
{
    int intValue;
    char charValue;
    char *stringValue;
    bool boolValue;
} DataUnion;

struct DataStruct
{
    DataUnion data;
    DataType type;
    void (*print)(DataStruct *); // Ensure it's using the typedef alias
};

DataStruct set_int(int value);
DataStruct set_char(char value);
DataStruct set_string(char *value);
DataStruct set_bool(bool value);

int datacmp(DataStruct d1, DataStruct d2);
int try(char *test, DataStruct rec, DataStruct exp);
void results(uint32_t result);

void is_opt_test(void);

