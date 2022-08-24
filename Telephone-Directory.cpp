#include<bits/stdc++.h>

using namespace std;

class tel
{
	private:
		char name[30],email[40],add[90];
		char hmobno[11],wmobno[11],fax[12];
		long pcode;
	public:
		void input();
		void show();
		char* retnum()
		{
			return hmobno;
		}
		char* retmobno()
		{
			return wmobno;
		}
		char* retname()
		{
			return name;
		}
		tel()
		{
			pcode=0;
			strcpy(name,"Null");
			strcpy(email,"Null");
			strcpy(add,"Null");
		}
};

void adddata()
{
	ofstream fout("data.dat",ios::app|ios::binary);
	tel e;
	cout<<"Enter the data (Use '_' in place of space):-"<<endl;
	e.input();
	fout.write((char*)&e, sizeof(e));
}

void tel::input()
{
	cout<<"\tEnter Customer Name:";
	cin>>name;
	cout<<"\tEnter Customer Address:";
	cin>>add;
	cout<<"\tEnter Email Address:";
	cin>>email;
	cout<<"\tEnter Mobile Number (10 Digit):";
	cin>>wmobno;
	cout<<"\tEnter Home Mobile Number (10 Digit):";
	cin>>hmobno;
	cout<<"\tEnter FAX Number:";
	cin>>fax;
	cout<<"\tEnter Pincode:";
	cin>>pcode;
	cout<<"\n\t\tProcessing...............";
	for(long i=0;i<999999999;i++); //for timer
	cout<<"\tRecord Added...."<<endl;
}

void tel::show()
{
	cout<<"********************************************************************************"<<"||"<<endl;
	cout<<"||\tCustomer Name:";
	cout<<"\t"<<name<<endl;
	cout<<"||\tAddress:";
	cout<<"\t"<<add<<endl;
	cout<<"||\tEmail ID:";
	cout<<"\t"<<email<<endl;
	cout<<"||\tMobile Number:";
	cout<<"\t"<<wmobno<<endl;
	cout<<"||\tHome Number:";
	cout<<"\t"<<hmobno<<endl;
	cout<<"||\tFAX Number:";
	cout<<"\t"<<fax<<endl;
	cout<<"||\tPincode:";
	cout<<"\t"<<pcode<<endl;	
	cout<<"||"<<endl<<"********************************************************************************"<<endl<<endl;
}

void dispdata()
{
	ifstream fin("data.dat",ios::binary);
	if(!fin)
	{
		cout<<"File not Open!!";
		exit(0);
	}
	tel e;
	int l=0;
	while(fin.read((char*)&e,sizeof(e)))
	{
		e.show();
		l++;
	}
	if(l==0)
	cout<<"No Record Found.";
	fin.close();
}

void searchnum()
{
	ifstream fin("data.dat",ios::binary);
	if(!fin)
	{
		cout<<"File not Open!!";
		exit(0);
	}
	tel e;
	int l=0;
	char n[11];
	cout<<"Enter the Number to be searched:";
	cin>>n;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if((strcmpi(e.retnum(),n)==0)||(strcmpi(e.retmobno(),n)==0))
		{
			e.show();
			l++;
		}
	}
	if(l==0)
	cout<<"Record Not Found.";
	fin.close();
}

void searchname()
{
	ifstream fin("data.dat",ios::binary);
	if(!fin)
	{
		cout<<"File not Open!!";
		exit(0);
	}
	tel e;
	char ch[20];
	int l=0;
	cout<<"Enter the Name to be searched:";
	gets(ch);
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(strcmpi(e.retname(),ch)==0)
		{
			e.show();
			l++;
		}
	}
	if(l==0)
	cout<<"Record Not Found.";	
	fin.close();
}

void deldata()
{
	ofstream fout("xyz.dat",ios::binary);
	ifstream fin("data.dat",ios::binary);
	if(!fin)
	{
		cout<<"File not Open!!";
		exit(0);
	}
	tel e;
	int l=0;
	char n[11];
	cout<<"Enter the Number to be deleted:";
	cin>>n;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if((strcmpi(e.retnum(),n)==1)||(strcmpi(e.retmobno(),n)==1))
		{
			fout.write((char*)&e,sizeof(e));
			l++;
		}
	}
	if(l==0)
	cout<<"Record Not Found.";
	else if(l!=0)
	cout<<"Record has been Deleted.";
	fin.close();
	fout.close();
	remove("data.dat");
	rename("xyz.dat","data.dat");
}

void updata()
{
	fstream fin("data.dat",ios::in|ios::out|ios::binary);
	if(!fin)
	{
		cout<<"File not Open!!";
		exit(0);
	}
	tel e;
	int l=0;
	char n[11];
	cout<<"Enter the Number to be updated:";
	cin>>n;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if((strcmpi(e.retnum(),n)==0)||(strcmpi(e.retmobno(),n)==0))
		{
			e.input();
			fin.seekp(-1*sizeof(e),ios::cur);
			fin.write((char*)&e,sizeof(e));
		}
	}
	cout<<"\tFile has been Updated!!";
	fin.close();
}

int main()
{
	int n; char ch='y';
	while(ch=='y' || ch=='Y')
	{
		cout<<"\n********************************************************************************"<<endl;
		cout<<"\t\t      =========TELEPHONE DIRECTORY========="<<endl<<endl;
		cout<<"\t\t\t\t    $MENU$"<<endl<<endl;
		cout<<"\t\t\t#1. Add Data."<<endl;
		cout<<"\t\t\t#2. Display Data."<<endl;
		cout<<"\t\t\t#3. Search by Number."<<endl;
		cout<<"\t\t\t#4. Search by Name."<<endl;
		cout<<"\t\t\t#5. To Delete Data."<<endl;
		cout<<"\t\t\t#6. To Update Data."<<endl;
		cout<<"\t\t\t#0. Exit."<<endl<<endl;
		cout<<"********************************************************************************"<<endl;
		cout<<"\t\tEnter your choice:";
		cin>>n;
		system("cls");
		cout<<endl;
		switch(n)
		{
			case 1: adddata();
					break;
			case 2: dispdata();
					break;		
			case 3: searchnum();
					break;
			case 4: searchname();
					break;
			case 5: deldata();
					break;
			case 6: updata();
					break;
			case 0: {	
						cout<<"Thanks for visit!!!!!!";
						exit(0);
						break;
					}
			default: cout<<"Wrong choice.";
		}
		cout<<"\nDo you want to continue  Y/N ?\n";
		cin>>ch;
		system("cls");
		cout<<"********************************************************************************"<<endl;
	}
	return(0);
}
