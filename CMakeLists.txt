CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    Sub.hpp
    Add.hpp
    Mult.hpp
    Div.hpp
    Pow.hpp
    factory.hpp
    test.cpp
    MockClasses.hpp
)

ADD_EXECUTABLE(calculator
	main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
