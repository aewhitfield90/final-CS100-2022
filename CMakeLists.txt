CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(TESTING)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    class_test.cpp
    Actions/Action.cpp
    creature.cpp)

ADD_EXECUTABLE(game
    main.cpp)
