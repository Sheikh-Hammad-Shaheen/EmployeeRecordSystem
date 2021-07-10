#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
struct rec
{
	char *name;
	int id;
	char *des;
	char *dep;
	int sal;
	void display()
	{
		cout << "Name :\t**** " << name << endl;
		cout << "id :\t**** " << id<<endl;
		cout << "Designation :\t**** " << des<<endl;
		cout << "Department :\t**** " << dep << endl;
		cout << "Salary :\t**** " << sal << endl;

	}
};
int record;
rec *recordArr = NULL;
//rec*recordArr2 = nullptr;
char *grow(char str[], int &size)
{
	char *newstr = new char[size + 1];
	for (int i = 0; i<size; i++)
	{
		newstr[i] = str[i];
	}
	//size++;
	if (size != 0)
		delete[]str;
	newstr[size++] = '\0';
	return newstr;
}
void structgrow(int &size)
{
	rec *temp = new rec[++size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = recordArr[i];
	}

	if (size != 0)
		delete[]recordArr;
	recordArr = temp;
}
void menu()
{
	cout << "\t******MENU FUNCTION******";
	cout << endl << endl;
	cout << "       ";
	cout << endl << "\t  b :: Build record ";
	cout << endl << "\t  i :: Add A New Record ";
	cout << endl << "\t  s :: Search Record From Employee Id ";
	cout << endl << "\t  d :: Display All Employees ";
	cout << endl << "\t  e :: Update Record of An Employee ";
	cout << endl << "\t  r :: Delete record of particular Employee  ";
	cout << endl << "\t  q :: Exit from Program  " << endl;
	cout << endl << "\t  Select your choice ";
	cout<<endl;
}
bool present(int tempid)
{
	for (int i = 0; i <= record - 1; i++)
	{
		if (recordArr[i].id == tempid)
		{
			cout << "This id already exits ";
			return false;
		}
	}
	return true;
}
void Add()
{
	system("cls");
	int tempsize = 0;
	char ch = '\0';
	cout << endl << "Enter number of records  ";
	cin >> record;
	recordArr = new rec[record];
	for (int i = 0; i <= record - 1; i++)
	{
		cout << "Enter name ___ ";
		cin >> ch;
		while (ch != '\n')
		{
			recordArr[i].name = grow(recordArr[i].name, tempsize);
			recordArr[i].name[tempsize - 1] = ch;
			cin.get(ch);
		}
		recordArr[i].name = grow(recordArr[i].name, tempsize);
		tempsize = 0;
		cout << "Enter Id ___ ";
		int tempid = 0;
		cin >> tempid;
		if (present(tempid))
			recordArr[i].id = tempid;
		cout << "Enter Department ___";
		cin >> ch;
		while (ch != '\n')
		{
			recordArr[i].dep = grow(recordArr[i].dep, tempsize);
			recordArr[i].dep[tempsize - 1] = ch;
			cin.get(ch);
		}
		recordArr[i].dep = grow(recordArr[i].dep, tempsize);
		tempsize = 0;
		cout << "Enter designation ___";
		cin >> ch;
		while (ch != '\n')
		{
			recordArr[i].des = grow(recordArr[i].des, tempsize);
			recordArr[i].des[tempsize - 1] = ch;
			cin.get(ch);
		}
		recordArr[i].des = grow(recordArr[i].des, tempsize);
		tempsize = 0;
		cout << "Enter salary ___";
		cin >> recordArr[i].sal;
		cout << endl << endl;
	}
	cout << "Going to main menu ";
}

