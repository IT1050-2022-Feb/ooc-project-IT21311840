#include <iostream>
#include<cstring>
using namespace std;

class RegisterUser;
class Resume;


class Feedback {
private:
    int feedbackID;
    string feedback;
public:
    Feedback(int ID, string fb);
    string getFeedback();
    void displayFeedback();
};

Feedback::Feedback(int ID, string fb) {
    feedbackID = ID;
    feedback = fb;
}
string Feedback::getFeedback() {
    return feedback;
}
void Feedback::displayFeedback() {
    cout << "Feedback ID: " << feedbackID << endl << "Feedback: " << feedback << endl;
}

//................................................................................................

class User {
protected:
    string username;
    string address;
    string email;
    int contactNo;
    int  feedbackID;
public:
    User(string uname, string add, string mail, int no, int ID);
    void displayDetails();
    void giveFeedback(Feedback* f);
};

User::User(string uName, string add, string mail, int no, int ID) {
    username = uName;
    address = add;
    email = mail;
    contactNo = no;
    feedbackID = ID;
}
void User::displayDetails() {

}
void User::giveFeedback(Feedback* f) {
    f->getFeedback();
}

//...............................................................................................

class RegisterUser : public User {
private:
    int job_id;
    Resume* r;
public:
    RegisterUser(string uName, string add, string mail, int no, int jobId, int ID);
    void addResume( Resume* r1);
    void displayRegisterDetails();
};

class Resume {
private:
    string name;
    string academicDetails;
    string personalDetails;
    RegisterUser* RU;
public:
    Resume(string nam, string a_Details, string p_Details, RegisterUser* RUr);
    void displayResumeDetails();
};

//...............................................................................

RegisterUser::RegisterUser(string uName, string add, string mail, int no, int jobId, int ID) :User(uName, add, mail, no, ID) {
    job_id = jobId;
}
void RegisterUser::addResume(Resume* r1)
{
    r = r1;
    
}
void RegisterUser::displayRegisterDetails() {

    cout << "Name: " << username << endl << "Address: " << address << endl << "Email: " << email << endl << "Contact No: " << contactNo << endl << "Job ID : " << job_id << endl << "Feedback ID: " << feedbackID<<endl;
    r->displayResumeDetails();
}

//........................................................................................................



Resume::Resume(string nam, string a_Details, string p_Details, RegisterUser* RUr) {
    name = nam;
    academicDetails = a_Details;
    personalDetails = p_Details;
    RU = RUr;
    RU->addResume(this);
}
void Resume::displayResumeDetails() {
    cout<<"Resume: "<< "Uploaded." << endl<<endl;
}



//................................................................................................

class UnRegisteredUser :public User {
public:
    UnRegisteredUser(string uName, string add, string mail, int no, int ID);
    void displayUnRegisteredUser();
};
UnRegisteredUser::UnRegisteredUser(string uName, string add, string mail, int no, int ID) :User(uName, add, mail, no, ID) {
}
void UnRegisteredUser::displayUnRegisteredUser() {
    cout << "Name: " << username << endl << "Address: " << address << endl << "Email: " << email << endl << "Contact No: " << contactNo << endl << "Feedback ID: " << feedbackID << endl << endl;
}
//............................................................................................................



int main() {

    Feedback* f = new Feedback(1, "outstanding service");
    Feedback* f1 = new Feedback(2, "quality service");
    RegisterUser* u1 = new RegisterUser("Savi", "Batticalo", "savi@gmail.com", 764948189, 101, 1);
    Resume* r = new Resume("Savi", "personal details", "academic details", u1);
    cout<< "---------------Register user---------------" << endl;
    u1->giveFeedback(f);
    u1->displayRegisterDetails();
    cout<< "---------------UnRegistered user---------------" << endl;
    UnRegisteredUser* ur1 = new UnRegisteredUser("Jathu", "Vavuniya", "jathu@gmail.com", 769052508, 2);
    ur1->giveFeedback(f1);
    ur1->displayUnRegisteredUser();
    cout<< "---------------Feedback---------------" << endl;
    f->displayFeedback();
    cout << endl;
    f1->displayFeedback();

    return 0;
}