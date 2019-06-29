#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <map>

// Complex class definition
class SomeComplexClass;

class Something
{
public:
    Something() {}

private:
    std::string complexStr;
    std::map<
        std::pair<
            std::string,
            int>,
        std::map<
            int,
            std::string
            >
        > justSomeWeirdMap;
};

class Base
{
public:
    virtual ~Base() {}
    virtual void someVirtualMethod() {}
    virtual void someVirtualMethod1() {}
    virtual void someVirtualMethod2() {}
    virtual void someVirtualMethod3() {}
    virtual void someVirtualMethod4() {}
    virtual void someVirtualMethod5() {}
    virtual void someVirtualMethod6() {}
    virtual void someVirtualMethod7() {}
    virtual void someVirtualMethod8() {}
    virtual void someVirtualMethod9() {}
    virtual void someVirtualMethod10() {}
    virtual void someVirtualMethod11() {}

    static void someStaticMethod() {}

    static constexpr int someConstexprInt = 0;
};

class SomeComplexClass
    : public Base
{
    friend class Something;

public:
    SomeComplexClass() {}
    virtual void someVirtualMethod() {}

private:
    void somePrivateMethod(int test1, char test2)
    {
        test1 = static_cast<int>(test2);
        intMember += test1;
        strMember = std::to_string(intMember);
    }
    virtual void someVirtualMethod1() {}
    virtual void someVirtualMethod2() {}
    virtual void someVirtualMethod3() {}
    virtual void someVirtualMethod4() {}
    virtual void someVirtualMethod5() {}
    virtual void someVirtualMethod6() {}
    virtual void someVirtualMethod7() {}
    virtual void someVirtualMethod8() {}
    virtual void someVirtualMethod9() {}
    virtual void someVirtualMethod10() {}
    virtual void someVirtualMethod11() {}

    std::string strMember = "";
    int intMember = 0;
    Something justSomething;
};

// !Complex class definition

template<typename Container>
std::chrono::duration<double> benchmark_container_insertion(int number_of_elements_to_insert)
{
    using namespace std::chrono;

    Container container;
    typename Container::value_type element;
    const auto beginning = steady_clock().now();

    for (int i = 0; i < number_of_elements_to_insert; ++i)
        container.push_back(element);

    const auto after_insert = steady_clock().now();
    return after_insert - beginning;
}

void printInsertionTime(const std::string& containerName, int N, std::chrono::duration<double> time)
{
    std::cout << containerName << " insertion time for " << N << " elements\n";
    std::cout << time.count() << "\n\n";
}

template<typename UnderlyingType>
void benchmark_insertion_into_containers(int n)
{
    const auto vector_insertion_duration = benchmark_container_insertion<std::vector<UnderlyingType>>(n);
    printInsertionTime("Vector", n, vector_insertion_duration);

    const auto list_insertion_duration = benchmark_container_insertion<std::list<UnderlyingType>>(n);
    printInsertionTime("List", n, list_insertion_duration);
}

void printSurroundedWith(const std::string& message, char surroundingCharacter)
{
    for (size_t i = 0; i < message.size() + 3; ++i)
        std::cout << surroundingCharacter;

    std::cout << surroundingCharacter << '\n';

    std::cout << surroundingCharacter << ' ' << message << ' ' << surroundingCharacter << '\n';

    for (size_t i = 0; i < message.size() + 3; ++i)
        std::cout << surroundingCharacter;

    std::cout << surroundingCharacter << "\n\n";
}

void benchmark_simple()
{
    printSurroundedWith("Benchmarking insertion to containers for simple types (int)", '=');
    benchmark_insertion_into_containers<int>(100);
    benchmark_insertion_into_containers<int>(10000);
    benchmark_insertion_into_containers<int>(1000000);
    benchmark_insertion_into_containers<int>(100000000);
}

void benchmark_complex()
{
    printSurroundedWith("Benchmarking insertion to containers for complex types (SomeComplexClass)", '=');
    benchmark_insertion_into_containers<SomeComplexClass>(100);
    benchmark_insertion_into_containers<SomeComplexClass>(10000);
    benchmark_insertion_into_containers<SomeComplexClass>(1000000);
    benchmark_insertion_into_containers<SomeComplexClass>(100000000);
}

int main()
{
    benchmark_simple();
    benchmark_complex();

    return 0;
}
