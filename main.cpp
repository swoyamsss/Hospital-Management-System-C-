#include <bits/stdc++.h>
#include<conio.h> // for getch()
using namespace std;

struct Patient_info{
    //contains all the fields for storing Patient's Info
    string First_Name;
    string Last_Name;
    int Age;
    string Blood_group;
    char Gender;
    string Contact_No;
    Patient_info* next;
};
class Hospital_Management{
    //Contains all the functions for Managing the Program
    private:
        Patient_info * head,*tail; //We need Two pointers for Fast inserting of Nodes
    public:
        Hospital_Management(){
            //A constructor to initialize the value of private members
            head = NULL;
            tail = NULL;
        }
        Patient_info new_patient();//New patient's Info
        void insert_at_head();//For patients who need immediate attention
        void insert_at_tail();//For patients with Check up / not so serious condition
        void show_patients();
        void discharge();// operate and discharge the patient
        string Department_name;
};
Patient_info Hospital_Management :: new_patient(){
    Patient_info * temp = new Patient_info();
    cout<<"\t Enter The Details Of the Patient :- \n";
    cout<<"\t Enter First Name  ::";
    cin>>temp->First_Name;
    cout<<"\t Enter Last Name   ::";
    cin>>temp->Last_Name;
    cout<<"\t Enter Age         ::";
    cin>>temp->Age;

    again1 :
    cout<<"\t Enter Blood Group ::";
    cin>>temp->Blood_group;
    int f1 = 0;
    if(temp->Blood_group=="A+" || temp->Blood_group=="a+" || temp->Blood_group=="B+" || temp->Blood_group=="b+" || temp->Blood_group=="O+" || temp->Blood_group=="o+" ||temp->Blood_group=="AB+" ||temp->Blood_group=="ab+"||temp->Blood_group=="A-" || temp->Blood_group=="a-" || temp->Blood_group=="B-" || temp->Blood_group=="b-" || temp->Blood_group=="O-" || temp->Blood_group=="o-" ||temp->Blood_group=="AB-" ||temp->Blood_group=="ab-"){
        f1 = 1;
    }
    if(f1==0){
        cout<<"\t Wrong Blood Type... Enter Again\n";
        goto again1;
    }

    again2 :
    cout<<"\t Enter Gender(M/F) ::";
    cin>>temp->Gender;
    int f2 = 0;
    if(temp->Gender=='M'|| temp->Gender=='F') f2 = 1;
    if(f2==0){
         cout<<"\t Wrong Gender Type.. Enter Again\n";
         goto again2;
    }

    again3 :
    cout<<"\t Enter Contact Number ::";
    cin>>temp->Contact_No;
    int f3 = 0;
    for(int i=0;i<temp->Contact_No.size();i++){
        if(!(temp->Contact_No[i]>='0' && temp->Contact_No[i]<='9')){
            f3 = 1;
            break;
        }
    }
    if(f3==1){
         cout<<"\t Wrong Format..Enter Again\n";
         goto again3;
    }
    temp->next = NULL;
    return *temp;
}
void Hospital_Management :: insert_at_head(){
    Patient_info * p = new Patient_info();
    *p = new_patient();
    if(!head){
        head = p;
        tail = p;
    }
    else{
        p->next = head;
        head = p;
    }
    system("cls");
    cout<<"\n\t\t\t\t New Patient Added\n\n";
    cout<<"\t First Name       : "<<p->First_Name<<"\n";
    cout<<"\t Last Name        : "<<p->Last_Name<<"\n";
    cout<<"\t Age              : "<<p->Age<<"\n";
    cout<<"\t Blood Group      : "<<p->Blood_group<<"\n";
    cout<<"\t Gender           : "<<p->Gender<<"\n";
    cout<<"\t Contact Number   : "<<p->Contact_No<<"\n\n";
}
void Hospital_Management :: insert_at_tail(){
    Patient_info * p = new Patient_info();
    *p = new_patient();
    if(!head){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
    system("cls");
    cout<<"\n\t\t\t\t New Patient Added\n\n";
    cout<<"\t First Name       : "<<p->First_Name<<"\n";
    cout<<"\t Last Name        : "<<p->Last_Name<<"\n";
    cout<<"\t Age              : "<<p->Age<<"\n";
    cout<<"\t Blood Group      : "<<p->Blood_group<<"\n";
    cout<<"\t Gender           : "<<p->Gender<<"\n";
    cout<<"\t Contact Number   : "<<p->Contact_No<<"\n\n";
}
void Hospital_Management :: show_patients(){
     cout<<"\n\t\t\t\t List Of Patients\n\n";
     if(!head) cout<<"\t No patients Present\n";
     else{
        Patient_info * curr = head;
        int i = 1;
        while(curr){
            cout<<"\t "<<i<<" :: \n\n";
            i++;
            cout<<"\t First Name       : "<<curr->First_Name<<"\n";
            cout<<"\t Last Name        : "<<curr->Last_Name<<"\n";
            cout<<"\t Age              : "<<curr->Age<<"\n";
            cout<<"\t Blood Group      : "<<curr->Blood_group<<"\n";
            cout<<"\t Gender           : "<<curr->Gender<<"\n";
            cout<<"\t Contact Number   : "<<curr->Contact_No<<"\n\n";
            curr = curr->next;
        }
     }
}
void Hospital_Management :: discharge(){
    system("cls");
    if(!head) cout<<"\t No Patient To Be Treated\n";
    else{
        Patient_info * temp = head;
        head = head->next;
        cout<<"\n\t\t\t\t Patient To be Operated:-\n";
        cout<<"\t First Name       : "<<temp->First_Name<<"\n";
        cout<<"\t Last Name        : "<<temp->Last_Name<<"\n";
        cout<<"\t Age              : "<<temp->Age<<"\n";
        cout<<"\t Blood Group      : "<<temp->Blood_group<<"\n";
        cout<<"\t Gender           : "<<temp->Gender<<"\n";
        cout<<"\t Contact Number   : "<<temp->Contact_No<<"\n\n";

    }
}
void Admission(Hospital_Management *Dept){
    Patient_info p;
    int x = 10;
    while(x!=5){
        system("cls");
        cout<<"\n\t\t\t\t "<<Dept->Department_name<<"\n\n";
        cout<<"\t 1 :: Add Patients For Normal Routine Check-up\n";
        cout<<"\t 2 :: Add Patients Who Need Immediate Medical Attention\n";
        cout<<"\t 3 :: Show The List Of Patients\n";
        cout<<"\t 4 :: Send A Patient To Doctor\n";
        cout<<"\t 5 :: Return To Main Menu\n\n";
        cout<<"\t Enter Your Choice -> ";
        cin>>x;
        if(x>5){
            cout<<"\t Wrong Choice... Enter Any Key To Try Again\n";
            getch();
            continue;
        }
        switch(x){
            case 1:{
                Dept->insert_at_tail();
                cout<<"\t Enter Any Key To Continue\n";
                getch();
                break;
            }
            case 2:{
                Dept->insert_at_head();
                cout<<"\t Enter Any Key To Continue\n";
                getch();
                break;
            }
            case 3:{
                Dept->show_patients();
                cout<<"\t Enter Any Key To Continue\n";
                getch();
                break;
            }
            case 4:{
                system("cls");
                Dept->discharge();
                cout<<"\t Enter Any Key To Continue\n";
                getch();
                break;
            }

        }
    }
}
int main()
{
    Hospital_Management dept[5];
    dept[0].Department_name = "Pediatrics Department";
    dept[1].Department_name = "Pulmonology Department";
    dept[2].Department_name = "Cardiology Department";
    dept[3].Department_name = "Dermatology Department";
    dept[4].Department_name = "General Clinic";
    int x = 10;
    while(x!=6){
        system("cls");
        cout<<"\n\t\t\t\t Hospital Management System\n\n";
        for(int i=0;i<5;i++) cout<<"\t "<<i+1<<" :: "<<dept[i].Department_name<<"\n";
        cout<<"\t 6 :: EXIT\n\n";
        cout<<"\t Enter your Choice :: ";
        cin>>x;
        if(x>6){
            cout<<"\t Wrong Choice... Enter Any Key To Try Again\n";
            getch();
            continue;
        }
        Admission(&dept[x-1]);
    }
    return 0;
}
