
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[1;34m"
#define ORANGE  "\033[38;5;202m\033[22m"
#define GRAY    "\033[1;30m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define DEFAULT "\033[1;39m"

#define I_MASK  0xFFFF
#define J_SHIFT 16

// static bool mem_track = true; // change to "true" track memory
extern bool mem_track;

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

void *malloc(size_t size);
void free(void *ptr);
void print_leaks();

void mem_track_on(void);
void mem_track_off(void);

// void is_opt_test(void);
// void get_opt_test(void);
