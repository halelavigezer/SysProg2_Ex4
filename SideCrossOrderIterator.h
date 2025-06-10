//
// Created by Halel on 09/06/2025.
//האיטרטור SideCrossOrder סורק את הקונטיינר בצורה עולה ויורדת
//- קודם האיבר הקטן ביותר ולאחריו האיבר הגדול ביותר וכן הלאה.
//למשל, עבור הקונטיינר [7,15,6,1,2] סדר הסריקה (משמאל לימין) יהיה 1,15,2,7,6
//avigezerhalel@gmail.com
#ifndef SIDECROSSORDERITERATOR_H
#define SIDECROSSORDERITERATOR_H
#include <algorithm>
#include <stdexcept>

#include "vector"

namespace MyNamespace {
    template<typename T>
    class MyContainer;

    template<typename T>
    class SideCrossOrderIterator {
    private:
        MyContainer<T>* container; // מצביע למיכל המקורי
        std::vector<T> sortedElements; //בסדר עולה  רשימה ממוינת
        size_t currentIndex; // המיקום הנוכחי באיטרטור
    public:
        //מכניס לתוך וקטור את המידע, ממין את הוקטור, ואז 2 משתנים עוברים על הוקטור אחד מהדגוך ואחד מהקטן וכל אחד בתורו מוסיף איבר עד שהם ניפגשים
        SideCrossOrderIterator(MyContainer<T>* cont):container(cont),currentIndex(0) {

            std::vector<T> arrySortedElements;
            for (auto it = cont->begin_order(); it != cont->end_order(); ++it) {
                arrySortedElements.push_back(*it);
            }
            // מיון עולה
            std::sort(arrySortedElements.begin(), arrySortedElements.end());
            int i=0;
            int j = arrySortedElements.size()-1;
            while (i < j) {
                sortedElements.push_back(arrySortedElements[i]);
                sortedElements.push_back(arrySortedElements[j]);
                i++;
                j--;
            }
            if (i==j) {
                sortedElements.push_back(arrySortedElements[i]);
            }
        }
        // אופרטור * גישה לאיבר הנוחכי
        T operator*() const {
            if (currentIndex>=sortedElements.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return sortedElements[currentIndex];
        }
        //אופרטור++ מעבר לעיבר הבא
        SideCrossOrderIterator& operator++() {
            if (currentIndex < sortedElements.size()) {
                ++currentIndex;
            }
            return *this;
        }
        // אופרטור ==
        bool operator==(const SideCrossOrderIterator& other) const {
            return currentIndex == other.get_currentIndex() && container == other.get_container();
        }
        //אופרטור != בודק אם סיימנו את הסריקה ??.
        bool operator!=(const SideCrossOrderIterator& other) const {
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

#endif //SIDECROSSORDERITERATOR_H
