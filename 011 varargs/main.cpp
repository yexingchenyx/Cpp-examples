#include <iostream>
#include <stdlib.h>

int sum_int(int n, ...) {
    int sum = 0;

    va_list ap;
    va_start(ap, n);

    for (int i = 0; i < n; ++i) {
        int value = va_arg(ap, int);
        sum += value;
    }

    va_end(ap);

    return sum;
}

/* 递归调用的终止条件 */
void test_variadic_templete_func()
{
    std::cout << "The end!!!" << std::endl;
}
/* 不定参函数模板的使用 采用的是递归的方式 */
template<typename T,typename ... Types>
void  test_variadic_templete_func(const T &frist, const Types&... args)
{
    std::cout << frist << std::endl;
    std::cout << "variadic template function sizeof Usage:" << sizeof...(args) << std::endl;
    test_variadic_templete_func(args...);
}

template<typename T>
T max(T v) {
    return v;
}
template<typename T, typename ... Args>
T max(T v, Args ... args) {
    return std::max(v, max(args...));
}

void print(const char *str)
{
    while (*str)
    {
        if (*str == '%' && *++str != '%')
            throw std::runtime_error("invalid format string:missing argument");

        std::cout << *str++;
    }
}
template <typename T, typename... Args>
void print(const char *str,  T value,  Args ... args)
{
    while (*str)
    {
        if (*str == '%' && *++str != '%')
        {
            std::cout << value;
            print(++str, args...);
            return;
        }
        std::cout << *str++;
    }
    throw std::logic_error("extra agrument provided to print");
}

/* 打印tuple的类 */
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print(std::ostream &os, const std::tuple<Args...> &t)
    {
        /* 取出tuple的第几个元素 */
        os << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
    }
};
/* 模板特化  也是终止条件 */
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>
{
    static void print(std::ostream &os, const std::tuple<Args...> &t)
    {
    }
};
template <typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t)
{
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}

template <typename... Vaules>
class tuple;
template <>
class tuple<>
{
};
template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...>
{
    typedef tuple<Tail...> inherited;
    /* 为了让编译器认识 m_head */
//protected:
//   Head m_head;
public:
    tuple() {}
    tuple(Head v, Tail... vtail): m_head(v), inherited(vtail...) {}

//   typename  Head::type head() { return m_head; }
    //auto head()->decltype(m_head){return m_head;}
    Head head(){return m_head;}
    inherited & tail() { return *this; }

protected:
    Head m_head;
};

template <typename... Values>
class tup;
template <>
class tup<>
{
};
template <typename Head, typename... Tail>
class tup<Head, Tail...>
{
    typedef tup<Tail...> composited;

protected:
    composited m_tail;
    Head m_head;

public:
    tup() {}
    tup(Head v, Tail... vtail) : m_tail(vtail...), m_head(v) {}
    Head head() { return m_head; }
    composited &tail() { return m_tail; }
};


int main(int argc, char** argv) {
    printf("sum_int: %d\n", sum_int(3, 1, 2, 3));

    test_variadic_templete_func("hhaah", 112, 333, 222, 999, "abc");

    printf("max: %d\n", max(1, 2, 3, 12, 35, 123));

    int pi[1];
    print("%d %s %p %f\n",
    15,
    "This is Ace",
    pi,
    3.1415926);

    std::cout << std::make_tuple(7.5, std::string("hello"), std::bitset<16>(377), 42) << std::endl;

    tuple<int, float, std::string> t(41, 6.3, "nico");
    std::cout << sizeof(t) << std::endl;
    std::cout << t.head() << std::endl;
    std::cout << t.tail().head() << std::endl;
    std::cout << t.tail().tail().head() << std::endl;

    tup<int, float, std::string> it(41, 63.5, "nico");
    std::cout << sizeof(it) << std::endl;
    std::cout << it.head() << std::endl;
    std::cout << it.tail().head() << std::endl;
    std::cout << it.tail().tail().head() << std::endl;
}

