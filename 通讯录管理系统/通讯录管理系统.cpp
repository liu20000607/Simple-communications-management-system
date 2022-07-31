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
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
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
			cin >> age;
			getchar();
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
		while (true)
		{
			cin >> tel;	
			if (tel !=  "") {
				abs->ps[abs->size].tel = tel;
				break;
			}
			else {
				cout << "未输入号码" << endl;
			}
		}
		abs->size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks * abs) {
	if (abs->size == 0) {
		cout << "记录为空" << endl;
	}else{
	for (int i = 0; i < abs->size; i++) {
		if (abs->ps[i].name == "") {
			continue;
		}
		cout << "姓名：" << abs->ps[i].name << "\t";
		/*if (abs->ps[i].sex == 1) {
			cout << "性别：男\t";
		}
		else {
			cout << "性别：女\t";
		}*/
		cout << "性别：" << (abs->ps[i].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->ps[i].age << "\t电话：" << abs->ps[i].tel << endl;
	}
	}
	system("pause");
	system("cls");
}

int checkPerson(Addressbooks * abs, string name) {
	for (int i = 0; i < abs->size; i++) {
		//找到用户输入的姓名
		if (abs->ps[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs, int ret) {
	//找到用户输入的姓名
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
	cout << "删除成功" << endl;
	system("pause");
	system("cls");

}

void printfPerson(Addressbooks * abs ,string name) {
	string del = "";
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "联系人不存在" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//找到用户输入的姓名
			if (abs->ps[i].name == name) {
				cout << "姓名：" << abs->ps[i].name << "\t";
				cout << "性别：" << (abs->ps[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << abs->ps[i].age << "\t电话：" << abs->ps[i].tel << endl;
			}
		}
		cout << "是否删除?(Y/y---是 N/n---否)" << endl;
		while (true)
		{
			cin >> del;
			getchar();
			if (cin.fail()) {
				cout << "请输入字母" << endl;
				cin.clear();
			}
			else {
				if (del == "y" || del == "Y") {
					deletePerson(abs,  ret);
					break;
				}
				else if (del == "n" || del == "N") {
					cout << "取消删除联系人" << endl;
					system("pause");
					system("cls");
					break;
				}
				else {
					cout << "输入错误，重新输入" << endl;
				}
			}
		}
	}
}

void searchPerson(Addressbooks* abs, string  name)
{
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "联系人不存在" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//找到用户输入的姓名
			if (abs->ps[i].name == name) {
				cout << "姓名：" << abs->ps[i].name << "\t";
				cout << "性别：" << (abs->ps[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << abs->ps[i].age << "\t电话：" << abs->ps[i].tel << endl;
			}
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}

void changeP(Addressbooks * abs, int ret) {
	string name = "";
	cout << "请输入姓名" << endl;
	cin >> name;
	abs->ps[ret].name = name;
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
		}
		else {
			if (sex == 1 || sex == 2) {
				abs->ps[ret].sex = sex;
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
		cin >> age;
		getchar();
		if (cin.fail()) {
			cout << "请输入数字" << endl;
			cin.clear();
		}
		else {
			if (age > 0) {
				abs->ps[ret].age = age;
				break;
			}
			else {
				cout << "输入有误，重新输入" << endl;
			}
		}
	}
	string tel = "";
	cout << "请输入号码" << endl;
	while (true)
	{
		cin >> tel;
		if (tel != "") {
			abs->ps[ret].tel = tel;
			break;
		}
		else {
			cout << "未输入号码" << endl;
		}
	}

	cout << "修改成功" << endl;
	system("pause");
	system("cls");
}
void changePerson(Addressbooks* abs, string  name) {
	string change = "";
	int ret = checkPerson(abs, name);
	if (ret == -1) {
		cout << "联系人不存在" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			//找到用户输入的姓名
			if (abs->ps[i].name == name) {
				cout << "姓名：" << abs->ps[i].name << "\t";
				cout << "性别：" << (abs->ps[i].sex == 1 ? "男" : "女") << "\t";
				cout << "年龄：" << abs->ps[i].age << "\t电话：" << abs->ps[i].tel << endl;
			}
		}
		cout << "是否修改?(Y/y---是 N/n---否)" << endl;
		while (true)
		{
			cin >> change;
			getchar();
			if (cin.fail()) {
				cout << "请输入字母" << endl;
				cin.clear();
			}
			else {
				if (change == "y" || change == "Y") {
					changeP(abs, ret);
					break;
				}
				else if (change == "n" || change == "N") {
					cout << "取消删除联系人" << endl;
					system("pause");
					system("cls");
					break;
				}
				else {
					cout << "输入错误，重新输入" << endl;
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
			cout << "请输入字母" << endl;
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
				cout << "已清空" << endl;
				break;
			}
			else if (clear == "n" || clear == "N") {
				cout << "取消清空联系人" << endl;
				break;
			}
			else {
				cout << "输入错误，重新输入" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

int main() { 
	//通讯录结构体变量
	Addressbooks abs; 
	int select = 0;
	string name;
	while (true) {
		showMenu();
		cin >> select;
		getchar();
		
		if (cin.fail()) {
			cout << "请输入数字" << endl;
			cin.clear();
			system("pause");//按任意键继续
			system("cls");//清屏
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
					cout << "请输入要删除的联系人姓名" << endl;
					cin >> name;
					printfPerson(&abs,name);
					break;
				case 4:
					cout << "请输入要查找的联系人姓名" << endl;
					cin >> name;
					searchPerson(&abs, name);
					break;
				case 5:
					cout << "请输入要修改的联系人姓名" << endl;
					cin >> name;
					changePerson(&abs, name);
					break;
				case 6:
					cout << "是否清空联系人？(Y/y---是 N/n---否)" << endl;
					clearPerson(&abs);
					break;
				case 0:
					cout << "欢迎下次使用" << endl;
					system("pause");
					break;
				default:
					cout << "输入错误，重新输入" << endl;
					break;
				}
		}
	}
	system("pause");
	return 0;
}    