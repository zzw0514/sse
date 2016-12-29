#include<iostream>
#include<list>
#include<string>
using namespace std;
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {}
};
//����  
class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Attach(Observer *observer) { m_observers.push_back(observer); }     //��ӹ۲���  
	void Remove(Observer *observer) { m_observers.remove(observer); }        //�Ƴ��۲���  
	void Notify() //֪ͨ�۲���  
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus(string s) { m_status = s; } //����״̬  
	virtual string GetStatus() { return m_status; }    //���״̬  
private:
	list<Observer* > m_observers; //�۲�������  
protected:
	string m_status; //״̬  
};
//���岩����  
class BlogSSE : public Blog
{
private:
	string m_name; //��������  
public:
	BlogSSE(string name) : m_name(name) {}
	~BlogSSE() {}
	void SetStatus(string s) { m_status = "SSEBlog֪ͨ : " + m_name + s; } //��������״̬��Ϣ  
	string GetStatus() { return m_status; }
};
//����۲���  
class ObserverBlog : public Observer
{
private:
	string m_name;  //�۲�������  
	Blog *m_blog;   //�۲�Ĳ��ͣ���Ȼ��������ʽ���ã��Ϳ��Թ۲�������  
public:
	ObserverBlog(string name, Blog *blog) : m_name(name), m_blog(blog) {}
	~ObserverBlog() {}
	void Update()  //��ø���״̬  
	{
		string status = m_blog->GetStatus();
		cout << m_name << "-------" << status << endl;
	}
};
//���԰���  
int main()
{
	Blog *blog = new BlogSSE("zhuzhewei1996");
	Observer *observer1 = new ObserverBlog("piggy", blog);
	blog->Attach(observer1);
	blog->SetStatus("�����ͣ��۲���ģʽ��ʵ��");
	blog->Notify();
	delete blog; delete observer1;
	while(1);
}