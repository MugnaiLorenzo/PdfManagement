cmake_minimum_required(VERSION 3.16)
add_subdirectory(lib/googletest)
set(GTEST_SOURCE_DIR, ./lib/googletest)
include_directories(../src ${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

set(SOURCE RunAllTest.cpp ViewTest.cpp
        DeletePageTest.cpp MovePageTest.cpp UnionTest.cpp)
set(PoDoFo_DIR ../lib/podofo/build)
find_package(PoDoFo REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
add_executable(runTest ${SOURCE})
target_link_libraries(runTest gtest gtest_main core Qt5::Widgets Qt5::Core podofo poppler poppler-qt5)