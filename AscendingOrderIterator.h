//avigezerhalel@gmail.com
// Created by Halel on 09/06/2025.
//האיטרטור AscendingOrder סורק את הקונטיינר בצורה עולה
//(כלומר מהאיבר הקטן ביותר לאיבר הגדול ביותר)
//למשל, עבור הקונטיינר [7,15,6,1,2] סדר הסריקה (משמאל לימין) יהיה 1,2,6,7,15

#ifndef ASCENDINGORDERITERATOR_H
#define ASCENDINGORDERITERATOR_H
//#include "MyContainer.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace MyNamespace {
    template<typename T>
    class MyContainer;

    template<typename T>
    class AscendingOrderIterator {
    private:
        MyContainer<T>* container; // מצביע למיכל המקורי
        std::vector<T> sortedElements; //בסדר עולה  רשימה ממוינת
        size_t currentIndex; // המיקום הנוכחי באיטרטור

    public:
        // בנאי - אני מכניסה לוקטור וממינת רותו לפי סדר עולה
        AscendingOrderIterator(MyContainer<T>* cont):container(cont),currentIndex(0) {
            //הכנסת הנתונים לווקטור מהקונטיינר
            for (auto it = cont->begin_order(); it != cont->end_order(); ++it) {
                sortedElements.push_back(*it);
            }
            // מיון עולה
            std::sort(sortedElements.begin(), sortedElements.end());
        }

        // אופרטור * גישה לאיבר הנוחכי
        T operator*() const {
            if (currentIndex>=sortedElements.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return sortedElements[currentIndex];
        }
        //אופרטור++ מעבר לעיבר הבא
        AscendingOrderIterator& operator++() {
            if (currentIndex < sortedElements.size()) {
                ++currentIndex;
            }
            return *this;
        }

        // אופרטור ==
        bool operator==(const AscendingOrderIterator& other) const {
            return currentIndex == other.get_currentIndex() && container == other.get_container();
        }
        //אופרטור != בודק אם סיימנו את הסריקה ??.
        bool operator!=(const AscendingOrderIterator& other) const {
            return !(*this == other);
        }


        // //מחזירה איטרטור שמצביע על האיבר הראשון בסדר הממויין
        // AscendingOrderIterator begin() {
        //     return AscendingOrderIterator(container);
        // }
        //מחזירה איטרטור שמצביע "מעבר לסוף", לסמן סיום סריקה
        // AscendingOrderIterator end() {
        //     AscendingOrderIterator it(container);
        //     it.currentIndex = it.sortedElements.size();
        //     return it;
        // }
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

#endif //ASCENDINGORDERITERATOR_H
