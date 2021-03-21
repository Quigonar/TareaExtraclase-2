#include <iostream>

using namespace std;

class Subsystem {
    public:
        string initialize() const
        {
            return "Subsystem initialized!\n";
        }

        string action() const
        {
            return "Subsystem activated!\n";
        }
        
        string destroy() const
        {
            return "Subsytem destroying!\n";
        }
};