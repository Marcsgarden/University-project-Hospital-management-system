#include "proj.h"

Hospital::Hospital(string name)
{
    this->name = name;
    this->head = nullptr;
}
Hospital::~Hospital()
{
    Clinic* c = this->head;
    while(c)
    {
        this->head = c->get_next();
        delete c;
        c = this->head;
    }
}



void Hospital::set_head(Clinic* clinic)
{
    this->head = clinic;
}

string Hospital::getNameOfAHospital() { return this->name; }

Clinic::Clinic(int id, string name, string location, string type)
{
    this->id = id;
    this->name = name;
    this->location = location;
    this->type = type;
    this->next = nullptr;
    this->dhead = nullptr;
}


Clinic::~Clinic(){
    Doctor* d = this->dhead;
    while(d)
    {
        this->dhead = d->get_next();
        delete d;
        d = this->dhead;
    }
}

void Clinic::set_next(Clinic* next) { this->next = next; }
Clinic* Clinic::get_next() { return this->next; }

void Clinic::set_dhead(Doctor* doctor)
{
    this->dhead = doctor;
}

void Clinic::add_doctor(Doctor* doctor)
{
    doctor->set_next(this->dhead);
    this->dhead = doctor;
}


Person::Person(string name, int age, string date_of_birth)
{
    this->name = name;
    this->age = age;
    this->date_of_birth = date_of_birth;

    this->next = nullptr;
}

void Person::set_next(Person* next)
{
    this->next = next;
}

Doctor::Doctor(string name, int age, string date_of_birth)
{
    this->name = name;
    this->age = age;
    this->date_of_birth = date_of_birth;

    this->app = nullptr;
    this->next = nullptr;
    this->phead = nullptr;
    this->current_patient = nullptr;
}

void Doctor::assign_appointment(Appointment* app, Patient* patient)
{
    //if appointment time is not set we cannot assign it
    if(!app->time_set()) return;

    if(!patient) return;
    //if patient is not among the patient assigned to the doctor then return 
    //the pattern is as follows: comparing the pointers -> checking if the next exists -> comparing.... 
    if(patient != this->phead && this->phead->get_next() &&
       patient != this->phead->get_next() && this->phead->get_next()->get_next() &&
       patient != this->phead->get_next()->get_next()) return;

    this->app = app;
    this->current_patient = patient;

    app->set_patient_and_doctor_app(patient, this);
}

void Doctor::cancel_appointment()
{
    this->app = nullptr;
    this->current_patient = nullptr;
}


void Doctor::add_patient(Patient* patient){
    Patient* p = this->phead;

    int i = 0;
    //doctor can have only 3 patients maximum
    if(p && p->get_next() && p->get_next()->get_next()) return;
    else if(p && p->get_next()) { p->get_next()->set_next(patient); }
    else if(p) { p->set_next(patient); }
    else { this->phead = patient; }
}

void Doctor::set_next(Doctor* next)
{
    this->next = next;
}



Doctor* Doctor::get_next()
{
    return this->next;
}

Patient::Patient(string name, int age, string date_of_birth)
{
    this->name = name;
    this->age = age;
    this->date_of_birth = date_of_birth;
    this->next = nullptr;
}

void Patient::set_type(string type) { this->type = type; }
void Patient::set_next(Patient* next) { this->next = next; }
Patient* Patient::get_next() { return this->next; }

void Appointment::set_next(Appointment* next) { this->next = next; }
Appointment* Appointment::get_next() { return this->next; }
bool Appointment::time_set() { return this->time.size() != 0; }


void Appointment::set_patient_and_doctor_app(Patient* patient, Doctor* doctor)
{
    this->doctor = doctor;
    this->patient = patient;
}

void Appointment::set_time(string time){ this->time = time; }





void Hospital::print()
{
    cout << "Name: " << this->getNameOfAHospital() << endl;
    cout << "Clinics: " << endl;

    Clinic* c = this->head;
    while(c)
    {
        c->print();
        c = c->get_next();

        cout << "---------------" << endl;
    }
    cout << "---------------" << endl; 
}

void Clinic::print()
{
    cout << "Type: " << this->type << endl;
    cout << "Name: " << this->name << endl;
    cout << "ID: " << this->id << endl;
    cout << "Location: " << this->location << endl;
    cout << "Doctors: " << endl;

    Doctor* d = this->dhead;

    while(d)
    {
        d->print(false);
        d = d->get_next();

        cout << "---------------" << endl;
    }
    cout << "---------------" << endl;
}

void Doctor::print(bool from_app)
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Date of birth: " << this->date_of_birth << endl;
    if(!from_app && this->app) this->app->print();
    cout << "---------------" << endl;
}

void Patient::print()
{
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
    cout << "Date of birth: " << this->date_of_birth << endl;
    cout << "Type: " << this->type << endl;
    cout << "---------------" << endl;
}

void Appointment::print()
{
    cout << "Time: " << this->time << endl;
    cout << "Doctor: " << endl;
    if(this->doctor) this->doctor->print(true);
    cout << "Patient: " << endl;
    if(this->patient) this->patient->print();
    cout << "---------------" << endl;
}