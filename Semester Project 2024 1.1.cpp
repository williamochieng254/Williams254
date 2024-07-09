#include <iostream>
// The vector will store elements of a given type in a linear arrangement.
#include <vector>
#include <string>
// The library that stores elements.
#include <unordered_map>
// The library that stores keys not following any particular order.
#include <unordered_set>
#include <algorithm>
// Will used be to generate a series of random numbers.
#include <random>
// This will be used to indicate the time data was changed.
#include <ctime>

using namespace std;

//initializing the maximum accomodation of the clubs and groups.
const int max_students_per_group = 50;
const int max_students_per_sport = 20;
const int max_students_per_club = 60;
const int max_clubs_per_student = 3;
const int max_sports_per_student = 1;
const int max_total_activities = 3;
const double max_gender_ratio_club = 0.5;
const double max_gender_ratio_sport = 0.75;

enum Gender { male, female };

struct Student {
    string first_name;
    string last_name;
    int student_number;
    string course_group;
    Gender gender;
};

// This will manage the activities and their fuctions that will be used later in the code.
class Activity {
public:
    string name;
    int max_capacity;
    unordered_set<int> student_numbers;
    unordered_map<Gender, int> gender_count;

    Activity(string n, int capacity) : name(n), max_capacity(capacity) {
        gender_count[male] = 0;
        gender_count[female] = 0;
    }
// This is the backend function for addition of students to the database.
    bool addMember(int student_number, Gender gender) {
        if (student_numbers.size() < max_capacity) {
            double gender_ratio = (double)(gender_count[gender] + 1) / (student_numbers.size() + 1);
            if ((name == "Rugby" || name == "Athletics" || name == "Swimming" || name == "Soccer") &&
                gender_ratio > max_gender_ratio_sport) {
                return false;
            } else if (gender_ratio > max_gender_ratio_club) {
                return false;
            }
            student_numbers.insert(student_number);
            gender_count[gender]++;
            return true;
        }
        return false;
    }

    bool removeStudent(int student_number, Gender gender) {
        if (student_numbers.find(student_number) != student_numbers.end()) {
            student_numbers.erase(student_number);
            gender_count[gender]--;
            return true;
        }
        return false;
    }

    bool isFull() {
        return student_numbers.size() >= max_capacity;
    }
};

// This will comprise the clubs, sports and activities
class School {
public:
    vector<Activity> clubs;
    vector<Activity> sports;

    School() {
        // This is where the activities and clubs are initiated.
        // The emplace_back inserts new elements at the end of the vector.
        clubs.emplace_back("Journalism Club", max_students_per_club);
        clubs.emplace_back("Red Cross Society", max_students_per_club);
        clubs.emplace_back("AISEC", max_students_per_club);
        clubs.emplace_back("Business Club", max_students_per_club);
        clubs.emplace_back("Computer Science Club", max_students_per_club);

        sports.emplace_back("Rugby", max_students_per_sport);
        sports.emplace_back("Athletics", max_students_per_sport);
        sports.emplace_back("Swimming", max_students_per_sport);
        sports.emplace_back("Soccer", max_students_per_sport);
    }

// This is the back end sector in assigning the cubs and societies.
    bool assignActivityToStudent(int student_number, Gender gender, const string& activity_name) {
        for (auto& club : clubs) {
            if (club.name == activity_name) {
                return club.addMember(student_number, gender);
            }
        }
        for (auto& sport : sports) {
            if (sport.name == activity_name) {
                return sport.addMember(student_number, gender);
            }
        }
        return false;
    }

// This will help the user to view school information which is the club, sports etc.
    void displaySchoolInfo() {
        cout << "School Information:\n";
        cout << "Clubs:\n";
        for (const auto& club : clubs) {
            cout << club.name << ": " << club.student_numbers.size() << " students\n";
        }
        cout << "Sports:\n";
        for (const auto& sport : sports) {
            cout << sport.name << ": " << sport.student_numbers.size() << " students\n";
        }
    }
};

// This function is for the maximum number of students that can be accomodated in the databse system.
Student students[150];
int number_of_students = 0;

