#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
struct Person
{
	string name = "";
	int sex = 0;
	int age = 0;
	string tel = "";
};
struct Addressbooks
{
	Person ps[MAX];
	int size = 0;
};
void showMenu() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}

void addPerson(Addressbooks * abs) {
	if (abs->size >= MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		string name = "";
		cout << "����������" << endl;
		cin >> name;
		abs->ps[abs->size].name = name;
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1----�� 2----Ů" << endl;

		while (true)
		{
			cin >> sex;
			getchar();
			if (cin.fail()) {
				cout << "����������" << endl;
				cin.clear();
			}else{
				if(sex == 1 || sex == 2){
					abs->ps[abs->size].sex = sex;
					break;
				}
				else {
					cout << "����������������" << endl;
				}
			}
		}
		int age = 0;
		cout << "����������" << endl;
		while (true)
		{
			cin >> age;
			getchar();
			if (cin.fail()) {
				cout << "����������" << endl;
				cin.clear();
			}
			else {
				if (age > 0) {
					abs->ps[abs->size].age = age;
					break;
				}
				else {
					cout << "����������������" << endl;
				}
			}
		}
		string tel = "";
		cout << "���������" << endl;
		while (true)
		{
			cin >> tel;	
			if (tel !=  "") {
				abs->ps[abs->size].tel = tel;
				break;
			}
			else {
				cout << "δ�������" << endl;
			}
		}
		abs->size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks * abs) {
	if (abs->size == 0) {
		cout << "��¼Ϊ��" << endl;
	}else{
	for (int i = 0; i < abs->size; i++) {
		if (abs->ps[i].name == "") {
			continue;
		}
		cout << "������" << abs->ps[i].name << "\t";
		/*if (abs->ps[i].sex == 1) {
			cout << "�Ա���\t";
		}
		else {
			cout << "�Ա�Ů\t";
		}*/
		cout << "�Ա�" << (abs->ps[i].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->ps[i].age << "\t�绰��" << abs->ps[i].tel << endl;
	}
	}
	system("pause");
	system("cls");
}

int checkPerson(Addressbooks * abs, string name) {
	for (int i = 0; i < abs->size; i++) {
		//�ҵ��û����������
		if (abs->ps[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs, int ret) {
	//�ҵ��û����������
	if (abs->size >= 1000 && ret == abs->size) {
		abs->ps[ret].name = "";
		abs->ps[ret].age = 0;
		abs->ps[ret].sex = 0;
		abs->ps[ret].tel = "";
	}
	else {
		for(int i = ret; i < abs->size; i++){
			abs->ps[i] = abs->ps[i + 1];
		}
	}
	abs->size--;
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");

}

void printfPerson(Addressbooks * abs ,string name) {
	string del = "";
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "��ϵ�˲�����" << endl;
		system("pause");//�����������
		system("cls");//����
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//�ҵ��û����������
			if (abs->ps[i].name == name) {
				cout << "������" << abs->ps[i].name << "\t";
				cout << "�Ա�" << (abs->ps[i].sex == 1 ? "��" : "Ů") << "\t";
				cout << "���䣺" << abs->ps[i].age << "\t�绰��" << abs->ps[i].tel << endl;
			}
		}
		cout << "�Ƿ�ɾ��?(Y/y---�� N/n---��)" << endl;
		while (true)
		{
			cin >> del;
			getchar();
			if (cin.fail()) {
				cout << "��������ĸ" << endl;
				cin.clear();
			}
			else {
				if (del == "y" || del == "Y") {
					deletePerson(abs,  ret);
					break;
				}
				else if (del == "n" || del == "N") {
					cout << "ȡ��ɾ����ϵ��" << endl;
					system("pause");
					system("cls");
					break;
				}
				else {
					cout << "���������������" << endl;
				}
			}
		}
	}
}

void searchPerson(Addressbooks* abs, string  name)
{
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "��ϵ�˲�����" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//�ҵ��û����������
			if (abs->ps[i].name == name) {
				cout << "������" << abs->ps[i].name << "\t";
				cout << "�Ա�" << (abs->ps[i].sex == 1 ? "��" : "Ů") << "\t";
				cout << "���䣺" << abs->ps[i].age << "\t�绰��" << abs->ps[i].tel << endl;
			}
		}
	}
	system("pause");//�����������
	system("cls");//����
}

void changeP(Addressbooks * abs, int ret) {
	string name = "";
	cout << "����������" << endl;
	cin >> name;
	abs->ps[ret].name = name;
	int sex = 0;
	cout << "�������Ա�" << endl;
	cout << "1----�� 2----Ů" << endl;

	while (true)
	{
		cin >> sex;
		getchar();
		if (cin.fail()) {
			cout << "����������" << endl;
			cin.clear();
		}
		else {
			if (sex == 1 || sex == 2) {
				abs->ps[ret].sex = sex;
				break;
			}
			else {
				cout << "����������������" << endl;
			}
		}
	}
	int age = 0;
	cout << "����������" << endl;
	while (true)
	{
		cin >> age;
		getchar();
		if (cin.fail()) {
			cout << "����������" << endl;
			cin.clear();
		}
		else {
			if (age > 0) {
				abs->ps[ret].age = age;
				break;
			}
			else {
				cout << "����������������" << endl;
			}
		}
	}
	string tel = "";
	cout << "���������" << endl;
	while (true)
	{
		cin >> tel;
		if (tel != "") {
			abs->ps[ret].tel = tel;
			break;
		}
		else {
			cout << "δ�������" << endl;
		}
	}

	cout << "�޸ĳɹ�" << endl;
	system("pause");
	system("cls");
}
void changePerson(Addressbooks* abs, string  name) {
	string change = "";
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "��ϵ�˲�����" << endl;
		system("pause");//�����������
		system("cls");//����
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//�ҵ��û����������
			if (abs->ps[i].name == name) {
				cout << "������" << abs->ps[i].name << "\t";
				cout << "�Ա�" << (abs->ps[i].sex == 1 ? "��" : "Ů") << "\t";
				cout << "���䣺" << abs->ps[i].age << "\t�绰��" << abs->ps[i].tel << endl;
			}
		}
		cout << "�Ƿ��޸�?(Y/y---�� N/n---��)" << endl;
		while (true)
		{
			cin >> change;
			getchar();
			if (cin.fail()) {
				cout << "��������ĸ" << endl;
				cin.clear();
			}
			else {
				if (change == "y" || change == "Y") {
					changeP(abs, ret);
					break;
				}
				else if (change == "n" || change == "N") {
					cout << "ȡ��ɾ����ϵ��" << endl;
					system("pause");
					system("cls");
					break;
				}
				else {
					cout << "���������������" << endl;
				}
			}
		}
	}
}

