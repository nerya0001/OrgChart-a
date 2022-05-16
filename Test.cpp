#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>
#include "OrgChart.hpp"
using namespace ariel;

TEST_CASE("good input"){
    OrgChart org1;

    SUBCASE("add root + add subordinates"){
        CHECK_NOTHROW(org1.add_root("CEO")); // just for start a root
        CHECK_NOTHROW(org1.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org1.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org1.add_sub("COO", "VP_BI"));
    }
   
    std::string s1;
    for (auto i = org1.begin_level_order(); i != org1.end_level_order(); ++i)
    {
    s1 += (*i);
    s1 += " ";
    }
    CHECK(s1 == "CEO CTO CFO COO VP_SW VP_BI ");
    
    SUBCASE("reverse order iterator"){
        CHECK_NOTHROW(org1.add_root("CEO")); // just for start a root
        CHECK_NOTHROW(org1.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org1.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org1.add_sub("COO", "VP_BI"));
        std::string s2;
        for (auto i = org1.begin_reverse_order(); i != org1.end_reverse_order(); ++i)
        {
            s2 += (*i);
            s2 += " ";
        }
        CHECK(s2 == "VP_SW VP_BI CTO CFO COO CEO ");
    }
    SUBCASE("preorder iterator"){
        CHECK_NOTHROW(org1.add_root("CEO")); 
        CHECK_NOTHROW(org1.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org1.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org1.add_sub("COO", "VP_BI"));
        std::string s3;
        for (auto i = org1.begin_preorder(); i != org1.end_preorder(); ++i)
        {
            s3 += (*i);
            s3 += " ";
        }
        CHECK(s3 == "CEO CTO VP_SW CFO COO VP_BI ");
    }
    SUBCASE("for each iterator"){
        CHECK_NOTHROW(org1.add_root("CEO")); 
        CHECK_NOTHROW(org1.add_sub("CEO", "CTO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "CFO"));
        CHECK_NOTHROW(org1.add_sub("CEO", "COO"));
        CHECK_NOTHROW(org1.add_sub("CTO", "VP_SW"));
        CHECK_NOTHROW(org1.add_sub("COO", "VP_BI"));
        std::vector<std::string> level_order = {"CEO" ,"CTO", "CFO", "COO" ,"VP_SW" ,"VP_BI"};
        size_t i = 0;
        for (auto employ : org1)
        {
            CHECK_EQ(level_order[i], employ);
            i++;
        }
    }
}
TEST_CASE("bad input"){
    OrgChart org2;
    CHECK_NOTHROW(org2.add_root("CEO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org2.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org2.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org2.add_sub("COO", "VP_BI"));
    CHECK_THROWS(org2.add_sub("hey", "hey"));
    CHECK_THROWS(org2.add_sub("hey", "bla"));
    CHECK_THROWS(org2.add_sub("hey", "bla"));
    CHECK_THROWS(org2.add_sub("hey", "bla"));
    CHECK_THROWS(org2.add_sub("hey", "bla"));
    CHECK_THROWS(org2.add_sub("hey", "bla"));
    CHECK_THROWS(org2.add_sub("hey", "hey"));
}