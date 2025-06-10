//
// Created by Halel on 09/06/2025.
//
//avigezerhalel@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.h"
#include "AscendingOrderIterator.h"

using namespace MyNamespace;

TEST_CASE("test_AscendingOrderIterator - מעבר תקין על איברים בסדר עולה") {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    AscendingOrderIterator<int> it(&container);
    AscendingOrderIterator<int> end(&container);
    end.set_currentIndex(it.get_sortedElements().size()); // איטרטור סיום

    std::vector<int> expected = {1, 2, 6, 7, 15};
    size_t index = 0;

    while (it != end) {
        CHECK(*it == expected[index]);
        ++it;
        ++index;
    }

    CHECK(index == expected.size()); // עברנו על כל האיברים
}
