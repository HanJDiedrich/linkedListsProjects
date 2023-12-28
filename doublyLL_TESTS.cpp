#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>

#include "doublyLinkedList.hpp"


TEST_CASE("SIZE_ONLY_TEST", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    //l.insert(1, "One");
    REQUIRE(l.isEmpty());
    REQUIRE(l.size() == 0);
}

TEST_CASE("PreliminaryTests", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    l.insert(1, "One");
    l.insert(2, "Two");
    l.insert(3, "Three");
    REQUIRE(l.contains(1));
    REQUIRE(l.contains(2));
    REQUIRE(l.contains(3));
    REQUIRE(! l.contains(4) );
    REQUIRE(! l.contains(0) );
    REQUIRE(l.size() == 3);
    REQUIRE(! l.isEmpty() );
}

TEST_CASE("ReverseInserts", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    l.insert(3, "Three");
    l.insert(2, "Two");
    l.insert(1, "One");
    REQUIRE(l.contains(1));
    REQUIRE(l.contains(2));
    REQUIRE(l.contains(3));
    REQUIRE(! l.contains(4) );
    REQUIRE(! l.contains(0) );
}

TEST_CASE("MyFirstRemovals1", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    l.insert(1, "One");
    l.insert(2, "Two");
    l.insert(3, "Three");
    l.remove(1);
    REQUIRE(! l.contains(1));
    REQUIRE(l.contains(2));
    REQUIRE(l.contains(3));
    REQUIRE(! l.contains(4) );
}

TEST_CASE("MyFirstRemovals2", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    l.insert(1, "One");
    l.insert(2, "Two");
    l.insert(3, "Three");
    l.remove(2);
    REQUIRE(l.contains(1));
    REQUIRE(! l.contains(2));
    REQUIRE(l.contains(3));
    REQUIRE(! l.contains(4) );
}

TEST_CASE("MyFirstRemovals3", "[MYTEST]")
{
    SortedList<unsigned, std::string> l;
    l.insert(1, "One");
    l.insert(2, "Two");
    l.insert(3, "Three");
    l.remove(3);
    REQUIRE(l.contains(1));
    REQUIRE(l.contains(2));
    REQUIRE(! l.contains(3));
    REQUIRE(! l.contains(4) );
}

TEST_CASE("ContainsWithCarmichaelNumbers", "[MYTEST]")
{
    // because Carmichael numbers are fun
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Second");
    cms.insert(1729, "Third");
    cms.insert(2465, "Fourth");
    REQUIRE(cms.getIndex(561) == 0);
    REQUIRE(cms.getIndex(1105) == 1);
    REQUIRE(cms.getIndex(1729) == 2);
    REQUIRE(cms.getIndex(2465) == 3);
    REQUIRE_THROWS_AS( cms.getIndex(600), KeyNotFoundException );
    REQUIRE_THROWS_AS( cms.getIndex(6000), KeyNotFoundException );
}

TEST_CASE("LargestLessThanTest1", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Second");
    cms.insert(1729, "Third");
    cms.insert(2465, "Fourth");
    REQUIRE_THROWS_AS( cms.largestLessThan(560), KeyNotFoundException );
    REQUIRE_THROWS_AS( cms.largestLessThan(561), KeyNotFoundException );

    REQUIRE( cms.largestLessThan(1104) == 561  );
    REQUIRE( cms.largestLessThan(1728) == 1105 );
    REQUIRE( cms.largestLessThan(1900) == 1729 );
    REQUIRE( cms.largestLessThan(2470) == 2465 );
    REQUIRE( cms.largestLessThan(4096) == 2465 );

}
TEST_CASE("LargestLessThanTest2", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Second");
    cms.insert(1729, "Third");
    cms.insert(2465, "Fourth");
    REQUIRE_THROWS_AS( cms.largestLessThan(560), KeyNotFoundException );
    REQUIRE_THROWS_AS( cms.largestLessThan(561), KeyNotFoundException );

    REQUIRE( cms.largestLessThan(1105) == 561  );
    REQUIRE( cms.largestLessThan(1106) == 1105 );
    REQUIRE( cms.largestLessThan(1900) == 1729 );
    REQUIRE( cms.largestLessThan(2470) == 2465 );
    REQUIRE( cms.largestLessThan(4096) == 2465 );

}

