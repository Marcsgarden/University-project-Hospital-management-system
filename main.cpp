#include "proj.h"

int main()
{
    // creating a hospital
    Hospital hsp = Hospital("Josephs hospital");
    cout << "Hospital creation\n" << endl;
    hsp.print();
    //creating clinics
    Clinic cln = Clinic(1, "Madden Clinic", "32 Clean St. New York", "Urgent Care clinic");
    Clinic cln1 = Clinic(4, "Goku Clinic", "Argo rd 4545", "Medicine Clinic");
    cout << "Creating clinig with id 1\n" << endl;
    cln.print();
    cout << "Creating clinic with id 4\n" << endl;
    cln1.print();
    //forming a list of clinics
    cln.set_next(&cln1);
    cout << "Set next for clinic with id 1\n" << endl;
    cln.print();
    //assigning the list to the hospital
    hsp.set_head(&cln);
    cout << "Assigning the list of clinics to hospital" << endl;
    hsp.print();
    //creating doctors
    Doctor doc1 = Doctor("Carlson", 22, "2000-03-20");
    cout << "Creating doc1 \n" << endl;
    doc1.print(false);
    Doctor doc2 = Doctor("Jeremy", 35, "1998-08-22");
    cout << "Creating doc2 \n" << endl;
    doc2.print(false);
    Doctor doc3  = Doctor("John", 45, "1988-08-01");
    cout << "Creating doc3 \n" << endl;
    doc3.print(false);
    Doctor doc4  = Doctor("Adam", 43, "1990-05-01");
    cout << "Creating doc4 \n" << endl;
    doc4.print(false);

    Patient pat1 = Patient("Anthony", 15, "2007-12-12");
    cout << "Creating pat1 \n" << endl;
    pat1.print();
    pat1.set_type("Ill");
    Patient pat2 = Patient("Stevenson", 16, "2006-01-15");
    cout << "Creating pat2 \n" << endl;
    pat2.print();
    pat2.set_type("Ill");
    Patient pat3 = Patient("Carol", 33, "1989-12-30");
    cout << "Creating pat3 \n" << endl;
    pat3.print();
    Patient pat4 = Patient("Simon", 30, "1992-03-10");
    cout << "Creating pat4 \n" << endl;
    pat4.print();
    Patient pat5 = Patient("Adrian", 22, "2000-09-09");
    cout << "Creating pat5 \n" << endl;
    pat5.print();
    //one way to add doctors to clinic is to stuff them up into it
    cln.add_doctor(&doc1);
    cout << "Adding doc1 to the clinic with id 1\n" << endl;
    cln.print();
    cln.add_doctor(&doc3);
    cout << "Adding doc3 to the clinic with id 1\n" << endl;
    cln.print();

    //another way is to form a list of doctors and set the doctor head of the clinic
    doc2.set_next(&doc4);
    cln1.set_dhead(&doc2);
    cout << "Another way of adding doctors to the clinics\n" << endl;
    cln1.print();


    doc1.add_patient(&pat2);
    cout << "Adding pat2 to doc1\n" << endl;
    doc1.print(false);
    doc1.add_patient(&pat3);
    cout << "Adding pat3 to doc1\n" << endl;
    doc1.print(false);
    doc1.add_patient(&pat4);
    cout << "Adding pat4 to doc1\n" << endl;
    doc1.print(false);
    doc2.add_patient(&pat1);
    cout << "Adding pat1 to doc2\n" << endl;
    doc2.print(false);
    doc3.add_patient(&pat5);
    cout << "Adding pat5 to doc3\n" << endl;
    doc3.print(false);

    Appointment app1 = Appointment();
    cout << "Creating app1\n" << endl;
    app1.print();
    //wont do - time is not assigned
    doc1.assign_appointment(&app1, &pat3);
    cout << "Assigning app1 to doc1 but without time\n" << endl;
    doc1.print(false);

    app1.set_time("2022-10-23");
    cout << "Setting time for it to work\n" << endl;
    app1.print();
    //works
    doc1.assign_appointment(&app1, &pat3);
    cout << "Now it works\n" << endl;
    doc1.print(false);

    //canceling appointment
    doc1.cancel_appointment();
    cout << "Canceling appointment\n" << endl;
    doc1.print(false);
    cout << "End" << endl;
    return 0;
}