
#include "../../include/ft_ping.h"
#include "../CUnit.h"


void is_opt_test(void)
{
    uint32_t count;

    dprintf(1, ORANGE"~~~~~~~~~~~~~~~~~~~~~~~~~~~ is_opt TESTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"DEFAULT);
    count = 0;
    //			TEST_CASE		RECEIVED						EXPECTED
    count += try("NULL",		set_bool(is_opt(NULL)),			set_bool(false));
    count += try("<>",			set_bool(is_opt("")),			set_bool(false));
    count += try("<random>",	set_bool(is_opt("random")),		set_bool(false));
    count += try("<-random>",	set_bool(is_opt("-random")),	set_bool(true));

    results(count);
}
