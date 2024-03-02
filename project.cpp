/*
        DS GOUP ASSIGNMENT
        SECTION 3
    Name                                    ID Number                 
1. Abenezer Gemena                      UGR/25441/14
2. Zemedkun Girmaye                     UGR/25372/14
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string name;
    string position;
    int age;
    string address;
    string email;
    string phone;
    Node* next;
};
Node* head=NULL;

void add_employee(){
    system("cls");
    char choice;
    do{
        string name, position, address, email, phone;
        int age;
        Node* newNode=new Node;
        cout << "Enter employee name: ";
        cin >> name;
        newNode->name=name;
        cout << "Enter employee position: ";
        cin >> position;
        newNode->position=position;
        cout << "Enter employee age: ";
        cin >> age;
        newNode->age=age;
        cout << "Enter employee address: ";
        cin >> address;
        newNode->address=address;
        cout << "Enter employee email: ";
        cin >> email;
        newNode->email=email;
        cout << "Enter employee phone number: ";
        cin >> phone;
        newNode->phone=phone;

        newNode->next=head;
        head=newNode;

        cout << endl;
        cout << "do you want to continue (y/n): ";
        cin >> choice;
    }while(choice=='y');
    
}

void search(){
    system("cls");
    char choice;
    do{
        string name;
        cout << "Enter employee name: ";
        cin >> name;
        Node* temp=head;
        while (temp != NULL){
            if (temp->name==name){
                do{
                    cout << left << setw(20) << "Name" << setw(15) << "Position" << setw(5) << "Age" << setw(15) << "Address" << setw(20) << "Email" << setw(15) << "Phone" << endl;
                    cout << left << setw(20) << temp->name<< setw(15) << temp->position << setw(5) << temp->age << setw(15) << temp->address << setw(20) << temp->email << setw(15) << temp->phone << endl;
                    cout << "Do you want to do it again (y/n): ";
                    cin >> choice;
                }while(choice=='y');
                goto a;

            }
            temp=temp->next;
        }
        cout << "Employee not found!";
        a:
        cout << endl;
        cout << "Press m to return to menu: ";
        cin >> choice;
    }while(choice=='y');
    
}

void delete_employee(){
    system("cls");
    char choice;
    string name;
    cout << "Enter employee name: ";
    cin >> name;
    cout <<endl;
    if (head == NULL){
        cout << "List is empty!"<< endl;
        return;
    }
    Node* temp=head;
    if(temp->name==name){
        head=head->next;
        do{
            delete temp;
            cout << "Employee deleted successfully";
            cout << endl;
            cout << endl;
            cout << "press m to return to menu: ";
            cin >> choice;
        }while(choice=='#');
        return;
    }
    Node* prev=head;
    temp=head->next;
    while(temp !=NULL){
        if (temp->name==name){
            prev->next=temp->next;
             do{
                delete temp;
                cout << "Employee deleted successfully";
                cout << endl;
                cout << endl;
                cout << "press m to return to menu: ";
                cin >> choice;
            }while(choice=='#');
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout << "Employee not found!";

}

void display(){
    system("cls");
    char choice;
    do{
        if (head==NULL){
            do{
                cout << "The list is Empty!";
                cout << endl;
                cout << endl;
                cout << "press m to return to menu: ";
                cin >> choice;
            }while(choice=='#');
            cout << "The list is empty!";
            return;
        }
        cout << left << setw(20) << "Name" << setw(15) << "Position" << setw(5) << "Age" << setw(15) << "Address" << setw(20) << "Email" << setw(15) << "Phone" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << left << setw(20) << temp->name<< setw(15) << temp->position << setw(5) << temp->age << setw(15) << temp->address << setw(20) << temp->email << setw(15) << temp->phone << endl;
            temp = temp->next;
        }
        cout << endl;
        cout << "To return to menu press (m): ";
        cin >> choice;
    }while(choice=='#');
    
}

int main(){
    int a;
    a:
    while(true){
        system("cls");
        cout << "\t*****************************************\n";
        cout << "\t|     EMPLOYEE MANAGMMENT SYSTEM        |\n";
        cout << "\t|\t                                |\n";
        cout << "\t|\t1:Add employee                  |\n";
        cout << "\t|\t2:Search employee               |\n";
        cout << "\t|\t3:Delete employee               |\n";
        cout << "\t|\t4:Display                       |\n";
        cout << "\t|\t5:Exit                          |\n";
        cout << "\t*****************************************\n";
        cout << "\t\tEnter your choice here: ";
        cin>>a;
        switch(a){
            case 1:
                add_employee();
                break;
            case 2:
                search();
                break;
            case 3:
                delete_employee();
                break;
            case 4:
                display();
                break;
            case 5:
                return 1;
            default:
                goto a;
            
        }
    }
}
