/*
*	2017.4.28 By GiveMeFive
*/

/*
*	1.�Ӽ�������ְ����Ϣ(id, name, sex, education, tel)
*	2.���ļ�����ְ����Ϣ
*	3.��ְ���Ų�ѯְ����Ϣ
*	4.��ְ����ɾ��ְ����Ϣ
*	5.���ݹ����޸�ְ����Ϣ
*	6.�ܽ�ְ����Ϣ���浽�ļ�
*/

/*
*	Ĭ��employee.dat·��C://employee.dat
*	���г����employee.dat��ȡ���ݵ�����
*	�޸�\����\ɾ������������浽�ļ���
*/
#include <iostream>
#include "employee.h"

//����ѡ��
int menu();
void addEmployee(employee* &pr);
void findEmployee(employee *pr);
void rmEmployee(employee* &pr);
void mdEmployee(employee* &pr);
void showAll(employee *pr);

//test
int main() {
	employee *pr = new employee();
	pr->readByFile(); //��Ĭ���ļ��ж�ȡ����
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
		default:std::cout << "û�д˹���"; break;
		}
		system("cls");
	}
	
	return 0;
}

int menu() {
		std::cout
			<< "*****************\n*1. ����ְ����Ϣ*" << std::endl
			<< "*2. ����ְ����Ϣ*" << std::endl
			<< "*3. ɾ��ְ����Ϣ*" << std::endl
			<< "*4. �޸�ְ����Ϣ*" << std::endl
			<< "*5. ��ʾ���� \t*" << std::endl
			<< "*0. �˳�����\t*\n*****************"<<std::endl
			<< "�����빦��ǰ������" << std::endl;
		int temp;
		std::cin >> temp;
		return temp;
}

void addEmployee(employee* &pr) {
	int emp_id; //����
	std::cout << "�����빤��" << std::endl;
	std::cin >> emp_id;
	std::string name; //����
	std::cout << "����������" << std::endl;
	std::cin >> name;
	char sex; //�Ա� M/W
	std::cout << "�������Ա� M/W" << std::endl;
	std::cin >> sex;
	std::string education;//�����̶�
	std::cout << "����������̶�" << std::endl;
	std::cin >> education;
	long long tel;//�绰
	std::cout << "������绰����" << std::endl;
	std::cin >> tel;
	pr->addRecord(emp_id, name, sex, education, tel);
	std::cout << "��ӳɹ�" << std::endl;
	std::cout << "�����������һ��" << std::endl;
	pr->saveToFile();
	getchar();
	getchar();
}

void findEmployee(employee *pr) {
	int emp_id; //����
	std::cout << "�����빤��" << std::endl;
	std::cin >> emp_id;
	node *tmp = pr->getRecord(emp_id);
	if (tmp == NULL) {
		std::cout << "���޴���" << std::endl;
		std::cout << "�����������һ��" << std::endl;
		getchar();
		getchar();
		return;
	}
	std::cout << "���� : " << tmp->emp_id
		<< " ���� : " << tmp->name
		<< " �Ա� : " << tmp->sex
		<< " �����̶� : " << tmp->education
		<< " �绰 : " << tmp->tel << std::endl;
	std::cout << "�����������һ��"<<std::endl;
	getchar();
	getchar();
}

void rmEmployee(employee* &pr) {
	int emp_id; //����
	std::cout << "������Ҫɾ��ְ���Ĺ���" << std::endl;
	std::cin >> emp_id;
	pr->rmRecord(emp_id);
	std::cout << "ɾ���ɹ�,�����������һ��" << std::endl;
	pr->saveToFile();
	getchar();
	getchar();
	return;
}

void mdEmployee(employee* &pr) {
	int emp_id; //����
	std::cout << "������Ҫ�޸�ְ���Ĺ���" << std::endl;
	std::cin >> emp_id;
	node *tmp = pr->getRecord(emp_id);
	if (tmp == NULL) {
		std::cout << "���޴���"<<std::endl;
		std::cout << "�����������һ��" << std::endl;
		pr->saveToFile();
		getchar();
		getchar();
		return ;
	}
	std::cout << "1.���� : " << tmp->emp_id
		<< " 2.���� : " << tmp->name
		<< " 3.�Ա� : " << tmp->sex
		<< " 4.�����̶� : " << tmp->education
		<< " 5.�绰 : " << tmp->tel << std::endl;
	std::cout << "������Ҫ�޸ĵ��ֶ�ǰ������,0�˳�"<<std::endl;
	int temp;
	std::cin >> temp;
	if (temp == 1) {
		std::cout << "�޸Ĺ���Ϊ : ";
		std::cin >> tmp->emp_id;
	}
	else if (temp == 2) {
		std::cout << "�޸�����Ϊ :";
		std::cin >> tmp->name;
	}
	else if (temp  == 3) {
		std::cout << "�޸��Ա�(M/W)Ϊ :";
		std::cin >> tmp->sex;
	}
	else if (temp  == 4) {
		std::cout << "�޸Ľ����̶�Ϊ :";
		std::cin >> tmp->education;
	}
	else if (temp  == 5) {
		std::cout << "�޸ĵ绰Ϊ :";
		std::cin >> tmp->tel;
	}
	else if (temp == 0) {
		return;
	}
	pr->saveToFile();

	std::cout << "�޸���� ,�����������һ��" << std::endl;
	getchar();
	getchar();
	return;
}
void showAll(employee *pr) {
	pr->test();
	std::cout << "�����������һ��" << std::endl;
	getchar();
	getchar();
	return;
}