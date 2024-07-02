#include <iostream>
using namespace std;
int main ()
{;
    cout<< "Welcome to the Strathmore Co-Cirricular Menu:" <<endl; 
    
    int a;
    cout<< "1. Register Student"<< endl;
    cout<< "2. Clubs and activities"<< endl;
    cout<< "3. View the sports" <<endl;
    cout<< "4. Groups available" <<endl;
    cout<< "5. Exit" <<endl;
    cin>>a;

    switch (a){
        case 1:
        char name;
        char gender;
        cout<<"Enter your full names." <<endl;
        cin>>name;
        cout<<"Enter your gender." <<endl;
        cin>>gender;
        break;
        
        
        switch (gender){
            case 'M':
            cout<<"Male" <<endl;
            break;

            case 'F':
            cout<<"Female" <<endl;
            break;

            default:
            cout<<"Invalid choice. Try again." <<endl;
            break;
        }
        break;

        case 2:
        cout<<"Here are the clubs available" <<endl;
        cout<<"\t 1. Journalism Club." <<endl;
        cout<<"\t 2. The Red Cross Society." <<endl;
        cout<<"\t 3. AISEC." <<endl;
        cout<<"\t 4. Business Club" <<endl;
        cout<<"\t 5. The Computer Science Club" <<endl;
        break;

        case 3:
        int b;
        cout<<"These are the sport acitivites available" <<endl;
        cout<<"\t 1. Rugby." <<endl;
        cout<<"\t 2. Athlectics." <<endl;
        cout<<"\t 3. Swimming." <<endl;
        cout<<"\t 4. Soccer." <<endl;
        cin>>b;
        break;

        case 4:
        cout<<"These are the groups available" <<endl;
        break;

        case 5:
        cout<<"You have saved and exited the menu" <<endl;
        break;

        default:

        cout<<"Invalid choice. Please try again" <<endl;  
        break;
    }
    
    return 0;

}
    
