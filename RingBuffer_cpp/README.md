# RingBuffer C++ Template

A versatile C++ template implementation of a ring buffer, designed for flexibility and ease of use. The ring buffer is a circular data structure that efficiently manages a fixed-size buffer, useful in scenarios where a FIFO (First In, First Out) data structure is required.

## Features

- Generic template with customizable data types.
- Simple and intuitive interface.
- Efficient circular buffer management.
- Supports typical buffer operations: push, pop, size, capacity, and more.

## Usage

1. **Include the Header File**

   Include the `RingBuffer.hpp` header file in your C++ project.

   ```cpp
   #include "RingBuffer.h"
   ```

2. **Create an Instance of RingBuffer**

   Create an instance of the `RingBuffer` template, specifying the desired data type and buffer capacity.

   ```cpp
   RingBuffer<int, 10> buffer; // Example for an integer buffer with a capacity of 10
   ```

3. **Basic Operations**

   - **Push Elements:**
     ```cpp
     buffer.push(42); // Push the value 42 to the buffer
     ```

   - **Pop Element:**
     ```cpp
     int value = buffer.get(); // Get and remove the oldest element from the buffer
     ```

   - **Check Buffer Status:**
     ```cpp
     bool isEmpty = buffer.isEmpty(); // Check if the buffer is empty
     bool isFull = buffer.isFull();   // Check if the buffer is full
     ```

   - **Iterate Through Elements:**
     ```cpp
     buffer.forEach([](int element) {
         // Process each element in the buffer
         // ...
     });
     ```

   - **Additional Operations:**
     ```cpp
     size_t bufferSize = buffer.size();     // Get the current size of the buffer
     size_t bufferCapacity = buffer.capacity(); // Get the buffer capacity
     ```

4. **Advanced Usage**

   - **Save Push:**
     ```cpp
     bool success = buffer.savePush(123); // Push only if the buffer is not full
     ```

   - **Access Internal Data Array:**
     ```cpp
     std::array<int, 10>& data = buffer.data(); // Access the internal data array
     ```

   - **Reset Buffer:**
     ```cpp
     buffer.reset(); // Clear the buffer and reset indices
     ```

5. **Compile and Run**

   Ensure to compile your C++ code with the `RingBuffer.hpp` file, and execute your program.

## Example

```cpp
#include "RingBuffer.hpp"

int main() {
    RingBuffer<int, 5> buffer;

    buffer.push(10);
    buffer.push(20);
    buffer.push(30);

    int value = buffer.get(); // Retrieves and removes the oldest element (10)

    buffer.forEach([](int element) {
        // Process each remaining element in the buffer (20, 30)
        // ...
    });

    return 0;
}
```

## How Push Works

### Initial State
- ```cpp
  RingBuffer<uint32_t, 3> frequencyBuffer;
  ```
- Buffer: `[ ][ ][ ]`
- Head: 0, Tail: 0, Full: false

### First Push
- Push value 10
  ```cpp
  frequencyBuffer.push(10.0);
  ```
- Buffer: `[10][ ][ ]`
- Head: 1, Tail: 0, Full: false

### Second Push
- Push value 20
  ```cpp
  frequencyBuffer.push(20.0);
  ```
- Buffer: `[10][20][ ]`
- Head: 2, Tail: 0, Full: false

### Third Push
- Push value 30
  ```cpp
  frequencyBuffer.push(30.0);
  ```
- Buffer: `[10][20][30]`
- Head: 0, Tail: 0, Full: true
  - At this point, the buffer is full, and the head has wrapped around to the beginning. The Full flag is set to true.

### Fourth Push
- Push value 40
  - Overwrites the oldest value with 40
  ```cpp
  frequencyBuffer.push(40.0);
  ```
- Buffer: `[40][20][30]`
- Head: 1, Tail: 1, Full: true
- The buffer has now wrapped around, and the tail is catching up to the head.

### Fifth Push
- Push value 50
  - Overwrites the oldest value with 50
  ```cpp
  frequencyBuffer.push(50.0);
  ```
- Buffer: `[40][50][30]`
- Head: 2, Tail: 2, Full: true

## Contributing

Feel free to contribute to the development of this RingBuffer template. Fork the repository, make improvements, and submit a pull request.

## License

This RingBuffer C++ Template is licensed under the [MIT License](LICENSE).
