# avigezerhalel@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

# כל קבצי ההדרים
HEADERS = MyContainer.h \
          OrderIterator.h \
          AscendingOrderIterator.h \
          DescendingOrder.h \
          SideCrossOrderIterator.h \
          ReverseOrderIterator.h \
          MiddleOutOrderIterator.h

# ברירת מחדל — נבנה Main ואת הטסטים
all: Main test

# מטרה "Main" — קובץ ההדגמה
Main: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) main.cpp -o Main
	./Main

# טסטים — בניית כל אחד מהטסטים
test_SideCrossOrderIterator: test_SideCrossOrderIterator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_SideCrossOrderIterator.cpp -o test_SideCrossOrderIterator

test_ReverseOrderIterator: test_ReverseOrderIterator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_ReverseOrderIterator.cpp -o test_ReverseOrderIterator

test_OrderIteratorTests: test_OrderIteratorTests.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_OrderIteratorTests.cpp -o test_OrderIteratorTests

test_MyContainer: test_MyContainer.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_MyContainer.cpp -o test_MyContainer

test_MiddleOutOrderIterator: test_MiddleOutOrderIterator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_MiddleOutOrderIterator.cpp -o test_MiddleOutOrderIterator

test_DescendingOrder: test_DescendingOrder.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_DescendingOrder.cpp -o test_DescendingOrder

test_AscendingOrderIterator: test_AscendingOrderIterator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) test_AscendingOrderIterator.cpp -o test_AscendingOrderIterator

# מטרה "test" — מריצה את כל הטסטים
test: test_SideCrossOrderIterator test_ReverseOrderIterator test_OrderIteratorTests test_MyContainer test_MiddleOutOrderIterator test_DescendingOrder test_AscendingOrderIterator
	./test_SideCrossOrderIterator
	./test_ReverseOrderIterator
	./test_OrderIteratorTests
	./test_MyContainer
	./test_MiddleOutOrderIterator
	./test_DescendingOrder
	./test_AscendingOrderIterator

# מטרה "valgrind" — בדיקת זליגת זיכרון על כל הטסטים
valgrind: test_SideCrossOrderIterator test_ReverseOrderIterator test_OrderIteratorTests test_MyContainer test_MiddleOutOrderIterator test_DescendingOrder test_AscendingOrderIterator
	valgrind --leak-check=full ./test_SideCrossOrderIterator
	valgrind --leak-check=full ./test_ReverseOrderIterator
	valgrind --leak-check=full ./test_OrderIteratorTests
	valgrind --leak-check=full ./test_MyContainer
	valgrind --leak-check=full ./test_MiddleOutOrderIterator
	valgrind --leak-check=full ./test_DescendingOrder
	valgrind --leak-check=full ./test_AscendingOrderIterator
	valgrind --leak-check=full ./main

# ניקוי כל הקבצים הלא רלוונטיים
clean:
	rm -f Main test_SideCrossOrderIterator test_ReverseOrderIterator test_OrderIteratorTests test_MyContainer test_MiddleOutOrderIterator test_DescendingOrder test_AscendingOrderIterator *.o
