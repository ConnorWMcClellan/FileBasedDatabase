#include <iostream>
#include <sstream>
#include <string> 
#include <filesystem>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    //first command
    string input;

    //create directory for database if one is not present
    filesystem::create_directory("Database");

    //run until q is inputted
    while (input != "q")
    {
        //read in the second command in the line
        cout << ">>> ";
        cin >> input;
        //if input is a, add data to database
        if (input == "a")
        {
            //if input is c, add course
            cin >> input;
            if (input == "c")
            {
                //get the rest of the input line
                string course;
                getline(cin, course, '\n');

                //if a course text file is not created, create one
                if (!filesystem::exists("Database/courses.txt"))
                {
                    ofstream courseFile("Database/courses.txt");
                    courseFile << course << endl;
                }
                //if a course text file exists open and read from it
                else
                {
                    ifstream courseFile;
                    courseFile.open("Database/courses.txt");

                    string currentLine;
                    bool found = false;
                    //check if course has already been added
                    while(!courseFile.eof() && !found)
                    {
                        getline(courseFile, currentLine);
                        //if course has been found in database print error message
                        if (currentLine == course)
                        {
                            cout << "Course Already in Database." << endl;
                            found = true;
                        }
                    }
                    courseFile.close();
                    //if course does not exist in database then add course to courses.txt
                    if(!found)
                    {
                        ofstream courseFileWrite;
                        courseFileWrite.open("Database/courses.txt", ios_base::app);
                        courseFileWrite << course << endl;
                        courseFileWrite.close();
                    }
                }
            }
            //if g is inputted add grade to grading scale
            else if (input == "g")
            {
                //read in inputted grade
                string grade;
                getline(cin, grade, '\n');
                
                //if grade file does not exist, create one and add grade
                if (!filesystem::exists("Database/grades.txt"))
                {
                    ofstream gradeFile("Database/grades.txt");
                    gradeFile << grade << endl;
                }
                //if grade file exists add grade to grading scale 
                else
                {
                    ifstream gradeFile;
                    gradeFile.open("Database/grades.txt");

                    string currentLine;
                    bool found = false;
                    //read file and if grade is found print error message
                    while(!gradeFile.eof() && !found)
                    {
                        getline(gradeFile, currentLine);
                        if (currentLine == grade)
                        {
                            cout << "Grade Already in Database." << endl;
                            found = true;
                        }
                    }
                    gradeFile.close();
                    // if grade is not found add to database
                    if(!found)
                    {
                        ofstream gradeFileWrite;
                        gradeFileWrite.open("Database/grades.txt", ios_base::app);
                        gradeFileWrite << grade << endl;
                        gradeFileWrite.close();
                    }
                }

            }
            //if m is inputted add semester   
            else if (input == "m")
            {
                string semester;
                getline(cin, semester, '\n');

                //if semester file does not exist, create one and add semester
                if (!filesystem::exists("Database/semester.txt"))
                {
                    ofstream semesterFile("Database/semester.txt");
                    semesterFile << semester << endl;
                }
                //if semester file exists add grade to semester file
                else
                {
                    ifstream semesterFile;
                    semesterFile.open("Database/semester.txt");

                    string currentLine;
                    bool found = false;

                    //read file and if semester is found print error message
                    while(!semesterFile.eof() && !found)
                    {
                        getline(semesterFile, currentLine);
                        if (currentLine == semester)
                        {
                            cout << "Semester Already in Database." << endl;
                            found = true;
                        }
                    }
                    semesterFile.close();
                    // if semester is not found add to database
                    if(!found)
                    {
                        ofstream semesterFileWrite;
                        semesterFileWrite.open("Database/semester.txt", ios_base::app);
                        semesterFileWrite << semester << endl;
                        semesterFileWrite.close();
                    }
                }
            }

            //if s is inputted add student   
            else if (input== "s")
            {
                string student;
                getline(cin, student, '\n');
                
                //if student file does not exist, create one and add student        
                if (!filesystem::exists("Database/students.txt"))
                {
                    ofstream studentFile("Database/students.txt");
                    studentFile << student << endl;
                }
                //if semester file exists add grade to semester file
                else
                {
                    ifstream studentFile;
                    studentFile.open("Database/students.txt");

                    string currentLine;
                    bool found = false;
                    //read file and if student is found print error message
                    while(!studentFile.eof() && !found)
                    {
                        getline(studentFile, currentLine);
                        if (currentLine == student)
                        {
                            cout << "Student Already in Database." << endl;
                            found = true;
                        }
                    }
                    studentFile.close();
                    // if student is not found add to database
                    if(!found)
                    {
                        ofstream studentFileWrite;
                        studentFileWrite.open("Database/students.txt", ios_base::app);
                        studentFileWrite << student << endl;
                        studentFileWrite.close();
                    }
                }
            }
            //if t is inputted add course taken
            else if (input == "t")
            {
                string taken;
                getline(cin, taken, '\n');

                //if course taken file does not exist, create one and add course taken
                if (!filesystem::exists("Database/taken.txt"))
                {
                    ofstream takenFile("Database/taken.txt");
                    takenFile << taken << endl;
                }
                //if course taken file exists add taken to file
                else
                {
                    ifstream takenFile;
                    takenFile.open("Database/taken.txt");

                    string currentLine;
                    bool found = false;

                    //read file and if course taken is found print error message
                    while(!takenFile.eof() && !found)
                    {
                        getline(takenFile, currentLine);
                        if (currentLine == taken)
                        {
                            cout << "Class Taken Already in Database." << endl;
                            found = true;
                        }
                        takenFile.close();
                    }
                    // if course taken is not found add to database
                    if(!found)
                    {
                        //open grade file to check if grade for course taken is valid
                        ifstream gradeFile;
                        gradeFile.open("Database/grades.txt");

                        //read in the taken course
                        string last,first,department,courseNum,grade,semester;
                        stringstream stream(taken);
                        stream >> last >> first >> department >> courseNum 
                        >> grade >> semester;
                        
                        //check if grade is in grading scale
                        bool gradeFound = false;
                        while(!gradeFile.eof() && !gradeFound)
                        {
                            string streamGrade;
                            string gpa;
                            getline(gradeFile, currentLine);
                            stringstream gradeStream(currentLine);
                            gradeStream >> streamGrade >> gpa;
                            //if grade is valid check if the course is valid
                            if (streamGrade == grade)
                            {
                                ifstream courseFile;
                                courseFile.open("Database/courses.txt");
                                gradeFound = true;
                                bool courseFound = false;
                                //search course file for course
                                while(!courseFile.eof() && !courseFound)
                                {
                                    string depart;
                                    string courseNumber;
                                    string name, creditHour;
                                    getline(courseFile, currentLine);
                                    stringstream courseStream(currentLine);
                                    courseStream >> depart >> courseNumber >> name >> creditHour;
                                    //if the courses match up check if student is in database
                                    if (depart+courseNumber == department+courseNum)
                                    {
                                        ifstream studentFile;
                                        studentFile.open("Database/students.txt");
                                        courseFound = true;
                                        bool studentFound = false;
                                        //search student file for student
                                        while(!studentFile.eof() && !studentFound)
                                        {
                                            string studentLast;
                                            string studentFirst;
                                            string phoneNum;
                                            getline(studentFile, currentLine);
                                            stringstream studentStream(currentLine);
                                            studentStream >> studentLast >> studentFirst >> phoneNum;
                                            //if student is in database add course taken to the file 
                                            if (last+first == studentLast+studentFirst)
                                            {
                                                ofstream takenFileWrite;
                                                takenFileWrite.open("Database/taken.txt", ios_base::app);
                                                takenFileWrite << taken << endl;
                                                takenFileWrite.close();
                                                studentFound = true;
                                            }
                                        }
                                    studentFile.close();
                                    //if the student is not in database print error message
                                    if (studentFound == false)
                                    {
                                        cout << "Error: Student is not added." << endl;
                                    }
                                    }
                                }
                                courseFile.close();
                                //if the course is not in database print error message
                                if (courseFound == false)
                                {
                                    cout << "Error: Course is not added." << endl;
                                }
                            }
                        }
                        //if the grade is not in database print error message
                        if (gradeFound == false)
                        {
                            cout << "Error: Grade is not in grading scale." << endl;
                        }
                        gradeFile.close();
                    }
                }
            } 
        }
        //if input is l, print data from database
        else if (input == "l")
        {
            //read in second command
            cin >> input;
            //if c is inputted print all courses
            if(input == "c")
            {
                fstream file("Database/courses.txt");
                string course;
                while(getline(file, course))
                {
                    cout << course << endl;
                }
            }
            //if g is inputted print all grades
            else if(input == "g")
            {
                fstream file("Database/grades.txt");
                string grades;
                while(getline(file, grades))
                {
                    cout << grades << endl;
                }
            }
            //if m is inputted print all semesters
            else if(input == "m")
            {
                fstream file("Database/semester.txt");
                string semester;
                while(getline(file, semester))
                {
                    cout << semester << endl;
                }
            }
            //if s is inputted print all students
            else if(input == "s")
            {
                fstream file("Database/students.txt");
                string student;
                while(getline(file, student))
                {
                    cout << student << endl;
                }
            }
            //if t is inputted print all courses taken
            else if(input == "t")
            {
                fstream file("Database/taken.txt");
                string course;
                while(getline(file, course))
                {
                    cout << course << endl;
                }
            }
        }
        //print transcript for student
        else if (input == "t")
        {
            string lastName;
            string firstName;
            string depart, courseNum, grade, semCode;
            string semester, code, year, season;
            //read in last and first name
            cin >> lastName;
            cin >> firstName;
            cout << "============" << firstName << " " << lastName << " Transcript" << "============" << endl;

            //keep track of each course taken by the student
            vector<string> courseArray;
            //give a semester code a value of season and year for easy look up
            map <string, pair<string,int>> semesters;
            fstream file("Database/taken.txt");
            string course;
            //read through the taken file looking for courses taken by student
            while(getline(file, course))
            {
                string last;
                string first;
                string taken;
                //break apart the course found for use in searching other files
                stringstream stream(course);
                stream >> last >> first >> depart >> courseNum >> grade >> semCode;
                getline(stream, taken);
                //if the student name entered matches the student name in file continue
                if((last+first) == (lastName+firstName))
                {
                    taken = depart + " " + courseNum + " " + grade + " " + semCode;
                    fstream file("Database/semester.txt");
                    string semester, code, year, season;
                    //read through the semester file to get a map correlating a semester
                    //code with a season and year
                    while(getline(file, semester))
                    {
                        stringstream stream(semester);
                        stream >> code >> year >> season;
                        //if the code from the course taken matches a semester code in the file
                        //insert into map
                        if(code == semCode)
                        {
                            int yearNum = stoi(year);
                            pair<string,int> pear = make_pair(season,yearNum);
                            semesters.insert(make_pair(code, pear));
                        }
                    }
                    //add course to array to keep track
                    courseArray.push_back(taken);
                }
            }
            //keep track of each grade from each course taken by student for gpa calculation later
            vector <pair<string, double>> gradeVector;
            double hoursComplete = 0;
            //for each semester print out courses taken by student
            for (auto it : semesters)
            {
                cout << "============ " << "Semester: " << it.second.first << " " << it.second.second  << " ============" << endl;
                fstream file("Database/taken.txt");
                string course, lastName_2, firstName_2, department, courseNum, grade, semester;
                //search for a course taken by student that matches the currently selected semester
                while(getline(file, course))
                {
                    stringstream stream(course);
                    stream >> lastName_2 >> firstName_2 >> department >> courseNum >> grade >> semester;
                    //if semester code matches semester code from course taken then continue
                    if(it.first == semester)
                    {
                            string studentName, last, first, phoneNum;
                            fstream studentfile("Database/students.txt");
                            //search student file for student
                            while (getline(studentfile, studentName))
                            {
                                stringstream streamStudent(studentName);
                                streamStudent >> last >> first >> phoneNum;
                                string courseName,streamDepart,streamNum,streamName,streamCredit;
                                fstream file("Database/courses.txt");
                                //search course file
                                while (getline(file, courseName))
                                {
                                stringstream stream2(courseName);
                                stream2 >> streamDepart >> streamNum >> streamName >> streamCredit;
                                //if the course names and student names match add the corresponding grade to gradeVector
                                //Also, keep track of total hours completed for gpa calculations and print out course taken for transcript
                                if ((department+courseNum == streamDepart+streamNum) && (last+first == lastName+firstName)
                                    && (lastName_2+firstName_2 == last+first))
                                {
                                    gradeVector.push_back(make_pair(grade, stod(streamCredit)));
                                    hoursComplete += stod(streamCredit);
                                    cout << department << courseNum << " " << streamName 
                                    << " (" << streamCredit << ") " << grade << endl;
                                }
                            }
                        }
                        
                    }
                }
            }
            //print out total hours completed
            cout << "STUDENT HOURS COMPLETED: " << hoursComplete << endl;

            //create a map of the grading scale for easy look up of grade points for each grade
            map <string, double> gradeSystem;
            fstream gradeFile("Database/grades.txt");
            //search grade file for grades to add to map
            while(getline(gradeFile, course))
            {
                stringstream stream(course);
                string grade;
                string gpaPoints;
                stream >> grade >> gpaPoints;

                gradeSystem.insert(make_pair(grade, stod(gpaPoints)));
            }

            double gradePoints = 0;
            //tally up gradePoints earned
            for(auto it : gradeVector)
            {
                gradePoints += (gradeSystem.find(it.first)->second * it.second);
            }

            double gpa = 0;
            //calculate GPA
            gpa = gradePoints/hoursComplete;
            cout << "STUDENT GPA: " << gpa << endl;
        }
        //if q is inputted quit program
        else if (input == "q")
        {
            break;
        }
        //if the first command is not a, l, t, or q input is invalid
        else
        {
            cout << input << endl;
            cout << "Invalid input" << endl;
        }  
        }
}