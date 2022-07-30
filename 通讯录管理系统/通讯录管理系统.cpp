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
	cout << "4�������ϵ��" << endl;
	cout << "5��������ϵ��" << endl;
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
		   age = getchar();
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
		cin >> tel;
		abs->ps[abs->size].tel = tel;
		abs->size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

int main() { 
	//ͨѶ¼�ṹ�����
	Addressbooks abs; 
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		getchar();
		if (cin.fail()) {
			cout << "����������" << endl;
			cin.clear();
			system("pause");//�����������
			system("cls");//����
		}else{
			switch (select)
			{
			case 1:
				addPerson(&abs);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				break;
			default:
				break;
			}
		}
	}
	system("pause");
	return 0;
}    