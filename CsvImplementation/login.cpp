#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<vector>
using namespace std;
template <typename T>
T get_input(const string &strQuery);

string get_username();
string get_password();
vector<string>V1(300);
vector<string>V2(360);

void save_user(const string &username, const string &password);

void login();
void register_user();
void main_menu();

int main()
{
    main_menu();
    for(int j = 0; j < V1.size(); j++)
        {

            cout<<V1[j]<<" "<<V2[j]<<" ";
        }
}

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();

    while (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << "Error!" "\n";
        cout << strQuery << "\n> ";
    }

    return out;
}

string get_password()
{
    string password1 = get_input <string> ("Please enter your password.");
    string password2 = get_input <string> ("Please re-enter your password.");

    while (password1 != password2) {
        cout << "Error! Passwords do not match." "\n";
        password1 = get_input <string>("Please enter your password.");
        password2 = get_input <string>("Please re-enter your password.");
    }

    return password1;
}

string get_username()
{
    string username = get_input <string>("Please enter a username.");
    cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("Confirm? [0|1]") != 1) {
        username = get_input <string>("Please enter a username.");
        cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

void login()
{
    string username2 = get_input <string>("Please enter a username.");
    cout << "Username: \"" << username2 << "\"\n";

    while (get_input <int>("Confirm? [0|1]") != 1) {
        username2 = get_input <string>("Please enter a username.");
        cout << "Username: \"" << username2 << "\"\n";
    }
    //string password1 = get_input <string> ("Please enter your password.");
    string password2 = get_input <string> ("Please enter your password.");
    //return password1;
    ifstream file;
    file.open("login.csv");
    if(V1.size()>0 && V2.size()>0)
    {
        //getline(file,username2,'\n');
        //cout<<username2<< " ";
        for(int j = 0; j < V1.size(); j++)
        {
            if(V1[j].find(username2) != std::string::npos && V2[j].find(password2) != std::string::npos)
            {
                cout<<"Successfully login"<<endl;
                break;
            }
            cout<<V1[j]<<" "<<V2[j]<<" ";
        }

    }
}


void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
}

void save_user(const string &username, const string &password)
{
   // string filename = username + ".txt";
   int i =0;
    ofstream file;
    file.open("login.csv",ofstream::out | ofstream::app);
    //ofstream file(filename);
        V1[i] = {username};
        V2[i] = {password};

    cout<<V1[i]<<" "<<V2[i]<<" "<<endl;
    file << V1[i] <<"\n";
    file << V2[i] << "\n";
    i++;
}
void main_menu()
{
    int choice = get_input <int>(
        "Hello, Would you like to log in or register?" "\n"
        "[1] Login" "\n"
        "[2] Register" "\n"
        "[3] Exit");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    }
}
