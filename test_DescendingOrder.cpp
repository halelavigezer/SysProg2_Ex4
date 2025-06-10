//
//avigezerhalel@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.h"
#include "DescendingOrder.h"

using namespace MyNamespace;

TEST_CASE("DescendingOrder iterator test") {
    MyContainer<int> container;

    // מוסיפים איברים לקונטיינר
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    DescendingOrder<int> it(&container);

    std::vector<int> expected = {15, 7, 6, 2, 1};
    std::vector<int> result;

    // אוספים את האיברים בסדר יורד
    for (size_t i = 0; i < expected.size(); ++i) {
        result.push_back(*it);
        ++it;
    }

    CHECK(result == expected);
}
