//avigezerhalel@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <cassert>
#include "MyContainer.h"

using namespace MyNamespace;

class test_OrderIteratorTests {
private:
    MyContainer<int> container;

public:
    test_OrderIteratorTests() {
        // מוסיפים איברים
        container.add(1);
        container.add(2);
        container.add(3);
    }

    void run_tests() {
        test_iteration_order();
        test_empty_container();
        std::cout << "All tests passed successfully!" << std::endl;
    }

    void test_iteration_order() {
        std::cout << "Running test_iteration_order..." << std::endl;

        auto it_begin = container.begin_order();
        auto it_end = container.end_order();

        int expected_values[] = {1, 2, 3};
        size_t index = 0;

        for (auto it = it_begin; it != it_end; ++it) {
            assert(*it == expected_values[index]);
            ++index;
        }

        assert(index == 3); // ווידוא שסיימנו לעבור על 3 איברים
    }

    void test_empty_container() {
        std::cout << "Running test_empty_container..." << std::endl;

        MyContainer<int> empty_container;
        auto it_begin = empty_container.begin_order();
        auto it_end = empty_container.end_order();

        // אין איברים — לא ניכנס ללולאה בכלל
        for (auto it = it_begin; it != it_end; ++it) {
            assert(false); // לא אמור להיכנס לכאן
        }
    }
};
