CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(SO2)

INCLUDE_DIRECTORIES("include")

ADD_EXECUTABLE(SO2
			   src/main.cpp
			   src/problem/philosopher/Launcher.cpp
			   src/problem/philosopher/Storage.cpp
			   src/problem/philosopher/Philosopher.cpp
			   src/problem/philosopher/Controller.cpp
			   )

FIND_PACKAGE(Curses REQUIRED)
FIND_PACKAGE(Threads REQUIRED)

target_link_libraries(SO2 ${CURSES_LIBRARIES})
target_link_libraries (SO2 ${CMAKE_THREAD_LIBS_INIT})
