#include<iostream>
#include<iomanip>
#include<string>
#include <cstring>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
#include<cstdio>
#include<sstream>
#include<windows.h>
#include <winsock.h>
#include <typeinfo>
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
//***************************************************************
// CLASS USED IN PROJECT
//****************************************************************
//*******************customer information****************************
class customer
{
int cust_id;
char cname[25];
char address[35];
char phno[15];
public:
void modifycust_data(int n1,char nm[15],char add[15],char q[15]);
int getcustid()
{return cust_id;}
char *getcustnm()
{ return cname;}
char *getcustadd()
{ return address;}
char *getphno()
{ return phno;}
void cust_input(int custid)
{
 //(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"CUST NO:"<<endl;
 cust_id=custid;
 //(24,8);
 cout<<cust_id;
 //(35,8);
 cout<<"NAME OF CUST:"<<endl;
 //(54,8);
 cin>>cname;
 //(10,9);
 cout<<"ADDRESS:"<<endl;
 //(22,9);
 cin>>address;
 //(10,11);
 cout<<"PHONE NO.:"<<endl;
 //(25,11);
 cin>>phno;
 //(5,12);
 cout<<"====================================================================="<<endl;
}
void show_cust()
{
//(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"CUST NO:";
 //(25,8);
 cout<<cust_id;
 //(35,8);
 cout<<"NAME OF CUST:";
 //(54,8);
 cout<<cname;
 //(10,9);
 cout<<"ADDRESS:";
 //(25,9);
 cout<<address;
 //(10,10);
 cout<<"PHONE NO.:";
 //(25,10);
 cout<<phno;
 //(5,12);
 cout<<"====================================================================="<<endl;
}
void showallcust(int c)
{
 //(1,c);
 cout<<cust_id<<setw(17)<<cname<<setw(15)<<address<<setw(30)<<phno;
}
void showcustdatamulti()
{
 //(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"CUST NO:";
 //(30,8);
 cout<<cust_id;
 //(40,8);
 cout<<"NAME OF CUSTD:";
 //(60,8);
 cout<<cname;
 //(10,9);
 cout<<"ADDRESS:";
 //(30,9);
 cout<<address;
 //(10,10);
 cout<<"PHONE NO.:";
 //(30,10);
 cout<<phno;
 //(5,11);
 cout<<"====================================================================="<<endl;
}
};
//*************************modify customer details
void customer::modifycust_data(int n1,char nm[15],char add[15],char q[15])
{
char tmpnm[40],tmpnm2[40],tmpnm3[15];
//(5,14);
 cout<<"===================WANT TO MODIFY ==============================="<<endl;
 //(10,15);
 cout<<"CUST NO:";
 cust_id=n1;
 //(25,15);
 cout<<cust_id;
 //(40,15);
 strcpy(cname,nm);
 cout<<"NAME OF CUST:";
 //(60,15);
 cout<<cname;
 //(10,17);
 cout<<"Want to change the name of customer"<<endl;
 //(50,17);
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
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(cname,tmpnm);
 }
 else
 {
 }
 //(1,18);
 strcpy(address,add);
 //**************** NAME TO BE MODIFY
 cout<<"CUSTOMER ADDRESS:";
 //(20,18);
 cout<<address;
 //(45,18);
 cout<<"Want to change the address"<<endl;
 //(70,18);
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
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(address,tmpnm2);
 }
 //*****************COMPANY NAME TO BE MODIFIED ENDS HERE
 //(5,19);
strcpy(phno,q);
 //**************** phone no. TO BE MODIFY
 cout<<"CUSTOMER PHONE NO.:";
 //(20,18);
 cout<<phno;
 //(45,18);
 cout<<"Want to change the phone no."<<endl;
 //(70,18);
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
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(phno,tmpnm3);
 }
 //*****************MODIFIED ENDS HERE
