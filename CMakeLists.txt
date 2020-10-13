cmake_minimum_required(VERSION 2.6)

project("caesar-cipher-part-2-annabakas")

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(LINUX)
  add_compile_options(-DWITH_LINUX)
elseif(APPLE)
  add_compile_options(-DWITH_APPLE) 
else()
  add_compile_options(-DWITH_LINUX)
endif()
 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gameboard gameboard.c)
target_link_libraries(gameboard ${GTEST_LIBRARIES} -lpthread -lm)

add_executable(othello_tests othello_tests.cc gameboard.c)
target_link_libraries(othello_tests ${GTEST_LIBRARIES} -lpthread -lm)
