//
//avigezerhalel@gmail.com
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "ReverseOrderIterator.h"
#include "MyContainer.h"
#include <vector>

using namespace MyNamespace;

class ReverseOrderIteratorTests {
public:
    MyContainer<int> container;
    ReverseOrderIterator<int> it_begin;
    ReverseOrderIterator<int> it_end;

    ReverseOrderIteratorTests()
        : container(),
          it_begin(&container),
          it_end(&container)
    {
        // הוספת איברים למיכל
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        container.add(5);

        // סימון סוף איטרטור
        it_end.set_currentIndex(it_end.get_sortedElements().size());
    }
};

TEST_CASE_FIXTURE(ReverseOrderIteratorTests, "בדיקת מעבר על כל האיברים בסדר הפוך") {
    std::vector<int> expectedOrder = {5, 4, 3, 2, 1};

    size_t index = 0;
    for (auto it = it_begin; it != it_end; ++it) {
        CHECK(*it == expectedOrder[index]);
        ++index;
    }

}

TEST_CASE_FIXTURE(ReverseOrderIteratorTests, "בדיקה ש-operator* זורק חריגה מחוץ לתחום") {
    it_begin.set_currentIndex(it_begin.get_sortedElements().size()); // מגדירים אינדקס מחוץ לתחום
    CHECK_THROWS_AS(*it_begin, std::out_of_range);
}

TEST_CASE_FIXTURE(ReverseOrderIteratorTests, "בדיקת אופרטור השוואה == ו-!=") {
    ReverseOrderIterator<int> it1(&container);
    ReverseOrderIterator<int> it2(&container);

    CHECK(it1 == it2);

    ++it1;
    CHECK(it1 != it2);

    ++it2;
    CHECK(it1 == it2);
}
