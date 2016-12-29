#include<iostream>
#include<list>
#include<string>
using namespace std;
class Company//����
{
public:
	Company(string name) { m_name = name; }
	virtual ~Company(){}
	virtual void Add(Company *pCom){}
	virtual void Show(int depth) {}
protected:
	string m_name;
};
//���幫˾
class ConcreteCompany : public Company//������
{
public:
	ConcreteCompany(string name) : Company(name) {}
	virtual ~ConcreteCompany() {}
	void Add(Company *pCom) { m_listCompany.push_back(pCom); } //λ�������м䣬������������
	void Show(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
		list<Company *>::iterator iter = m_listCompany.begin();
		for (; iter != m_listCompany.end(); iter++) //��ʾ�²���
			(*iter)->Show(depth + 2);
	}
private:
	list<Company *> m_listCompany;
};
//����Ĳ��ţ�����
class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string name) :Company(name){}
	virtual ~FinanceDepartment() {}
	virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};
//����Ĳ��ţ�������Դ��
class HRDepartment :public Company
{
public:
	HRDepartment(string name) :Company(name){}
	virtual ~HRDepartment() {}
	virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};
int main()
{
	Company *root = new ConcreteCompany("�ܹ�˾");
	Company *leaf1 = new FinanceDepartment("����");
	Company *leaf2 = new HRDepartment("������Դ��");
	root->Add(leaf1);
	root->Add(leaf2);

	//�ֹ�˾A
	Company *mid1 = new ConcreteCompany("�ֹ�˾A");
	Company *leaf3 = new FinanceDepartment("����");
	Company *leaf4 = new HRDepartment("������Դ��");
	mid1->Add(leaf3);
	mid1->Add(leaf4);
	root->Add(mid1);
	//�ֹ�˾B
	Company *mid2 = new ConcreteCompany("�ֹ�˾B");
	FinanceDepartment *leaf5 = new FinanceDepartment("����");
	HRDepartment *leaf6 = new HRDepartment("������Դ��");
	mid2->Add(leaf5);
	mid2->Add(leaf6);
	root->Add(mid2);
	root->Show(0);

	delete leaf1; delete leaf2;
	delete leaf3; delete leaf4;
	delete leaf5; delete leaf6;
	delete mid1; delete mid2;
	delete root;
	while (1);
}
