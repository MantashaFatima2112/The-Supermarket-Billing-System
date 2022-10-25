#include<conio.h>
#include<string.h>
#include<iostream>
#include<fstream> //because here we are going to do the file handling operations as well
using namespace std;
class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		int product_quantity;
		
    public:
    	void menu();
    	void administrator();
    	void buyer();
    	void add();
    	void edit();
    	void rem();
    	void list();
    	void reciept();
};

void shopping :: menu()
{
	m:
	int  choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t_______________________________\n";
	cout<<"\t\t\t\t                               \n";
	cout<<"\t\t\t\t    Supermarket Main Menu      \n";
	cout<<"\t\t\t\t                               \n";
	cout<<"\t\t\t\t_______________________________\n";
	cout<<"\t\t\t\t                               \n";
	
	cout<<"\t\t\t\t| 1) Administrator  |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t| 2) Buyer          |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t| 3) Exit           |\n";
	cout<<"\t\t\t\t|                   |\n";
	
	cout<<"\n\t\t\t Please select!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login\n";
			cout<<"\t\t\t Enter Email \n";
			cin>>email;
			cout<<"\t\t\tPassword     \n";
			cin>>password;
			
			if(email=="mantasha28964@gmail.com" && password=="project@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password";
				
			}
			break;
			
	    case 2:
		    {
			   buyer();
			}
			
		case 3:
		   {
			exit(0);
			}
		default:
		    {
			cout<<"Please select from the given options";
			}			
	}
	goto m;
}

void shopping :: administrator()
{
	m:
	int choice;
	cout<<"\n\n\nt\t\t Administrator menu";
	cout<<"\n\t\t\t|____1) Add the product____|";
    cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____2) Modify the product_|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____3) Delete the product_|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|____4) Back to main menu__|";
	
	cout<<"\n\n\t Please enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
		    edit();
			break;
		case 3:
		    rem();
			break;
		case 4:
		    menu();
			break;
		default:
		    cout<<"Invalid choice!";
					
	}
	goto m;
}

void shopping :: buyer()
{
	m:
	int choice;
	cout<<"\t\t\t  Buyer \n";
	cout<<"\t\t\t________________\n";
	cout<<"\t\t\t  1)Buy Product \n";
	cout<<"                      \n";
	cout<<"\t\t\t  2) Go back    \n";
	cout<<"\t\t\t________________\n";
	cout<<"\t\t\t Enter your choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			reciept();
			break;
		case 2:
		    menu();
		
		default:
			cout<<"Invalid choice";
			
		     	
				
	}	
	
	goto m;
		
}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	int pq;
	
	cout<<"\n\n\t\t\t Add new product : ";
	cout<<"\n\n\t Product code of the product : ";
	cin>>pcode;
	cout<<"\n\n Name of the product : ";
	cin>>pname;
	cout<<"\n\n\t Price of the product : ";
	cin>>price;
	cout<<"\n\n\t Discount on product : ";
	cin>>dis;
	cout<<"\n\n\t Quantity of the product : ";
	cin>>product_quantity;
	
	data.open("database.txt", ios::in); //ios in for reading mode , ios out for writing mode
	
	if(!data)
	{
		data.open("database.txt",ios::app| ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<product_quantity<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d>>pq;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d>>pq;
	}
		data.close();
	
    
	if(token==1)
	{
		goto m;
	}
	else
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<product_quantity<<"\n";
		data.close();
	}
}
	cout<<"\n\n\t\tRecord Inserted !";
	
}

void shopping :: edit()
{
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	int pq;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :   ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File does not exists!";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis>>product_quantity;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				cout<<"\n\t\t Quantity of the product : ";
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" "<<pq<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
				
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<product_quantity<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis>>product_quantity;
		}
		data.close();
	    data1.close();
	
	    remove("database.txt");
	    rename("database1.txt", "database.txt");
	
	    if(token==0)
	    {
		cout<<"\n\n Record not found sorry !";
	    }
	}
	
}

void shopping ::rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t\t Delete the record";
	cout<<"\n\t\t\t Product code :   ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
		
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis>>product_quantity;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<product_quantity<<"\n";
			}
			data>>pcode>>pname>>price>>dis>>product_quantity;
			
		}
		data.close();
		data1.close();
		remove("database.txt");
	    rename("database1.txt", "database.txt");
		if(token==0)
	    {
		cout<<"\n\n Record not found sorry !";
	    }
		
	}
	
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n|_______________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|________________________________________\n";
	data>>pcode>>pname>>price>>dis>>product_quantity;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis>>product_quantity;
		
	}
	data.close();
	
	
}

void shopping::reciept()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		
		list();
		cout<<"\n__________________________________________\n";
		cout<<"\n|                                         \n";
		cout<<"\n      Please place the order              \n";
		cout<<"\n|                                         \n";
		cout<<"\n__________________________________________\n";
		do
		{
		   m:
		   cout<<"\n\nEnter the product code :";
		   cin>>arrc[c];
		   cout<<"\n\nEnter the quantity     :";
		   cin>>arrq[c];
		   if(arrq[c]>product_quantity)
		   {
		   	cout<<"Sorry! Please enter lesser quanity ";
		   	goto m;
		   }
		   for(int i=0; i<c; i++)
		   {
		     if(arrc[c]==arrc[i])
			 {
			    cout<<"\n\n Duplicate product code. Please try again!";
				goto m;	
			 }	
		   }
		   c++;
		   cout<<"\n\n Do you want to buy another product? if YES press y else n";
		   cin>>choice;	
		}
		while(choice=='y');
		cout<<"\n\n\t\t\t_______________________RECEIPT__________________\n";
		cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount with dicount\n";
		
		for(int i=0; i<c; i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis>>product_quantity;
			
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis<<"\t\t"<<product_quantity;
					
					
				}
				data>>pcode>>pname>>price>>dis>>product_quantity;
			}
		}
		data.close();
				
				
	}
	cout<<"\n\n___________________________________________________";
	cout<<"\n Total Amount : "<<total;
	
	int customer_money;
	
	cout<<"Please pay the amount \n";
	cin>>customer_money;
	
	cout<<"Amount to get refund to the customer :"<<customer_money-total;
	
	
}
int main()
{
	shopping s;
	s.menu();
	
}


