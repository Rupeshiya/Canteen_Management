#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<sstream>
#include<typeinfo>
using namespace std;
struct order
{
      int prodid1;
      char pname1[50];
      char compy1[50];
      int qty1;
      float price1,dis1;
}o1[50];
int orderk=0;
void middleadminmenu();
void copyme(int k,order order1[],int q1,int &c2);
void intromain();
int getproduct();
int getcustomers();
void display_all();
void display_all_cust();
void prod_tabular();
void modify_record(int n);
void delete_record(int n);
void againopenandclose();
void againopenandclosecust();
int search(int p);
void changeqty(int pr1,int q11);
//CUSTOMER INFO
class customer
{
      int cust_id;
      char cname[25];
      char address[35];
      char phno[15];
public:
      void modifycust_data(int n1,char nm[15],char add[15],char q[15]);
      int getcustid()
      {
            return cust_id;
      }
      char *getcustnm()
      { 
            return cname;
      }
      char *getcustadd()
      { 
            return address;
      }
      char *getphno()
      { 
            return phno;
      }
      void cust_input(int custid)
      {
            cout<<"========================================================================="<<endl;
            cout<<"CUSTOMER NO: ";
            cust_id=custid;
            cout<<cust_id<<endl;
            cout<<"NAME OF CUSTOMER:"<<endl;
            cin>>cname;
            cout<<"ADDRESS:"<<endl;
            cin>>address;
            cout<<"PHONE NO.:"<<endl;
            cin>>phno;
            cout<<"========================================================================="<<endl;
      }
      void show_cust()
      {
            cout<<"========================================================================="<<endl;
            cout<<"CUSTOMER NO:"<<endl;
            cout<<cust_id<<endl;
            cout<<"NAME OF CUSTOMER:"<<endl;
            cout<<cname<<endl;
            cout<<"ADDRESS:"<<endl;
            cout<<address<<endl;
            cout<<"PHONE NO.:"<<endl;
            cout<<phno<<endl;
            cout<<"========================================================================="<<endl;
      }
      void showallcust(int c)
      {
            cout<<cust_id<<setw(17)<<cname<<setw(15)<<address<<setw(30)<<phno<<endl;
      }
      void showcustdatamulti()
      {
             cout<<"========================================================================="<<endl;
             cout<<"CUSTOMER NO:"<<endl;
             cout<<cust_id<<endl;
             cout<<"NAME OF CUSTOMER:"<<endl;
             cout<<cname<<endl;
             cout<<"ADDRESS:"<<endl;
             cout<<address<<endl;
             cout<<"PHONE NO.:"<<endl;
             cout<<phno<<endl;
             cout<<"========================================================================="<<endl;
      }
};
void customer::modifycust_data(int n1,char nm[15],char add[15],char q[15])
{
      char tmpnm[40],tmpnm2[40],tmpnm3[15];
      cout<<"============================  WANT TO MODIFY ============================"<<endl;
      cout<<"CUSTOMER NO: ";
      cust_id=n1;
      cout<<cust_id<<endl;
      strcpy(cname,nm);
      cout<<"NAME OF CUSTOMER:"<<endl;
      cout<<cname<<endl;
      cout<<"Want to change the name of customer"<<endl;
      int flag=0;
      while(1)
      {
            gets(tmpnm);
            if(strlen(tmpnm)!=0)
            {
                  flag=1;
                  break;
            }
            if(strlen(tmpnm)==0)
            { 
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      { 
            strcpy(cname,tmpnm);
      }
      strcpy(address,add);
      cout<<"CUSTOMER ADDRESS:"<<endl;
      cout<<address<<endl;
      cout<<"Want to change the address"<<endl;
      flag=0;
      while(1)
      {
            gets(tmpnm2);
            if(strlen(tmpnm2)!=0)
            {
                  flag=1;
                  break;
            }
            if(strlen(tmpnm2)==0)
            { 
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      { 
            strcpy(address,tmpnm2);
      }
      strcpy(phno,q);
      cout<<"CUSTOMER PHONE NO.:"<<endl;
      cout<<phno<<endl;
      cout<<"Want to change the phone no."<<endl;
      flag=0;
      while(1)
      {
            gets(tmpnm3);
            if(strlen(tmpnm3)!=0)
            {
                  flag=1;
                  break;
            }
            if(strlen(tmpnm3)==0)
            { 
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      { 
            strcpy(phno,tmpnm3);
      }
      cout<<"========================================================================="<<endl;
}
//Function to add the records in (convert to csv) file
void write_customer()
{
      ofstream objoff;
      customer cobj;
      objoff.open("customer.dat",ios::out|ios::app);
      intromain();
      int r=getcustomers();
      if(r>100) //1000
      {
            r=1; // r=100
      }
       cobj.cust_input(r);
       objoff.write((char*)&cobj,sizeof(customer));
       objoff.close();
       cout<<"***********************   CUSTOMER RECORD SAVED   ***********************"<<endl;
       cin.ignore();
       cin.get();
}
//function to add the record in a file ends here
//Function to check the customer number already given or not
int getcustomers()
{
      ifstream objiff;
      customer cust;
      int count=0;
      objiff.open("customer.dat",ios::binary);
      objiff.seekg(0,ios::beg);
      if(!objiff)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
      }
      while(objiff.read((char *) &cust, sizeof(customer)))
      {
            count++;
      }
      //***********jump to the last line
      objiff.seekg(count-sizeof(cust),ios::beg);
      objiff.read((char *) &cust, sizeof(customer));
      count=cust.getcustid();
      count++;
      objiff.close();
      return count;
}
//Check the customer number ends here
// Function to read specific record from file
void display_cust_sp(int n)
{
       ifstream objfp;
       customer cust;
       int flag=0;
       objfp.open("customer.dat",ios::binary);
       if(!objfp)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      while(objfp.read((char*)&cust,sizeof(customer)))
      {
             if(cust.getcustid()==n)
            {
                  intromain();
                  cust.show_cust();
                  flag=1;
            }
      }
      objfp.close();
      if(flag==0)
      cout<<"\n\nrecord not exist"<<endl;
      cin.get();
}
//Customer record sepecific
//FUNCTION TO DISPLAY ALL THE CUSTOMER TABULAR FORM
void cust_tabular()
{
      int r=0,col=10;
      customer cust;
      ifstream inFile;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      display_all_cust();
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
             if(r<=12)
             {
                   r++;
                   cust.showallcust(col);
                   col++;
             }
             else
             {
                   cout<<"----------------------------- Press any key -----------------------------"<<endl;
                   cin.get();
                   display_all_cust();
                   col=10;
                   r=0;
            }
      }
      inFile.close();
      cin.get();
}
//tabular forms ends
//function to display all the records of product
void display_all_cust()
{
      intromain();
      cout<<"========================================================================="<<endl;
      cout<<"   ************************  CUSTOMER DETAILS  **********************    "<<endl;
      cout<<"========================================================================="<<endl;
      cout<<"CUST.NO"<<setw(10)<<"NAME"<<setw(15)<<"ADDRESS"<<setw(30)<<"PHONE NO"<<endl;
      cout<<"========================================================================="<<endl;
}
//DISPLAY ALL ENDS HERE
//FUNCTION TO MODIFY customer RECORD
void modify_cust_record(int n)
{
      customer cust,temp;
      char tmpnm[50],tmpaddress[50];
      ifstream inFile;
      int fpos1=-1;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==n)
            {
             intromain();
             cust.showcustdatamulti();
             flag=1;
            }
      }
      inFile.close();
      if(flag==0)
            cout<<"\n\nrecord not exist"<<endl;
      else
      {
      //modifying the records starts here
            fstream File;
            File.open("customer.dat",ios::binary|ios::in|ios::out);
            if(!File)
            {
                  cout<<"File could not be open !! Press any Key..."<<endl;
                  cin.get();
                  return;
            }
            while(File.read((char *) &cust, sizeof(customer)))
            {
                  if(cust.getcustid()==n)
                  { 
                        fpos1=(int)File.tellg();
                        break;
                  }
            }
            File.seekp(fpos1-sizeof(customer),ios::beg);
            strcpy(tmpnm,cust.getcustnm());
            strcpy(tmpaddress,cust.getcustadd());
            char q1[15];
            strcpy(q1,cust.getphno());
            cout<<"*************************************************************************"<<endl;
            cout<<"============  ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE  ============="<<endl;
            cout<<"*************************************************************************"<<endl;
            temp.modifycust_data(n,tmpnm,tmpaddress,q1);
            File.write((char *) &temp, sizeof(customer));
            File.close();
      }
}
//FUNCTION TO DELETE THE RECORD OF THE CUSTOMER AVAILABLE
void deletecust_record(int n)
{
      customer cust;
      ifstream inFile;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==n)
            {
                   intromain();
                   cust.showcustdatamulti();
                   flag=1;
            }
      }
      inFile.close();
      char ch;
      if(flag==0)
            cout<<"\n\nrecord not exist"<<endl;
      else
      {
      //Deletion of the records starts from here
            cout<<"*************************************************************************"<<endl;
            cout<<"===  DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE [YES(Y) OR NO (N)] ==="<<endl;
            cout<<"*************************************************************************"<<endl;
            cin>>ch;
            if (toupper(ch)=='Y')
            {
                   ofstream outFile;
                   outFile.open("Temp2.dat",ios::binary);
                   ifstream objiff("customer.dat",ios::binary);
                   objiff.seekg(0,ios::beg);
                   while(objiff.read((char *) &cust, sizeof(customer)))
                   {
                         if(cust.getcustid()!=n)
                         {
                              outFile.write((char *) &cust, sizeof(customer));
                         }
                  }
                  outFile.close();
                  objiff.close();
                  remove("customer.dat");
                  rename("Temp2.dat","customer.dat");
                  againopenandclosecust();
                  cout<<"---------------------------Record Deleted--------------------------------"<<endl;
            }
      }
      cin.get();
}
//Delete record ends
void againopenandclosecust()
{
      ifstream inFile;
      customer cust;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cin.get();
            return;
      }
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
      }
      inFile.close();
}
//Search the customer
int searchcust(int p)
{
      customer cust;
      int tmprt=0;
      ifstream inFile;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return -1;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==p)
            {
                   intromain();
                   cust.showcustdatamulti();
                   flag=1;
                   tmprt=(int)inFile.tellg();
                   break;
            }
      }
      inFile.close();
      if(flag==0)
            return 1;
      //cout<<"\n\nrecord not exist";
      else
      {
            return tmprt;
      }
}
//Customer information ends
class product
{
      int prodid;
      char name[50];
      char company[50];
      int qty;
      float price,dis;
      public:
      product()
      {
            qty=0;
            price=0;
            dis=0;
      }
      void modifydata(int n1,char snm[15],char companynm[15],int q);
      void showdatamulti()
      {
             cout<<"========================================================================="<<endl;
             cout<<"PRODUCT NO:"<<endl;
             cout<<prodid<<endl;
             cout<<"NAME OF PRODUCT:"<<endl;
             cout<<name<<endl;
             cout<<"COMPANY:"<<endl;
             cout<<company<<endl;
             cout<<"PRODUCT PRICE:"<<endl;
             cout<<price<<endl;
             cout<<"QUANTITY:"<<endl;
             cout<<qty<<endl;
             cout<<"DISCOUNT"<<endl;
             cout<<dis<<endl;
             cout<<"========================================================================"<<endl;
      }
      void create_prod(int rn1)
      {
             cout<<"========================================================================"<<endl;
             cout<<"PRODUCT NO: ";
             prodid=rn1;
             cout<<prodid<<endl;
             cout<<"NAME OF PRODUCT:"<<endl;
             cin>>name;
             cout<<"COMPANY:"<<endl;
             cin>>company;
             cout<<"QUANTITY:"<<endl;
             cin>>qty;
             cout<<"PRODUCT PRICE:"<<endl;
             cin>>price;
             cout<<"DISCOUNT:"<<endl;
             cin>>dis;
             cout<<"========================================================================"<<endl;
      }
      void show_prod()
      {
             cout<<"========================================================================"<<endl;
             cout<<"PRODUCT NO: ";
             cout<<prodid<<endl;
             cout<<"NAME OF PRODUCT:"<<endl;
             cout<<name<<endl;
             cout<<"COMPANY:"<<endl;
             cout<<company<<endl;
             cout<<"PRODUCT PRICE:"<<endl;
             cout<<price<<endl;
             cout<<"DISCOUNT:"<<endl;
             cout<<dis<<"%"<<endl;
             cout<<"QUANTITY:"<<endl;
             cout<<qty<<endl;
             cout<<"========================================================================"<<endl;
       }
      //Function shows data tabular form
      void showall(int c)
      {
            cout<<prodid<<setw(10)<<name<<setw(15)<<company<<setw(15)<<"Rs."<<price<<setw(15)<<qty<<setw(10)<<dis<<"%"<<endl;
      }
      //ends here
      int retpno()
      {
           return prodid;
      }
      float retprice()
      {
           return price;
      }
      char* getcompany()
      {
          return company;
      }
      char* getname()
      {
          return name;
      }
      int getqty()
      {
          return qty;
      }
      float retdis()
      {
          return dis;
      }
      void setqty(int q21)
      {
          qty=q21;
      }
}; 
//class ends here
// global declaration for stream object, object
//modify product
void product::modifydata(int n1,char snm[15],char companynm[15],int q)
{
      char tmpnm[40],tmpnm2[40];
      cout<<"=======================  WANT TO MODIFY  ==============================="<<endl;
       cout<<"PRODUCT NO: ";
       prodid=n1;
       cout<<prodid<<endl;
       strcpy(name,snm);
       cout<<"NAME OF PRODUCT:"<<endl;
       cout<<name<<endl;
       cout<<"Want to change the name of product"<<endl;
       int flag=0;
       while(1)
       {
            gets(tmpnm);
            if(strlen(tmpnm)!=0)
            {
                flag=1;
                break;
            }
            if(strlen(tmpnm)==0)
            {  
                  flag=0;
                  break;
            }
       }
       if(flag==1)
       { 
            strcpy(name,tmpnm);
       }
       strcpy(company,companynm);
       //COMPANY NAME TO BE MODIFY
       cout<<"COMPANY NAME:"<<endl;
       cout<<company<<endl;
       cout<<"Want to change the COMPANY"<<endl;
      flag=0;
      while(1)
      {
            gets(tmpnm2);
            if(strlen(tmpnm2)!=0)
            {
                  flag=1;
                  break;
            }
            if(strlen(tmpnm2)==0)
            { 
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      { 
            strcpy(company,tmpnm2);
      }
      //Modifying function ends here
      cout<<"**********  MODIFY  **  PRODUCT PRICE - QUANTITY - DISCOUNT  ***********"<<endl;
      cout<<"PRICE:"<<endl;
      float tmppr=0;
      flag=-1;
      while(1)
      {
            cin>>tmppr;
            if(tmppr!=0)
            {
                  flag=1;
                  break;
            }
            else
            { 
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      { 
            price=tmppr;
      }
      cout<<"CHANGE QUANTITY:"<<endl;
      int tmpqty=0;
      cin>>tmpqty;
      qty=q;
      qty=qty+tmpqty;
      cout<<"DISCOUNT:"<<endl;
      float tmpdis=0;
      cin>>tmpdis;
      dis=tmpdis;
      cout<<"========================================================================"<<endl;
}
//Class function outside
fstream fp;
product pr;
// function to write in file
void write_book()
{
      fp.open("product.dat",ios::out|ios::app);
      intromain();
      int rnn=getproduct();
      if(rnn>100)
      {
            rnn=1;
      }
      pr.create_prod(rnn);
      fp.write((char*)&pr,sizeof(product));
      fp.close();
      cout<<"***********************  PRODUCTS RECORD SAVED  ************************"<<endl;
      cin.ignore();
      cin.get();
}
//Function to check the product number already given or not
int getproduct()
{
      ifstream objiff;
      product st;
      int count=0;
      objiff.open("product.dat",ios::binary);
      objiff.seekg(0,ios::beg);
      if(!objiff)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
      }
      while(objiff.read((char *) &st, sizeof(product)))
      {
            count++;
      }
      objiff.seekg(count-sizeof(st),ios::beg);
      objiff.read((char *) &st, sizeof(product));
      count=st.retpno();
      count++;
      objiff.close();
      return count;
}
//Function to read specific record from file
void display_sp(int n)
{
      int flag=0;
      fp.open("product.dat",ios::in);
      if(!fp)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      while(fp.read((char*)&pr,sizeof(product)))
      {
            if(pr.retpno()==n)
            {
                  intromain();
                  pr.show_prod();
                  flag=1;
            }
      }
      fp.close();
      if(flag==0)
            cout<<"\n\nrecord not exist"<<endl;
      cin.get();
}
//Function before place order and then call place order function
int before_order()
{ 
      int f=-1,num=0;
      customer cust;
      intromain();
      cout<<"ENTER THE CUSTOMER ID TO BE SEARCHED:"<<endl;
      cin>>num;
      ifstream inFile;
      inFile.open("customer.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return -1;
      }
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==num)
            {
                   intromain();
                   cust.showcustdatamulti();
                   f=1;
                   //tmprt=(int)inFile.tellg();
                   break;
            }
      }
      inFile.close();
      return f;
}
//Function to place order and generating bill for PRODUCT PURCHASED
void place_order()
{
      order o1[50];
      int c=0,pr1=0;
      float amt=0,damt=0,total=0,ttaxt=0;
      int k=0,q1;
      char ch='Y';
      int value=before_order();
      if(value==1)
      {
            prod_tabular();
            intromain();
            cout<<"========================================================================"<<endl;
            cout<<"                             PLACE YOUR ORDER                           "<<endl;
            cout<<"========================================================================"<<endl;
            do
            {
                  cout<<"ENTER THE PRODUCT NO: "<<endl;
                  cin>>pr1;
                  k=search(pr1);
                  if(k>0)
                  {
                        cout<<"Enter the Quantity:"<<endl;
                        cin>>q1;
                        changeqty(pr1,q1);
                        copyme(k,o1,q1,c);
                  }
                  else
                  {
                        cout<<"PRODUCT not found"<<endl;
                  }
                  cout<<"Do you want purchase more (Yes[ y or Y ] or NO [n or N])"<<endl;
                  cin>>ch;
            }while(ch=='y' || ch=='Y');
            cout<<"Thank You For Placing The Order  ........"<<endl;
            cin.get();
            intromain();
            cout<<"*****************************   INVOICE   ******************************"<<endl;
            cout<<"PR.No."<<setw(12)<<"NAME"<<setw(10)<<"Qty"<<setw(15)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount- discount"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            int yy=8;
            for(int x=0;x<c;x++)
            {
                  cout<<o1[x].prodid1<<endl;
                  cout<<o1[x].pname1<<endl;
                  cout<<o1[x].qty1<<endl;
                  cout<<"Rs."<<o1[x].price1<<endl;
                  amt=o1[x].qty1*o1[x].price1;
                  cout<<"Rs."<<amt<<endl;
                  damt=amt-o1[x].dis1;
                  cout<<"Rs."<<damt<<endl;
                  total+=damt;
                   //ttaxt+=o1[x].tax1;
                  yy++;
             }
             ttaxt=5;
             cout<<"-------------------------------------------------------------------------"<<endl;
             yy++;
             cout<<"TOTAL: ";
             cout<<total<<endl;
             yy++;
             cout<<"TAX%: ";
             cout<<"+"<<ttaxt<<"%"endl;
             yy++;
             cout<<"----------------------------";
             yy++;
             cout<<"NET TOTAL: ";
             cout<<"Rs."<<(total+((ttaxt*total)/100))<<endl;
             yy++;
             cout<<"-------------------------------------------------------------------------"<<endl;
      }
      else
      {
            cout<<"**************************  YOUR ID IS WRONG  ***************************"<<endl;
      }
}
//Fuction to copy all record to a structure
void copyme(int k2,order order1[50],int q1,int &c2)
{
      ifstream objiff2("product.dat",ios::binary);
      product bk1;
      objiff2.seekg(k2-sizeof(product));
      objiff2.read((char*)&bk1,sizeof(product));
      strcpy(order1[c2].pname1,bk1.getname());
      strcpy(order1[c2].compy1,bk1.getcompany());
      order1[c2].dis1=bk1.retdis();
      order1[c2].price1=bk1.retprice();
      //COPY RECORD
      order1[c2].qty1=q1;
      c2++;
      objiff2.close();
}
// INTRODUCTION FUNCTION
void intro()
{
      cout<<endl;
      cout<<"========================================================================="<<endl;
      cout<<"-------------------------------------------------------------------------"<<endl;
      cout<<"****************  C A N T E E N   M A N A G E M E N T   *****************"<<endl;
      cout<<"-------------------------------------------------------------------------"<<endl;
      cout<<"***************************   S Y S T E M   *****************************"<<endl;
      cout<<"-------------------------------------------------------------------------"<<endl;
      cout<<"PROJECT : "<<endl;
      cout<<"MADE BY : 1 - SWETA BEHERA        , ID- B117054"<<endl;
      cout<<"          2 - RUPESH KRISHNA JHA  , ID- B117043"<<endl;
      cout<<"          3 - SAYAN DE BHOWMICK   , ID- B117047"<<endl;
      cout<<"          4 - PULI KIRAN          , ID- B117038"<<endl;
      cout<<"          5 - SUMEET SAGAR LENKA  , ID- B117052"<<endl;
      cout<<endl;
      cout<<"----  INTERNATIONAL INSTITUTE OF INFORMATION TECHNOLOGY,BHUBANESWAR  ----"<<endl;
      cout<<"========================================================================="<<endl;
      cin.get();
}
// ADMINSTRATOR MENU1 FUNCTION
void admin_menu1()
{
      char ch2;
      int num;
      intromain();
      cout<<"============================   ADMIN MENU   ============================"<<endl;
      cout<<"1.CREATE CUSTOMERS DETAILS"<<endl;
      cout<<"2.DISPLAY ALL CUSTOMERS DETAILS"<<endl;
      cout<<"3.SEARCH RECORD(QUERY) "<<endl;
      cout<<"4.MODIFY CUSTOMERS RECORDS"<<endl;
      cout<<"5.DELETE CUSTOMERS RECORDS"<<endl;
      cout<<"6.BACK TO MAIN MENU"<<endl;
      cout<<"Please Enter Your Choice (1-6) "<<endl;
      ch2=cin.get();
      switch(ch2)
      {
            case '1':
                  write_customer();
                  break;
            case '2': 
                  cust_tabular();
                  break;
            case '3':
                  intromain();
                  cout<<"ENTER THE CUST ID TO BE SEARCHED:"<<endl;
                  cin>>num;
                  display_cust_sp(num);
                  break;
            case '4':
                  intromain();
                  cout<<"ENTER THE CUST ID TO BE SEARCHED AND MODIFY:"<<endl;
                  cin>>num;
                  modify_cust_record(num);
                  break;
            case '5':
                  intromain();
                  cout<<"ENTER THE CUST ID TO BE SEARCHED AND TO DELETE:"<<endl;
                  cin>>num;
                  deletecust_record(num);
                  break;
            case '6': 
                  break;
            default:
                  cout<<"\a";
                  admin_menu1();
      }
}
//CUSTOMERS MENU FUNCTION ENDS HERE
//ADMINSTRATOR MENU 2 FUNCTION
void admin_menu()
{
      char ch2;
      int num;
      intromain();
      cout<<"============================   ADMIN MENU   ============================"<<endl;
      cout<<"1.CREATE PRODUCTS"<<endl;
      cout<<"2.DISPLAY ALL PRODUCTS AVAILABLE"<<endl;
      cout<<"3.SEARCH RECORD (QUERY) "<<endl;
      cout<<"4.MODIFY PRODUCTS"<<endl;
      cout<<"5.DELETE PRODUCTS"<<endl;
      cout<<"6.BACK TO MAIN MENU"<<endl;
      cout<<"Please Enter Your Choice (1-6) "<<endl;
      ch2=cin.get();
      switch(ch2)
      {
            case '1':
                  write_book();
                  break;
            case '2': 
                  prod_tabular();//display_all();
                  break;
            case '3':
                  intromain();
                  cout<<"ENTER THE PRODUCT ID TO BE SEARCHED:"<<endl;
                  cin>>num;
                  display_sp(num);
                  break;
            case '4':
                  intromain();
                  cout<<"ENTER THE PRODUCT ID TO BE SEARCHED AND MODIFY:"<<endl;
                  cin>>num;
                  modify_record(num);
                  break;
            case '5':
                  intromain();
                  cout<<"ENTER THE PRODUCT ID TO BE SEARCHED AND TO DELETE:"<<endl;
                  cin>>num;
                  delete_record(num);
                  break;
            case '6': 
                  break;
            default:
                  cout<<"\a";
                  admin_menu();
      }
}
// THE MAIN FUNCTION OF PROGRAM
int main()
{
      char ch;
      intro();
      do
      {
            intromain();
            cout<<"=============================   MAIN MENU   ============================"<<endl;
            cout<<"1. PRODUCTS REPORT GENERATOR"<<endl;
            cout<<"2. ADMINISTRATOR"<<endl;
            cout<<"3. EXIT"<<endl;
            cout<<"========================================================================"<<endl;
            cout<<"Please Select Your Option (1-3) "<<endl;
            ch=cin.get();
            switch(ch)
            {
                  case '1':
                        orderk=0;
                        place_order();
                        cin.get();
                        break;
                  case '2': 
                        middleadminmenu();
                        break;
                  case '3':
                        exit(0);
                  default :
                        cout<<"\a";
            }
      }while(ch!='3');
      return 0;
}
//main intro
void intromain()
{
      cout<<endl;
      cout<<"------------------------------------------------------------------------"<<endl;
      cout<<"********   C A N T E E N  M A N A G E M E N T  S Y S T E M   ***********"<<endl;
      cout<<"------------------------------------------------------------------------"<<endl;
      cout<<endl;
}
//FUNCTION TO DISPLAY ALL THE PRODUCT TABULAR FORM
void prod_tabular()
{
      int r=0,col=10;
      product st;
      ifstream inFile;
      inFile.open("product.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      display_all();
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(r<=12)
            {
                  r++;
                  st.showall(col);
                  col++;
            }
            else
            {
                  cout<<"----------------------------- Press any key ----------------------------"<<endl;
                  cin.get();
                  display_all();
                  col=10;
                  r=0;
            }
      }
      inFile.close();
      cin.get();
}
//Tabular form ends here
//Function to display all the records of product
void display_all()
{
      intromain();
      cout<<"========================================================================"<<endl;
      cout<<"*************************   PRODUCTS DETAILS   *************************"<<endl;
      cout<<"========================================================================"<<endl;
      cout<<"PROD.NO"<<setw(10)<<"NAME"<<setw(15)<<"COMPANY"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<setw(10)<<"DISCOUNT"<<endl;
      cout<<"========================================================================"<<endl;
}
//FUNCTION TO MODIFY RECORD
void modify_record(int n)
{
      product st,temp;
      char tmpnm[50],tmpcompany[50];
      ifstream inFile;
      int fpos=-1;
      inFile.open("product.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==n)
            {
                  intromain();
                  st.showdatamulti();
                  flag=1;
            }
      }
      inFile.close();
      if(flag==0)
            cout<<"\n\nrecord not exist"<<endl;
      else
      {
            fstream File;
            File.open("product.dat",ios::binary|ios::in|ios::out);
            if(!File)
            {
                  cout<<"File could not be open !! Press any Key..."<<endl;
                  cin.get();
                  return;
            }
            while(File.read((char *) &st, sizeof(product)))
            {
                  if(st.retpno()==n)
                  { 
                        fpos=(int)File.tellg();
                        break;
                  }
            }
            File.seekp(fpos-sizeof(product),ios::beg);
            strcpy(tmpnm,st.getname());
            strcpy(tmpcompany,st.getcompany());
            int q1=st.getqty();
            cout<<"************************************************************************"<<endl;
            cout<<"===========   ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE   ==========="<<endl;
            cout<<"************************************************************************"<<endl;
            temp.modifydata(n,tmpnm,tmpcompany,q1);
            File.write((char *) &temp, sizeof(product));
            File.close();
      }
}
//FUNCTION TO DELETE THE RECORD OF THE PRODUCTS NOT AVAILABLE
void delete_record(int n)
{
      product st;
      ifstream inFile;
      inFile.open("product.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==n)
            {
                  intromain();
                  st.showdatamulti();
                  flag=1;
            }
      }
      inFile.close();
      char ch;
      if(flag==0)
            cout<<"\n\nrecord not exist"<<endl;
      else
      {
            cout<<"************************************************************************"<<endl;
            cout<<"==  DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE [YES(Y) OR NO (N)]  =="<<endl;
            cout<<"************************************************************************"<<endl;
            cin>>ch;
            if (toupper(ch)=='Y')
            {
                  ofstream outFile;
                  outFile.open("Temp1.dat",ios::binary);
                  ifstream objiff("product.dat",ios::binary);
                  objiff.seekg(0,ios::beg);
                  while(objiff.read((char *) &st, sizeof(product)))
                  {
                        if(st.retpno()!=n)
                        {
                              outFile.write((char *) &st, sizeof(product));
                        }
                  }
                  outFile.close();
                  objiff.close();
                  remove("product.dat");
                  rename("Temp1.dat","product.dat");
                  againopenandclose();
                  cout<<"------------------------------Record Deleted----------------------------"<<endl;
            }
      }
      cin.get();
}
void againopenandclose()
{
      ifstream inFile;
      product st;
      inFile.open("product.dat",ios::binary);
      if(!inFile)
      {
            cin.get();
            return;
      }
      while(inFile.read((char *) &st, sizeof(product)))
      {
      }
      inFile.close();
}
//Searching the product
int search(int p)
{
      product st;
      int tmprt=0;
      ifstream inFile;
      inFile.open("product.dat",ios::binary);
      if(!inFile)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return -1;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==p)
            {
                  intromain();
                  st.showdatamulti();
                  flag=1;
                  tmprt=(int)inFile.tellg();
                  break;
            }
      }
      inFile.close();
      if(flag==0)
            return 1;
      else
      {
            return tmprt;
      }
}
//Function to change quantity
void changeqty(int pr1,int q11)
{
      product st;
      int fpos=-1;
      fstream File;
      File.open("product.dat",ios::binary|ios::in|ios::out);
      if(!File)
      {
            cout<<"File could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      while(File.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==pr1)
            { 
                  fpos=(int)File.tellg();
                  break;
            }
      }
      File.seekp(fpos-sizeof(product),ios::beg);
      int q1=st.getqty();
      q1=q1-q11;
      st.setqty(q1);
      File.write((char *) &st, sizeof(product));
      File.close();
}
void middleadminmenu()
{
      char ch;
      do
      {
            intromain();
            cout<<"===================   CUSTOMERS' & PRODUCTS' MENU   ===================="<<endl;
            cout<<"1. CUSTOMERS' MENU"<<endl;
            cout<<"2. PRODUCTS' MENU"<<endl;
            cout<<"3. BACK TO MAIN"<<endl;
            cout<<"========================================================================"<<endl;
            cout<<"Please Select Your Option (1-3) "<<endl;
            ch=cin.get();
                  switch(ch)
                  {
                        case '1':
                              admin_menu1();
                              break;
                        case '2': 
                              admin_menu();
                              break;
                        case '3': 
                              break;
                        default : 
                              cout<<"\a";
                              admin_menu();
                  }
      }while(ch!='3');
}
