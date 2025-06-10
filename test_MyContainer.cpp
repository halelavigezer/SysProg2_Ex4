//avigezerhalel@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>

#include "doctest.h"
#include "MyContainer.h"

using namespace MyNamespace;

TEST_CASE("בדיקות בסיסיות של MyContainer") {
    MyContainer<int> c;

    SUBCASE("בדיקה של הוספה וגודל") {
        CHECK(c.size() == 0);
        c.add(5);
        c.add(10);
        c.add(15);
        CHECK(c.size() == 3);
    }


    SUBCASE("בדיקה של הסרה לא קיימת") {
        // הסרה של איבר לא קיים אמורה לזרוק שגיאה
        CHECK_THROWS_AS(c.remove(999), std::runtime_error);
    }

    SUBCASE("בדיקה של אופרטור פלט") {
        c.add(1);
        c.add(2);
        std::ostringstream oss;
        oss << c;
        auto output = oss.str();
        CHECK(output.front() == '[');
        CHECK(output.back() == ']');
    }

    SUBCASE("בדיקה של איטרטור בסדר") {
        MyContainer<int> cc;
        cc.add(1);
        cc.add(2);
        cc.add(3);
        int expected[] = {1, 2, 3};
        int idx = 0;
        for (auto it = cc.begin_order(); it != cc.end_order(); ++it) {
            CHECK(*it == expected[idx++]);
        }
        CHECK(idx == 3);
    }

    SUBCASE("בדיקה של קונטיינר ריק") {
        MyContainer<int> empty_c;
        CHECK(empty_c.size() == 0);
        int count = 0;
        for (auto it = empty_c.begin_order(); it != empty_c.end_order(); ++it) {
            count++;
        }
        CHECK(count == 0);
    }
}
