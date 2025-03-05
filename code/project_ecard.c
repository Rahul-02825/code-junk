#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <bits/stdc++.h>
#include <cstring>
#include <map>
using namespace std ;
class OrderDetails
{
public:
    void ShowMenu( );
    void ShowMobileMenu( );
    void ShowLaptopMenu( ) ;
    void ShowComputerCourseMenu( );
};
// menu to the user
void OrderDetails::ShowMenu()
{
    cout << "Menu\n";
    cout << "=  =  =  =  =  =  =  = "
         << " =  =  =  =  = \n";
    cout << "1.Mobile\n2.laptop\n3"
         << ".Computer courses\n";
    cout << "=  =  =  =  =  =  =  = "
         << " =  =  =  =  = \n";
}

// Function to display the mobile products
void OrderDetails::ShowMobileMenu()
{

    cout <<"- - - - - - - - - - - - -\nItem Cost\n";
    cout <<"1.Samsung  Rs.15, 000/-\n";
    cout <<"2.Redmi    Rs.12, 000/-\n";
    cout <<"3.Apple    Rs.1, 00, 000/-\n";
    cout <<"- - - - - - - - - - - - -\n";
}

// Function to display Laptop products
void OrderDetails::ShowLaptopMenu()
{
    cout << "- - - - - - - - - - -"
         << " - -\nItem       Cost\n";
    cout << "1.Macbook  Rs.2, 00, 000/-\n";
    cout << "2.HP       Rs.40, 000/-\n";
    cout << "3.Lenovo   Rs.35, 000/-\n";
    cout << "- - - - - - - - - - - - -\n";
}

// if the user selects computer couses,
// then courses list will be displayed
void OrderDetails::ShowComputerCourseMenu()
{
    cout << "- - - - - - - - - - "
         << " - -\nItem       Cost\n";
    cout << "1.C        Rs.1, 000/-\n";
    cout << "2.C++      Rs.3, 000/-\n";
    cout << "3.Java     Rs.4, 000/-\n";
    cout << "4.Python   Rs.3, 500/-\n";
    cout << "- - - - - - - - - - - - -\n";
}


class Delivery // class delivery
{
    int PinCode ;
public :
    char ShippingType ;
    int days ;
    int ShippingCost ;
    void DeliveryReqirments( );
};

void Delivery:: DeliveryReqirments( )
{
    cout<<"\n\n*******************PROCEED FILLING THE DELEVERY REQUIRMENTS**********************\n";
    cout<<"Enter the pincode : ";
    cin>>PinCode ;
    cout<<"enter the preferred shipping type P-Premium // N-normal [ P / N ] ";
    cin>>ShippingType ;
    if(ShippingType=='p'||ShippingType=='P')
    {
        ShippingCost=200 ;
        days = 2 ;
    }
    else if(ShippingType=='n'||ShippingType=='N')
    {
        ShippingCost=100 ;
        days = 5 ;
    }
    cout<<"THE ORDER WILL BE DELIVIRED TO "<<PinCode<<" WITHIN "<<days<<" DAYS "<<endl ;
    cout<<"THE SHIPPING COST IS : rupees"<<ShippingCost<<endl;
}

class Cart // class cart
{
private :

    map<string, double> items ;
    map<string, int> selected_items;
public:
    float TotalAmount ;
    Cart( )
    {
        TotalAmount = 0 ;
    }
    void PrintBill( );
};
//price
map<string, double> items = {
    { "Samsung", 15000 },
    { "Redmi", 12000 },
    { "Apple", 100000 },
    { "Macbook", 250000 },
    { "HP", 40000 },
    { "Lenovo", 35000 },
    { "C", 1000 },
    { "C++", 3000 },
    { "Java", 4000 },
    { "Python", 3500 }
};

// Stores the selected items with
// their quantity
map<string, int> selected_items;

// Function to print the bill after shopping