void Addfile()
{
	system("cls");
	ifstream fin;
	char ch = '\0';
	int tempsize = 0;
	cout << " the order of file data must be ";
	cout << endl << " Name  Id  Designation  Department  Salary ";
	char filename[200] = { '\0' };
	int i = 0;
	cout<<endl;
	cin.getline(filename, 20, '\n');
	while (true)
	{
		cout << " enter file name ";
		cin.getline(filename, 20, '\n');
		fin.open(filename, ios::in);
		if (!fin)
			cout << " file not found " << endl;
		else
			break;
	}

	while (!fin.eof())
	{
		if (fin.eof())
			break;
		structgrow(record);
		fin >> ch;
		while (ch != ' ')
		{
			recordArr[record - 1].name = grow(recordArr[record - 1].name, tempsize);
			recordArr[record - 1].name[tempsize - 1] = ch;
			fin.get(ch);
		}
		recordArr[record - 1].name = grow(recordArr[record - 1].name, tempsize);
		tempsize = 0;
		int tempid = 0;
		fin >> tempid;
		recordArr[record - 1].id = tempid;
		fin >> ch;
		while (ch != ' ')
		{
			recordArr[record - 1].dep = grow(recordArr[record - 1].dep, tempsize);
			recordArr[record - 1].dep[tempsize - 1] = ch;
			fin.get(ch);
		}
		recordArr[record - 1].dep = grow(recordArr[record - 1].dep, tempsize);
		tempsize = 0;
		fin >> ch;
		while (ch != ' ')
		{
			recordArr[record - 1].des = grow(recordArr[record - 1].des, tempsize);
			recordArr[record - 1].des[tempsize - 1] = ch;
			fin.get(ch);
		}
		recordArr[record - 1].des = grow(recordArr[record - 1].des, tempsize);
		tempsize = 0;
		fin >> recordArr[record - 1].sal;
	}
	cout<<endl;
	cout << "Going to main menu ";
	cout<<endl<<endl<<" Data has been read from input file ";
	cout<<endl<<endl;
}
void editmenu()
{
	system("CLS");
	cout << "  what do u want to edit  " << endl;
	cout << " n______ name " << endl;
	cout << " i______ id " << endl;
	cout << " d______ designation " << endl;
	cout << " f______ field " << endl;
	cout << " s______ salary " << endl;
	cout << " q______ quit " << endl;
	cout << " insert option ____>> ";
}
void editname(int i)
{
	cout << " enter new name ____ ";
	char ch = { '\0' };
	char *temp = NULL;
	int tempsize = 0;
	cin >> ch;
	while (ch != '\n')
	{
		temp = grow(temp, tempsize);
		temp[tempsize - 1] = ch;
		cin.get(ch);
	}
	temp = grow(temp, tempsize);
	delete[]recordArr[i].name;
	recordArr[i].name = temp;
	temp = NULL;
	tempsize = 0;
}
void deletesit(void)
{
	for (int i = 0; i<record; i++)
	{
		delete[]recordArr[i].name;
		delete[]recordArr[i].des;
		delete[]recordArr[i].dep;
	}
	delete[]recordArr;
}
void list()
{
	system("cls");
	cout << " ***List of all data*** " << endl;
	cout << "\tName\tId\tDesignation\tDepartment\tSalary ";
	cout << endl;
	cout << "\t------------------------------------------------------" << endl;

	for (int i = 0; i <= record - 1; i++)
	{

		cout << "\t" << recordArr[i].name;
		cout << "\t" << recordArr[i].id;
		cout << "\t" << recordArr[i].des;
		cout << "\t\t" << recordArr[i].dep;
		cout << "\t\t" << recordArr[i].sal;

		cout << endl;
	}
	cout << endl;
	cout << " going to main menu ";
}
void editcode(int i)
{
	cout << " enter new code ____ ";
	int teid = 0;
	cin >> teid;
	recordArr[i].id = teid;

}
void listfile()
{

	ofstream fout;
	char filnam[20] = { '\0' };
	cout << " enter filename ";
	cin>>filnam;
	cout<<endl;
	fout.open(filnam,ios::out);
	fout << " ***List of all data*** " << endl;
	fout << "\tName\tId\tDesignation\tDepartment\tSalary ";
	fout << endl;
	fout << "\t------------------------------------------------------" << endl<<endl;
	cout << " Data is transfered to output file ";
	cout<<endl;
	for (int i = 0; i <= record - 1; i++)
	{

		fout << "\t" << recordArr[i].name;
		fout << "\t" << recordArr[i].id;
		fout << "\t" << recordArr[i].des;
		fout << "\t\t" << recordArr[i].dep;
		fout << "\t\t" << recordArr[i].sal;

		fout << endl;
	}
	fout << endl;
}
void editdes(int i)
{
	char ch = { '\0' };
	char *temp = NULL;
	int tempsize = 0;
	cout << " enter designation ____ ";
	cin >> ch;
	while (ch != '\n')
	{
		temp = grow(temp, tempsize);
		temp[tempsize - 1] = ch;
		cin.get(ch);
	}
	temp = grow(temp, tempsize);
	delete[]recordArr[i].des;
	recordArr[i].des = temp;
	temp = NULL;
	tempsize = 0;
}
void  editdep(int i)
{
	cout << " enter department ____ ";
	char ch = { '\0' };
	char *temp = NULL;
	int tempsize = 0;
	cin >> ch;
	while (ch != '\n')
	{
		temp = grow(temp, tempsize);
		temp[tempsize - 1] = ch;
		cin.get(ch);
	}
	temp = grow(temp, tempsize);
	delete[]recordArr[i].dep;
	recordArr[i].dep = temp;
	temp = NULL;
	tempsize = 0;
}
void editsalary(int i)
{
	cout << " enter salary ____ ";
	int slr = 0;
	cin >> slr;
	recordArr[i].sal = slr;
}
void edit()
{
	system("cls");
	int id;
	cout << " edit entry ";
	cout << endl;
	cout << endl;
	int i;
	char option;
	cout << "Enter An id to edit entry----  ";
	cin >> id;
	editmenu();
	for (i = 0; i <= record - 1; i++)
	{
		if (recordArr[i].id == id)
		{
			while ((option = cin.get()) != 'q')
			{

				switch (option)
				{
				case 'n':
					editname(i);
					cout<<"Press q to quit ";
					break;

				case 'i':
					editcode(i);
					cout<<"Press q to quit ";
					break;

				case 'd':
					editdes(i);
					cout<<"Press q to quit ";
					break;

				case 'f':
					editdep(i);
					cout<<"Press q to quit ";
					break;
				case 's':
					editsalary(i);
					cout<<"Press q to quit ";
					break;
				}

			}
			editmenu();
		}
	}
}
void search()
{
	system("cls");
	cout << "Welcome To Search Of Employee Database ";
	cout << endl;
	cout << endl;
	int id;
	cout << "You Can Search Only By id Of An Employee";
	cout << endl << "Enter Code Of An Employee ";
	cin >> id;
	bool flag = false;
	for (int i = 0; i <= record - 1; i++)
	{
		if (recordArr[i].id == id)
		{
			cout << "\tName\tCode\tDesignation\tdepartment\tsalary " << endl;
			cout << "------------------------------------------------------ ";
			cout << endl;
			cout << "\t" << recordArr[i].name;
			cout << "\t" << recordArr[i].id;
			cout << "\t" << recordArr[i].des;
			cout << "\t\t" << recordArr[i].dep;
			cout << "\t\t" << recordArr[i].sal;
			flag = 1;
		}
	}
	if (!flag)
		cout << "this id is not found ";

	cout << endl;
	cout << " main menu ";

}
void insert()
{
	system("cls");
	char ch = { '\0' };
	int tempsize = 0;
	int i = record;
	structgrow(record);
	cout << "Enter name ___";
	cin >> ch;
	while (ch != '\n')
	{
		recordArr[record - 1].name = grow(recordArr[i].name, tempsize);
		recordArr[record - 1].name[tempsize - 1] = ch;
		cin.get(ch);
	}
	recordArr[record - 1].name = grow(recordArr[i].name, tempsize);
	tempsize = 0;
	cout << "Enter Id ___";
	int tempid = 0;
	cin >> tempid;
	if (present(tempid))
		recordArr[i].id = tempid;
	cout << "Enter Department ___";
	cin >> ch;
	while (ch != '\n')
	{
		recordArr[record - 1].dep = grow(recordArr[i].dep, tempsize);
		recordArr[record - 1].dep[tempsize - 1] = ch;
		cin.get(ch);
	}
	recordArr[record - 1].dep = grow(recordArr[i].dep, tempsize);
	tempsize = 0;
	cout << "Enter designation ___";
	cin >> ch;
	while (ch != '\n')
	{
		recordArr[i].des = grow(recordArr[i].des, tempsize);
		recordArr[i].des[tempsize - 1] = ch;
		cin.get(ch);
	}
	recordArr[i].des = grow(recordArr[i].des, tempsize);
	tempsize = 0;
	cout << "Enter salary ___";
	cin >> recordArr[i].sal;
	cout << endl << endl;

	cout << "Going to main menu ";
}

