// Developed by rupeshiya and team
#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include <winsock.h>
#include <mysql.h>
#include <typeinfo>
using namespace std;

// Global Variable
int qstate, previousQuantity = 0;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class Canteen
{
public:
    Canteen();
    void welcome();
    void show();
    void allItems();
    void soldItems();
    void addNewItem();
    void editItem();
    void deleteItem();
    void totalSale();
    void clearSoldItems();
    bool searchById(string);
    bool searchByName(string);
    bool checkQuantity(string,string);
    void addNewSale(string,string,string);

};

Canteen::Canteen()
{
    conn = mysql_init(0);
    if (conn)
    {
        cout << "Database Connected" << endl;
        cout << "Press any key to continue..." << endl;
        getchar();
        system("cls");
    }
    else {
        cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
    conn = mysql_real_connect(conn, "localhost", "root", "", "test3", 0, NULL, 0);//used test database to test
    if (conn)
    {
        cout << "Database Connected To MySql" << conn << endl;
        cout << "Press any key to continue..." << endl;
        getchar();
        system("cls");
    }
    else
        cout << "Failed To Connect!" << mysql_errno(conn) << endl;
}


void Canteen::welcome()
{
    //add some gui here
}
//function to add new items
void Canteen::addNewItem()   //completed in test database
{
    system("cls");

    string name;
    string quantity,price;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter quantity: ";
    cin>>quantity;
    cout<<"Enter price: ";
    cin>>price;

    string query = "insert into items (name, quantity ,price) values ('"+name+"','"+quantity+"','"+price+"')";

    const char* q = query.c_str();

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "New Item Added." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}


//function to add new sold items
void Canteen::addNewSale(string name, string quantity ,string price)  //completed test
{
    string query = "insert into sold (name, quantity ,price) values ('"+name+"','"+quantity+"','"+price+"')";

    const char* q = query.c_str();

    qstate = mysql_query(conn, q);
    int current = 0;

    if (!qstate)
    {
        cout << endl << "New Sale Item Added." << endl;
        stringstream geek1(quantity), ss;
        geek1 >> current;
        previousQuantity = previousQuantity - current;
        ss << previousQuantity;
        quantity = ss.str();
        string update_query = "update items set quantity = '"+quantity+"' ,price ='"+price+"' where name = '"+name+"'";
        q = update_query.c_str();

        qstate = mysql_query(conn, q);
        if(qstate)
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

//function to display all the items left
void Canteen::allItems() //completed test
{
    qstate = mysql_query(conn, "select * from items where quantity!=0");//changed for not to display quantity which has been sold

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("\n-------------------------------------------------------------\n");
        printf("| %-20s | %-10s | %-10s | %-10s | \n", "ID","Item Name", "Quantity" ,"Price");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-10s | %-10s | %-10s | \n", row[0], row[1], row[2] ,row[3]);
        }
        printf("---------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

//function to display all the sold items
void Canteen::soldItems() //completed test
{
    qstate = mysql_query(conn, "select * from sold where quantity!=0");

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("\n-----------------------------------------------------------\n");
        printf("| %-20s | %-10s | %-10s | %-10s |\n", "ID","Item Name", "Quantity", "Price");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-20s | %-10s | %-10s | %-10s |\n", row[0], row[1], row[2] ,row[3]);
        }
        printf("--------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
}

//function to search for a item using ID in database
bool Canteen::searchById(string id) //completed test
{
    string query = "SELECT id FROM items";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    bool found = false;

    if(!qstate)
    {
        while ((row = mysql_fetch_row(res)))
        {
            if(row[0] == id)
            {
                found = true;
                break;
            }
        }
    }

    return found;
}

//function to search item by name in database
bool Canteen::searchByName(string name) // completed test
{
    string query = "SELECT name FROM items";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    bool found = false;

    if(!qstate)
    {
        while ((row = mysql_fetch_row(res)))
        {
            if(row[1] == name)
            {
                found = true;
                break;
            }
        }
    }

    return found;
}

//function to check the quantity and items in database
bool Canteen::checkQuantity(string item, string quantity)  //completed test
{
    string query = "SELECT * FROM items where name = '"+item+"'";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    int rows, n;

    bool found = false;

    if(!qstate)
    {
        while ((row = mysql_fetch_row(res)))
        {
            stringstream geek1(row[2]);
            geek1 >> rows;
            stringstream geek2(quantity);
            geek2 >> n;

            if(n <= rows)
            {
                found = true;
                previousQuantity = rows;
                break;
            }
        }
    }

    return found;
}


//function to update the item details in database
void Canteen::editItem()  //completed test
{
    system("cls");
    Canteen::allItems();

    string id;
    cout<<"Enter item Id to edit: ";
    cin>>id;

    bool found = searchById(id);

    if(found)
    {

        string query = "select * from items where id = '"+id+"'";
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if(!qstate)
        {
            res = mysql_store_result(conn);
            row =mysql_fetch_row(res);
            cout<<"Name "<<row[1]<<" Quantity "<<row[2]<<" with ID "<<row[0];
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        string name, quantity ,price;
        cout<<"\n\nEnter new name: ";
        cin>>name;
        cout<<"Enter new quantity: ";
        cin>>quantity;
        cout<<"\n\nEnter new price: ";
        cin>>price;

        string update_query = "update items set name = '"+name+"', quantity = '"+quantity+"' ,price = '"+price+"' where id = '"+id+"'";

        q = update_query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            cout << endl << "Successfully Updated In Database." << endl;
        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }
    }
    else
    {
        cout << "Please Enter a valid ID." << endl;
    }
}

//function to delete the item from database
void Canteen::deleteItem()  //completed test
{
    Canteen::allItems();

    string id;
    cout<<"Enter item Id to delete: ";
    cin>>id;

    bool found = false;

    string query = "SELECT id FROM items";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    if(!qstate)
    {
        while ((row = mysql_fetch_row(res)))
        {
            if(row[0] == id)
            {
                found = true;
                break;
            }
        }
    }

    if(found)
    {
        query = "delete from items where id = '"+id+"'";
        q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            cout << "Successfully Deleted From Item Record." << endl;
        }
        else
        {
            cout << "Failed To Delete!" << mysql_errno(conn) << endl;
        }
    }
    else
    {
        cout << "Please Enter a valid ID." << endl;
    }
}

//function to clear the sold items data
void Canteen:: clearSoldItems()
{
    string query = "TRUNCATE TABLE sold";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);

    if (!qstate)
    {
        cout << endl << "Successfully cleared the sold items list." << endl;
    }
    else
    {
        cout << "Failed to clear the sold items list" << mysql_errno(conn) << endl;
    }

}
//function to calculate total sale
void Canteen::totalSale()
{
    string query = "SELECT FORMAT(SUM(quantity * price), 2) total FROM sold";
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    res = mysql_store_result(conn);
    double num_fields = mysql_num_fields(res);

    if (!qstate)
    {
        //cout << endl << "Successfully calculated the total sale" <<num_fields<<endl;
        while ((row = mysql_fetch_row(res)))
        {
            for(int i = 0; i < num_fields; i++)
            {
                cout<<"Total sale : Rs "<<row[i]<<"\n";
            }
        }
    }
    else
    {
        cout << "Failed to calculate the total sale " << mysql_errno(conn) << endl;
    }
}

//function to display all the options
void Canteen::show()  //completed test
{
    cout << "\nCanteen Management System" << "\n\n";

    cout << "1.New Customer" << endl;
    cout << "2.All Items" << endl;
    cout << "3.Sold Items" << endl;
    cout << "4.Add New Item" << endl;
    cout << "5.Edit Item" << endl;
    cout << "6.Delete Item" << endl;
    cout << "7.Total Sale" <<endl;
    cout << "8.Clear sold Items List" << endl;
    cout << "9.Exit" << endl;
    cout<<"Enter your choice: ";
}

int main()
{
    system("cls");
    system("title Canteen Management Program");
    system("mode con: cols=140 lines=30");
    system("color 0f");
    Canteen canteen;

    int choice;
    string name;
    //canteen.welcome();
//again:
    //canteen.show(); // cahnged

    while(1)  //made it infinite loop
    {
        canteen.show();
        cin>>choice;
    if(choice == 1)
    {
        cout<<"Enter Customer name: ";
        cin>>name;
        cout<<endl;
        canteen.allItems();
        cout<<endl;
        mm:
        cout<<"\nBuy any item from above given table. Enter Name of the item: ";
        string item, quantity ,price;
        cin>>item;
        if(canteen.searchByName(item))
        {
            cout<<"This item is not present";
            goto mm;
        }

        cout<<"\nEnter quantity of the item: ";
        cin>>quantity;
        cout<<"\nEnter the price of the item : ";
        cin>>price;
        if(canteen.checkQuantity(item, quantity))
        {
            canteen.addNewSale(item, quantity ,price);
            //goto again;
        }
        else
        {
            cout<<quantity<<" Item is not present in canteen. Please try again"<<endl;
            //goto mn;
        }
    }
    else if(choice == 2)
    {
        canteen.allItems();
        //goto again;
    }
    else if(choice == 3)
    {
        canteen.soldItems();
       // goto again;
    }
    else if(choice == 4)
    {
        canteen.addNewItem();
        //goto again;
    }
    else if(choice == 5)
    {
        canteen.editItem();
        //goto again;
    }
    else if(choice == 6)
    {
        canteen.deleteItem();
        //goto again;
    }
    else if(choice == 7)
    {
        canteen.totalSale();
    }
    else if(choice == 8)
    {
        canteen.clearSoldItems();
    }
    else if(choice == 9)
    {
        exit(0);
    }
    else
    {
        cout<<"Invalid choice !! , Please enter a valid choice"<<endl;
    }
    }
    return 0;
}
