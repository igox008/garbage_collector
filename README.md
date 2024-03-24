# G_Collector

G_Collector is a simple memory management utility implemented in C. It provides functions for managing a linked list of allocated memory blocks, allowing for easy tracking and cleanup of dynamically allocated memory.

## Files

### 1. g_collector.h

This header file contains the definitions of the data structures and function prototypes used in the G_Collector utility.

- `typedef struct s_col`: Defines a structure for a node in the linked list, containing a pointer to allocated memory (`ptr`) and a pointer to the next node (`next`).
  
- `typedef enum e_call`: Defines an enumeration for memory allocation operations (`FREE` for freeing memory, `MALLOC` for allocating memory).

#### Function Prototypes

- `t_col *new_node(void *ptr)`: Creates a new node for the linked list.
  
- `t_col *last_node(t_col **head)`: Returns a pointer to the last node in the linked list.
  
- `void add_back(t_col **head, t_col *new)`: Adds a new node to the end of the linked list.
  
- `void clear_all(t_col **head)`: Clears all nodes in the linked list and frees allocated memory.
  
- `void *g_malloc(size_t size, t_call call)`: Custom memory allocation function that tracks allocated memory using the G_Collector.

### 2. main.c (or any other source file)

You can include and use the functions from `g_collector.h` in your C programs to manage memory allocation and deallocation effectively.

## Usage

To use the G_Collector utility in your C projects, follow these steps:

1. Include the `g_collector.h` header file in your source files where memory management is required:

   ```c
   #include "g_collector.h"
   ```

2. Use the provided functions such as `g_malloc` for memory allocation and `clear_all` for memory cleanup as needed in your code.

3. Compile your C program with the necessary flags and dependencies, including the `g_collector.h` header file and any source files using G_Collector functions.

4. Run your compiled program to observe memory allocation and cleanup using G_Collector.

## Example

Here's a simple example of using G_Collector in a C program:

```c
#include <stdio.h>
#include "g_collector.h"

int main() {
    // Allocate memory using g_malloc
    int *ptr = g_malloc(sizeof(int), MALLOC);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    *ptr = 10;
    printf("Value stored in dynamically allocated memory: %d\n", *ptr);

    // Free allocated memory using g_malloc
    g_malloc(0, FREE);

    return 0;
}
```

## License

This project is licensed under the [MIT License](LICENSE).
