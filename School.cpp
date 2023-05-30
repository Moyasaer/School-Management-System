#include <iostream>
#include <iomanip>

using namespace std;

// Classes
class person {
protected:
    string fname;
    string lname;
    int age;
    string gender;
    int CoNumber;
    string mail;
    long long nationalID;
    virtual void set() = 0;
    virtual void show() = 0;
};

class students : public person {
private: int id, secret_num;
       float sub1, sub2, sub3, sub4, sub5, sub6;
       bool set_grades;
public:
    students* next;
    students* prev;
    students* headStudent;
    students* tailStudent;

    students() {
        fname = "No name";
        lname = "No name";
        age = 0;
        id = 0;
        secret_num = 00000;
        sub1 = 0;
        sub2 = 0;
        sub3 = 0;
        sub4 = 0;
        sub5 = 0;
        sub6 = 0;
        set_grades = false;
        gender = "Not Detected";
        CoNumber = 0000000000;
        mail = "No email";
        nationalID = 00000;
        next = NULL;
        prev = NULL;
        headStudent = NULL;
        tailStudent = NULL;
    }
    int getNumOfStudents() {
        int count =0;
        students* current = headStudent;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    void grades() {
        if (headStudent == NULL)
            cout<<setw(70) << "No Student is added\n";
        else {
            int gSecret;
            students* grades = headStudent;
            cout << setw(70) << "Enter the student's Secret Number\n";
            cin >> gSecret;
            while (grades->secret_num != gSecret && grades != NULL) {
                grades = grades->next;
            }
            if (grades == NULL)
                cout << setw(70) << "NOT FOUND\n";
            else {
                cout << setw(70) << "\nEnter percantage for subject 1 :-";
                cin >> grades->sub1;
                cout << setw(70) << "\nEnter percantage for subject 2 :-";
                cin >> grades->sub2;
                cout << setw(70) << "\nEnter percantage for subject 3 :-";
                cin >> grades->sub3;
                cout << setw(70) << "\nEnter percantage for subject 4 :-";
                cin >> grades->sub4;
                cout << setw(70) << "\nEnter percantage for subject 5 :-";
                cin >> grades->sub5;
                cout << setw(70) << "\nEnter percantage for subject 6 :-";
                cin >> grades->sub6;
                set_grades = true;
                cout << setw(60) << "\nDone\n";
            }
        }
    }
    void show_grades() {
        if (headStudent == NULL)
            cout << setw(70) << "No Student is added\n";
        else {
            int gSecret;
            cout << setw(70) << "Enter the student's Secret Number\n";
            cin >> gSecret;
            if (set_grades == false)
                cout << setw(70) << "Your Grades is not set yet\n";
            else {
                students* grades = headStudent;
                while (grades->secret_num != gSecret && grades != NULL) {
                    grades = grades->next;
                }
                if (grades == NULL){
                    cout << setw(60);
                    cout << "NOT FOUND\n";}
                else {
                    cout << setw(70);
                    cout << "\n the percantage for subject 1 :-";
                    cout << grades->sub1;
                    cout << setw(70);
                    cout << "\n the percantage for subject 2 :-";
                    cout << grades->sub2;
                    cout << setw(70);
                    cout << "\n the percantage for subject 3 :-";
                    cout << grades->sub3;
                    cout << setw(70) ;
                    cout<< "\n the percantage for subject 4 :-";
                    cout << grades->sub4;
                    cout << setw(70);
                    cout << "\n the percantage for subject 5 :-";
                    cout << grades->sub5;
                    cout << setw(70);
                    cout << "\n the percantage for subject 6 :-";
                    cout << grades->sub6;
                    cout << setw(60);
                    cout << "\nDone\n";
                }
            }
        }
    }
    void set() {
        char ch = ' ';
        int i = getNumOfStudents();
        students* newStudent = new students();
        do {
            cout << setw(69) << "1. Add Student at the last\n\n";
            cout << setw(70) << "2. Add Student at the first\n\n";
            cout << setw(65) << "3. Back to the options\n\n";
            cout << setw(67) << "Choose from the options\n\n";
            cin >> ch;
            system("cls");
            if (ch == '1' || ch == '2') {
             
                cout << setw(70) << "---Enter The First Name : " << i + 1 << "---" << ": \n";
                cin >> newStudent->fname;
            
                cout << setw(68) << "---Enter The Last Name : " << i + 1 << "---" << ": \n";
                cin >> newStudent->lname;
           
                cout << setw(63) << "---Enter ID : " << i + 1 << "---" << ": \n";
                cin >> newStudent->id;
 
                cout << setw(70) << "---Set a Secret Number : " << i + 1 << "---" << ": \n";
                cin >> newStudent->secret_num;

                cout << setw(67) << "---Enter The Age : " << i + 1 << "---" << ": \n";
                cin >> newStudent->age;
                string g = newStudent->gender;
                do {
                    cout << setw(73) << "---Enter The Gender (Male/Female): " << i + 1 << "---" << ": \n";
                    cin >> newStudent->gender;
                    g = newStudent->gender;
                    if (g == "male" || g == "Male" || g == "female" || g == "Female")
                        break;
                } while (g != "male" || g != "Male" || g != "female" || g != "Female");
              
                cout << setw(72) << "---Enter The Contact Number : " << i + 1 << "---" << ": \n";
                cin >> newStudent->CoNumber;
               
                cout << setw(68) << "---Enter The Email : " << i + 1 << "---" << ": \n";
                cin >> newStudent->mail;
               
                cout << setw(70) << "---Enter The National ID : " << i + 1 << "---" << ": \n";
                cin >> newStudent->nationalID;
                cout << endl;
            }
            switch (ch)
            {

            case '1': {

                if (headStudent == NULL) {
                    headStudent = newStudent;
                    tailStudent = newStudent;
                }
                else {
                    tailStudent->next = newStudent;
                    newStudent->prev = tailStudent;
                    tailStudent = newStudent;
                }
                break;
            }
            case '2': {
                if (headStudent == NULL) {
                    headStudent = newStudent;
                    tailStudent = newStudent;
                }
                else {
                    headStudent->prev = newStudent;
                    newStudent->next = headStudent;
                    headStudent = newStudent;
                }
                break;
            }
            case '3':
                cout << setw(70) << "Back to the options\n";
                break;
            }
            break;
        } while (ch != '3');
    }
    void delete_s() {
        char s = ' ';
        if (headStudent == NULL)
            cout << setw(75) << "there is no students to delete\n";
        else {
            do {
                cout << setw(70) << "Select an option:\n";
                cout << setw(70) << "1. Delete the last student\n";
                cout << setw(71) << "2. Delete the first student\n";
                cout << setw(67) << "3. Delete Student by id\n";
                cout << setw(62) << "4. Back to options\n";
                cout << setw(70) << "Enter your choice\n";
                cin >> s;
                system("cls");
                switch (s) {
                case '1': {
                    if (headStudent->next == NULL)
                        headStudent = tailStudent = NULL;
                    else {
                        students* temp = tailStudent;
                        tailStudent = temp->prev;
                        tailStudent->next = NULL;
                        free(temp);
                        cout << "Done\n";
                        return;
                    }
                    break;
                }
                case '2': {
                    if (headStudent->next == NULL)
                        headStudent = tailStudent = NULL;
                    else {
                        students* temp = headStudent;
                        headStudent = temp->next;
                        headStudent->prev = NULL;
                        free(temp);
                        cout << "Done\n";
                        return;
                    }
                    break; }
                case '3': {
                    int tid;
                    students* temp = headStudent;
                    cout << setw(70) << "Enter the student id\n";
                    cin >> tid;
                    if (temp->id == tid) {
                        headStudent = temp->next;
                        if (headStudent != NULL)
                            headStudent->prev = NULL;
                        free(temp);
                        return;
                    }
                    while (temp != NULL && temp->id != tid) {
                        temp = temp->next;
                    }

                    if (temp == NULL) {
                        return;
                    }
                    else {
                        temp->prev->next = temp->next;
                        if (temp->next != NULL)
                            temp->next->prev = temp->prev;
                        free(temp);
                    }
                    break;
                }
                case '4':
                    cout << setw(70) << "Back to the options\n";
                    break;
                default:
                    cout << setw(70) << "Invalid choice. Please try again." << endl;
                    break;
                }
                break;
            } while (s != 4);
        }
    }
    void show() {
        int i = 1;
        if (headStudent == NULL) {
            cout << setw(70) << "No students found." << endl;
        }
        else {
            cout << setw(70) << "List of Students: " << endl;
            students* current = headStudent;
            while (current != NULL) {
                cout << setw(62) << "Name:"<<  i<< current->fname << " " << current->lname << endl;
                cout << setw(61) << "ID: " << current->id << endl;
                cout << setw(62) << "Age: " << current->age << endl;
                cout << setw(65) << "Gender: " << current->gender << endl;
                cout << setw(73) << "Contact Number: " << current->CoNumber << endl;
                cout << setw(64) << "Email: " << current->mail << endl;
                cout << setw(70) << "National ID: " << current->nationalID << endl;
                cout << endl;
                current = current->next;
                i++;
            }
        }
    }
    void edit() {
        int searchID;
        bool found = false;
        if (headStudent == NULL) {
            cout << "No students added." << endl;
        }
        else {
            cout << "Enter Student ID:  " << endl;
            cin >> searchID;
            students* current = headStudent;
            while (current != NULL) {
                if (current->id == searchID) {
                    found = true;
                    cout << setw(72);
                    cout << "---Enter The First Name : " << "---" << ": \n";
                    cin >> current->fname;
                    cout << setw(71);
                    cout << "---Enter TheLast Name : " << "---" << ": \n";
                    cin >> current->lname;
                    cout << setw(72);
                    cout << "---Enter The Age : " << "---" << ": \n";
                    cin >> current->age;
                    string g = current->gender;
                    do {
                       
                        cout << setw(70) << "---Enter The Gender (Male/Female): " << "---" << ": \n";
                        cin >> current->gender;
                        g = current->gender;
                        if (g == "male" || g == "Male" || g == "female" || g == "Female")
                            break;
                    } while (g != "male" || g != "Male" || g != "female" || g != "Female");
                   
                    cout << setw(70) << "---Enter The Contact Number : " << "---" << ": \n";
                    cin >> current->CoNumber;
                 
                    cout << setw(70) << "---Enter The Email : " << "---" << ": \n";
                    cin >> current->mail;
                   
                    cout << setw(70) << "---Enter The National ID : " << "---" << ": \n";
                    cin >> current->nationalID;
                    cout << endl;
                    break;
                }

                current = current->next;
            }
            if (found == false)
                cout <<setw(70)<< "NOT FOUND \n";
        }

    }
    void search() {
        // s before variable for search
        char c = ' ';
        string sfname, slname;
        int sid, sage, sconum, i = 1;
        bool done = false;
        if (headStudent == NULL)
            cout <<setw(70)<< "No Students yet\n";
        else {
            students* search = headStudent;
            do {
                cout << setw(70) << "Select an option:\n";
                cout << setw(71) << "1. search by first name\n";
                cout << setw(70) << "2. search by last name\n";
                cout << setw(63) << "3. search by id\n";
                cout << setw(64) << "4. search by age\n";
                cout << setw(75) << "5. search by contact number\n";
                cout << setw(55) << "6. Exit\n";
                cout << setw(70) << "Enter your choice: ";
                cin >> c;
                system("cls");
                switch (c) {
                case '1':
                    cout << setw(70) << "Enter The first name\n";
                    cin >> sfname;
                    while (search != NULL) {
                        if (search->fname == sfname) {
                            cout << setw(60) << i << ". " << search->fname << " " << search->lname << endl;
                            cout << setw(60) << "ID: " << search->id << endl;
                            cout << setw(60) << "Age: " << search->age << endl;
                            cout << setw(60) << "Gender: " << search->gender << endl;
                            cout << setw(60) << "Contact Number: " << search->CoNumber << endl;
                            cout << setw(60) << "Email: " << search->mail << endl;
                            cout << setw(60) << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '2':
                    cout << setw(70) << "Enter The last name\n";
                    cin >> slname;
                    while (search != NULL) {
                        if (search->lname == slname) {
                            cout << setw(60) << i << ". " << search->fname << " " << search->lname << endl;
                            cout << setw(60) << "ID: " << search->id << endl;
                            cout << setw(60) << "Age: " << search->age << endl;
                            cout << setw(60) << "Gender: " << search->gender << endl;
                            cout << setw(60) << "Contact Number: " << search->CoNumber << endl;
                            cout << setw(60) << "Email: " << search->mail << endl;
                            cout << setw(60) << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '3':
                    cout << setw(70) << "Enter The student id\n";
                    cin >> sid;
                    while (search != NULL) {
                        if (search->id == sid) {
                            cout << setw(60) << i << ". " << search->fname << " " << search->lname << endl;
                            cout << setw(60) << "ID: " << search->id << endl;
                            cout << setw(60) << "Age: " << search->age << endl;
                            cout << setw(60) << "Gender: " << search->gender << endl;
                            cout << setw(60) << "Contact Number: " << search->CoNumber << endl;
                            cout << setw(60) << "Email: " << search->mail << endl;
                            cout << setw(60) << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '4':
                    cout << setw(70) << "Enter The Student age\n";
                    cin >> sage;
                    while (search != NULL) {
                        if (search->age == sage) {
                            cout << setw(70) << i << ". " << search->fname << " " << search->lname << endl;
                            cout << setw(70) << "ID: " << search->id << endl;
                            cout << setw(70) << "Age: " << search->age << endl;
                            cout << setw(70) << "Gender: " << search->gender << endl;
                            cout << setw(70) << "Contact Number: " << search->CoNumber << endl;
                            cout << setw(70) << "Email: " << search->mail << endl;
                            cout << setw(70) << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '5':
                    cout << "Enter The student contact number\n";
                    cin >> sconum;
                    while (search != NULL) {
                        if (search->CoNumber == sconum) {
                            cout << setw(70) << i << ". " << search->fname << " " << search->lname << endl;
                            cout << setw(70) << "ID: " << search->id << endl;
                            cout << setw(70) << "Age: " << search->age << endl;
                            cout << setw(70) << "Gender: " << search->gender << endl;
                            cout << setw(70) << "Contact Number: " << search->CoNumber << endl;
                            cout << setw(70) << "Email: " << search->mail << endl;
                            cout << setw(70) << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                case '6':
                    cout << setw(70) << "Back to the main options\n";
                    break;
                default:
                    cout << setw(70) << "Invalid choice. Please try again." << endl;
                    break;
                }
                break;
            } while (c != 6);
            if (done == false)
                cout << setw(70) << "NOT FOUND\n";
        }
    }
};

class teachers : public person {
private:
    string prof;
    float salary;
    int abs_days;
public:
    teachers* next;
    teachers* prev;
    teachers* headTeacher;
    teachers* tailTeacher;

    teachers() {
        fname = "No name";
        lname = "No name";
        age = 0;
        prof = "No Prof.";
        abs_days = 0;
        salary = 00.00;
        gender = "Not Detected";
        CoNumber = 0000000000;
        mail = "No email";
        nationalID = 00000;
        next = NULL;
        prev = NULL;
        headTeacher = NULL;
        tailTeacher = NULL;
    }

    void set() {
        char ch = ' ';
        int i = getNumOfTeachers();
        teachers* newTeacher = new teachers();
        do {
            cout <<setw(69)<< "1. Add teacher at the last\n";
            cout << setw(70) << "2. Add teacher at the first\n";
            cout << setw(65) << "3. Back to the options\n";
            cout << setw(67) << "Choose from the options\n";
            cin >> ch;
            system("cls");
            if (ch == '1' || ch == '2') {
                cout << setw(72);
                cout << "---Enter The First Name : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->fname;
                cout << setw(71);
                cout << "---Enter TheLast Name : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->lname;
                cout << setw(69);
                cout << "---Enter The Age : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->age;
                cout << setw(72);
                cout << "---Enter The Proffesion : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->prof;
                cout << setw(69);
                cout << "---Enter The Salary : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->salary;
                string g = newTeacher->gender;
                do {
                    cout << setw(79);
                    cout << "---Enter The Gender (Male/Female): " << i + 1 << "---" << ": \n";
                    cin >> newTeacher->gender;
                    g = newTeacher->gender;
                    if (g == "male" || g == "Male" || g == "female" || g == "Female")
                        break;
                } while (g != "male" || g != "Male" || g != "female" || g != "Female");
                cout << setw(77);
                cout << "---Enter The Contact Number : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->CoNumber;
                cout << setw(72);
                cout << "---Enter The Email : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->mail;
                cout << setw(73);
                cout << "---Enter The National ID : " << i + 1 << "---" << ": \n";
                cin >> newTeacher->nationalID;
                cout << endl;
            }
            switch (ch) {
            case '1': {
                if (headTeacher == NULL) {
                    headTeacher = newTeacher;
                    tailTeacher = newTeacher;
                }
                else {
                    tailTeacher->next = newTeacher;
                    newTeacher->prev = tailTeacher;
                    tailTeacher = newTeacher;
                }
                break;
            }
            case '2': {
                if (headTeacher == NULL) {
                    headTeacher = newTeacher;
                    tailTeacher = newTeacher;
                }
                else {
                    headTeacher->prev = newTeacher;
                    newTeacher->next = headTeacher;
                    headTeacher = newTeacher;
                }
                break;
            }
            case '3':
                cout << "Back to the options\n";
                break;

            }
            break;
        } while (ch != '3');
    }


    void show() {
        int i = 1;
        if (headTeacher == NULL) {
            cout <<setw(70) << "No teachers found." << endl;
        }
        else {
            cout << "List of Teachers: " << endl;
            teachers* current = headTeacher;
            while (current != NULL) {
                cout <<"Name:" << i << ". " << current->fname << " " << current->lname << endl;
                cout << "Age: " << current->age << endl;
                cout << "Proffesion: " << current->prof << endl;
                cout << "Salary: " << current->salary << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "Contact Number: " << current->CoNumber << endl;
                cout << "Email: " << current->mail << endl;
                cout << "National ID: " << current->nationalID << endl;
                cout << endl;
                current = current->next;
                i++;
            }
        }
    }
    void delete_t() {
        char s = ' ';
        if (headTeacher == NULL)
            cout <<setw(70)<< "there is no teacher to delete\n";
        else {
            do {
                cout << "Select an option:\n";
                cout << "1. Delete the last teacher\n";
                cout << "2. Delete the first teacher\n";
                cout << "3. Delete teqcher by national id\n";
                cout << "4. Back to options\n";
                cout << "Enter your choice\n";
                cin >> s;
                system("cls");
                switch (s) {
                case '1': {
                    if (headTeacher->next == NULL)
                        headTeacher = tailTeacher = NULL;
                    else {
                        teachers* temp = tailTeacher;
                        tailTeacher = temp->prev;
                        tailTeacher->next = NULL;
                        free(temp);
                        return;
                    }
                    break;
                }
                case '2': {
                    if (headTeacher->next == NULL)
                        headTeacher = tailTeacher = NULL;
                    else {
                        teachers* temp = headTeacher;
                        headTeacher = temp->next;
                        headTeacher->prev = NULL;
                        free(temp);
                        return;
                    }
                    break; }
                case '3': {
                    int tid;
                    teachers* temp = headTeacher;
                    cout <<setw(70)<< "Enter the teacher national id\n";
                    cin >> tid;
                    if (temp->nationalID == tid) {
                        headTeacher = temp->next;
                        if (headTeacher != NULL)
                            headTeacher->prev = NULL;
                        free(temp);
                        return;
                    }
                    while (temp != NULL && temp->nationalID != tid) {
                        temp = temp->next;
                    }

                    if (temp == NULL) {
                        cout <<setw(70) << "Not Found\n";
                        return;
                    }
                    else {
                        temp->prev->next = temp->next;
                        if (temp->next != NULL)
                            temp->next->prev = temp->prev;
                        free(temp);
                    }
                    break;
                }
                case '4':
                    cout <<setw(70)<< "Back to the options\n";
                    break;
                default:
                    cout <<setw(70)<< "Invalid choice. Please try again." << endl;
                    break;
                }
                break;
            } while (s != 4);
        }
    }

    int getNumOfTeachers() {
        int count = 0;
        teachers* current = headTeacher;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    void edit() {
        long long searchNid;
        bool found = false;
        if (headTeacher == NULL) {
            cout <<setw(70)<< "No teachers added." << endl;
        }
        else {
            cout << setw(70) << "Enter Teacher's National ID:  " << endl;
            cin >> searchNid;
            teachers* current = headTeacher;
            while (current != NULL) {
                if (current->nationalID == searchNid) {
                    found = true;
                   
                    cout << "---Enter The new First Name : " << "---" << ": \n";
                    cin >> current->fname;
                     
                    cout << "---Enter The new Last Name : " << "---" << ": \n";
                    cin >> current->lname;
                 
                    
                    cout << "---Enter The new Profession : " << "---" << ": \n";
                    cin >> current->prof;
                   
                    cout << "---Enter The new Salary : " << "---" << ": \n";
                    cin >> current->salary;
                    
                    cout << "---Enter The new Age : " << "---" << ": \n";
                    cin >> current->age;
                    string g = current->gender;
                    do {
                    
                        cout << "---Enter The Gender (Male/Female): " << "---" << ": \n";
                        cin >> current->gender;
                        g = current->gender;
                        if (g == "male" || g == "Male" || g == "female" || g == "Female")
                            break;
                    } while (g != "male" || g != "Male" || g != "female" || g != "Female");
                
                    cout << "---Enter The new Contact Number : " << "---" << ": \n";
                    cin >> current->CoNumber;
                     
                    cout << "---Enter The new Email : " << "---" << ": \n";
                    cin >> current->mail;
                
                    cout << "---Enter The new National ID : " << "---" << ": \n";
                    cin >> current->nationalID;
                    cout << endl;
                    break;
                }

                current = current->next;
            }
            if (found == false)
                cout <<setw(70) << "NOT FOUND\n";
        }

    }
    void search() {
        // s before variable for search
        char c = ' ';
        string sfname, slname, sprof;
        float ssalary;
        long long sid;
        int sage, sconum, i = 1;
        bool done = false;
        if (headTeacher == NULL)
            cout << "No Teachers yet\n";
        else {
            teachers* search = headTeacher;
            do {
                cout << "Select an option:\n";
                cout << " 1. search by first name\n";
                cout << " 2. search by last name\n";
                cout << " 3. search by national id\n";
                cout << " 4. search by age\n";
                cout << " 5. search by contact number\n";
                cout << " 6. search by salary\n";
                cout << " 7. search by profession\n";
                cout << " 8. Exit\n";
                cout << "Enter your choice: ";
                cin >> c;
                system("cls");
                switch (c) {
                case '1':
                    cout << "Enter The first name\n";
                    cin >> sfname;
                    while (search != NULL) {
                        if (search->fname == sfname) {
                            cout <<   i << ". " << search->fname << " " << search->lname << endl;
                            cout << "National ID: " << search->nationalID << endl;
                            cout <<   "Age: " << search->age << endl;
                            cout <<  "Gender: " << search->gender << endl;
                            cout <<  "Contact Number: " << search->CoNumber << endl;
                            cout <<  "Email: " << search->mail << endl;
                            cout <<   "Profession: " << search->prof << endl;
                            cout << endl;
                            cout <<  "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '2':
                    cout << "Enter The last name\n";
                    cin >> slname;
                    while (search != NULL) {
                        if (search->lname == slname) {
                            cout <<   i << ". " << search->fname << " " << search->lname << endl;
                            cout  << "Age: " << search->age << endl;
                            cout << "Gender: " << search->gender << endl;
                            cout  << "Contact Number: " << search->CoNumber << endl;
                            cout  << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '3':
                    cout << setw(70) << "Enter The Teacher National id\n";
                    cin >> sid;
                    while (search != NULL) {
                        if (search->nationalID == sid) {
                            cout  << i << ". " << search->fname << " " << search->lname << endl;
                            cout  << "Age: " << search->age << endl;
                            cout << "Gender: " << search->gender << endl;
                            cout  << "Contact Number: " << search->CoNumber << endl;
                            cout  << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '4':
                    cout << "Enter The teacher age\n";
                    cin >> sage;
                    while (search != NULL) {
                        if (search->age == sage) {
                            cout << i << ". " << search->fname << " " << search->lname << endl;
                            cout << "Age: " << search->age << endl;
                            cout  << "Gender: " << search->gender << endl;
                            cout << "Contact Number: " << search->CoNumber << endl;
                            cout  << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout  << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                    break;
                case '5':
                    cout << "Enter The Teacher contact number\n";
                    cin >> sconum;
                    while (search != NULL) {
                        if (search->CoNumber == sconum) {
                            cout << i << ". " << search->fname << " " << search->lname << endl;
                            cout << "Age: " << search->age << endl;
                            cout  << "Gender: " << search->gender << endl;
                            cout  << "Contact Number: " << search->CoNumber << endl;
                            cout  << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                case '6':
                    cout << "Enter The teacher salary\n";
                    cin >> ssalary;
                    while (search != NULL) {
                        if (search->salary == ssalary) {
                            cout << i << ". " << search->fname << " " << search->lname << endl;
                            cout  << "Age: " << search->age << endl;
                            cout << "Gender: " << search->gender << endl;
                            cout  << "Contact Number: " << search->CoNumber << endl;
                            cout << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout  << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                case '7':
                    cout << "Enter The Teacher profession\n";        cin >> sprof;
                    while (search != NULL) {
                        if (search->prof == sprof) {
                            cout  << i << ". " << search->fname << " " << search->lname << endl;
                            cout  << "Age: " << search->age << endl;
                            cout  << "Gender: " << search->gender << endl;
                            cout  << "Contact Number: " << search->CoNumber << endl;
                            cout  << "Email: " << search->mail << endl;
                            cout  << "National ID: " << search->nationalID << endl;
                            cout << endl;
                            cout  << "Profession: " << search->prof << endl;
                            cout << endl;
                            cout  << "Salary:  " << search->salary << endl;
                            cout << endl;
                            done = true;
                        }
                        search = search->next;
                    }
                case '8':
                    cout << setw(70) << "Back to the main options\n";
                    break;
                default:
                    cout << setw(70) << "Invalid choice. Please try again." << endl;
                    break;
                }
                break;
            } while (c != 8);
            if (done == false)
                cout << "NOT FOUND\n";
        }
    }
    void i_abs_days() {
        teachers* abs = headTeacher;
        long long sN_ID;
        if (abs == NULL)
            cout << setw(70) << "theres no teachers yet\n";
        else {
            cout << setw(70) << "Enter the teacher's National ID\n";
            cin >> sN_ID;
            while (abs != NULL && abs->nationalID != sN_ID) {
                abs = abs->next;
            }
            if (abs == NULL)
                cout << setw(70) << "NOT FOUND\n";
            else {
                abs->abs_days++;
                cout << setw(70) << "The Total days of absence :";
                cout << abs->abs_days << endl;
            }
        }
    }
    void total_salary() {
        if (headTeacher == NULL)
            cout <<setw(70) << "No Teachers is added\n";
        else {
            long long n;
            cout << "Enter the national ID\n";
            cin >> n;
            teachers* salary = headTeacher;
            while (salary->nationalID != n && salary != NULL) {
                salary = salary->next;
            }
            if (salary == NULL)
                cout << setw(70) << "NOT FOUND\n";
            else {
                if (salary->abs_days > 3) {
                    float s = salary->salary;
                    int a = salary->abs_days;
                    salary->salary = s - (s * ((a - 3) * 10) / 100);
                }
                cout << "The total days of absence :-";
                cout << salary->abs_days;
                cout << "Your Salary is :- ";
                cout << salary->salary << endl;
            }
        }
    }
};
// Main function
int main()
{
    char sCh = ' ';
    int choice;
    char ch;
    students student;
    teachers teacher;
    do {
        cout << setw(75) << "=========================\n";
        cout << setw(75) << "Welcome to school System\n";
        cout << setw(76) << "=========================\n\n";
        cout << setw(70) << "Select an option:\n";
        cout << setw(70) << "1. Manager Portal\n";
        cout << setw(70) << "2. Student Portal\n";
        cout << setw(70) << "3. Teacher Portal\n";
        cout << setw(61) << "4. EXIT\n\n";
        cout << setw(70) << "Enter your choice\n";
        cin >> ch;
        switch (ch)
        {
        case '1': {
            system("cls");
            do {
                cout << setw(68) << "======================\n";
                cout << setw(68) << "--The Manager Portal--\n";
                cout << setw(68) << "======================\n";
                cout << setw(65) << "Select an option:\n";
                cout << setw(63) << "1. Add a student\n";
                cout << setw(63) << "2. Add a teacher\n";
                cout << setw(71) << "3. Show list of students\n";
                cout << setw(71) << "4. Show list of teachers\n";
                cout << setw(88) << "5. Increase days of absence for a teacher\n";
                cout << setw(66) << "6. Edit in Students\n";
                cout << setw(67) << "7. Edit in Teachers \n";
                cout << setw(69) << "8. Search in Students \n";
                cout << setw(69) << "9. Search in Teachers \n";
                cout << setw(70) << "10. Delete in Students \n";
                cout << setw(69) << "11. Delete in Teachers\n";
                cout << setw(55) << "12. Exit\n";
                cout << setw(70) << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    system("cls");
                    student.set();
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    teacher.set();
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    student.show();
                    cout << endl;
                    cout << setw(73) << "The total number of students :" << student.getNumOfStudents() << endl;
                    break;
                case 4:
                    system("cls");
                    teacher.show();
                    cout << endl;
                    cout << setw(70) << "The total number of teacher is :" << teacher.getNumOfTeachers() << endl;
                    break;
                case 5:
                    system("cls");
                    teacher.i_abs_days();
                    break;
                case 6:
                    system("cls");
                    student.edit();
                    system("cls");
                    break;
                case 7:
                    system("cls");
                    teacher.edit();
                    system("cls");
                    break;
                case 8:
                    system("cls");
                    student.search();
                    break;
                case 9:
                    system("cls");
                    teacher.search();
                    break;
                case 10:
                    system("cls");
                    student.delete_s();
                    break;
                case 11:
                    teacher.delete_t();
                case 12:
                    system("cls");
                    cout << setw(70) << "Exiting the program..." << endl;
                    break;
                default:
                    system("cls");
                    cout << setw(70) << "Invalid choice. Please try again." << endl;
                    break;
                }
                break;
            } while (choice != 11);
            break;
        }
        case '2': {
            system("cls");
            do {
                cout << setw(70) << "======================\n";
                cout << setw(70) << "--The Student Portal--\n";
                cout << setw(70) << "======================\n";
                cout << setw(70) << "Choose from the options\n";
                cout << setw(70) << "1. Show list of students\n";
                cout << setw(70) << "3. Show list of teachers\n";
                cout << setw(69) << "3. Search for a Student\n";
                cout << setw(69) << "4. Search for a Teacher\n";
                cout << setw(60) << "5. Show grades\n";
                cout << setw(53) << "6. Exit\n";
                cout << setw(66) << "Enter your choice";
                cin >> sCh;
                switch (sCh)
                {
                case '1':
                    system("cls");
                    student.show();
                    break;
                case '2':
                    system("cls");
                    teacher.show();
                    break;
                case '3':
                    system("cls");
                    student.search();
                    break;
                case '4':
                    system("cls");
                    teacher.search();
                    break;
                case '5':
                    system("cls");
                    student.show_grades();
                    break;
                case '6':
                    system("cls");
                    cout << setw(70) << "Back To main \n";
                    break;
                default:
                    system("cls");
                    cout << setw(70) << "Please choose form the options\n";
                    break;
                }
                break;
            } while (sCh != 5);
            break;
        }
        case '3': {
            system("cls");
            do {
                cout << setw(70) << "======================\n";
                cout << setw(70) << "--The Teacher Portal--\n";
                cout << setw(70) << "======================\n";
                cout << setw(70) << "Choose from the options\n";
                cout << setw(70) << "1. Show list of students\n";
                cout << setw(70) << "2. Show list of teachers\n";
                cout << setw(66) << "3. Check Your salary\n";
                cout << setw(69) << "4. Search for a Student\n";
                cout << setw(69) << "5. Search for a Teacher\n";
                cout << setw(66) << "6. Edit student data\n";
                cout << setw(71) << "7. Set grades for student\n";
                cout << setw(53) << "8. Exit\n";
                cout << setw(67) << "Enter your choice";
                cin >> sCh;
                switch (sCh)
                {
                case '1':
                    system("cls");
                    student.show();
                    break;
                case '2':
                    system("cls");
                    teacher.show();
                    break;
                case '3':
                    system("cls");
                    teacher.total_salary();
                    break;
                case '4':
                    system("cls");
                    student.search();
                    break;
                case '5':
                    system("cls");
                    teacher.search();
                    break;
                case '6':
                    system("cls");
                    student.edit();
                    break;
                case '7':
                    system("cls");
                    student.grades();
                    break;
                case '8':
                    system("cls");
                    cout << setw(70) << "Back To main \n";
                    break;
                default:
                    system("cls");
                    cout << setw(70) << "Please choose form the options\n";
                    break;
                }
                break;
            } while (sCh != 5);
            break;
        }
        default:
            system("cls");
            cout << setw(70) << "Please choose form the options\n";
            break;
        }
    } while (ch != '4');

    return 0;
}
