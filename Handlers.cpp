#include <iostream>
#include <vector>

using namespace std;

/**
 * Se tuvo que adjuntar todas las clases de Handler por error de redefinicion
 */

class Handler {
    public:
        virtual Handler *SetNext(Handler *handler) = 0;
        virtual string Handle (string request) = 0;
};

class AbstractHandler : public Handler {
    private:
        Handler *next_handler_;

    public:
    AbstractHandler() : next_handler_(nullptr){}
    Handler *SetNext(Handler *handler) override
    {
        this->next_handler_ = handler;
        return handler;
    }
    string Handle(string request) override
    {
        if (this->next_handler_)
        {
            return this->next_handler_->Handle(request);
        }
        return {};
    }
};

class PrintHandler : public AbstractHandler{
    public:
    string Handle(string request) override
    {
        if (request == "Print")
        {
            return "Printer: I'll do the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class CallHandler : public AbstractHandler{
    public:
    string Handle(string request) override
    {
        if (request == "Call")
        {
            return "Phone: I'll do the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class EmailHandler : public AbstractHandler{
    public:
    string Handle(string request) override
    {
        if (request == "Email")
        {
            return "Emailer: I'll do the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

void displayChain(Handler &handler, vector<string> resp)
{
    for (const string &f : resp)
    {
        const string result = handler.Handle(f);
        if (!result.empty())
        {
            cout << result;
        }
        else
        {
            cout << f << " was not handled.\n";
        }
    }
}