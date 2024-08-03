#pragma once

#define fail_unless(cond) do {				\
	if (!cond) {					\
		fprintf(stderr, "%s failed at %s:%d\n",	\
			#cond, __FILE__, __LINE__);	\
		exit(1);				\
	}						\
} while (false)