void shift(const int &start)
{
	for (int i = start; i < record; i++)
	{
		recordArr[i] = recordArr[i + 1];
	}
}
void shrink()
{
	rec *temp = new rec[--record];
	for (int i = 0; i < record; i++)
		temp[i] = recordArr[i];
	if (record != 0)
		delete[] recordArr;
	recordArr = temp;
	temp = NULL;
}
void deletes()
{
	int id = 0;
	bool flag = false;
	cout << " Enter id to delete ";
	cin >> id;
	cout<<endl;
	if(record!=0)
	{
		for (int i = 0; i <= record - 1; i++)
		{
			if (recordArr[i].id == id)
			{
				flag = true;
				shift(i);
				shrink();
				break;
			}
		}
		if (!flag)
			cout << "id not found ";
	}
	else
	cout<<"All records are deleted ";
	cout<<endl<<endl;
		

}
int main()
{
	int size = 0;
	cout << "  Do you want to enter input from file or by user ";
	cout << endl << "  For user press U ";
	cout << endl << "  For filing press F ";
	cout << endl<<"  ";
	char choice;
	cin >> choice;
	if (choice == 'f')
	{
		char tip = '\0';
		while ((tip = cin.get()) != 'q')
		{
			switch (tip)
			{
			case 'b':
				Addfile();
				break;

			case 's':
				search();
				break;

			case 'i':
				insert();
				break;

			case 'e':
				edit();
				break;

			case 'd':
				listfile();
				break;

			case 'r':
				deletes();
				break;

			}
			menu();
		}
	}
	else
	{
		menu();
		char tip = '\0';
		while ((tip = cin.get()) != 'q')
		{
			switch (tip)
			{
			case 'b':
				Add();
				menu();
				break;

			case 's':
				search();
				menu();
				break;

			case 'i':
				insert();
				menu();
				break;

			case 'e':
				edit();
				menu();
				break;

			case 'd':
				list();
				menu();
				break;

			case 'r':
				deletes();
				menu();
				break;

			}
		}
	}
	deletesit();
	return 0;
}
