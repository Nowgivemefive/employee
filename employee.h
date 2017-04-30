/*
* 2017.4.30 By GiveMeFive
*/

/*
*	定义node结构保存单个职工信息
*	封装employee类,用单向链表实现
*/
#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <fstream>

struct node{
	int emp_id;	//工号
	std::string name; //姓名
	char sex; //性别 M/W
	std::string education;//教育程度
	long long tel;//电话
	struct node *next;
};

class employee {
public:
	employee();
	//增加记录
	 void addRecord(
		int emp_id,
		std::string name,
		char sex,
		std::string education,
		long long tel
	);
	 //根据工号获取记录，返回node指针
	node* getRecord(int emp_id);
	//删除记录
	void  rmRecord(int emp_id);
	//保存到文件中
	void saveToFile();
	//从文件中读取记录
	void readByFile();
	//test 打印所有数据
	void test();
private:
	node *head, *end;
};

#endif //EMPLOYEE_H
