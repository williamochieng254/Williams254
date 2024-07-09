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

