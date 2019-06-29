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
    Something(const SomeComplexClass&) {}

private:
    std::string complexStr;
    std::map<
        std::pair<
            std::string,
            std::chrono::duration<
                std::chrono::nanoseconds
                >
            >,
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

void benchmark_simple()
{
    std::vector<int> simple_vector;
    std::list<int> simple_list;
}

void benchmark_complex()
{
    std::vector<SomeComplexClass> complex_vector;
    std::list<SomeComplexClass> complex_list;
}

int main()
{
    benchmark_simple();
    benchmark_complex();

    std::cout << "Just a test";
    return 0;
}
