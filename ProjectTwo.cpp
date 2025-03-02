#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Structure to store course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Function to load courses from file into a map
typedef map<string, Course> CourseMap;
void loadCourses(const string& filename, CourseMap& courses) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseTitle, prereq;
        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');
        Course course{courseNumber, courseTitle, {}};

        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }

        courses[courseNumber] = course;
    }
    file.close();
    cout << "Courses successfully loaded.\n";
}

// Function to sort courses manually using bubble sort
void bubbleSort(vector<Course>& courses) {
    int n = courses.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (courses[j].courseNumber > courses[j + 1].courseNumber) {
                swap(courses[j], courses[j + 1]);
            }
        }
    }
}

// Function to print the sorted course list
void printCourseList(const CourseMap& courses) {
    vector<Course> sortedCourses;
    for (const auto& pair : courses) {
        sortedCourses.push_back(pair.second);
    }

    bubbleSort(sortedCourses);

    cout << "\nHere is a sample schedule:\n";
    for (const auto& course : sortedCourses) {
        cout << course.courseNumber << ", " << course.courseTitle << endl;
    }
}

// Function to search for a course manually
Course* searchCourse(CourseMap& courses, const string& courseNum) {
    for (auto& pair : courses) {
        if (pair.first == courseNum) {
            return &pair.second;
        }
    }
    return nullptr;
}

// Function to print course information
void printCourseInfo(CourseMap& courses) {
    cout << "\nWhat course do you want to know about? ";
    string courseNum;
    cin >> courseNum;

    // Convert input to uppercase to match stored keys
    for (char &c : courseNum) c = toupper(c);

    Course* course = searchCourse(courses, courseNum);
    if (course) {
        cout << course->courseNumber << ", " << course->courseTitle << endl;
        if (!course->prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < course->prerequisites.size(); ++i) {
                cout << course->prerequisites[i];
                if (i < course->prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        } else {
            cout << "No prerequisites." << endl;
        }
    } else {
        cout << "Course not found." << endl;
    }
}

int main() {
    CourseMap courses;
    int choice;
    string filename;

    cout << "Welcome to the course planner.\n";

    do {
        cout << "\n1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n";
        cout << "\nWhat would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name of the data file: ";
                cin >> filename;
                loadCourses(filename, courses);
                break;
            case 2:
                if (courses.empty()) {
                    cout << "Please load the course data first." << endl;
                } else {
                    printCourseList(courses);
                }
                break;
            case 3:
                if (courses.empty()) {
                    cout << "Please load the course data first." << endl;
                } else {
                    printCourseInfo(courses);
                }
                break;
            case 9:
                cout << "Thank you for using the course planner!\n";
                break;
            default:
                cout << choice << " is not a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}
