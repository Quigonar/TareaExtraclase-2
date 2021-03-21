#include <iostream>
#include <vector>
#include "Handlers.cpp"

using namespace std;

int main()
{
    PrintHandler *printer = new PrintHandler;
    CallHandler *phone = new CallHandler;
    EmailHandler *emailer = new EmailHandler;
    printer->SetNext(phone)->SetNext(emailer);

    vector<string> responsabilities = {"Print", "Text", "Email", "Call"};

    displayChain(*printer, responsabilities);
}