void clearPerson(Addressbooks * abs) {
	string clear = " ";
	while (true)
	{
		cin >> clear;
		getchar();
		if (cin.fail()) {
			cout << "��������ĸ" << endl;
			cin.clear();
		}
		else {
			if (clear == "y" || clear == "Y") {
				for (int i = 0; i < abs->size; i++) {
					abs->ps[i].name = "";
					abs->ps[i].age = 0;
					abs->ps[i].sex = 0;
					abs->ps[i].tel = "";
				}
				abs->size = 0;
				cout << "�����" << endl;
				break;
			}
			else if (clear == "n" || clear == "N") {
				cout << "ȡ�������ϵ��" << endl;
				break;
			}
			else {
				cout << "���������������" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

int main() { 
	//ͨѶ¼�ṹ�����
	Addressbooks abs; 
	int select = 0;
	string name;
	while (true) {
		showMenu();
		cin >> select;
		getchar();
		
		if (cin.fail()) {
			cout << "����������" << endl;
			cin.clear();
			system("pause");//�����������
			system("cls");//����
		} 
		else {
				switch (select)
				{
				case 1:
					addPerson(&abs);
					break;
				case 2:
					showPerson(&abs);
					break;
				case 3:
					cout << "������Ҫɾ������ϵ������" << endl;
					cin >> name;
					printfPerson(&abs,name);
					break;
				case 4:
					cout << "������Ҫ���ҵ���ϵ������" << endl;
					cin >> name;
					searchPerson(&abs, name);
					break;
				case 5:
					cout << "������Ҫ�޸ĵ���ϵ������" << endl;
					cin >> name;
					changePerson(&abs, name);
					break;
				case 6:
					cout << "�Ƿ������ϵ�ˣ�(Y/y---�� N/n---��)" << endl;
					clearPerson(&abs);
					break;
				case 0:
					cout << "��ӭ�´�ʹ��" << endl;
					system("pause");
					break;
				default:
					cout << "���������������" << endl;
					break;
				}
		}
	}
	system("pause");
	return 0;
}    