
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;
int obn,prnt_once=0,ar[100][100][100][12][18],hall_no,hall_no_cus;
int dir_customer=0;
//dir_customer=0 if the user directly goes to user instead of manager
//obn is the storing the selected number of the movie hall
string ticket_save,*h;
class key
{
public:
void hall_select();
void hall_print();
};


class movie_booking:public key
{

public:
    movie_booking()
    {
        (*this).first();
    }
    int ext;
//prnt_once to print once the term user foun
int m=0,*p,sn,arg,arg2,tkt,tkt_pr,nt=0,sti,foundu=0,foundp=0,pas_chk=0,mv_str=0,data_store=0;
double cost=0;
//data_store=0 TO STORE THAT THE DATA IS SUCCESSFULLY STORED IN FILE
//mv_str=0 to run the loop when data is being brought from file to compiler
int  pas_rak=0;//to store the return value of function password_check()
//sn is variable for show number in manager function N m is for number of shows in a day
//pas_chk stores the value i.e password matched or not
//foundu to storevalue if user exists
//foundo to storevalue if password is correct
char cus_in;
//cus_in is for storing if customer is new or existing
//sti is for showtime input in manager func
//st is for showtime check the seat_disp func
//tkt is to count the no.of tickets to be booked by customer
//tkt_pr is to print the no.of tickets to be booked
//nt is the number of timings of a particular movie
string name[100],tkt_pnt,pass,cus_id,cus_pas,user,hall_name;//pass is to save the password
//hall_name to store the hall name
//cus_id for storing customer id
//cus_pas is for storing customer password
//tkt_pnt[100] to print the movie name in ticket
int tkt_row[12],tkt_col[18],str_tim[100];//last two array r to be used to print ticket
//str_tim is saving the no.of show of a particular movie
/*in the array ar
1st arg is for movie no.
2nd arg is for particular showtime of particular movie
3rd arg is for rows
4th arg is for columns*/
string tim[100][100];
/*ITS THE string array to store the timings of a particular movie
1st argument is for movie number and and argument is for no.timings that
particular runs*/
string timing[100];//to store various timings of movie in file
    void first();
    void show_seat_frm_file();
    void show();
    void show(int z,int wt);
    void book(int z,int wt ,int a);
    void seatin(int z,int wt);
    void manager();
    void ticket_print();
    void pass_proctect();
    void data_str();
    int password_check();
    void hal_name();

};


void key::hall_select()
{
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF MOVIE HALLS IN UR AREA\n";
    cin>>hall_no;
    h=new string[hall_no];
    string mov_halname[hall_no],*p;
    p=h;
    for(int i=0;i<hall_no;i++)
    {
        cout<<"\n\n\t\t\t\t\t\t\tEnter the movie hall name:\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>mov_halname[i];
        (*p)=mov_halname[i];
        p++;
    }

(*this).hall_print();
}
void key::hall_print()
{
system("cls");
string *p;
p=h;
if(dir_customer!=0)
{
   cout<<"THE MOVIE HALLS IN BHUBANESWAR ARE:\n";
for(int i=0;i<hall_no;i++)
    {
        cout<<(*p)<<endl;
        p++;
    }
    cout<<"CHOOSE THE MOVIE HALL\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>obn;
}

else
{
        cout<<"\n\n\t\t\t\t\t\t\t PRESS 1 TO BOOK TICKET IN INOX BHUBANESWAR";
    cout<<"\n\n\t\t\t\t\t\t\t PRESS 2 TO BOOK TICKET IN CINEPOLIS BHUBANESWAR";
    cout<<"\n\n\t\t\t\t\t\t\t PRESS 3 TO BOOK TICKET IN KESHARI TALKIES ";
    cout<<"\n\n\t\t\t\t\t\t\t PRESS 4 TO BOOK TICKET IN MAHARAJA";
    cout<<"\n\n\t\t\t\t\t\t\t ";
    cin>>obn;

}
}

