cmake_minimum_required(VERSION 3.10)
project(linkedListsProjects)
"""
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)
"""
find_package(catch2 3 REQUIRED)

# Add your source files

# Code files
add_executable(doublyLinkedList doublyLinkedList.cpp)
add_executable(singlyLinkedList singlyLinkedList.cpp)

# Test files
add_executable(doublyLL_TESTS doublyLL_TESTS.cpp)
add_executable(singlyLL_TESTS singlyLL_TESTS.cpp)

#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Link Catch2 with test executables
target_link_libraries(doublyLL_TESTS PRIVATE Catch2::Catch2)
target_link_libraries(singlyLL_TESTS PRIVATE Catch2::Catch2)

#target_include_directories(doublyLL_TESTS PRIVATE ${Catch2_SOURCE_DIR}/single_include)
#target_include_directories(singlyLL_TESTS PRIVATE ${Catch2_SOURCE_DIR}/single_include)
