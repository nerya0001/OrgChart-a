#include "OrgChart.hpp"
#include <vector>

namespace ariel
{
    OrgChart &OrgChart::add_root(std::string name){return *this;}
    OrgChart &OrgChart::add_sub(std::string father, std::string son){return *this;}
    std::string *OrgChart::begin_level_order(){return &this->_root.title;}
    std::string *OrgChart::end_level_order(){return &this->_root.title;}
    std::string *OrgChart::begin_reverse_order(){return &this->_root.title;}
    std::string *OrgChart::end_reverse_order(){return &this->_root.title;}
    std::string *OrgChart::begin_preorder(){return &this->_root.title;}
    std::string *OrgChart::end_preorder(){return &this->_root.title;}
    std::ostream &operator<<(std::ostream &out, OrgChart &root){return out;}
}