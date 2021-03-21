#include <iostream>

class Subsystem {
    public:
        std::string initialize() const
        {
            return "Subsystem initialized!\n";
        }

        std::string action() const
        {
            return "Subsystem activated!\n";
        }
        
        std::string destroy() const
        {
            return "Subsytem destroying!\n";
        }
};