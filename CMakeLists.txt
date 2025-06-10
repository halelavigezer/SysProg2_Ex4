cmake_minimum_required(VERSION 3.31)
project(untitled4)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled4 main.cpp
        MyContainer.h
        OrderIterator.h
        AscendingOrderIterator.h
        DescendingOrder.h
        SideCrossOrderIterator.h
        ReverseOrderIterator.h
        MiddleOutOrderIterator.h
        test_SideCrossOrderIterator.cpp
        test_ReverseOrderIterator.cpp
        test_OrderIteratorTests.cpp
        test_MyContainer.cpp
        test_MiddleOutOrderIterator.cpp
        test_DescendingOrder.cpp
        test_AscendingOrderIterator.cpp
)
