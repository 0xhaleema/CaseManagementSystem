#include<iostream>
#include "CustodyNodeClass.cpp"
using namespace std;
class custodyList
{
    Node* head;
    Node* tail;
    Node* current;
    int size;
public:
    custodyList()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    //insertion 
    void insert(string d,string t,string e)
    {
    	Node* newNode=new Node();
    	newNode->setDate(d);
    	newNode->setTime(t);
    	newNode->setEvent(e);
    	if(head!=NULL)
        {
            newNode->setNext(NULL);
            newNode->setPrev(current);
            current->setNext(newNode);
            current=newNode;
            tail=newNode;
        }
        else
        {
            newNode->setNext(NULL);
            newNode->setPrev(NULL);
            head=newNode;
            tail=newNode;
            current=newNode;
        }
        size++;
	}
	void start()
    {
        current=head;
    }
    
    void addEvent(string d,string t,string e)
    {
    	current=tail;
    	insert(d,t,e);
	}
	
	//removal
	void removeOldestEvent()
    {
        if(head!=NULL)
        {
        	Node* temp=head;
        	head=head->getNext();
        	if(head!=NULL)
        		head->setPrev(NULL);
        	else
        		tail=NULL;
        			
        	delete temp;
        	size--;
        	cout<<"oldest event removed!\n";
		}
		else
		{
			cout<<"No events, so could not delete!\n";
		}
    }
    
    //Display events
    void displayEvents()
    {
    	if(head==NULL)
    	{
        	cout<<"No events to display!\n";
        	return;
    	}
    	current=head;
    	while(current!=NULL)
    	{
    		cout<<"Date:"<<current->getDate()<<" | "<<"Time:"<<current->getTime()<<" | "<<"Event:"<<current->getEvent()<<endl;
			current=current->getNext(); 
		}
	}
	
	
};
