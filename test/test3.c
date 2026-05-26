#include <stdint.h>

int main()
{
	uint64_t var1, var2;

	volatile uint64_t *var1_ptr = &var1;
	volatile uint64_t *var2_ptr = &var2;

	int hammer_count = 10000;

	while(hammer_count > 0)
	{
		var1 = var1 + 1;
		var2 = var2 + 1;
		asm volatile(
		"clflush (%0);\n\t"
		"clflush (%1);\n\t;"
		"mfence; \n\t"
		::"r"(var1_ptr), "r"(var2_ptr) : "memory");

		hammer_count--;
	}

	return 0;
}
