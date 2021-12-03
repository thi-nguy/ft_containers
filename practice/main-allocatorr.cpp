// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
int main()
{
  
    // allocator for integer values
    std::allocator<int> myAllocator;
  
    // allocate space for five ints
    int* arr = myAllocator.allocate(5);
  
    // construct arr[0] and arr[3]
    myAllocator.construct(arr, 100);
    arr[3] = 10;
  
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;
  
    // deallocate space for five ints
    myAllocator.deallocate(arr, 5);
  
    return 0;
}

// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
#include <string>
using namespace std;
  
int main()
{
  
    // allocator for string values
    allocator<string> myAllocator;
  
    // allocate space for three strings
    string* str = myAllocator.allocate(3);
  
    // construct these 3 strings
    myAllocator.construct(str, "Geeks");
    myAllocator.construct(str + 1, "for");
    myAllocator.construct(str + 2, "Geeks");
  
    cout << str[0] << str[1] << str[2];
  
    // destroy these 3 strings
    myAllocator.destroy(str);
    myAllocator.destroy(str + 1);
    myAllocator.destroy(str + 2);
  
    // deallocate space for 3 strings
    myAllocator.deallocate(str, 3);
}