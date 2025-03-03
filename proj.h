#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name, int age, string date_of_birth);  
    Person() = default;
    void set_next(Person* next);
    void print();

protected:
    string name;
    int age;
    string date_of_birth;
private:
    Person *next;
};


class Patient : public Person
{
public:
    Patient(string name, int age, string date_of_birth);                                                             
    void set_next(Patient* next);
    Patient* get_next();   
    void set_type(string type); 
    void print();                      

private:
    string type; 
    Patient *next;
};

class Appointment; // so that doctor can see this class

class Doctor : public Person
{
public:
    Doctor(string name, int age, string date_of_birth);
    void assign_appointment(Appointment* app, Patient* patient);                         
    void cancel_appointment();                          
    void add_patient(Patient* patient);  
    void set_next(Doctor* next); 
    Doctor* get_next();  
    void print(bool from_app);   //argument is used to indicate where function is called so that
                    // print functions are not called recursively                    

private:
    Patient* current_patient;
    Appointment* app;
    Doctor *next;
    Patient *phead;
};


class Appointment
{
public:
    Appointment() = default;
    void set_next(Appointment* next);
    Appointment* get_next();
    void set_patient_and_doctor_app(Patient *patient, Doctor *doctor);
    void set_time(string time);
    bool time_set();
    void print();
private:
    string time;
    Patient *patient;
    Doctor *doctor;
    Appointment *next;
};



class Clinic
{
public:
    Clinic(int id, string name, string location, string type); 
    ~Clinic(); 
    void set_next(Clinic* next);    
    Clinic* get_next();   
    void set_dhead(Doctor* doctor);
    void add_doctor(Doctor* doctor);  
    void print();                                      

private:
    string type;
    string name;
    int id;
    string location;
    Clinic *next;
    Doctor* dhead;
};

class Hospital
{
public:
    Hospital(string name);  
    ~Hospital();
    string getNameOfAHospital();
    void set_head(Clinic* clinic);
    void print(); 

private:
    string name;
    Clinic* head;
};








