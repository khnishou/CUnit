
#include "CUnit.h"

static int alloc_count = 0;

void *malloc(size_t size)
{
    static void *(*real_malloc)(size_t) = NULL;
    if (!real_malloc) {
        real_malloc = dlsym(RTLD_NEXT, "malloc");
    }

    void *ptr = real_malloc(size);
    if (ptr && mem_track) {
        alloc_count++;
        printf(BLUE "[ALLOC] " CYAN "%-3d" DEFAULT " | " ORANGE "Addr: %-16p" DEFAULT " | " GREEN "Size: %-4zu\n"DEFAULT, 
               alloc_count, ptr, size);
    }
    return ptr;
}

void free(void *ptr) {
    static void (*real_free)(void *) = NULL;
    if (!real_free) {
        real_free = dlsym(RTLD_NEXT, "free");
    }

    if (ptr && mem_track) {
        alloc_count--;
        printf(YELLOW "[FREE]  " CYAN "%-3d" DEFAULT " | " ORANGE "Addr: %-16p" DEFAULT "\n", 
               alloc_count, ptr);
    }

    real_free(ptr);
}

void print_leaks()
{
    if (mem_track)
    {
        printf("\n" GRAY "--------------------------------------\n" DEFAULT);
        if (alloc_count > 0)
            printf(RED "[LEAK DETECTED] " DEFAULT "%d unfreed allocations!\n"DEFAULT, alloc_count);
        else if (alloc_count < 0)
            printf(RED "[EXTRA FREE DETECTED] " DEFAULT "%d extra free calls detected!\n"DEFAULT, alloc_count * -1);
        else
            printf(GREEN "[NO LEAKS] " DEFAULT "All memory was freed properly.\n"DEFAULT);
        printf(GRAY "--------------------------------------\n" DEFAULT);
    }
}