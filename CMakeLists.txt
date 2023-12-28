cmake_minimum_required(VERSION 3.10)
project(linkedListsProjects)


Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)


# Code files
add_executable(doublyLinkedList doublyLinkedList.cpp)
add_executable(singlyLinkedList singlyLinkedList.cpp)

# Test files
add_executable(TESTSdouble TESTSdouble.cpp)
add_executable(TESTSsingle TESTSsingle.cpp)

# Link Catch2 with test executables
target_link_libraries(TESTSdouble PRIVATE Catch2::Catch2WithMain)
target_link_libraries(TESTSsingle PRIVATE Catch2::Catch2WithMain)

