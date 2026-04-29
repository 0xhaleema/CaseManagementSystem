#include<iostream>
using namespace std;

class CaseInfo
{
	private:
		int caseId;
	    string caseName;
	    string assignedOfficer;
	    
	public:
		CaseInfo()
    	{
        	caseId=0;
        	caseName="";
        	assignedOfficer="";
    	}
    	
		CaseInfo(int id, string name, string officer)
		{
	        caseId=id;
	        caseName=name;
	        assignedOfficer=officer;
        }
        
	    int getId() const
		{
			return caseId;
		}
		
	    string getName() const
		{
			return caseName;
		}
		
	    string getOfficer() const
		{
			return assignedOfficer;
		}
		
	    void setId(int id)
		{
			caseId=id;
		}
		
	    void setName(string name)
		{
			caseName=name;
		}
		
	    void setOfficer(string officer)
		{
			assignedOfficer=officer;
		}
};