void Cart:: PrintBill( )
{
    for (auto j = selected_items.begin();
         j != selected_items.end(); j++) {
        cout << j->first << "        ";
        cout << j->second << "          ";
        cout << (selected_items[j->first])
                    * (items[j->first])
             << endl;
    }

    cout << "-----------------------"
         << "-------------\n";
    cout << "Total amount:             "
         << TotalAmount << endl;
    cout << "-----------------------"
         << "-------------\n";
    cout << "*****THANK YOU && HAPPY"
         << " ONLINE SHOPPING*****";
}



int flag=0 ;
char  confirm_quantity;

class Order // class order
{
private :
    Delivery D ;
    Cart C ;
    OrderDetails OD ;
    float quantity;
    int ObjectId;
    Ordrer( )
    {
        quantity = 0 ;
        ObjectId = 0 ;

}
public:
    void PlaceOrder( );
    void SelectedMobile( );
    void SelectedLaptop( );
    void SelectedCourses( );
};




// If computer course
// category is selected
void Order::SelectedCourses()
{
    char c1 ;
    cout << "Do you wish to continue?"
         << "(for yes press (Y/y ), "
         << " if no press other letter ): ";
    cin >> c1;
    if (c1 == 'Y' || c1 == 'y') {
        cout << "Enter the respective object ID [ 1 / 2 / 3 ]: ";
        cin >> ObjectId;
        if (ObjectId == 1
            || ObjectId == 2
            || ObjectId == 3
            || ObjectId== 4) {

            // selected C
            if (ObjectId == 1) {
                cout << "selected C Language"
                     << " course\n";
                C.TotalAmount += items["C"];
                selected_items["C"]++;
                cout << "amount  =  "
                     << C.TotalAmount
                     << endl;
            }

            // selected C++
            if (ObjectId == 2) {
                cout << "selected C++ Language course\n";
                C.TotalAmount += items["C++"];
                selected_items["C++"]++;
                cout << "amount  =  " << C.TotalAmount << endl;
            }

            // selected Java
            if (ObjectId == 3) {
                cout << "selected Java Language course\n";
                C.TotalAmount += items["Java"];
                selected_items["Java"]++;
                cout << "amount  =  " << C.TotalAmount << endl;
            }

            // selected python
            if (ObjectId == 4) {
                cout << "selected Python"
                     << " Language course\n";
                C.TotalAmount += items["Python"];
                selected_items["Python"]++;
                cout << "amount  =  "
                     << C.TotalAmount
                     << endl;
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}




void Order::SelectedLaptop()
{
    char c1 ;
    cout << "Do you wish to continue?"
         << "(for yes press (Y/y ), "
         << "if no press other letter): ";
    cin >> c1;
    if (c1 == 'Y' || c1 == 'y') {

        cout << "Enter respective Object ID [1 / 3 / 4 ]: ";
        cin >> ObjectId;

        if (ObjectId== 1
            || ObjectId== 2
            || ObjectId == 3) {

            // selected Macbook
            if (ObjectId == 1) {
                cout << "selected Macbook\n";
                do {

                    cout << "Quantity: ";
                    cin >> quantity;

                    cout << "You have selected"
                         << " Macbook - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    C.TotalAmount += quantity
                                    * items["Macbook"];
                    selected_items["Macbook"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount
                         << endl;
                }
            }

            // selected HP
            if (ObjectId == 2) {
                cout << "selected HP\n";
                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selected"
                         << " HP - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity
                              != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    C.TotalAmount += quantity
                                    * items["HP"];
                    selected_items["HP"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount
                         << endl;
                }
            }

            // selected Lenovo
            if (ObjectId== 3) {
                cout << "selected Lenovo\n";
                do {

                    cout << "Quantity: ";
                    cin >> quantity;

                    cout << "You have selected"
                            " Lenovo - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << "if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    C.TotalAmount += quantity
                                    * items["Lenovo"];
                    selected_items["Lenovo"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount
                         << endl;
                }
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}





void Order:: SelectedMobile()
{
    char c1 ;
    int flag ;
    cout << "Do you wish to continue?(for yes press (Y/y ),if no press other letter ):";
    cin >> c1;

    if (c1 == 'Y' || c1 == 'y') {
        cout << "Enter respective object ID [1/ 2 / 3 ]: ";
        cin >> ObjectId;

        if ( ObjectId== 1
            || ObjectId == 2
            || ObjectId == 3) {

            // Selected Samsung
            if (ObjectId == 1) {

                cout << "selected Samsung\n";
                do {
                    cout << "Quantity: ";

                    cin >> quantity;

                    cout << "You have selected Samsung - "
                         << quantity << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y ), "
                         << " if no press other letter): ";

                    cin >> confirm_quantity;

                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity) != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    C.TotalAmount += quantity
                                    * items["Samsung"];
                    selected_items["Samsung"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount << endl;
                }
            }

            // Selected Redmi
            if (ObjectId == 2) {

                cout << "selected Redmi\n";

                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selec"
                         << "ted Redmi - "
                         << quantity << endl;
                    cout << "Are you sure?(f"
                         << "or yes press (Y/y ), "
                         << " if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {

                    C.TotalAmount += quantity
                                    * items["Redmi"];
                    selected_items["Redmi"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount << endl;
                }
            }

            // Selected Apple
            if (ObjectId == 3) {

                cout << "You have selected Apple\n";

                do {
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "You have selected"
                         << " Apple - "
                         << quantity
                         << endl;
                    cout << "Are you sure?"
                         << "(for yes press (Y/y )"
                         << ", if no press other letter ): ";
                    cin >> confirm_quantity;
                } while ((confirm_quantity != 'y'
                          && confirm_quantity != 'Y')
                         || (quantity < 0)
                         || (ceil(quantity)
                             != floor(quantity)));

                if (confirm_quantity == 'y'
                    || confirm_quantity == 'Y') {
                    C.TotalAmount += quantity
                                    * items["Apple"];
                    selected_items["Apple"] = quantity;
                    cout << "amount  =  "
                         << C.TotalAmount
                         << endl;
                }
            }
        }
        else {
            flag = 1;
        }
    }
    else {
        flag = 1;
    }
}




void Order::PlaceOrder( )
{
     do {
        OD.ShowMenu();
        cout << "Do you wish to continue?"
             << "(for yes press (Y/y ), "
             << " if no press other letter ): ";
        char c;
        cin >> c;
        if (c == 'Y' || c == 'y') {
            cout << "Enter respective number: ";
            int num;
            cin >> num;
            if (num == 1 || num == 2
                || num == 3) {
                switch (num) {
                case 1:

                    // For Mobile
                    OD.ShowMobileMenu();
                    SelectedMobile();
                    break;

                case 2:

                    // For Laptop
                    OD.ShowLaptopMenu();
                    SelectedLaptop();
                    break;

                case 3:

                    // For computer course
                    OD.ShowComputerCourseMenu();
                    SelectedCourses();
                    break;
                }
            }
            else {
                flag = 1;
            }
        }
        else {
            flag = 1;
        }

    } while (flag == 0);
    C.PrintBill( ) ;
    D.DeliveryReqirments( );

}

class User : public Order
{
private:
   string password ;
   string UserId;
public:
   void Login();
   void Register();
   void Menu( );
   User( )
   {
       UserId = " " ;
       password = " " ;
   }

};

void User::Menu( )
{
    User u1 ;
        int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.LOGIN "<<endl;
        cout<<"2.REGISTER  (if you are a new user ) "<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        u1.Login();
                        break;
                case 2:
                        u1.Register();
                        break;

                case 3:

                        cout<<"exiting the program \n";
                        break;
                default:
                        system("cls");
                        cout<<" try again\n"<<endl;

        }

}

void User::Login()
{
        int count;
        string UserId,password,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>UserId;
        cout<<"PASSWORD :";
        cin>>password;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==UserId && p==password)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<UserId<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                cout<<"\n \n PROCEED TO PLACING YOUR ORDER \n \n ";
                PlaceOrder( );
                cin.get();
                cin.get();

        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";

        }

}

void User::Register()
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        cout<<"\n \n PROCEED TO PLACING YOUR ORDER \n \n ";
        PlaceOrder( );


}

int main( )
{
    User u2 ;
    u2.Menu( );
}



