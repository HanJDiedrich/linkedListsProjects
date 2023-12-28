#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>

#include "singlyLinkedList.hpp"

TEST_CASE("Singly Linked List Initialization", "[singlyLinkedList]") {
    
    QueueOfStrings a;
    REQUIRE(a.isEmpty());
}