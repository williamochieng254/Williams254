#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <ctime>
struct student {
    string first_name;
    string last_name;
    int student_number;
    string course_group[3] = {"A","B","C"};
} students[150];

int number_of_students = 0;

using namespace std;

const int max_students_per_group = 50;
const int max_students_per_sport = 20;
const int max_students_per_club = 60;
const int max_clubs_per_students = 3;
const int max_sports_per_student = 1;
const int max_total_activities = 3;
const double max_gender_ratio_club = 0.5;
const double max_gender_ratio_sport = 0.75;

enum Gender { male, female};

class activity {
public:
    string name;
    int maxcapacity;
    unordered_set <int> students;
    unordered_map <Gender, int> gendercount;

    activity(string n, int capacity) : name(n), maxcapacity(capacity){
        gendercount [male] = 0;
        gendercount [female] = 0;
    }

    bool addmember(int studentnumber, Gender gender){
        if (students.size() < maxcapacity) {
            double genderratio = (double) (gendercount[gender] + 1 );
            if ((name == "Rugby" || name == "Athletics" || name == "Swimming" || name == "Soccer") &&
                genderratio > max_gender_ratio_sport) {
                    return false;
                }
                else if (genderratio > max_gender_ratio_club){
                    return false;
                }
                students.insert(studentnumber);
                gendercount[gender]++;
                return true;
        }
        return false;
    }

    bool removestudent(int studentnumber, Gender gender){
        if (students.find(studentnumber) != students.end()) {
            students.erase(studentnumber);
            gendercount[gender]--;
            return true;
        }
        return false;
    }
    bool isFull;
        

// Prompts user to key in details.
    void add_student();
    {
        cout<<"Enter the student ID" <<endl;
        int student_number;
        cin>>student_number;

        for(int i = 0; i < number_of_students; i++)
        {
            if(students[i].student_number == student_number)
            {
                cout<<"This student number allready exists" <<endl;
                return;
            }
        }

        cout<<"Enter your first name" <<endl;
        cin>>students[number_of_students].first_name;

        cout<<"Enter your last name" <<endl;
        cin>>students[number_of_students].last.name;

        students[number_of_students].student_number = student_number;
        std::cout <<"Enter course group allocated." <<endl;
    }

    void view_student();{

    }
    void view_club();        
    void view_sports();
    void view_groups();
    
// First main menue displayed upon opening.
int main ()
    {
    std::cout<< "Welcome to the Strathmore Co-Cirricular Menu:" <<endl; 
    
    int choice;
    cout<< "1. Add student."<< endl;
    cout<< "2. View students."<< endl;
    cout<< "3. View clubs/societies." <<endl;
    cout<< "4. View sports" <<endl;
    cout<< "5. View grouped students." <<endl;
    cout<< "6. Save all files." <<endl;
    cout<< "7. Exit application." <<endl;
    cout<< "Enter your choice" <<endl;
    cin>>choice;

    switch (choice){
        case 1: 
            cout<<"Enter first name" <<endl;
            cout<<"Enter last name" <<endl;
            cout<<"Enter student number" <<endl;
        break;
        
        case 2: view_student();
        break;

        case 3: view_club();
            cout<<"Here are some of the clubs available." <<endl;
            cout<<"\t 1. Journalism Club." <<endl;
            cout<<"\t 2. The Red Cross Society." <<endl;
            cout<<"\t 3. AISEC." <<endl;
            cout<<"\t 4. Business Club" <<endl;
            cout<<"\t 5. The Computer Science Club" <<endl;

        break;

        case 4: view_sports();
            cout<<"These are the sports available." <<endl;
            cout<<"\t 1. Rugby." <<endl;
            cout<<"\t 2. Athlectics." <<endl;
            cout<<"\t 3. Swimming." <<endl;
            cout<<"\t 4. Soccer." <<endl;

        break;

        case 5: view_groups();
        break;

        case 6: save();
        break;

        case 7: break;
        
        default:
        cout<<"Invalid choice. Please try again" <<endl;  
        break;
    }
}

// Generating and assigning students to groups.
int main(){
    srand(time(0));
    School school;

    for (int i = 0; i < 150; i++){
        Gender gender = rand() % 2 == 0 ? male : female;
        Student student(i + 1, gender);
        school.addstudenttogroup((i / max_students_per_group) + 1, student);

    }

// Assigning activities to students.
for (int i = 0; i < 150; i++){
    int activitiesassigned = 0;
    Gender gender = rand() % 2 == 0 ? male : female;
    bool sportassigned = false;
    while (activitiesassigned < max_total_activities){
        int activitytype == rand() % 2;
        if(activitytype == 0 && !sportassigned){
            int sport = rand() % 4;
            string sportname;
            switch (sport){
                case 0: sportname = "Rugby";
                break;

                case 1: sportname = "Athlectics";
                break;

                case 2: sportname = "Swimming";
                break;

                case 3: sportname = "Soccer";
                break;
            if (school.assignactivitytostudent(i + 1, gender, sportname)){
                activitiesassigned++;
                sportassigned = true;
            }
            else if (activitytype == 1) {
                int club = rand() % 5;
                string clubname;
                switch(club){
                    case 0: clubname = "Journalism club";
                    break;

                    case 1: clubname = "Red cross society";
                    break;

                    case 2: clubname = "AISEC";
                    break;

                    case 3: clubname = "Business club";
                    break;

                    case 4: clubname = "Computer Science club";
                    break;
                }
                if (school.assignactivitytostudent(i + 1,gender,clubname)){
                    activitiesassigned++;
                }
                }
            }
        }
    } 
}
school.displayschoolinfo();

return 0;
}



