#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>

#include "singlyLinkedList.cpp"

TEST_CASE("Singly Linked List Initialization", "[singlyLinkedList]") {
    
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE(a.isEmpty());
}