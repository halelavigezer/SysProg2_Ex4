//
//avigezerhalel@gmail.com
//

#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H
#include "MyContainer.h"

namespace MyNamespace {
    template<typename T>
    //האיטרטור Order סורק את הקונטיינר בצורה רגילה.
    class OrderIterator {
    private:
        //מצביעים לנוחכי ולסוף
        typename std::vector<T>::iterator current;
        typename std::vector<T>::iterator end_it;
    public:

       OrderIterator(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
        : current(begin), end_it(end) {}

        T& operator*() {//גישה לאיבר הנוחכי
            return *current;
        }
        //אופרטור מעביר לאיבר הבא
        OrderIterator& operator++() {
            ++current;
            return *this;
        }
        //בדיקה אם סיימנו את הסריקה
        bool operator!=(const OrderIterator& other) const {
            return this->current != other.current;
        }
        typename std::vector<T>::iterator getCurrent() const {
           return current;
       }
        typename std::vector<T>::iterator getEnd() const {
           return end_it;
       }


    };

} // MyNamespace

#endif //ORDERITERATOR_H
