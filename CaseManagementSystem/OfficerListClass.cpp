#include <iostream>
#include <string>
#include "OfficerNodeClass.cpp"
using namespace std;

class OfficerList 
{
private:
    OfficerNode* tail;
    OfficerNode* current;

public:
    OfficerList()
    {
        tail=NULL;
        current=NULL;
    }

    void addOfficer(string name)
    {
        OfficerNode* newNode=new OfficerNode(name);
        if(tail==NULL)
        {
            tail=newNode;
            tail->setNext(tail);   
            current=tail;
        }
        else
        {
            newNode->setNext(tail->getNext());   
            tail->setNext(newNode);              
            tail=newNode;                     
        }
    }
    string getNextOfficer()
    {
        if (current==NULL)
            return "No Officers";

        string assigned=current->getName();
        current=current->getNext(); 
        return assigned;
    }

    void displayOfficers()
    {
        if (tail==NULL)
        {
            cout<<"No officers available.\n";
            return;
        }
        OfficerNode* temp=tail->getNext(); 

        do
        {
            cout<<temp->getName()<<" | ";
            temp=temp->getNext();
        }
        while(temp!=tail->getNext());
        cout<<endl;
    }
};

