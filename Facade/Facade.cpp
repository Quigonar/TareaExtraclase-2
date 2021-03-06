#include <iostream>
#include "Subsystem.cpp"

using namespace std;

class Facade {
    protected:
        Subsystem *subsystem1_;

    public:
        Facade ()
        {
            Subsystem *subsystem1 = new Subsystem;
            this->subsystem1_ = subsystem1;
        }

        ~Facade()
        {
            cout << "Ordering subsystem to destroy\n" << this->subsystem1_->destroy();
            delete subsystem1_;
        }

        void initialize()
        {
            string result = "Facade is initializing subsystems\n";
            result += this->subsystem1_->initialize();
            result += "Facade ordered subsystems to activate\n";
            result += this->subsystem1_->action();
            cout << result;
        }
};

int main()
{
    Facade *facade = new Facade();
    facade->initialize();

    delete facade;

    return 0;
}