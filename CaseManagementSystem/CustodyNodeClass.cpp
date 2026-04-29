#include<iostream>
using namespace std;
class Node
{
	private:
		Node* next;
		Node* prev;
		string date;
		string time;
		string event;
		
	public:
	//constructor
	Node()
    {
        date="";
        time="";
        event="";
        next=NULL;
        prev=NULL;
    }
    
	//setter and getter for time
	string getTime()
    {
        return time;
    }
    void setTime(string t)
    {
        time=t;
    }
    
    //setter and getter for event
    string getEvent()
    {
        return event;
    }
    void setEvent(string msg)
    {
        event=msg;
    }
    
    //setter and getter for next
    void setNext(Node* n)
    {
        next=n;
    }
    Node* getNext()
    {
        return next;
    }
    
    //setter and getter for previous
    void setPrev(Node* p)
    {
        prev=p;
    }
    Node* getPrev()
    {
        return prev;
    }
    
    //setter and getter for date
    string getDate()
    {
        return date;
    }
    void setDate(string t)
    {
        date=t;
    }
};