void movie_booking::first()
{
    int i;
    char in='c',ind,cus;//cus is customer and ind is manager input
    cout<<"\n\n\t\t\t\t\tTO ENTER MANAGER LOGIN PRESS 'o' or 'O' ELSE ANY OTHER KEY FOR CUSTOMER BOOKING\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>ind;
    int pas_count=0;
   if((ind=='o')||(ind=='O'))
    {
        while(pas_count<3)
        {
            (*this).pass_proctect();
        if(pass=="KASAW")
        {    dir_customer++;
            (*this).hall_select();
            (*this).manager();//the manager mode to set the number of seats available for booking
            pas_count=3;
        }

        else
        {
        cout<<"PASSWORD ENTERED IS WRONG!!"<<" ATTEMPTS REMAINING = "<<2-pas_count<<" \n";//pas_count is to count no. of attempts left
            pas_count++;
        }

    }
    }

    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\tDEAR CUSTOMER TO BOOK SEATS PRESS 'y' or 'Y' \n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>cus;
    //HERE I HAVE TO ADD THE CUSTOMER LOGIN FUNCTION
     if((cus=='y')||(cus=='Y'))//the customer part starts here
     {  cout<<"\n\t\t\t\t\t\t\tIF YOU ARE NEW CUSTOMER PRESS N/n TO SIGNUP\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>cus_in;
        if(cus_in=='N'||cus_in=='n')
        (*this).data_str();
        else
        {
            cout<<"\n\t\t\t\t\t\t\tWELCOME EXISTING CUSTOMER!!!\n";
           pas_rak=(*this).password_check();

        }

//cout<<"+++++++++++"<<pas_rak<<"--------"<<data_store<<endl;to check the values
        cout<<"\t\t\t\t\t\t\t";
        cout<<"PRESS ANYKEY TO CONTINUE\n";
getch();
         if(pas_rak!=0||data_store!=0)
         { (*this).hall_print();

          cout<<"\n\n\t\t\t\t\t\tTHE SEATS AVAILABLE ARE:\n";
                 while((in=='c')||(in=='C'))
    {
        cost=0;
       (*this).show_seat_frm_file();
            cout<<"\n\n\t\t\t\t\t\t\tENTER THE MOVIE NUMBER TO BOOK TICKET\n";
            cout<<"\t\t\t\t\t\t\t";
            cin>>arg;
            ofstream seat_save;
            seat_save.open("seat_saving.csv",ios::app);
            ticket_save=arg;
            seat_save<<ticket_save<<",";
            ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
    fin.close();
             cout<<"\n\n\t\t\t\t\t\t\tCHOOSE THE NUMBER CORRENSPONDING TO TIMING TO BOOK TICKET FOR MOVIE :-"<<endl;

            cout<<"\t\t\t\t\t\t\t"<<name[i];


            cout<<"\t\t\t\t\t\t\t";

            cin>>sti;

             seat_save<<sti<<",";
            tkt_pnt=name[i];
            (int)sti;

               // cout<<"THE ARGUMENT IS ="<<arg<<endl;
            (*this).show(arg,sti);
            (*this).seatin(arg,sti);
            system("cls");
            (*this).show(arg,sti);
            /*HERE ANOTHER FUNCTION IS TO BE WRITTEN TO PRINT THE TICKETS*/
            system("cls");

            (*this).ticket_print();
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO BOOK SEAT AGAIN?\n";
    cin>>in;



    }
         }

else{cout<<"\n\n\t\t\t\t\t\t\t YOU PRESSED WRONG USER PASSWORD\n";
    cout<<"\n\n\t\t\t\t\t\t\t PROGRAM TERMINATED!!!\n";
        cout<<"\n\n\t\t\t\t\t\t\t YOU ENTERED WRONG PASSWORD";}

     }
}

