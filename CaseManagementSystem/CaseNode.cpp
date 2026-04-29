#include<iostream>
#include "CaseInfo.cpp"
#include "EvidenceListClass.cpp"
#include "CustodyListClass.cpp"

using namespace std;

class CaseNode{
	private:
		CaseInfo* info;          
	    EvidenceList* evidence;  
	    custodyList* custody;    

	    CaseNode* left;
	    CaseNode* right;
	    int height;
	    
	public:
		CaseNode(int id, string name, string officer)
		{
	        info=new CaseInfo(id, name, officer);
	        evidence=new EvidenceList();
	        custody=new custodyList();
	        left=NULL;
			right=NULL;
	        height=0;
        }
        
	    CaseInfo* getInfo()
		{
			return info;
		}
		
	    EvidenceList* getEvidence()
		{
			return evidence;
		}
		
	    custodyList* getCustody()
		{
			return custody;
		}

	    CaseNode* getLeft()
		{
			return left;
		}
		
	    CaseNode* getRight()
		{
			return right;
		}
		
		int getHeight()
		{
			return height;
		}
		
		void setLeft(CaseNode* node)
		{
			left=node;
		}
		
    	void setRight(CaseNode* node)
		{
			right=node;
		}
		
		void setHeight(int h)
		{
			height=h;
		}
		
		void swap(CaseNode* other)
		{
	        std::swap(info, other->info);
	        std::swap(evidence, other->evidence);
	        std::swap(custody, other->custody);
	    }
};

