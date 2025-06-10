//
//avigezerhalel@gmail.com
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

namespace MyNamespace {
} // MyNamespace#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SideCrossOrderIterator.h"
#include "MyContainer.h" // נניח שאת מייבאת את זה גם

using namespace MyNamespace;

TEST_CASE("SideCrossOrderIterator basic functionality") {

    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    SideCrossOrderIterator<int> it(&container);

    // הסדר הצפוי לפי ההגדרה:
    // 1, 15, 2, 7, 6
    std::vector<int> expectedOrder = {1, 15, 2, 7, 6};

    size_t index = 0;
    for (; it != SideCrossOrderIterator<int>(&container); ++it) {
        CHECK(*it == expectedOrder[index]);
        ++index;
        if (index >= expectedOrder.size()) {
            break; // אם יש בעיה בלולאה שלא תהיה לולאה אינסופית
        }
    }
}

TEST_CASE("SideCrossOrderIterator on empty container") {

    MyContainer<int> emptyContainer;
    SideCrossOrderIterator<int> it(&emptyContainer);

    // האיטרטור צריך להיות ריק
    CHECK_THROWS_AS(*it, std::out_of_range);
}

TEST_CASE("SideCrossOrderIterator single element") {

    MyContainer<int> container;
    container.add(42);

    SideCrossOrderIterator<int> it(&container);

    // צריך להיות איבר אחד בלבד
    CHECK(*it == 42);
    ++it;
    CHECK_THROWS_AS(*it, std::out_of_range);
}

