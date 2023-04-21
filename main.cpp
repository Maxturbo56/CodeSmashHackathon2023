#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<unistd.h>
using namespace std;

/* COMPLEXITY " BIG O" : This codebase has a O(n) complexity; 
/  DESCRIPTION : We first make the fruit combination for the day after launching the program which can later be stored inside a .txt file, then we prompt the buyer
/  to tell us which fruit he / she wishes to buy. After said prompt we check for the first item in our shopping cart "userList" which is also the first item in our awarded "codeList". Then we iterate over 
/  both lists through the other elements and if they match then both the group and listing of fruits is matching. In that case the buyer is a winner, in any other we simply tell the user to try again  next time.*/ 

string codeList[6];

//fruit combination is a string made up of many elements
void fill_Code_List()
{
	int a;
	for(int i = 0; i < 6; i++)
	{
		a = rand()%4;
		switch(a)
		{
			case 1:
			{
				codeList[i] = "banana";
				break;
			}
			case 2:
			{
				codeList[i] = "apple";
				break;
			}
			case 3:
			{
				codeList[i] = "kiwi";
				break;
			}
			case 4:
			{
				codeList[i] = "lemon";
				break;
			}
			default :
			{
				codeList[i] = "anything";
			}
		}
	}
}

int main()
{
		
	int first_Element;
	int change_Group;
	int k = 0;	
	
	srand(time(NULL));
	int n;
	
	//fills the code list
	fill_Code_List();
	
	//Reads out the specific code
	cout<<endl<<endl<<"[";
	for(int i = 0; i < 6; i++)
	{
		cout<<codeList[i];
		if(i != 5)
		{
			cout<<", ";
		}
		else if(i == 5)
		{		
			cout<<"]";
		}
	}
	
	cout<<endl<<endl<<"Please follow the prompt to Input the fruit you wish to buy : \n\n";
	cout<<"How many fruits do you wish to buy?   (Input Format : a whole number)     Your Input : ";
	cin>>n;
	string userList[n];
	int user_Choice;
	
	for(int i = 0; i < n; i++)
	{		
		if(i > 0)
		{
			cout<<"The last fruit added to your list is : "<<userList[i - 1]<<endl<<endl;
		}
	
		cout<<"\n\nClick the option for the next fruit you wish to buy : \n\t 1 : Kiwi \n\t 2 : Banana \n\t 3 : Strawberry \n\t 4 : Apple \n\t 5 : Lemon \n\t 6 : Orange \n\t 7 : Pineapple"<<endl<<"\t";
		cin>>user_Choice;
		system("cls");
		switch(user_Choice)
		{
			case 1:
			{
				userList[i] = "kiwi";
				break;
			}
			case 2:
			{
				userList[i] = "banana";
				break;
			}
			case 3:
			{
				userList[i] = "strawberry";
				break;
			}
			case 4:
			{
				userList[i] = "apple";
				break;
			}
			case 5:
			{
				userList[i] = "lemon";
				break;				
			}
			case 6: 
			{
				userList[i] = "orange";
				break;
			}
			case 7:
			{
				userList[i] = "pineapple";
				break;
			}
			default:
			{
				cout<<"\n\n\tPlease comply with the prompt given by the application. Error 308 Code : ~ 7####9 ~ "<<endl;
				i--;
				break;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout<<userList[i]<<" ";
	}

	if(n < 6)
	{
		cout<<endl<<endl<<"Thank you for your purchase. You need to buy more items to be eligable of participation. \n\n\n\t\t Try again next time.\n\n\nOutput code : 0"<<endl<<endl;
		goto end;
	}
	
	if(codeList[0] == "anything")
	{
		first_Element = 0;
		k++;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(userList[i] == codeList[0])
		{
			k++;
			first_Element = i;
			break;
		}
	}
	
	for(int i = first_Element; i < n; i++)
	{
		if(codeList[i] == "anything")
		{
			k++;
		}
		else if(userList[i] == codeList[i])
		{
			k++;
		}
				
		if(k == 6)
		{
			cout<<endl<<endl<<"1";
			break;
		}
	}
	
	end :
	
	return 0; 	
}
