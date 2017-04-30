/*
* 2017.4.30 By GiveMeFive
*/

/*
*	����node�ṹ���浥��ְ����Ϣ
*	��װemployee��,�õ�������ʵ��
*/
#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <fstream>

struct node{
	int emp_id;	//����
	std::string name; //����
	char sex; //�Ա� M/W
	std::string education;//�����̶�
	long long tel;//�绰
	struct node *next;
};

class employee {
public:
	employee();
	//���Ӽ�¼
	 void addRecord(
		int emp_id,
		std::string name,
		char sex,
		std::string education,
		long long tel
	);
	 //���ݹ��Ż�ȡ��¼������nodeָ��
	node* getRecord(int emp_id);
	//ɾ����¼
	void  rmRecord(int emp_id);
	//���浽�ļ���
	void saveToFile();
	//���ļ��ж�ȡ��¼
	void readByFile();
	//test ��ӡ��������
	void test();
private:
	node *head, *end;
};

#endif //EMPLOYEE_H
