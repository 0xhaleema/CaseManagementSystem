#include <iostream>
#include "CaseTree.cpp"
#include "OfficerListClass.cpp" 
using namespace std;

int main()
{
    CaseTree tree;
    OfficerList officers;
    
    officers.addOfficer("Ali");
    officers.addOfficer("Sara");
    officers.addOfficer("Bilal");

    int choice;

    do
    {
        cout<<"\n================= CASE TRACKING SYSTEM =================\n";
        cout<<"1. Add New Case\n";
        cout<<"2. Add Evidence to Case\n";
        cout<<"3. Add Custody Event to Case\n";
        cout<<"4. Display Full Case Details\n";
        cout<<"5. Display All Cases\n";
        cout<<"6. Delete Case\n";
        cout<<"7. Exit\n";
        cout<<"=======================================================\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                int id;
                string name;
                cout<<"\nEnter Case ID: ";
                cin>>id;
                cin.ignore(1000,'\n');
                cout << "Enter Case Name: ";
                getline(cin, name);

                string officer=officers.getNextOfficer(); 
                tree.insertCase(id, name, officer);
                cout<<"Case added successfully! \nAssigned Officer: "<<officer<<endl;
                break;
            }

            case 2:
            {
                int id;
                cout<<"\nEnter Case ID to add evidence: ";
                cin>>id;
                CaseNode* node=tree.searchCase(tree.getRoot(), id);
                if(node)
    			{
        			cin.ignore(1000,'\n');  
        			string desc;
        			cout<<"Enter evidence description: ";
        			getline(cin, desc);

        			node->getEvidence()->addEvidence(desc);
    			}
    			else
    			{
        			cout<<"Case not found!\n";
    			}
                break;
            }

            case 3:
            {
                int id;
                cout<<"\nEnter Case ID to add custody event: ";
                cin>>id;
                CaseNode* node=tree.searchCase(tree.getRoot(), id);
                if(node)
    			{
        			string date, time, eventName;
					cin.ignore(1000,'\n'); 

        			cout<<"Enter Event Date (DD-MM-YYYY): ";
        			getline(cin, date);

        			cout<<"Enter Event Time (HH:MM): ";
        			getline(cin, time);

        			cout<<"Enter Event Description: ";
        			getline(cin, eventName);
	
        			node->getCustody()->addEvent(date, time, eventName);
    			}
    			else
    			{
        			cout<<"Case not found!\n";
    			}

                break;
            }

            case 4:
            {
                int id;
                cout<<"\nEnter Case ID to display: ";
                cin>>id;
                tree.displayCaseDetails(id);
                break;
            }

            case 5:
            {
                cout<<"\n===== All Cases (Inorder) =====\n";
                tree.displayAllCases(tree.getRoot()); 
                break;
            }

            case 6:
            {
                int id;
                cout<<"\nEnter Case ID to delete: ";
                cin>>id;
                tree.removeCase(id);
                cout<<"Case deleted if existed!\n";
                break;
            }

            case 7:
                cout<<"\nExiting Program... \n";
                break;

            default:
                cout<<"\n Invalid choice! Try again.\n";
        }

    } while(choice!=7);

    return 0;
}