//(5,20);
 cout<<"====================================================================="<<endl;
}
//**************************class function customer modify ends here
//*********************customer class ends here*********************
//****************function to add the records in a file
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
 //(10,20);
 cout<<"***************CUSTOMER RECORD SAVED******************* "<<endl;
 cin.ignore();
 cin.get();
}
//****************function to add the record in a file ends here
//********************check the customer number already given or not******
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
//**************temporary hiding these lines
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
//***********************check the customer number ends here
//***************************************************************
// function to read specific record from file
//****************************************************************
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
cout<<"\n\nrecord not exist";
cin.get();
}
//**********************customer record sepecific*******************************
//******************************************************************************
// DISPLAY ALL THE CUSTOMER TABULAR FORM
//******************************************************************************
void cust_tabular()
{
 int r=0,col=10;
customer cust;
ifstream inFile;
inFile.open("customer.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
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
 }else
 {
 //(20,30);
 cout<<"--------------press any key------------------------"<<endl;
 cin.get();

 display_all_cust();
 col=10;
 r=0;
}
}
inFile.close();
cin.get();
}
//**************************tabular forms ends**********************************
//function to display all the records of product
//**********************************************************************
void display_all_cust()
{

intromain();
//(1,5);
cout<<" **********************CUSTOMER DETAILS***************************"<<endl;
//(1,6);
cout<<"================================================================================"<<endl;
//(1,7);
cout<<"CUST.NO"<<setw(10)<<"NAME"<<setw(15)<<"ADDRESS"<<setw(30)<<"PHONE NO";
//(1,8);
cout<<"================================================================================"<<endl;
}
//*********************DISPLAY ALL ENDS HERE***************************
//************************************************************
// MODIFY customer RECORD
//**********************************************************
void modify_cust_record(int n)
{
customer cust,temp;
char tmpnm[50],tmpaddress[50];
ifstream inFile;
int fpos1=-1;
inFile.open("customer.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
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
cout<<"\n\nrecord not exist";
else
{
//*******modifying the records starts here
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
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(customer),ios::beg);
strcpy(tmpnm,cust.getcustnm());
strcpy(tmpaddress,cust.getcustadd());
char q1[15];
strcpy(q1,cust.getphno());
//(1,12);
cout<<"*****************************************************************************"<<endl;
//(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE================="<<endl;
temp.modifycust_data(n,tmpnm,tmpaddress,q1);
File.write((char *) &temp, sizeof(customer));
File.close();
 }
}
//*****************************************************************************
//*****************************************************************************
// DELETE THE RECORD OF THE customer AVAILABLE
//****************************************************************************
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
cout<<"\n\nrecord not exist";
else
{
//*******deletion of the records starts from here
//(1,15);
cout<<"*****************************************************************************"<<endl;
//(5,16);
cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========"<<endl;
//(2,17);
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
//(30,20);
cout<<"----------------------------Record Deleted----------------------------------"<<endl;
}
}
cin.get();
}
//***********************delete record ends************************************
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
//***********************search the customer***********************
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
//*******************customer information ends*********************
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
//*****************************************************************************
void showdatamulti()
{
 //(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"PROD NO:";
 //(30,8);
 cout<<prodid;
 //(40,8);
 cout<<"NAME OF PROD:";
 //(60,8);
 cout<<name;
 //(10,9);
 cout<<"COMPANY:";
 //(30,9);
 cout<<company;
 //(40,9);
 cout<<"PROD PRICE:";
 //(60,9);
 cout<<price;
 //(10,10);
 cout<<"QUANTITY:";
 //(30,10);
 cout<<qty;
 //(40,10);
 cout<<"DISCOUNT";
 //(60,10);
 cout<<dis;
 //(5,11);
 cout<<"====================================================================="<<endl;
}
//*****************************************************************************
void create_prod(int rn1)
{
 //**********************************************
 //(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"PROD NO:";
 prodid=rn1;
 //(24,8);
 cout<<prodid;
 //(35,8);
 cout<<"NAME OF PROD:";
 //(54,8);
 cin>>name;
 //(10,9);
 cout<<"COMPANY:";
 //(22,9);
 cin>>company;
 //(35,9);
 cout<<"QUANTITY";
 //(54,9);
 cin>>qty;
 //(10,11);
 cout<<"PROD PRICE";
 //(25,11);
 cin>>price;
 //(35,11);
 cout<<"DISCOUNT";
 //(45,11);
 cin>>dis;
 //(5,12);
 cout<<"====================================================================="<<endl;
}
void show_prod()
{
 //********************************
 //(5,7);
 cout<<"======================================================================"<<endl;
 //(10,8);
 cout<<"PROD NO:";
 //rollno=rn1;
 //(25,8);
 cout<<prodid;
 //(35,8);
 cout<<"NAME OF PROD:";
 //(54,8);
 cout<<name;
 //(10,9);
 cout<<"COMPANY:";
 //(25,9);
 cout<<company;
 //(35,9);
 cout<<"PROD PRICE:";
 //(54,9);
 cout<<price;
 //(10,10);
 cout<<"DISCOUNT:";
 //(25,10);
 cout<<dis<<"%";
 //(35,10);
 cout<<"QUANTITY:";
 //(54,10);
 cout<<qty;
 //(5,11);
 cout<<"====================================================================="<<endl;
 }
