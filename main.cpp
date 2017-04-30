/*
*	2017.4.28 By GiveMeFive
*/

/*
*	1.从键盘输入职工信息(id, name, sex, education, tel)
*	2.从文件导入职工信息
*	3.按职工号查询职工信息
*	4.按职工号删除职工信息
*	5.根据工号修改职工信息
*	6.能将职工信息保存到文件
*/

/*
*	默认employee.dat路径C://employee.dat
*	运行程序从employee.dat读取数据到链表
*	修改\增加\删除都会从链表保存到文件中
*/
#include <iostream>
#include "employee.h"

//功能选择
int menu();
void addEmployee(employee* &pr);
void findEmployee(employee *pr);
void rmEmployee(employee* &pr);
void mdEmployee(employee* &pr);
void showAll(employee *pr);

//test
int main() {
	employee *pr = new employee();
	pr->readByFile(); //从默认文件中读取数据
	while (1) {
		int temp = menu();
		//test std::cout << temp;
		switch (temp) {
		case 1:addEmployee(pr); break;
		case 2:findEmployee(pr); break;
		case 3:rmEmployee(pr); break;
		case 4:mdEmployee(pr); break;
		case 5:showAll(pr); break;
		case 0:exit(0);
		default:std::cout << "没有此功能"; break;
		}
		system("cls");
	}
	
	return 0;
}

int menu() {
		std::cout
			<< "*****************\n*1. 增加职工信息*" << std::endl
			<< "*2. 查找职工信息*" << std::endl
			<< "*3. 删除职工信息*" << std::endl
			<< "*4. 修改职工信息*" << std::endl
			<< "*5. 显示所有 \t*" << std::endl
			<< "*0. 退出程序\t*\n*****************"<<std::endl
			<< "请输入功能前的数字" << std::endl;
		int temp;
		std::cin >> temp;
		return temp;
}

void addEmployee(employee* &pr) {
	int emp_id; //工号
	std::cout << "请输入工号" << std::endl;
	std::cin >> emp_id;
	std::string name; //姓名
	std::cout << "请输入姓名" << std::endl;
	std::cin >> name;
	char sex; //性别 M/W
	std::cout << "请输入性别 M/W" << std::endl;
	std::cin >> sex;
	std::string education;//教育程度
	std::cout << "请输入教育程度" << std::endl;
	std::cin >> education;
	long long tel;//电话
	std::cout << "请输入电话号码" << std::endl;
	std::cin >> tel;
	pr->addRecord(emp_id, name, sex, education, tel);
	std::cout << "添加成功" << std::endl;
	std::cout << "任意键返回上一层" << std::endl;
	pr->saveToFile();
	getchar();
	getchar();
}

void findEmployee(employee *pr) {
	int emp_id; //工号
	std::cout << "请输入工号" << std::endl;
	std::cin >> emp_id;
	node *tmp = pr->getRecord(emp_id);
	if (tmp == NULL) {
		std::cout << "查无此人" << std::endl;
		std::cout << "任意键返回上一层" << std::endl;
		getchar();
		getchar();
		return;
	}
	std::cout << "工号 : " << tmp->emp_id
		<< " 姓名 : " << tmp->name
		<< " 性别 : " << tmp->sex
		<< " 教育程度 : " << tmp->education
		<< " 电话 : " << tmp->tel << std::endl;
	std::cout << "任意键返回上一层"<<std::endl;
	getchar();
	getchar();
}

void rmEmployee(employee* &pr) {
	int emp_id; //工号
	std::cout << "请输入要删除职工的工号" << std::endl;
	std::cin >> emp_id;
	pr->rmRecord(emp_id);
	std::cout << "删除成功,任意键返回上一层" << std::endl;
	pr->saveToFile();
	getchar();
	getchar();
	return;
}

void mdEmployee(employee* &pr) {
	int emp_id; //工号
	std::cout << "请输入要修改职工的工号" << std::endl;
	std::cin >> emp_id;
	node *tmp = pr->getRecord(emp_id);
	if (tmp == NULL) {
		std::cout << "查无此人"<<std::endl;
		std::cout << "任意键返回上一层" << std::endl;
		pr->saveToFile();
		getchar();
		getchar();
		return ;
	}
	std::cout << "1.工号 : " << tmp->emp_id
		<< " 2.姓名 : " << tmp->name
		<< " 3.性别 : " << tmp->sex
		<< " 4.教育程度 : " << tmp->education
		<< " 5.电话 : " << tmp->tel << std::endl;
	std::cout << "输入需要修改的字段前的数字,0退出"<<std::endl;
	int temp;
	std::cin >> temp;
	if (temp == 1) {
		std::cout << "修改工号为 : ";
		std::cin >> tmp->emp_id;
	}
	else if (temp == 2) {
		std::cout << "修改姓名为 :";
		std::cin >> tmp->name;
	}
	else if (temp  == 3) {
		std::cout << "修改性别(M/W)为 :";
		std::cin >> tmp->sex;
	}
	else if (temp  == 4) {
		std::cout << "修改教育程度为 :";
		std::cin >> tmp->education;
	}
	else if (temp  == 5) {
		std::cout << "修改电话为 :";
		std::cin >> tmp->tel;
	}
	else if (temp == 0) {
		return;
	}
	pr->saveToFile();

	std::cout << "修改完成 ,任意键返回上一层" << std::endl;
	getchar();
	getchar();
	return;
}
void showAll(employee *pr) {
	pr->test();
	std::cout << "任意键返回上一层" << std::endl;
	getchar();
	getchar();
	return;
}