//
//avigezerhalel@gmail.com
//

#ifndef MYCONTAINER_H
#define MYCONTAINER_H

#include <vector>
#include <iostream>
#include <algorithm>  // ל-remove
#include "OrderIterator.h"
#include "AscendingOrderIterator.h"
#include "DescendingOrder.h"
#include "SideCrossOrderIterator.h"
#include "ReverseOrderIterator.h"
#include "MiddleOutOrderIterator.h"

namespace MyNamespace {
    //שם אותו דיפולטי מספר שלם
    template<typename T= int >

    class MyContainer {
    private:
        std::vector<T> data;

    public:
        //הוספת איבר חדש - add - הפעולה מקבלת איבר ומכניסה אותו לקונטיינר
        void add (const T& item){
            data.push_back(item);
        }
        //נחיקת איבר???
        //מחיקת איבר קיים - remove - הפעולה מקבלת איבר ומוחקת אותו מהקונטיינר. אם האיבר לא קיים יש לזרוק שגיאה מתאימה. במידה והאיבר קיים כמה פעמים, הפעולה תמחוק את כל המופעים שלו מהקונטיינר.
        void remove(const T& item){
            auto new_end = std::remove(data.begin(), data.end(), item);
            bool found = std::find(data.begin(), data.end(), item) != data.end();
    		if (!found) {
      			throw std::runtime_error("Item not found");
    		}
            data.erase(new_end, data.end());
        }
        //מתודה בשם size המחזירה את גודל הקונטיינר (כלומר כמות האיברים הנמצאת בתוכו).
        int size()const{
            return data.size();
        }
        // אופרטור פלט המדפיס את הקונטיינר בצורה הגיונית לבחירתכם.
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
            os << "[";
            for (size_t i = 0; i < container.data.size(); ++i) {
                os << container.data[i];
                if (i != container.data.size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }
        OrderIterator<T> begin_order() {
            return OrderIterator<T>(data.begin(), data.end());
        }
        OrderIterator<T> end_order() {
            return OrderIterator<T>(data.end(), data.end());
        }
        //מחזירה איטרטור שמצביע על האיבר הראשון בסדר הממויין
        AscendingOrderIterator<T> begin_ascebding() {
            return AscendingOrderIterator(this);
        }
        AscendingOrderIterator<T> end_ascebding() {
            AscendingOrderIterator it(this);
            it.set_currentIndex(it.get_sortedElements().size());
            return it;
        }
        DescendingOrder<T> begin_descending() {
            return DescendingOrder(this);
        }
        DescendingOrder<T> end_descending() {
            DescendingOrder it(this);
            it.set_currentIndex(it.get_sortedElements().size());
            return it;
        }
        SideCrossOrderIterator<T> begin_sideCross() {
            return SideCrossOrderIterator(this);
        }
        SideCrossOrderIterator<T> end_sideCross() {
            SideCrossOrderIterator it(this);
            it.set_currentIndex(it.get_sortedElements().size());
            return it;
        }
        ReverseOrderIterator<T> begin_revers() {
            return ReverseOrderIterator(this);
        }
        ReverseOrderIterator<T> end_revers() {
            ReverseOrderIterator it(this);
            it.set_currentIndex(it.get_sortedElements().size());
            return it;
        }
        MiddleOutOrderIterator<T> begin_middle() {
            return MiddleOutOrderIterator(this);
        }
        MiddleOutOrderIterator<T> end_middle() {
            MiddleOutOrderIterator it(this);
            it.set_currentIndex(it.get_sortedElements().size());
            return it;
        }


    };

} // MyNamespace

#endif //MYCONTAINER_H
