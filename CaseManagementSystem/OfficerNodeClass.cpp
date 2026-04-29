#include <iostream>
#include <string>
using namespace std;

class OfficerNode 
{
private:
    string name;
    OfficerNode* next;

public:
    OfficerNode(string n)
    {
        name=n;
        next=NULL;
    }
    void setName(string n)
    {
        name=n;
    }
    void setNext(OfficerNode* nxt)
    {
        next=nxt;
    }

    string getName()
    {
        return name;
    }

    OfficerNode* getNext()
    {
        return next;
    }
};