void movie_booking::show_seat_frm_file()
{int i=0,j;
    system("cls");//after the input is being over the screen is cleared and data is displayed
cout<<"\n\n\t\t\t\t\t\t\tTHE MOVIES RUNNING IN HALL ARE:\n\n\n";
ifstream fin;
fin.open("movie_test2.csv");
if(dir_customer==0)
    m=13;
while(i<m)
{
     cout<<"\n\t\t\t\t\t\t\t";

    getline(fin,name[i],',');
    cout<<"MOVIE :\t"<<i+1<<"\t"<<name[i]<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"THE TIMINGS OF THE MOVIE : "<<name[i]<<" :-  "<<endl;
    int j=0;

   getline(fin,tim[i][j],'\n');
        cout<<"\t\t\t\t\t\t\t";
        cout<<tim[i][j]<<endl<<endl;

i++;//to access the different movie names
}

}
void movie_booking::show()//this function is for entering the number of movie running in hall
{
    int i,j;
    p=(int*)(malloc(sizeof(int)));
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER MOVIES RUNNING IN THE HALL\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>m;
    (*p)=m;
     ofstream fout;
    fout.open("movie_test2.csv",ios::app);
for(i=0;i<m;i++)//m is the total no of movies running in that hall
{   fflush(stdin);
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NAME OF MOVIE "<<i+1<<endl;
    cout<<"\t\t\t\t\t\t\t";
    getline(cin,name[i]);
    fflush(stdin);
    fout<<name[i]<<",";//movie name writing in file
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SHOWS OF MOVIE: "<<name[i]<<" IN A DAY : ";
    cin>>nt;
    str_tim[i]=nt;
    //here a function is to be added to save the show timings
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE SHOW TIMINGS OF THE MOVIE : "<<name[i]<<endl;
    for(j=0;j<nt;j++)
    {   fflush(stdin);
         cout<<"\t\t\t\t\t\t\t";
        getline(cin,tim[i][j]);// this is the function for collecting the show timings
        fout<<tim[i][j]<<",";

    }
    fout<<endl;

}
 fout.close();
 //FILE HANDLING 100% CORRECT TILL HERE
 m=m+13;//as already is csv file there 13 movies
(*this).show_seat_frm_file();
}


void movie_booking::show(int z,int wt)
//1st argument to display the seats of that particular movie
//2nd arg is for the particular movie time
{
    arg=z;
    sti=wt;
    int i,j;
    char ch='A',st;
    system("cls");
    cout<<"\n\nCOST OF RECTILINEAR:Rs 500/-\n";
      cout<<"COST OF SUPER DELUXE :Rs 200/-\n";
    cout<<"COST OF  DELUXE :Rs 100/-\n";
ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");
   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
   cout<<"\n\n\t\t\t\t\t\t\tTHIS IS THE SEAT MATRIX FOR MOVIE: "<<name[i]<<"\n\n";
    fin.close();
    for(i=0;i<13;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";
     for(j=0;j<18;j++)
        {
            if(ar[obn][arg][sti][i][j]==1)
            cout<<"["<<" X"<<"]";
            else
            {
                cout<<"["<<ch<<j+1<<"]";
            }

            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]

            if(j==4||j==12)
                cout<<"\t";

        }
        cout<<"\n\n";
 if(i==12)
    {
        cout<<"\n\n\t\t\t\t\t\t SCREEN THIS WAY\n";
        cout<<"\t______________________________________________________________________________________________________________";
    }

    }

}




