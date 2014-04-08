/**
 * @file Memory.c
 * @author Zhang Hai
 */

#include "Memory.h"

#ifndef NDEBUG
#define __LOG_MEMORY_INFO__
#endif

#include <stdlib.h>

#include "Application.h"
#include "Log.h"


static void Memory_checkAllocation(void *address) {
    if (address == null) {
        Application_fatalError("Memory allocation failed.");
    }
}

/**
 * Allocate memory by bytes.
 * @note This function will clear the allocated memory to 0.
 * @param size The size of memory to be allocated.
 */
void *Memory_allocate(size_t size) {
    void *address = calloc(1, size);
    Memory_checkAllocation(address);
    Log_info("Memory: %zu bytes allocated at 0x%p", size, address);
    return address;
}

/**
 * Reallocate memory at an address to a new size.
 * @note This function will NOT clear the reallocated memory.
 * @param address The address of the memory.
 * @param size The size of the memory to be reallocated to.
 */
void *Memory_reallocate(void *address, size_t size) {
    address = realloc(address, size);
    Memory_checkAllocation(address);
    Log_info("Memory: %zu bytes reallocated at 0x%p", size, address);
    return address;
}

void Memory_free(void *address) {
    free(address);
    Log_info("Memory: Memory freed at 0x%p", address);
}
