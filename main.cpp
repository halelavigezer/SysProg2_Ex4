//avigezerhalel@gmail.com
#include <iostream>
#include "MyContainer.h"
#include "AscendingOrderIterator.h"

using namespace MyNamespace;
    int main() {
        MyContainer<int> c;
        c.add(7);
        c.add(15);
        c.add(6);
        c.add(1);
        c.add(2);
//הדפסה של מה שיש לי בתוך המייכל
        std::cout << "Container: " << c << std::endl;
        //הדפסה של מעבר רגיל
        std::cout << "Print using Order:" << std::endl;
        for (auto it = c.begin_order(); it != c.end_order(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "" << std::endl;
        //הדפסה של מעבר מהקטן לגדול
        std::cout << "Print using AscendingOrder:" << std::endl;
        for (auto it = c.begin_ascebding(); it != c.end_ascebding(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "" << std::endl;
        //הדפסה מהגדול  לקטן
        std::cout << "Print using DescendingOrder :" << std::endl;
        for (auto it = c.begin_descending(); it != c.end_descending(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "" << std::endl;
        //סורק בצורה עולה ויורדת
        std::cout << "Print using SideCrossOrderIterator:" << std::endl;
        for (auto it = c.begin_sideCross(); it != c.end_sideCross(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "" << std::endl;
        //סורק בצורה הפוכה
        std::cout << "Print using ReverseOrder:" << std::endl;
        for (auto it = c.begin_revers(); it != c.end_revers(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "" << std::endl;
        //סורק קודם כל את האיבר האמצעי, ולאחר מכן פונה לאיבר השמאלי ואז הימני.
        std::cout << "Print using MiddleOutOrder :" << std::endl;
        for (auto it = c.begin_middle(); it != c.end_middle(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;


        return 0;
    }
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
