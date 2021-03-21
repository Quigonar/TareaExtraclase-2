#include <iostream>
#include "Subsystem.cpp"

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
            std::cout << "Ordering subsystem to destroy\n" << this->subsystem1_->destroy();
            delete subsystem1_;
        }

        void initialize()
        {
            std::string result = "Facade is initializing subsystems\n";
            result += this->subsystem1_->initialize();
            result += "Facade ordered subsystems to activate\n";
            result += this->subsystem1_->action();
            std::cout << result;
        }
};

int main()
{
    Facade *facade = new Facade();
    facade->initialize();

    delete facade;

    return 0;
}