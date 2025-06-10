//
//avigezerhalel@gmail.com


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include "doctest.h"
#include "MyContainer.h"

using namespace MyNamespace;

TEST_CASE("MiddleOutOrderIterator בדיקות בסיסיות") {
    MyContainer<int> c;

    SUBCASE("בדיקה של סדר הסריקה") {
        c.add(7);
        c.add(15);
        c.add(6);
        c.add(1);
        c.add(2);

        MiddleOutOrderIterator<int> it(&c);
        MiddleOutOrderIterator<int> endIt = it;
        endIt.set_currentIndex(it.get_sortedElements().size());

        int expected[] = {6, 15, 1, 7, 2};
        int idx = 0;
        for (; it != endIt; ++it) {
            CHECK(*it == expected[idx++]);
        }
        CHECK(idx == 5);
    }

    SUBCASE("בדיקה של השוואת איטרטורים") {
        c.add(1);
        MiddleOutOrderIterator<int> it1(&c);
        MiddleOutOrderIterator<int> it2(&c);
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("בדיקה של חריגה בגישה לא חוקית") {
        c.add(1);
        MiddleOutOrderIterator<int> it(&c);
        it.set_currentIndex(it.get_sortedElements().size());
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
}
