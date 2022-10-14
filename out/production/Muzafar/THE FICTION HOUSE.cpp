#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class The_Fiction_House{
		public:
			void control_panel();
			void add_book();
			void show_books();
			void check_book();
			void update_book();
			void del_book();
};
	void The_Fiction_House::control_panel(){
		system("cls");
		cout<<"\n\n\t\t\tControl Panel";
		cout<<"\n\n 1. Add New Book ";
		cout<<"\n 2. Display Books ";
		cout<<"\n 3. Check availibilty of specific book ";
		cout<<"\n 4. Update Books ";
		cout<<"\n 5. Delete Book ";
		cout<<"\n 6. Exit.";
	}
	void The_Fiction_House::add_book()
{
	system("cls");
	fstream article;
	int n_copies;
	string b_name, a_name, b_id;
	cout<<"\n\n\t\t\tADD NEW BOOK";
	cout<<"\n\nEnter Book Name: ";
	cin>>b_name;
	//getline(cin,b_name);
	cout<<"\n\n\t\t Enter Book ID: ";
	cin>>b_id;
	cout<<"\n\nAuthor Name: ";
	cin>>a_name;	
	//getline(cin,a_name);
	cout<<"\n\n\t\tNumber of Copies: ";
	cin>>n_copies;
	article.open("E://The_Fiction_House.txt",ios::out|ios::app);//without append each time previous data will be deleted and new datawill be saved	 	
	//ios::out is used to write a file.
	article<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<n_copies<<endl;
	article.close();

}
	void The_Fiction_House::show_books(){
		system("cls");
		fstream article1;
		int n_copies;
		string b_id,b_name,a_name;
		cout<<"\n\n\t\t\tSHOWING DATA "<<endl;																																																																																																																																																																																																																																																																																																														 				
		article1.open("E://The_Fiction_House.txt",ios::in);
		if(!article1){
			cout<<"\n\nFILE OPENING ERROR...";
		}
		else
			cout<<endl<<endl<<"Book ID \tBook Name \t\tAuthor Name \t\t\tNumber of Copies "<<endl;
			article1>>b_id>>b_name>>a_name>>n_copies;
			while(!article1.eof()){
			cout<<b_id<<" \t\t"<<b_name<<" \t\t\t"<<a_name<<" \t\t\t"<<n_copies<<endl;
			article1>>b_id>>b_name>>a_name>>n_copies;
}
			article1.close();
	}
	
	void The_Fiction_House::check_book(){
		system("cls");
		fstream article2;
		int no_copies;
		int count=0;
		string b_id,b_name,a_name,b_idd;
		cout<"\n\n\n\t\tCHECKING AVAILIBILITY OF SPECIFIC BOOKS";
		article2.open("E://The_Fiction_House.txt",ios::in);
		if(!article2){
			cout<<"FILE OPENING ERROR...";
		}
		else{
			cout<<"\n\nEnter Book ID: ";
			cin>>b_idd; 
			article2>>b_id>>b_name>>a_name>>no_copies;
			while(!article2.eof()){//eof will run the file untill the file data does not ends.
				if(b_idd==b_id){
					system("cls");
					cout<"\n\n\n\t\tCHECKING AVAILIBILITY OF SPECIFIC BOOKS";
					cout<<"\n\nBook id: "<<b_id;
					cout<<"\n\nBook Name:"<<b_name;
					cout<<"\n\nAuthor Name: "<<a_name;
					cout<<"\n\nNumber of available copies: "<<no_copies;
					count++;
					break;
				}
			article2>>b_id>>b_name>>a_name>>no_copies;
			}
			article2.close();
			if(count==0)
			cout<<"\n\nSORRY BOOK NOT FOUND...\n\nTry another one ";
					
		}
			 
			}
		void The_Fiction_House::update_book()
		{
			system("cls");
			fstream article3,article31;
			int no_copies,no_cop,count=0;
			string b_id,b_ide,b_name,a_name,b_nam,a_nam;
			cout<<"\n\n\nUPDATING THE BOOK RECORDS";
			article3.open("E://The_Fiction_House.txt",ios::in);
			article31.open("E://The_Fiction_House1.txt",ios::app|ios::out); 
			if(!article3){
				cout<<"\n\nERROR IN FILE OPENING...";
				
			}
			else{
				cout<<"\n\nBook ID: ";
				cin>>b_id;
				article3>>b_ide>>b_name>>a_name>>no_copies;
				while(!article3.eof()){
					if(b_id==b_ide)
						{
							system("cls");
							cout<<"\n\n\t\t\tUPDATING THE BOOK RECORDS";
							cout<<"\n\nEnter New Book Name: ";
							cin>>b_nam;
							cout<<"\n\nEnter new author name:";
							cin>>a_nam;
							cout<<"\n\nEnter number of copies: ";
							cin>>no_cop;
							article31<<" "<<b_id<<" "<<b_nam<<" "<<a_nam<<" "<<no_cop;
							count++;
						}
					else
						article31<<" "<<b_ide<<" "<<b_name<<" "<<a_name<<" "<<no_copies;
					article3>>b_ide>>b_name>>a_name>>no_copies;
				}
				if(count==0)
				cout<<"\n\nBook ID NOT FOUND...";
			}
			article3.close();
			article31.close();
			remove("E://The_Fiction_House.txt");
			rename("E://The_Fiction_House1.txt","E://The_Fiction_House.txt");
		}
	void The_Fiction_House::del_book()
	{
		system("cls");
		fstream article4,article41;
		int no_copies,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\n\t\t\t\tDeleting Book Record: ";
		article41.open("E://The_Fiction_House1.txt",ios::app|ios::out);
		article4.open("E://The_Fiction_House.txt",ios::in);
		if(!article4){
				cout<<"\n\nERROR IN FILE OPENING...";	
			}
		else
		{
			cout<<"\n\nEnter the ID of book you want to delete: ";
			cin>>b_id;
			article4>>b_idd>>b_name>>a_name>>no_copies;
			while(!article4.eof())
			{
				if(b_id ==b_idd)
				{
					system("cls");
					cout<<"\n\n\n\t\t\tDeleting Book Record";
					cout<<"\n\nBook Record deleted succesfully";
					count++;
				}
				else
				article41<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copies<<"\n";
				article4>>b_idd>>b_name>>a_name>>no_copies;
			}
			if(count==0)
			cout<<"\n\nRecord Not Found ";
		}
		article4.close();
		article41.close();
		remove("E://The_Fiction_House.txt");
		rename("E://The_Fiction_House1.txt","E://The_Fiction_House.txt");
	}
			

int main(){
	int choice;
	char will;
	The_Fiction_House tfh;
	p:
	tfh.control_panel();
	cout<<"\n\n What Do you want to do: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do{
			tfh.add_book();
			cout<<"\n\nDo you want to add another book?(y/n) ";
			cin>>will;
		}while(will == 'y');
			cout<<"Press any key to continue: ";
			break;
		case 2:
			tfh.show_books(); 
			break;
		case 3:
			tfh.check_book();
			break;
		case 4:
			tfh.update_book();
			break;
		case 5:
			tfh.del_book();
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\n Invalid Choice... \nPlease Try Again";
	}
	getch();
	goto p;
	
}





