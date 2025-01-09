#pragma once

#define fail_unless(cond) do {				\
	if (!cond) {					\
		fprintf(stderr, "%s failed at %s:%d\n",	\
			#cond, __FILE__, __LINE__);	\
		exit(1);				\
	}						\
} while (false)

#define note(fmt, ...) fprintf(stderr, "%s: " fmt "\n", __func__, ## __VA_ARGS__);
