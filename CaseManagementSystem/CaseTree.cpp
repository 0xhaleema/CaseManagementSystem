#include<iostream>
#include "CaseNode.cpp"
using namespace std;

class CaseTree
{
	private:
		CaseNode* root;
		
		//LL case
	    CaseNode* singleRightRotate(CaseNode* y)
	    {
	        CaseNode* x=y->getLeft();
	        CaseNode* t2=x->getRight();

	        x->setRight(y);
	        y->setLeft(t2);

	        int leftHeight=getHeight(y->getLeft());
	        int rightHeight = getHeight(y->getRight());
	        y->setHeight(max(leftHeight,rightHeight)+1);

	        leftHeight=getHeight(x->getLeft());
	        rightHeight=getHeight(x->getRight());
	        x->setHeight(max(leftHeight, rightHeight)+1);

	        cout<<"Right Rotated"<<endl;

	        return x;
	    }

	    //RR case
	    CaseNode* singleLeftRotate(CaseNode* x)
	    {
	        CaseNode* y=x->getRight();
	        CaseNode* t2=y->getLeft();

	        y->setLeft(x);
	        x->setRight(t2);

	        int leftHeight=getHeight(x->getLeft());
	        int rightHeight = getHeight(x->getRight());
	        x->setHeight(max(leftHeight, rightHeight)+1);

	        leftHeight=getHeight(y->getLeft());
	        rightHeight=getHeight(y->getRight());
	        y->setHeight(max(leftHeight, rightHeight)+1);

	        cout<<"Left Rotated"<<endl;

	        return y;
	    }

	    //LR case
	    CaseNode* leftRightRotate(CaseNode* k3)
	    {
	    	if(k3==NULL)
	    	return NULL;
	        k3->setLeft(singleLeftRotate(k3->getLeft()));
	        return singleRightRotate(k3);
	    }

	    //RL case
	    CaseNode* rightLeftRotate(CaseNode* k1)
	    {
	        if(k1==NULL)
	    	return NULL;
	        k1->setRight(singleRightRotate(k1->getRight()));
	        return singleLeftRotate(k1);
	    }

	public:
		CaseTree()
		{
			root=NULL;
		}
		
		CaseNode* getRoot()
		{
			return root;
		}

		
		//get height Function
	    int getHeight(CaseNode* n)
	    {
	        if(n==NULL)
	        return 0;
	        int leftHeight=getHeight(n->getLeft());
	        int rightHeight=getHeight(n->getRight());
	        return 1+max(leftHeight, rightHeight);
	    }

	    //Get balance
	    int getBalance(CaseNode* n)
	    {
	        if (n==NULL)
	        return 0;
	        return getHeight(n->getLeft())-getHeight(n->getRight());
	    }
		
		void insertCase(int id, string name, string officer)
	    {
	        root=insert(root, id, name, officer);
	    }
	    
	    //insert function
	    CaseNode* insert(CaseNode* node,int id, string name, string officer)
	    {
	        if(node==NULL)
	        {
	            CaseNode* newNode=new CaseNode(id, name, officer);
	            return newNode;
	        }

	        if(id < node->getInfo()->getId())
	        {
	            node->setLeft(insert(node->getLeft(), id, name, officer));
	        }

	        else if(id > node->getInfo()->getId())
	        {
	            node->setRight(insert(node->getRight(), id, name, officer));
	        }
	        
	        else
	        {
	            cout<<"Duplicate case ID "<<id<<", skipping insertion.\n";
	            return node;
	        }

	        node->setHeight(getHeight(node));

	        int balance=getBalance(node);

			if(balance > 1 && getBalance(node->getLeft())>=0)
	        {
	            return singleRightRotate(node);
	        }

	        if(balance < -1 && getBalance(node->getRight())<=0)
	        {
	            return singleLeftRotate(node);
	        }

	        if(balance > 1 && getBalance(node->getLeft())<0)
	        {
	            return leftRightRotate(node);
	        }

	        if(balance < -1 && getBalance(node->getRight())>0)
	        {
	            return rightLeftRotate(node);
	        }

        	return node;
        }
        
        //minimum function
	    CaseNode* min(CaseNode* node)
	    {
	    	CaseNode* temp=node;
	    	while(temp->getLeft()!=NULL)
	    		temp=temp->getLeft();
	    	return temp;
		}
		
		void removeCase(int id)
	    {
	        root=remove(root, id);
	    }
	    
	    CaseNode* remove(CaseNode* node,int id)
	    {
	        if(node==NULL)
	        {
	            return node;
	        }

	        if(id < node->getInfo()->getId())
	        {
	            node->setLeft(remove(node->getLeft(),id));
	        }
	        else if(id > node->getInfo()->getId())
	        {
	            node->setRight(remove(node->getRight(),id));
	        }
	        else
	        {

	            if(node->getLeft()==NULL && node->getRight()==NULL)
	            {
	                delete node;
	                return NULL;
	            }

	            else if(node->getRight()==NULL)
	            {
	                CaseNode* temp=node->getLeft();
	                delete node;
	                return temp;
	            }
	            else if(node->getLeft()==NULL)
	            {
	                CaseNode* temp=node->getRight();
	                delete node;
	                return temp;
	            }

	            else
	            {
	                CaseNode* temp=min(node->getRight());
	                node->swap(temp);
	                node->setRight(remove(node->getRight(),temp->getInfo()->getId()));
	            }
	        }
	        node->setHeight(getHeight(node));
	        int balance=getBalance(node);

	        if(balance > 1 && getBalance(node->getLeft())>=0)
	        {
	            return singleRightRotate(node);
	        }

	        if(balance < -1 && getBalance(node->getRight())<=0)
	        {
	            return singleLeftRotate(node);
	        }

	        if(balance > 1 && getBalance(node->getLeft())<0)
	        {
	            return leftRightRotate(node);
	        }

	        if(balance < -1 && getBalance(node->getRight())>0)
	        {
	            return rightLeftRotate(node);
	        }
	        
	        return node;
	    }
	    
	    CaseNode* searchCase(CaseNode* node, int id)
		{
	        if(node==NULL)
				return NULL;
			
	        if(node->getInfo()->getId()==id)
				return node;
			
	        if(id < node->getInfo()->getId())
				return searchCase(node->getLeft(), id);
	        return searchCase(node->getRight(), id);
	    }
	    
	    //for summary view
	    void displayAllCases(CaseNode* node)
		{
		    if(node==NULL)
			return;

		    displayAllCases(node->getLeft());

		    cout<<"Case ID: "<<node->getInfo()->getId() << " | ";
		    cout<<"Name: "<<node->getInfo()->getName() << " | ";
		    cout<<"Officer:"<<node->getInfo()->getOfficer() << endl;

		    displayAllCases(node->getRight());
		}
		
		//for detailed view
		void displayCaseDetails(int id)
		{
		    CaseNode* node = searchCase(root, id);
		    if(node==NULL)
		    {
		        cout<<"Case with ID "<<id<<" not found.\n";
		        return;
		    }

		    cout<<"\n====================== CASE DETAILS ======================\n";
		    cout<<"Case ID          : "<<node->getInfo()->getId()<<endl;
		    cout<<"Case Name        : "<<node->getInfo()->getName()<<endl;
		    cout<<"Assigned Officer : "<<node->getInfo()->getOfficer()<<endl;
		    
		    cout << "\n------------------- Evidence List ----------------------\n";
		    node->getEvidence()->displayEvidence();

		    cout << "\n-------------------- Chain of Custody ------------------\n";
		    node->getCustody()->displayEvents();
		    cout << "==========================================================\n\n";
		}	    
};

