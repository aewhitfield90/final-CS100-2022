CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(TESTING)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    test.cpp
    dialogue.cpp
    creature.cpp
    Actions/Action.cpp
    display.cpp)

ADD_EXECUTABLE(game
    main.cpp
    Actions/Action.cpp
    creature.cpp
    dialogue.cpp
    display.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
