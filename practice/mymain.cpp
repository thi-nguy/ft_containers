#include <iostream>
#include <memory>
#include <string>
using namespace std;
  
int main(void)
{
    allocator<string> myAllocator;
    
  
    // allocate space for three strings
    string* str = myAllocator.allocate(3);
       // construct these 3 strings
    typename allocator<string>::pointer old_start = str;
    typename allocator<string>::pointer old_end = str + 2;
    myAllocator.construct(str, "Geeks");
    myAllocator.construct(str + 1, "for");
    
    typename allocator<string>::pointer new_start = myAllocator.allocate(5);
    typename allocator<string>::pointer new_end = new_start;
    while (old_start != old_end)
    {
        myAllocator.construct(new_end, *old_start);
        old_start++;
        new_end++;
    }
    // myAllocator.deallocate(old_start - 2, 5); // ! ???
    myAllocator.deallocate(new_start, 5);
    return (0);
}