TEST_CASE("SmallestGreaterThanTest1", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Second");
    cms.insert(1729, "Third");
    cms.insert(2465, "Fourth");

    REQUIRE_THROWS_AS( cms.smallestGreaterThan(2470), KeyNotFoundException );
    REQUIRE_THROWS_AS( cms.smallestGreaterThan(4096), KeyNotFoundException );

    REQUIRE( cms.smallestGreaterThan(560) == 561  );
    REQUIRE( cms.smallestGreaterThan(1) == 561  );
    REQUIRE( cms.smallestGreaterThan(562) == 1105 );
    REQUIRE( cms.smallestGreaterThan(1728) == 1729 );
    REQUIRE( cms.smallestGreaterThan(2048) == 2465 );

}
TEST_CASE("SmallestGreaterThanTest2", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Second");
    cms.insert(1729, "Third");
    cms.insert(2465, "Fourth");

    REQUIRE_THROWS_AS( cms.smallestGreaterThan(2465), KeyNotFoundException );
    REQUIRE_THROWS_AS( cms.smallestGreaterThan(4096), KeyNotFoundException );

    REQUIRE( cms.smallestGreaterThan(560) == 561  );
    REQUIRE( cms.smallestGreaterThan(1) == 561  );
    REQUIRE( cms.smallestGreaterThan(561) == 1105 );
    REQUIRE( cms.smallestGreaterThan(1728) == 1729 );
    REQUIRE( cms.smallestGreaterThan(2048) == 2465 );

}
TEST_CASE("EveryonesCopyAndAssignmentOperatorCanBeGraded", "[MYTEST]")
{
    SortedList<unsigned, std::string> s1;//add stuff
    SortedList<unsigned, std::string> s2;
    s2 = s1; //call assignment operator
    REQUIRE(true);
}
TEST_CASE("Assignment=_operator", "[MYTEST]"){
    SortedList<unsigned, std::string> s1;
    s1.insert(1, "One");
    s1.insert(2, "Two");
    SortedList<unsigned, std::string> s2;
    s2 = s1; //call assignment operator
    REQUIRE(s1 == s2);

}
TEST_CASE("COPY_Constructor", "[MYTEST]")
{
    SortedList<unsigned, std::string> s1;
    s1.insert(1, "One");
    s1.insert(2, "Two");
    SortedList<unsigned, std::string> s2(s1); //copy
    REQUIRE(s1.size() == s2.size());
    REQUIRE(s2[1] == "One");
    REQUIRE(s2[2] == "Two");
    REQUIRE_THROWS_AS( s2[3], KeyNotFoundException );

}

TEST_CASE("SubscriptOperatorAsAccessor", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Secnod");
    cms.insert(1729, "Thrid");
    cms.insert(2465, "Fourth");
    REQUIRE(cms[561] == "First");
    REQUIRE(cms[1105] == "Secnod");
    REQUIRE(cms[1729] == "Thrid");
    REQUIRE(cms[2465] == "Fourth");
    REQUIRE_THROWS_AS( cms[600], KeyNotFoundException );
    REQUIRE_THROWS_AS( cms[6000], KeyNotFoundException );
}

TEST_CASE("SubscriptOperatorReturnsReference", "[MYTEST]")
{
    SortedList<unsigned, std::string> cms;
    cms.insert(561, "First");
    cms.insert(1105, "Secnod");
    cms.insert(1729, "Thrid");
    cms.insert(2465, "Fourth");
    // oops, let's fix those typos.
    cms[1105] = "Second";
    cms[1729] = "Third";
    REQUIRE(cms[561] == "First");
    REQUIRE(cms[1105] == "Second");
    REQUIRE(cms[1729] == "Third");
    REQUIRE(cms[2465] == "Fourth");
}
TEST_CASE("TESTING_CONST", "[MYTEST]")
{
    SortedList<unsigned, std::string> myList;
    myList.insert(561, "First");
    myList.insert(1105, "Second");
    
    const SortedList<unsigned, std::string>& constList = myList;
    REQUIRE(constList[561] == "First");
    REQUIRE(constList[1105] == "Second");
}


TEST_CASE("SimpleTestsOfEquality", "[MYTEST]")
{
    SortedList<unsigned, std::string> l1;
    SortedList<unsigned, std::string> l2;
    REQUIRE(l1 == l2);
    l1.insert(561, "First");
    REQUIRE(!(l1 == l2));  
    l2.insert(561, "First");
    REQUIRE(l1==l2);
}

TEST_CASE("Testing++Operator", "[MYTEST]")
{
    SortedList<std::string, unsigned> numbers;
    numbers.insert("Jenny", 8675309);
    ++numbers;
    REQUIRE(numbers["Jenny"] == 8675310);
}

