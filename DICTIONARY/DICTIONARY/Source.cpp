#include<iostream>
#include<conio.h>

using namespace std;

struct dict //creating a structure (dict)
{
	struct dict* left, * right; //creating pointers for the structure
	char word[20], meaning[30]; //character variables
}*Root=NULL; //global pointer of type structure

typedef dict dictionary; //typedef for the specified datatype 

//functions used in program
void search(); 
void insert(dictionary *temp);
void view(dictionary *);
int check(char[], char[]);

int main()
{
	int choice=0; //variable for condition
	dictionary* temp; //pointer created 
	while (choice != 4) //while condition to be terminated at choice = 4
	{
		system("CLS");
		cout << "\t\t   ****************************" << endl;
		cout << "\t\t***DICTIONARY USING BINARY TREE***" << endl;
		cout << "\t\t   ****************************" << endl;
		cout << "\n\n\n\n";
		cout << "\t**********" << endl;
		cout << "\t1. SEARCH" << endl;
		cout << "\t2. INSERT" << endl;
		cout << "\t3. VIEW" << endl;
		cout << "\t4. QUIT" << endl;
		cout << "\t**********" << endl;
		cout << "\n\n\n\n";
		cout << "\t\tENTER YOUR CHOICE : ";
		cin >> choice;
		switch (choice) 
		{
		case 1:
			system("CLS");
			search();
			system("pause");
			break;
		case 2:
			system("CLS");
			temp = (dictionary*)malloc(sizeof(dictionary));
			temp->left = NULL;
			temp->right = NULL;
			cout << "\t\tENTER THE WORD : ";
			cin >> temp->word;
			cout << "\t\tENTER MEANING : ";
			cin >> temp->meaning;
			insert(temp);
			system("pause");
			break;
		case 3:
			system("CLS");
			view(Root);
			system("pause");
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}

//check function works to find where the word is to be placed in the tree
int check(char a[], char b[])
{
	int i, j, c;
	for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
	{
		if (a[i] > b[j])
		{
			c = 1;
			break;
		}
		else if (a[i] < b[j])
		{
			c = -1;
			break;
		}
		else
		{
			c = 0;
		}
	}
	if (c == 1)
	{
		return 1;
	}
	else if (c == -1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//search function to find a specific word from the dictionary
void search()
{
	char w[30];
	dictionary *temporary; //pointer
	temporary = Root; //starting from the root
	int flag = 0; //loop breaking variable
	cout << "\t\tENTER THE WORD TO SEARCH : ";
	cin >> w;
	while (temporary != NULL && flag == 0)
	{
		if (check(w, temporary->word) == 1)
		{
			temporary = temporary->right;
		}
		else if (check(w, temporary->word) == -1)
		{
			temporary = temporary->left;
		}
		else
		{
			flag = 1;
			cout << "\t\tMEANING OF THE WORD : " << temporary->meaning << endl;
			break;
		}
	}
	if (flag == 0 && temporary == NULL)
	{
		cout << "\t\tCAN'T FIND THE WORD" << endl;
	}
}

//insert function to add data in the dictionary
void insert(dictionary *temp)
{
	dictionary* temporary, *ptr=NULL; //two pointers 
	temporary = Root; //starting from the root
	int flag = 0; //loop terminating variable
	if (Root == NULL)
	{
		Root = temp;

	}
	else
	{
		while (temporary != NULL && flag == 0)
		{
			if (check(temp->word, temporary->word) > 0)
			{
				ptr = temporary;
				temporary = temporary->right;
			}
			else if (check(temp->word, temporary->word) < 0)
			{
				ptr = temporary;
				temporary = temporary->left;
			}
			else //if word already exists hen don't add
			{
				flag = 1;
				cout << "\t\tWORD ALREADY EXIST IN THE DICTIONARY" << endl;
				break;
			}
		}
		if (flag == 0)
		{
			if (check(ptr->word, temp->word) == 1)
			{
				ptr->left = temp;
			}
			else if (check(ptr->word, temp->word) == -1)
			{
				ptr->right = temp;
			}
		}
	}
}

//view function to view whole dictionary
void view(dictionary* temporary)
{
	if (Root == NULL)
	{
		cout << "\t\tDICTIONARY IS EMPTY" << endl;
	}
	else
	{
		if (temporary != NULL) //recursion to get to the end
		{
			view(temporary->left);
			cout << "\t\t" << temporary->word << "->" << temporary->meaning << endl;
			view(temporary->right);
		}
	}
}