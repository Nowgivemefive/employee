/*
* 2017.4.30 By GiveMeFive
*/

#include "employee.h"

employee::employee() {
	head = end = NULL;
}

void employee::addRecord(
	int emp_id,
	std::string name,
	char sex,
	std::string education,
	long long tel) {
		node *pr = new node;
		pr->emp_id = emp_id;
		pr->name = name;
		pr->sex = sex;
		pr->education = education;
		pr->tel = tel;
		pr->next = NULL;
		if (head == NULL) {
			head = end = pr;
		}
		else {
			end->next = pr;
			end = pr;
		}
}

node* employee::getRecord(int emp_id) {
	node *pr = head;
	while (pr != NULL) {
		if (pr->emp_id == emp_id) {
			return pr;
		}
		pr = pr->next;
	}
	return NULL;
}

void  employee::rmRecord(int emp_id) {
	node *pr = head;
	node *tmp = NULL;
	if (pr->emp_id == emp_id) {
		head = head->next;
		return;
	}
	while (pr->next != NULL) {
		if (pr->next->emp_id == emp_id) {
			tmp = pr->next->next;
			pr->next = NULL;
			delete pr->next;
			pr->next = tmp;
			return;
		}
		else
			pr = pr->next;
	}
	return;
}


void employee::test() {
	node *pr = head;
	while (pr != NULL) {
		std::cout << "姓名: " << pr->name << "  "
			<< "工号: " << pr->emp_id << "  "
			<< "教育程度: " << pr->education << "  "
			<< "性别: " << pr->sex << "  "
			<< "电话: " << pr->tel << std::endl;
		pr = pr->next;
	}
	return;
}

void employee::saveToFile() {
	node *pr = head;
	if (pr == NULL) {
		return;
	}
	std::ofstream  outfile;
	outfile.open("C:\\employee.dat", std::ios::out | std::ios::trunc);
	if (!outfile.is_open()) {
		std::cout << "文件打开失败"<<std::endl;
	}
	while (pr != NULL) {
		outfile <<pr->emp_id<<"\t"
			<<pr->name<<"\t"
			<<pr->sex<<"\t"
			<<pr->education<<"\t"
			<<pr->tel<<std::endl;
		pr = pr->next;
	}
	//std::cout << "save success " << std::endl;
	outfile.clear();
	outfile.close();
	return;
}

void employee::readByFile() {
	std::fstream  infile;
	infile.open("C:\\employee.dat",std::ios::in);
	if (!infile.is_open()) {
		std::cout << "读文件打开失败" << std::endl;
	}
	while (!infile.eof()) {
		node *pr = new node;
		infile>>pr->emp_id 
		>>pr->name
		>>pr->sex
		>>pr->education
		>>pr->tel;
		pr->next = NULL;
		if (head == NULL) {
			head = end = pr;
		}
		else {
			end->next = pr;
			end = pr;
		}

	}
	infile.close();
	//std::cout << "read success" << std::endl;
}