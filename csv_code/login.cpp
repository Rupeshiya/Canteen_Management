#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
int Login(){
	label:
	system("cls");
	cout<<"1.REGISTER"<<endl;
	cout<<"2.LOGIN"<<endl;
	cout<<"3.EXIT"<<endl;
	string p,q,w;
	int x;
    string s;
	cin>>x;
	if(x==1){

			system("cls");
  			ofstream fout;
  			cout<<"ENTER YOUR USERNAME"<<endl;
  			cin>>s;
  			cout<<"ENTER YOUR PASSWORD"<<endl;
  			cin>>p;
  			s=s+p;
  			ifstream fin;
  			string line;
  			int offset=0;
  			fin.open("myfile.txt");
  			if(fin.is_open())
  			{
  				while(!fin.eof())
  				{
  					getline(fin,line);
					if(line.find(s,0)!=-1)
					{
						cout<<"sorry! this username is not available"<<endl;
						cout<<"Press any key to go to Home Page"<<endl;
						char kk;
						cin>>kk;
						goto label;
						//break;
					}
				}
			}
  			fin.close();
  			fout.open("myfile.txt",ios::app);
  			fout<<s+"\n";
  			fout.close();
	}
		else if(x==2){

			string line;
			system("cls");
  			ifstream fin;
  			int offset=0;
  			cout<<"ENTER YOUR USERNAME"<<endl;
  			cin>>q;
  			cout<<"ENTER YOUR PASSWORD"<<endl;
  			cin>>w;
  			q=q+w;
  			fin.open("myfile.txt");
  			if(fin.is_open())
  			{
  				while(!fin.eof())
  				{
  					getline(fin,line);
					if(line.find(q,0)!=-1)
					{
						cout<<"you are logged in"<<endl;
						offset=1;
						break;
						  }
				}
				if(offset==0)
				{
					cout<<"sorry you are unauthorised!!"<<endl;
					cout<<"Press 1 and enter to go to home page"<<endl;
					//getch();
					char o;
					cin>>o;
					goto label;
								  }
			}
  			fin.close();
	}
	else if(x==3){
		return 0;
	}else{
	    goto label;
	}
    
}
int main()
{
    Login();
    return(0);
}