// This sector facilitates in adding of student details.
void addStudent() {
    cout << "Enter the student ID: ";
    int student_number;
    cin >> student_number;

    for (int i = 0; i < number_of_students; i++) {
        if (students[i].student_number == student_number) {
            cout << "This student number already exists\n";
            return;
        }
    }

//Prompts user to enter their credentials.
    cout << "Enter your first name: ";
    cin >> students[number_of_students].first_name;
    cout << "Enter your last name: ";
    cin >> students[number_of_students].last_name;
    students[number_of_students].student_number = student_number;
    cout << "Enter course group allocated (A/B/C): ";
    cin >> students[number_of_students].course_group;
    cout << "Enter gender (0 for male, 1 for female): ";
    int gender_input;
    cin >> gender_input;
    students[number_of_students].gender = static_cast<Gender>(gender_input);
    number_of_students++;
}


// This sector helps the user to view the students and the group they have been assigned to.
void viewStudents() {
    cout << "Students List:\n";
    for (int i = 0; i < number_of_students; i++) {
        cout << students[i].student_number << ": " << students[i].first_name << " " << students[i].last_name << " (" << students[i].course_group << ")\n";
    }
}

// This here gives output of showing the user the clubs and activities they can choose from.
void viewClubs(School& school) {
    cout << "Here are some of the clubs available:\n";
    for (const auto& club : school.clubs) {
        cout << "\t" << club.name << "\n";
    }
}

// This here gives output of showing the user the sports he can choose from.
void viewSports(School& school) {
    cout << "These are the sports available:\n";
    for (const auto& sport : school.sports) {
        cout << "\t" << sport.name << "\n";
    }
}

// This helps to view students by how they are grouped.
void viewGroups() {
    cout << "Grouped students:\n";
}

// This helps to save the data entered by the users.
void save() {
    cout << "Saving all files...\n";
}

// Assists uders to enter their student number in process of registering.
void registerForActivities(School& school) {
    cout << "Enter student number: ";
    int student_number;
    cin >> student_number;

    // Find the student by their student number.
    bool student_found = false;
    Gender gender;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].student_number == student_number) {
            gender = students[i].gender;
            student_found = true;
            break;
        }
    }

    if (!student_found) {
        cout << "Student not found.\n";
        return;
    }

    int activities_assigned = 0;
    bool sport_assigned = false;

    // Assigns 0 fro chosing sports and 1 for thec clubs.
    while (activities_assigned < max_total_activities) {
        cout << "Choose activity type (0 for sport, 1 for club): ";
        int activity_type;
        cin >> activity_type;

        // Pop up when the student choses 0 for sports.
        if (activity_type == 0 && !sport_assigned) {
            cout << "Choose a sport: 0. Rugby, 1. Athletics, 2. Swimming, 3. Soccer: ";
            int sport;
            cin >> sport;
            string sport_name;
            switch (sport) {
                case 0: sport_name = "Rugby"; break;
                case 1: sport_name = "Athletics"; break;
                case 2: sport_name = "Swimming"; break;
                case 3: sport_name = "Soccer"; break;
                default: cout << "Invalid sport choice.\n"; continue;
            }
            // Stops assigning of sport if its full or unequal gender ratio.
            if (school.assignActivityToStudent(student_number, gender, sport_name)) {
                activities_assigned++;
                sport_assigned = true;
            } else {
                cout << "Unable to assign sport due to capacity or gender ratio.\n";
            }

            // The pop up when the student choses 1 for the clubs and activities.
        } else if (activity_type == 1) {
            cout << "Choose a club: 0. Journalism Club, 1. Red Cross Society, 2. AISEC, 3. Business Club, 4. Computer Science Club: ";
            int club;
            cin >> club;
            string club_name;
            switch (club) {
                case 0: club_name = "Journalism Club"; break;
                case 1: club_name = "Red Cross Society"; break;
                case 2: club_name = "AISEC"; break;
                case 3: club_name = "Business Club"; break;
                case 4: club_name = "Computer Science Club"; break;
                default: cout << "Invalid club choice.\n"; continue;
            }

            // The student will not be unable to be assinged a club if the capacity is at its max or the gender ration is to equal.
            if (school.assignActivityToStudent(student_number, gender, club_name)) {
                activities_assigned++;
            } else {
                cout << "Unable to assign club due to capacity or gender ratio.\n";
            }
            // Any other invalid input will bring the erroe message below.
        } else {
            cout << "Invalid activity type.\n";
        }
    }
}
