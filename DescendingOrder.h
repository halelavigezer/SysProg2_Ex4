//avigezerhalel@gmail.com
// Created by Halel on 09/06/2025.
//האיטרור DescendingOrder סורק את הקונטיינר בצורה יורדת
//(כלומר מהאיבר הגדול ביותר לאיבר הקטן ביותר)
//למשל, עבור הקונטיינר [7,15,6,1,2] סדר הסריקה (משמאל לימין) יהיה 15,7,6,2,1

#ifndef DESCENDINGORDER_H
#define DESCENDINGORDER_H
#include "MyContainer.h"


namespace MyNamespace {
    template<typename T>
    class MyContainer;

    template<typename T>
    class DescendingOrder {
    private:
        //בנאי - מכניסה את הנתונים לוקטור וממינת את הוקטור בסדר יורד
         MyContainer<T>* container; // מצביע למיכל המקורי
        std::vector<T> sortedElements; //בסדר עולה  רשימה ממוינת
        size_t currentIndex; // המיקום הנוכחי באיטרטור
    public:
        DescendingOrder(MyContainer<T>* cont):container(cont),currentIndex(0) {
            //הכנסת הנתונים לווקטור מהקונטיינר
            for (auto it = cont->begin_order(); it != cont->end_order(); ++it) {
                sortedElements.push_back(*it);
            }
            // מיון יורד (מהגדול לקטן)
            std::sort(sortedElements.begin(), sortedElements.end(), std::greater<T>());

        }
        // אופרטור * גישה לאיבר הנוחכי
        T operator*() const {
            if (currentIndex>=sortedElements.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return sortedElements[currentIndex];
        }
        //אופרטור++ מעבר לעיבר הבא
        DescendingOrder& operator++() {
            if (currentIndex < sortedElements.size()) {
                ++currentIndex;
            }
            return *this;
        }
        // אופרטור ==
        bool operator==(const DescendingOrder& other) const {
            return currentIndex == other.get_currentIndex() && container == other.get_container();
        }
        //אופרטור != בודק אם סיימנו את הסריקה ??.
        bool operator!=(const DescendingOrder& other) const {
            return !(*this == other);
        }
        MyContainer<T>* get_container()const {
            return container;
        }
        std::vector<T> get_sortedElements()const {
            return sortedElements;
        }
        size_t get_currentIndex()const {
            return currentIndex;
        }
        void set_container(MyContainer<T>* cont) {
            container = cont;
        }

        void set_sortedElements(const std::vector<T>& vec) {
            sortedElements = vec;
        }

        void set_currentIndex(size_t index) {
            currentIndex = index;
        }
};

} // MyNamespace

#endif //DESCENDINGORDER_H
