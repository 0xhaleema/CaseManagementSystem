#include <iostream>
#include <string>
#include "EvidenceNodeClass.cpp"
using namespace std;

class EvidenceList 
{
private:
    EvidenceNode* head;

public:
    EvidenceList() 
	{
        head=NULL;
    }

    // Add new evidence
    void addEvidence(string d) 
	{
        EvidenceNode* newNode=new EvidenceNode(d);

        if(head==NULL) 
		{
            head=newNode;
            return;
        }

        EvidenceNode* temp=head;
        while(temp->getNext()!=NULL) 
		{
            temp=temp->getNext();
        }

        temp->setNext(newNode);
        newNode->setNext(NULL);
    }

    // Display all evidence
    void displayEvidence() 
	{
        if (head==NULL) 
		{
            cout<<"No evidence added.\n";
            return;
        }

        EvidenceNode* temp=head;
        cout<<"\nEvidence List:\n";
        while (temp!=NULL) 
		{
            cout<<"o "<<temp->getDescription()<< endl;
            temp=temp->getNext();
        }
    }

    // Delete by description
    void deleteEvidence(string d) 
	{
        if(head==NULL) 
		{
            cout<<"No evidence to delete.\n";
            return;
        }

        // Delete head
        if (head->getDescription()==d) 
		{
            EvidenceNode* temp=head;
            head=head->getNext();
            delete temp;
            cout<<"Evidence deleted.\n";
            return;
        }

        // Search for node to delete
    	EvidenceNode* prev=head;
    	EvidenceNode* curr=head->getNext();

    	while(curr!=NULL && curr->getDescription()!=d)
    	{
    		prev=curr;
    		curr=curr->getNext();
		}

    	if(curr==NULL)
    	{
        	cout<<"Evidence not found.\n";
        	return;
    	}

    	// Delete the node
    	prev->setNext(curr->getNext());
    	delete curr;
		cout<<"Evidence deleted.\n";
	}
};
