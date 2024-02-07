#include <iostream>

#ifdef EXAMPLE_FLAG
    #define TIMEOUT_DURATION 5  // Set a short timeout for the example
#else
    #define TIMEOUT_DURATION (1000 * 60)  // Default timeout for regular usage
#endif

int32_t timeout{TIMEOUT_DURATION};

int main(){
  std::cout << "Timeout: " << timeout << std::endl;
  return 0;
}
