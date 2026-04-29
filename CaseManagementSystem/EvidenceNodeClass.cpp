#include <iostream>
#include <string>
using namespace std;

// EvidenceNode 
class EvidenceNode 
{
private:
    string description;
    EvidenceNode* next;

public:
    EvidenceNode(string d) 
	{
        description=d;
        next=NULL;
    }

    // Setters 
    void setDescription(string d) 
	{
        description=d;
    }

    void setNext(EvidenceNode* n) 
	{
        next=n;
    }

    // Getters 
    string getDescription() 
	{
        return description;
    }

    EvidenceNode* getNext() 
	{
        return next;
    }
};

