#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
	unsigned int lo, hi;

	__asm__ volatile(
			"rdtsc" : "=a"(lo), "=d"(hi)
			);
	return ((uint64_t)hi << 32) | lo;
}

int main() {
	uint64_t start, end, total = 0;
	int iterations = 10000;

	for (int i = 0; i < iterations; i++) {
		start = rdtsc();
		getpid();
		end = rdtsc();
		total += (end - start);
	}
	printf("Total Cycles: %lu\n", total);
	printf("Avg Cycles: %lu\n", total / iterations);
	return 0;
}
