#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static int	g_call_count;
static int	g_last_index;
static void	*g_seen_ctx;

static void	count_body(int index, void *ctx)
{
	(void)ctx;
	g_call_count++;
	g_last_index = index;
}

static void	record_ctx_body(int index, void *ctx)
{
	(void)index;
	g_seen_ctx = ctx;
}

tstsuite("run_trials") {
    tstcase("calls body once per trial with sequential indices") {
        g_call_count = 0;
        g_last_index = -1;
        run_trials(SEED, TRIALS, count_body, NULL);
        tstexpect(g_call_count == TRIALS,
            "run_trials called body %d times, expected %d", g_call_count, TRIALS);
        tstexpect(g_last_index == TRIALS - 1,
            "run_trials last index was %d, expected %d", g_last_index, TRIALS - 1);
    }

    tstcase("passes context pointer through to body") {
        int	marker = 42;
        g_seen_ctx = NULL;
        run_trials(SEED, 1, record_ctx_body, &marker);
        tstexpect(g_seen_ctx == &marker,
            "run_trials did not pass ctx through");
    }

    tstcase("runs zero trials when trials is 0") {
        g_call_count = 0;
        run_trials(SEED, 0, count_body, NULL);
        tstexpect(g_call_count == 0,
            "run_trials called body %d times with trials=0", g_call_count);
    }
}
