
#include "CUnit.h"

bool mem_track = false;

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

void mem_track_on(void)
{
    mem_track = true;
}

void mem_track_off(void)
{
	mem_track = false;
}