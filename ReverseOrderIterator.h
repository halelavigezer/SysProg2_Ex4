//
//avigezerhalel@gmail.com
//

#ifndef REVERSEORDERITERATOR_H
#define REVERSEORDERITERATOR_H
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace MyNamespace {
    template<typename T>
    class MyContainer;

    template<typename T>

class ReverseOrderIterator {
     private:
        MyContainer<T>* container; // מצביע למיכל המקורי
        std::vector<T> sortedElements; //בסדר עולה  רשימה ממוינת
        size_t currentIndex; // המיקום הנוכחי באיטרטור

    public:
        //מכניסה לתוך וקטור והופכת את הסדר
        ReverseOrderIterator(MyContainer<T>* cont):container(cont),currentIndex(0) {
            std::vector<T> arryElements;

            for (auto it = cont->begin_order(); it != cont->end_order(); ++it) {
                arryElements.push_back(*it);
            }

            // להפוך את הוקטור
            std::reverse(arryElements.begin(), arryElements.end());

            // לשמור במשתנה של האיטרטור
            sortedElements = arryElements;

        }

        // אופרטור * גישה לאיבר הנוחכי
        T operator*() const {
            if (currentIndex>=sortedElements.size()) {
                throw std::out_of_range("Iterator out of range");
            }
            return sortedElements[currentIndex];
        }
        //אופרטור++ מעבר לעיבר הבא
        ReverseOrderIterator& operator++() {
            if (currentIndex < sortedElements.size()) {
                ++currentIndex;
            }
            return *this;
        }

        // אופרטור ==
        bool operator==(const ReverseOrderIterator& other) const {
            return currentIndex == other.get_currentIndex() && container == other.get_container();
        }
        //אופרטור != בודק אם סיימנו את הסריקה ??.
        bool operator!=(const ReverseOrderIterator& other) const {
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

#endif //REVERSEORDERITERATOR_H