void movie_booking::book(int z,int wt ,int a)//first argument is for the movie number and 3rd argument for manager mode
//2nd arg is for show time
{int i,j,num,al,n,col,stor,arg;
arg=z;
sti=wt;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\n\n\t\t\t\t\t\t\tADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\n\n\t\t\t\t\t\t\tCUSTOMER BOOKING\n";
}

        (*this).show(arg,sti);
    char ch='A',chr;
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE SEAT NUMBER\t";

        cin>>chr>>col;
        stor=chr-65;
        col=col-1;

        if(ar[obn][arg][sti][stor][col]==0)
        {
            ar[obn][arg][sti][stor][col]=1;

            tkt_col[tkt]=col;
            tkt_row[tkt]=stor;


        }
        else
        {

            while(ar[obn][arg][sti][stor][col]!=0)
            {
                if(arg2==100)
                {
                  cout<<"\n\n\t\t\t\t\t\t\tADMIN YOU HAVE ALREADY MARKED THIS SEAT AS BOOKED ENTER A NEW SEAT WHICH IS BOOKED\n";
               cout<<"\t\t\t\t\t\t\t ";
                }

           else
           {
            cout<<"\n\n\t\t\t\t\t\t\tTHE SEAT YOU SELECTED IS ALREADY OCCUPIED ENTER A NEW SEAT\n";
            cout<<"\t\t\t\t\t\t\t ";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[obn][arg][sti][stor][col]=1;
           tkt_col[tkt]=col;
            tkt_row[tkt]=stor;
        }

}

void movie_booking::seatin(int z,int wt)//1st argument for the particular movie seat booking
//2nd arg is for particular show time of particular movie
{

     int n,i;
    arg=z;
    sti=wt;
    //cout<<"THE ARGUMENT IS nest="<<arg<<endl;
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SEATS TO BE BOOKED"<<endl;
     ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");
   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');

            cout<<"\t\t\t\t\t\t\t MOVIE NAME="<<name[i]<<endl;
           fin.close();
            cout<<"\t\t\t\t\t\t\t ";
    cin>>n;
    tkt_pr=n;
       for(tkt=0;tkt<n;tkt++)//loop for booking the desired no. of tickets as input by user
{
     (*this).book(arg,sti,20);
     cout<<"LOOP IS RUNNING\n";
       system("cls");
  (*this).show(arg,sti);

}
cout<<"\n\n\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE\n";
getch();

}




void movie_booking::manager()
{   char mov='c',in='c';
    (*this).show();
    while((mov=='c')||(mov=='C'))//this loop is for entering the seats that are booked for different movies
    {
        cout<<"\n\n\t\t\t\t\t\t\t ENTER THE SHOW NUMBER WHOSE SEATS U WANT TO ASSIGN FOR BOOKING\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sn;
      cout<<"\n\n\t\t\t\t\t\t\t ENTER THE NUMBER CORRESPONDING TO THE TIME TO BOOK TICKET\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sti;
    tkt_pnt=name[sn];

    while((in=='c')||(in=='C'))
    {
      (*this).book(sn,sti,100);
      system("cls");
      (*this).show(sn,sti);
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING THE BOOKED SEATS\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>in;
    }

    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING FOR OTHER MOVIES\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>mov;
    in='c';
    }
    mv_str++;

}
 void movie_booking::hal_name()
    {
        switch(obn)
        {
            case 1:
            hall_name="INOX BHUBANESWAR";
            break;
             case 2:
            hall_name="CINEPOLIS BHUBANESWAR";
            break;
             case 3:
            hall_name="KESHARI TALKIES";
            break;
             case 4:
            hall_name="MAHARAJA";
            break;
        }

    }

void movie_booking::ticket_print()
{    int i,a=0,b=0,d=0;
    char c;
    string time;//time to store the movie timing

    for(i=0;i<tkt_pr;i++)//this loop is for printing the total cost of ticket
        {


             if(tkt_row[i]==0||tkt_row[i]==1)
            {
                cost=cost+500;
                a++;
            }
            else if(tkt_row[i]>1&&tkt_row[i]<7)
            {
                cost=cost+200;
                b++;
            }
            else{cost=cost+100;d++;}


        }
           cout<<"\n\n\n\t\t\tCOST : "<<endl;
           if(a!=0)
           cout<<"\t\t\t       "<<a<<" * 500"<<endl;
           if(b!=0)
           cout<<"\t\t\t      +"<<b<<" * 200"<<endl;
           if(c!=0)
           cout<<"\t\t\t      +"<<d<<" * 100"<<endl;
       cout<<"GST 18% = "<<cost*0.18<<endl;
       cost=cost+cost*(0.18);
        cout<<"\n\n\n\n\t\t\tTHE TOTAL TICKET COST = Rs "<<cost<<"/-"<<endl;
        cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
        getch();

         system("cls");
  //HERE ISTHE HALL NAME PRINTING PART
if(dir_customer==0)
    (*this).hal_name();
    else
    {
        string *p;
p=h;
 cout<<"THE MOVIE HALLS IN BHUBANESWAR ARE:\n";
for(i=0;i<obn-1;i++)
    {
        p++;
    }
hall_name=(*p);
    }

                 ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');

         for(int j=0;j<sti;j++)
   {
    getline(fin,time,',');
   }
   fin.close();

    cout<<"\n\n\n\n\t\t\t________________________________________________________________________\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|   Dear Customer,                                                      |\n";
cout<<"\t\t\t|                      Congratulation!! Your tickets has been booked.   |\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|                  THE DETAILS:                                         |\n";
cout<<"\t\t\t|                            MOVIE HALL: "<<hall_name<<"                 \n";
cout<<"\t\t\t|                            MOVIE NAME: "<<name[i]<<"                                 \n";
cout<<"\t\t\t|                            SHOW STARTS:"<<time<<"                        \n";
cout<<"\t\t\t|                            NUMBER OF TICKETS BOOKED: "<<tkt_pr<<"                |\n";
cout<<"\t\t\t|                 THE SEAT NUMBERS ARE: ";for(i=0;i<tkt_pr;i++)
                                            {   c=tkt_row[i]+65;
                                                cout<<c<<tkt_col[i]+1;//PLS CHECK WHY I HV WRITTEN HERE +
                                                if(i<tkt-1)
                                                {
                                                    cout<<",";
                                                }
                                            }
cout<<"                        \n";
cout<<"\t\t\t|                                                     QR CODE           |\n";
cout<<"\t\t\t|                                                       ..++>>>         |\n";
cout<<"\t\t\t|                                                       ..__***         |\n";
cout<<"\t\t\t|                                                       &%^>>>>         |\n";
cout<<"\t\t\t|                                                       :::::::         |\n";
cout<<"\t\t\t|_______________________________________________________________________|\n";

                                                cout<<"\t\t\t\t\t\t\t\"PROJECT CREATED N IMPLEMENTED BY:\""<<endl;
                                                cout<<"\t\t\t\t\t\t\t\t\t\t         -LIT_GUY";
}

void movie_booking::pass_proctect()//to protect the password
{

        int ps=0,star=0;// to count the characters in password

        //star is to print the password in * format
                    //pas[-1]=0;//intialised just like that "I GUESS ITS NIT REQUIRED"
         cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n";
         cout<<"\t\t\t\t\t\t\t";

                cin>>pass;
               ps=pass.length();
                system("cls");
                while(star<ps)
                {   if(star==0)
                {
                    cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n\n";

                    cout<<"\t\t\t\t\t\t\t\t";

                }

                    cout<<" * ";
                    star++;
                }

}

void movie_booking::data_str()
{
 ofstream fout;
    fout.open("database1.csv",ios::app);
    string name1,name2,usr_id,usr_psd;
    /*format to be save is 1st name,title,user id,age,password*/
    fflush(stdin);


 cout<<"\t\t\t\t\t\t\tENTER THE FIRST NAME\n";
        fflush(stdin);
        getline(cin,name1);
         cout<<"\t\t\t\t\t\t\tENTER THE LAST NAME\n";
         fflush(stdin);
        getline(cin,name2);
         cout<<"\t\t\t\t\t\t\tENTER THE USER ID\n";
         fflush(stdin);
        getline(cin,usr_id);
         cout<<"\t\t\t\t\t\t\tENTER THE USER PASSWORD\n";
         fflush(stdin);
        getline(cin,usr_psd);
         fout<<name1<<","<<name2<<","<<usr_id<<","<<usr_psd<<endl;

fout.close();
data_store=1;
}
int movie_booking::password_check()
{
     cout<<"\n\n\t\t\t\t\t\t\tENTER YOUR USER ID\n";
            fflush(stdin);
            cout<<"\t\t\t\t\t\t\t";

            cin>>cus_id;
 ifstream myfile;
            myfile.open("database1.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(user==cus_id||pass==cus_id)
                {
                   foundu++;
                   prnt_once++;
                   if(prnt_once==1)
                   cout<<"\n\n\t\t\t\t\t\t\tUSER ID FOUND\n";
                }


            }

            if(foundu==0)
            {cout<<"\n\n\t\t\t\t\t\t\tUSER ID NOT FOUND\n";
             myfile.close();
            }
              else
              {
                 myfile.close();
                              cout<<"\n\n\t\t\t\t\t\t\tENTER YOUR USER PASSWORD\n";
            fflush(stdin);
             cout<<"\t\t\t\t\t\t\t";
            cin>>cus_pas;
 myfile.open("database1.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(pass==cus_pas)
                {
                   foundp++;
                   cout<<"\n\n\t\t\t\t\t\t\tPASSWORD MATCHED\n";
                }


            }

              }

            if(foundp==0)
               cout<<"\n\n\t\t\t\t\t\t\tPASSWORD IS WRONG\n";


             myfile.close();
             return foundp;


}

int main()
{   cout<<"lol";
    prnt_once=0;
    movie_booking obj;
    obj.first();
bye:
     cout<<"its working WITH file handling \n";
     system("cls");
     cout<<"\n\n\n\n\t\t\t\t\t\t\t THANK YOU FOR USING OUR APPLICATION!!!!";
 return 0;

}

   