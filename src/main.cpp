#include <iostream>
#include <vector>
#include <list>
#include <chrono>
// #include <complex_class>

void benchmark_simple()
{
    std::vector<int> simple_vector;
    std::list<int> simple_list;
}

void benchmark_complex()
{
    std::vector<int> complex_vector;
    std::list<int> complex_list;
}

int main()
{
    benchmark_simple();
    benchmark_complex();

    std::cout << "Just a test";
    return 0;
}
