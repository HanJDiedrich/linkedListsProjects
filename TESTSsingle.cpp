#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>

#include "singlyLinkedList.hpp"

TEST_CASE("Singly Linked List Initialization", "[MYTEST]") {
    
    QueueOfStrings a;
    REQUIRE(a.isEmpty());

}
TEST_CASE("MyFirstEnqueue", "[MYTEST]")
{
    QueueOfStrings a;
    a.enqueue("Han");
    REQUIRE( a.front() == "Han" );
}

TEST_CASE("FrontThrowsWhenNone", "[MYTEST]")
{
    QueueOfStrings q;
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

TEST_CASE("Size_Test", "[MYTEST]")
{
    QueueOfStrings a;
    a.enqueue("Java");
    a.enqueue("Python");
    a.enqueue("Javascript");
    a.enqueue("Golang");
    a.enqueue("Kotlin");
    REQUIRE( a.size() == 5 );
}

TEST_CASE("Remove_Size_Test", "[MYTEST]")
{
    QueueOfStrings a;
    a.enqueue("Java");
    a.enqueue("Python");
    a.enqueue("Javascript");
    a.enqueue("Golang");
    a.enqueue("Kotlin");
    REQUIRE( a.size() == 5 );
    a.dequeue();
    REQUIRE( a.size() == 4 );
}
TEST_CASE("DeepCopy", "[MYTEST]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    QueueOfStrings b{a};
    REQUIRE( a.front() == "Mike" );
    REQUIRE( b.front() == "Mike" );
    
    b.dequeue();
    REQUIRE( b.isEmpty() );
}

TEST_CASE("AssignToSelf", "[MYTEST]")
{
    QueueOfStrings a;
    a.enqueue("A");
    REQUIRE( a.front() == "A" );
    a = a;
    REQUIRE( a.front() == "A");
}

TEST_CASE("CopyQueueOperator=", "[MYTEST]")
{
    QueueOfStrings q;
    q.enqueue("Steve");
    q.enqueue("Tony");
    QueueOfStrings q_copy;
    q_copy.enqueue("Bruce");
    q_copy.enqueue("Natasha");
    q_copy.enqueue("Clint");

    REQUIRE( q.size() == 2 );
    REQUIRE( q_copy.size() == 3 );

    REQUIRE( q.front() == "Steve" );
    REQUIRE( q_copy.front() == "Bruce" );

    q_copy = q;

    REQUIRE( q.size() == 2 );
    REQUIRE( q_copy.size() == 2 );

    REQUIRE( q.front() == "Steve" );
    REQUIRE( q_copy.front() == "Steve" );

    q.dequeue();

    REQUIRE( q.size() == 1 );
    REQUIRE( q_copy.size() == 2 );

    REQUIRE( q.front() == "Tony" );
    REQUIRE( q_copy.front() == "Steve" );
}


