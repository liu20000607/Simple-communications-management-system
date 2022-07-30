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
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、清空联系人" << endl;
	cout << "5、查找联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}

void addPerson(Addressbooks * abs) {
	if (abs->size >= MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name = "";
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->ps[abs->size].name = name;
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1----男 2----女" << endl;

		while (true)
		{
			cin >> sex;
			getchar();
			if (cin.fail()) {
				cout << "请输入数字" << endl;
				cin.clear();
			}else{
				if(sex == 1 || sex == 2){
					abs->ps[abs->size].sex = sex;
					break;
				}
				else {
					cout << "输入有误，重新输入" << endl;
				}
			}
		}
		int age = 0;
		cout << "请输入年龄" << endl;
		while (true)
		{
		   age = getchar();
			if (cin.fail()) {
				cout << "请输入数字" << endl;
				cin.clear();
			}
			else {
				if (age > 0) {
					abs->ps[abs->size].age = age;
					break;
				}
				else {
					cout << "输入有误，重新输入" << endl;
				}
			}
		}
		string tel = "";
		cout << "请输入号码" << endl;
		cin >> tel;
		abs->ps[abs->size].tel = tel;
		abs->size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

int main() { 
	//通讯录结构体变量
	Addressbooks abs; 
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		getchar();
		if (cin.fail()) {
			cout << "请输入数字" << endl;
			cin.clear();
			system("pause");//按任意键继续
			system("cls");//清屏
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
				cout << "欢迎下次使用" << endl;
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