#include <stdio.h>

#define CACHE_SIZE 8        // Number of cache lines
#define MEMORY_SIZE 32      // Simulated memory size intialized.with 32 for the less complicity
#define BLOCK_SIZE 1        // Assuming block size = 1 word for simplicity

int main() {
    int cache[CACHE_SIZE];       // Cache storage (just stores memory block addresses)
    int memory[MEMORY_SIZE];     // Simulated main memory

    
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = i * 10;
    }

    // Initialize cache as empty(flag)
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i] = -1;  // -1 means empty
    }

    // Simulate memory accesses
    int addresses_to_access[] = {0, 5, 8, 16, 24, 8, 0, 25, 16};
    int n = sizeof(addresses_to_access) / sizeof(addresses_to_access[0]);

    for (int i = 0; i < n; i++) {
        int addr = addresses_to_access[i];
        int index = (addr / BLOCK_SIZE) % CACHE_SIZE;

        printf("Accessing memory address %d: ", addr);

        if (cache[index] == addr) {
            printf("Cache HIT at index %d\n", index);
        } else {
            printf("Cache MISS at index %d. Replacing %d with %d\n", index, cache[index], addr);
            cache[index] = addr;
        }
    }

    return 0;
}
