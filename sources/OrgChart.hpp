#ifndef _ORGCHART_HPP_
#define _ORGCHART_HPP_

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>


namespace ariel {
    struct Node
    {
        std::string title;
        std::vector<Node> subordinates;
    };
    class OrgChart {
    public:
        Node _root;
    public:
        OrgChart(){}
        ~OrgChart(){}
        OrgChart &add_root(std::string title);
        OrgChart &add_sub(std::string manager, std::string subor);
        std::string* begin_level_order();
        std::string* end_level_order();
        std::string* begin_reverse_order();
        std::string* end_reverse_order();
        std::string* begin_preorder();
        std::string* end_preorder();
        friend std::ostream &operator<<(std::ostream &output, OrgChart& chart);
        std::string* begin(){return begin_level_order();}
        std::string* end(){return end_level_order();}

    };
}
#endif 