//-----------------------show data tabular form----------------------
void showall(int c)
{
 //(1,c);
cout<<prodid<<setw(17)<<name<<setw(11)<<company<<setw(10)<<"Rs."<<price<<setw(15)<<qty<<setw(12)<<dis<<"%";

}
//-----------------------ends here------------------------------------
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
}; //class ends here
//***************************************************************
// global declaration for stream object, object
//****************************************************************
//*************************modify product
void product::modifydata(int n1,char snm[15],char companynm[15],int q)
{
char tmpnm[40],tmpnm2[40];
//(5,14);
 cout<<"===================WANT TO MODIFY ==============================="<<endl;
 //(10,15);
 cout<<"PROD NO:";
 prodid=n1;
 //(25,15);
 cout<<prodid;
 //(40,15);
 strcpy(name,snm);
 cout<<"NAME OF PROD:";
 //(60,15);
 cout<<name;
 //(10,17);
 cout<<"Want to change the name of product";
 //(50,17);
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
 {  flag=0;
    break;
    }
 }
 if(flag==1)
 { strcpy(name,tmpnm);
 }
 else
 {
 }
 //(1,18);
 strcpy(company,companynm);
 //****************COMPANY NAME TO BE MODIFY
 cout<<"COMPANY NAME:";
 //(20,18);
 cout<<company;
 //(35,18);
 cout<<"Want to change the COMPANY";
 //(65,18);
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
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(company,tmpnm2);
 }
 //*****************COMPANY NAME TO BE MODIFIED ENDS HERE
 //(5,19);
 cout<<"********MODIFY**PRODUCT PRICE - QUANTITY - DISCOUNT ***********"<<endl;
//****************************************************
//(5,20);
cout<<"PRICE:";
//(15,20);
 float tmppr=0;
flag=-1;
while(1)
 {
cin>>tmppr;
 if(tmppr!=0)
 {
flag=1;
break;
}else
{ flag=0;
 break;
}
 }
 if(flag==1)
 { price=tmppr;
 }
 else
 {
 }
//****************************************************
//****************************************************
//(22,20);
cout<<"INCREASE QUANTITY:";
//(45,20);
int tmpqty=0;
cin>>tmpqty;
qty=q;
qty=qty+tmpqty;
//***************************************************
 //***************************************************
