#include <vector>
#include <iostream>
#include <algorithm>

int main(void)
{
    std::vector<int> myvector;
    int myint;

    std::cout << "Please enter some integers (enter 0 to end):\n";

    do {
        std::cin >> myint;
        myvector.push_back (myint);
    } while (myint);

    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << "myvector's capacity " << myvector.capacity() << "\n";

}