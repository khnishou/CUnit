
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

int datacmp(const DataStruct d1, const DataStruct d2);
int try(const char *test, const char* detail, const DataStruct rec, const DataStruct exp);
void results(const uint32_t result);

void is_opt_test(void);
void get_opt_test(void);