//(50,20);
cout<<"DISCOUNT:";
//(63,20);
float tmpdis=0;
cin>>tmpdis;
dis=tmpdis;
//*****************************************
//(5,22);
 cout<<"====================================================================="<<endl;
}
//**************************class function outside
fstream fp;
product pr;
//***************************************************************
// function to write in file
//****************************************************************
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
 //(10,20);
 cout<<"***************PRODUCTS RECORD SAVED******************* "<<endl;
 cin.ignore();
 cin.get();
}
//********************check the product number already given or not******
int getproduct()
{
ifstream objiff;
product st;
int count=0;
objiff.open("product.dat",ios::binary);
objiff.seekg(0,ios::beg);
if(!objiff)
{
cout<<"File could not be open !! Press any Key...";
cin.get();
}
//**************temporary hiding these lines
while(objiff.read((char *) &st, sizeof(product)))
{
 count++;
}
//***********jump to the last line
objiff.seekg(count-sizeof(st),ios::beg);
objiff.read((char *) &st, sizeof(product));
count=st.retpno();
count++;
objiff.close();
return count;
}
//***************************************************************
// function to read specific record from file
//****************************************************************
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
cout<<"\n\nrecord not exist";
cin.get();
}
//******************************************************************
// function before place order and then call place order function
//******************************************************************
int before_order()
{ int f=-1,num=0;
 customer cust;

intromain();
//(10,8);
cout<<"*****ENTER THE CUST ID TO BE SEARCHED:";
//(55,9);
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
//*****************************************************************
//***************************************************************
// function to place order and generating bill for PRODUCT PURCHASED
//****************************************************************
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
 //(30,4);
 cout<<"============================"<<endl;
 //(30,5);
 cout<<" PLACE YOUR ORDER";
 //(30,6);
 cout<<"============================"<<endl;
do
{

 //(5,10);
 cout<<"ENTER THE PRODUCT NO: ";
 //(55,10);
 cin>>pr1;
 k=search(pr1);
 if(k>0)
 {
//(5,12);
cout<<"Enter the Quantity:";
 //(28,12);
cin>>q1;
changeqty(pr1,q1);
copyme(k,o1,q1,c);
 }else
 {
cout<<"PRODUCT not found";
 }

//(10,20);
cout<<"Do you want purchase more (Yes[ y or Y ] or NO [n or N])"<<endl;
//(10,21);
cin>>ch;
} while(ch=='y' || ch=='Y');
//***************while ends by these lines

 //(20,20);
 cout<<"Thank You For Placing The Order.........."<<endl;
 cin.get();

 intromain();
 //(13,5);
 cout<<"*************************INVOICE************************"<<endl;
 //(1,6);

cout<<"PR.No."<<setw(12)<<"NAME"<<setw(10)<<"Qty"<<setw(15)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount- discount";
 //(3,7);
 cout<<"----------------------------------------------------------------------------"<<endl;
 int yy=8;
for(int x=0;x<c;x++)
{
 //(1,yy);
 cout<<o1[x].prodid1;
 //(10,yy);
 cout<<o1[x].pname1;
 //(27,yy);
 cout<<o1[x].qty1;
 //(40,yy);
 cout<<"Rs."<<o1[x].price1;
 //(50,yy);
 amt=o1[x].qty1*o1[x].price1;
 cout<<"Rs."<<amt;
 damt=amt-o1[x].dis1;
 //(65,yy);
 cout<<"Rs."<<damt;
 total+=damt;
 //ttaxt+=o1[x].tax1;
yy++;
 }
 ttaxt=5;
 //(3,yy);
 cout<<"----------------------------------------------------------------------------"<<endl;
 yy++;
 //(25,yy);
 cout<<"TOTAL:";
 //(35,yy);
 cout<<total;
 yy++;
 //(25,yy);
 cout<<"TAX%:";
 //(36,yy);
 cout<<"+"<<ttaxt;
 yy++;
 //(25,yy);
 cout<<"----------------------------";
 yy++;
 //(25,yy);
 cout<<"NET TOTAL:";
 //(35,yy);
 cout<<(total+((ttaxt*total)/100));
 yy++;
 //(3,yy);
 cout<<"----------------------------------------------------------------------------"<<endl;
}else
{

 //(20,30);
 cout<<"************YOUR ID IS WRONG ************************************"<<endl;
}
//*****************change at the above
 cin.get();
}
//********************fuction to copy all record to a structure
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
 //*********************copy record***********************
 order1[c2].qty1=q1;
 c2++;
 objiff2.close();
}
//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
//(4,2);
cout<<"****************************CANTEEN-MANAGEMENT*************************"<<endl;
//(12,4);
cout<<"==========================================================="<<endl;
//(5,5);
cout<<"****************************S=Y=S=T=E=M********************************"<<endl;
//(50,10);
cout<<"PROJECT:";
//(50,12);
cout<<"MADE BY : BugHunters of IIIT"<<endl;
//(10,14);
cout<<endl;
cout<<"---------------SCHOOL : DOON PUBLIC SCHOOL--------------------"<<endl;
cin.get();
}
//***************************************************************
// ADMINSTRATOR MENU1 FUNCTION
//****************************************************************
void admin_menu1()
{

 char ch2;
int num;
 //************************************************************

intromain();
//(20,6);
cout<<"=================ADMIN MENU===================="<<endl;
//(22,7);
cout<<"1.CREATE CUSTOMERS DETAILS"<<endl;
//(22,8);
cout<<"2.DISPLAY ALL CUSTOMERS DETAILS"<<endl;
//(22,9);
cout<<"3.SEARCH RECORD(QUERY) "<<endl;
//(22,10);
cout<<"4.MODIFY CUSTOMERS RECORDS"<<endl;
//(22,11);
cout<<"5.DELETE CUSTOMERS RECORDS"<<endl;
//(22,12);
cout<<"6.BACK TO MAIN MENU"<<endl;
//(18,13);
cout<<"Please Enter Your Choice (1-6) "<<endl;
//(55,13);
 //**********************************************************
 ch2=cin.get();
 switch(ch2)
 {
 case '1':
write_customer();
break;
 case '2': cust_tabular();
 break;
 case '3':
 //********************

intromain();
//(10,8);
cout<<"*****ENTER THE CUST ID TO BE SEARCHED:";
//(55,9);
cin>>num;
display_cust_sp(num);
 break;
case '4':

intromain();
//(10,8);
cout<<"*****ENTER THE CUST ID TO BE SEARCHED AND MODIFY:";
//(55,9);
cin>>num;
modify_cust_record(num);
 break;
case '5':

intromain();
//(10,8);
cout<<"*****ENTER THE CUST ID TO BE SEARCHED AND TO DELETE:";
//(55,9);
cin>>num;
 deletecust_record(num);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}
//***********************MENU 1 CUSTOMERS ENDS HERE*************************
//------------------------------------------------------------------------------------
//***************************************************************
// ADMINSTRATOR MENU2 FUNCTION
//****************************************************************
void admin_menu()
{

 char ch2;
int num;
 //************************************************************

intromain();
//(20,6);
cout<<"=================ADMIN MENU===================="<<endl;
//(22,7);
cout<<"1.CREATE PRODUCTS"<<endl;
//(22,8);
cout<<"2.DISPLAY ALL PRODUCTS AVAILABEL"<<endl;
//(22,9);
cout<<"3.SEARCH RECORD(QUERY) "<<endl;
//(22,10);
cout<<"4.MODIFY PRODUCTS"<<endl;
//(22,11);
cout<<"5.DELETE PRODUCTS"<<endl;
//(22,12);
cout<<"6.BACK TO MAIN MENU"<<endl;
//(18,13);
cout<<"Please Enter Your Choice (1-6) "<<endl;
//(55,13);
 //**********************************************************
 ch2=cin.get();
 switch(ch2)
 {
 case '1':
write_book();
break;
 case '2': prod_tabular();//display_all();
 break;
 case '3':
 //********************

intromain();
//(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED:";
//(55,9);
cin>>num;
display_sp(num);
 break;
case '4':

intromain();
//(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED AND MODIFY:";
//(55,9);
cin>>num;
modify_record(num);
 break;
case '5':

intromain();
//(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED AND TO DELETE:";
//(55,9);
cin>>num;
delete_record(num);
break;
case '6': break;
default:cout<<"\a";admin_menu();
}
}
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
 char ch;
 intro();
 do
 {
 //****************TEMPORARY***********************

intromain();
//(20,6);
cout<<"=================MAIN MENU===================="<<endl;
//(28,7);
cout<<"01. PRODUCTS REPORT GENERATOR"<<endl;
//(28,8);
cout<<"02. ADMINISTRATOR"<<endl;
//(28,9);
cout<<"03. EXIT"<<endl;
//(20,10);
cout<<"=============================================="<<endl;
//(25,12);
cout<<"Please Select Your Option (1-3) "<<endl;
//(30,14);
ch=cin.get();
 switch(ch)
 {
 case '1':
orderk=0;
place_order();
cin.get();
break;
 case '2': middleadminmenu();
 break;
 case '3':exit(0);
 default :cout<<"\a";
}
 }while(ch!='3');
}
//***************main intro
void intromain()
{
//(1,2);
cout<<"**********CANTEEN******MANAGEMENT****SYSTEM******PROJECT**********************"<<endl;
//(1,3);
cout<<"******************************************************************************"<<endl;
}
//******************************************************************************
// DISPLAY ALL THE PRODUCT TABULAR FORM
//******************************************************************************
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
 }else
 {
 //(20,30);
 cout<<"--------------press any key------------------------"<<endl;
 cin.get();

 display_all();
 col=10;
 r=0;
}
}
inFile.close();
cin.get();
}
//**************************tabular forms ends**********************************
//*******************tabulars forms headings************************************
//function to display all the records of product
//**********************************************************************
void display_all()
{

intromain();
//(1,5);
cout<<" **********************PRODUCTS DETAILS***************************"<<endl;
//(1,6);
cout<<"================================================================================"<<endl;
//(1,7);
cout<<"PROD.NO"<<setw(10)<<"NAME"<<setw(15)<<"COMPANY"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<
setw(10)<<"DISCOUNT"<<endl;
//(1,8);
cout<<"================================================================================"<<endl;
}
//************************************************************
// MODIFY RECORD
//**********************************************************
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
cout<<"\n\nrecord not exist";
else
{
//*******modifying the records starts here
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
{ fpos=(int)File.tellg();
 break;
}
 }
