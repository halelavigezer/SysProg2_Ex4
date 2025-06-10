//
// Created by Halel on 09/06/2025.
//האיטרטור MiddleOutOrder סורק קודם כל את האיבר האמצעי,
//ולאחר מכן פונה לאיבר השמאלי ואז הימני.
//כלומר הסדר הוא אמצע ולאחר מכן שמאל-ימין
//(כאשר פעם אחת נסרק איבר משמאל ופעם אחת נסרק איבר מימין, במידה ומספר האיברים הוא זוגי אתם יכולים לבחור בעצמכם אם האינדקס של האיבר האמצעי יעוגל כלפי מעלה או מטה).
//למשל, עבור הקונטיינר [7,15,6,1,2] סדר הסריקה (משמאל לימין) יהיה 6,15,1,7,2
//avigezerhalel@gmail.com
#ifndef MIDDLEOUTORDERITERATOR_H
#define MIDDLEOUTORDERITERATOR_H
#include <vector>
#include <algorithm>
#include <stdexcept>
namespace MyNamespace {
    template<typename T>
    class MyContainer;

    template<typename T>
class MiddleOutOrderIterator {
        private:
        MyContainer<T>* container; // מצביע למיכל המקורי
        std::vector<T> sortedElements; //בסדר עולה  רשימה ממוינת
        size_t currentIndex; // המיקום הנוכחי באיטרטור
    public:
        //בנאי מכניסה את כל האיברים לוקטור,מוצאת/מגדירה את האינדקס של האיבר האמצעי ,
        //מוסיפה את האמצעי מגדירה שני משטנים להיות אחד מצד ימין ואחד מצד שמאל ומוסיפה כך כל פעם לפי הסדר שלי עשד שעברנו על כל הוקטור
        MiddleOutOrderIterator(MyContainer<T>* cont) : container(cont), currentIndex(0) {

            std::vector<T> arryElements;
            for (auto it = cont->begin_order(); it != cont->end_order(); ++it) {
                arryElements.push_back(*it);
            }

            int sizeh = arryElements.size();
            int middleIndex = sizeh / 2;

            if (sizeh % 2 == 0) {
                middleIndex--; // במקרה של זוגי רוצים לקחת את האמצעי היותר שמאלי
            }

            // קודם כל מוסיפים את האמצעי
            sortedElements.push_back(arryElements[middleIndex]);

            int left = middleIndex - 1;
            int right = middleIndex + 1;

            // כל עוד יש מה להוסיף
            while (left >= 0 || right < sizeh) {

                // פעם שמאל
                if (left >= 0) {
                    sortedElements.push_back(arryElements[left]);
                    left--;
                }

                // פעם ימין
                if (right < sizeh) {
                    sortedElements.push_back(arryElements[right]);
                    right++;
                }
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
        MiddleOutOrderIterator& operator++() {
            if (currentIndex < sortedElements.size()) {
                ++currentIndex;
            }
            return *this;
        }
        // אופרטור ==
        bool operator==(const MiddleOutOrderIterator& other) const {
            return currentIndex == other.get_currentIndex() && container == other.get_container();
        }
        //אופרטור != בודק אם סיימנו את הסריקה ??.
        bool operator!=(const MiddleOutOrderIterator& other) const {
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

} // MyNamwspace

#endif //MIDDLEOUTORDERITERATOR_H
