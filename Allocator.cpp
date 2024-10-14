#include <iostream>
#include <array>

#define BUFFER_SIZE 64

struct FixedBuffer 
{
    std::array<int, BUFFER_SIZE> buffer; // fixed amount of memory
    int end_index = 0; // indicator of how much memory is allocated

    int *allocate(int size) 
    {
        if (size <= 0) 
        {
            throw std::invalid_argument("Amount of memory must be positive.");
        }

        int new_index = end_index + size;

        if (new_index > BUFFER_SIZE) 
        {
            throw std::runtime_error("Space exceeded");
        }

        int *allocated_memory = &buffer[end_index]; // retrieves address of newly allocated memory
        end_index = new_index; // moves the pointer to the end of the newly allocated block
        return allocated_memory; // returns the address of the allocated memory
    
    }

};