File.seekp(fpos-sizeof(product),ios::beg);
strcpy(tmpnm,st.getname());
strcpy(tmpcompany,st.getcompany());
int q1=st.getqty();
//(1,12);
cout<<"*****************************************************************************"<<endl;
//(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE================="<<endl;
temp.modifydata(n,tmpnm,tmpcompany,q1);
File.write((char *) &temp, sizeof(product));
File.close();
 }
}
//*****************************************************************************
// DELETE THE RECORD OF THE PRODUCTC NOT AVAILABLE
//****************************************************************************
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
cout<<"\n\nrecord not exist";
else
{
//*******deletion of the records starts from here
//(1,15);
cout<<"*****************************************************************************"<<endl;
//(5,16);
cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========"<<endl;
//(2,17);
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
//(30,20);
cout<<"----------------------------Record Deleted----------------------------------"<<endl;
}
}
cin.get();
}
//***********************delete record ends************************************
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
//***********************search the product***********************
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
//cout<<"\n\nrecord not exist";
else
{
return tmprt;
}
}
//********************change quantity*************************
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
{ fpos=(int)File.tellg();
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
 //****************TEMPORARY***********************

intromain();
//(20,6);
cout<<"===========CUSTOMER'S-PRODUCT'S MENU==========="<<endl;
//(28,7);
cout<<"01. CUSTOMER'S MENU";
//(28,8);
cout<<"02. PRODUCT'S MENU";
//(28,9);
cout<<"03. BACK TO MAIN";
//(20,10);
cout<<"=============================================="<<endl;
//(25,12);
cout<<"Please Select Your Option (1-3) "<<endl;
//(30,14);
ch=cin.get();
 switch(ch)
 {
 case '1': admin_menu1();
break;
 case '2': admin_menu();
 break;
 case '3': break;
 default :cout<<"\a";admin_menu();
}
 }while(ch!='3');
}
