#include "Command.cpp"  

//ģ�������ַ���,Ȼ���������ַ�������undo redo����  
//����Դ���undo redo���ܵ��ı��༭��������Ƿ�������  
//�����¼����������¼,��:������undo �� redo �������ַ������ݸı�  
//Ҳ���¼,�������������undo ���� redo �������ַ���ʱ ��redo��ռ���  
//����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo  
int main()
{
	//Ĭ��û�������ַ��������ǿգ�����Ϊ����ʾ��ֵһ��������ַ���  
	Commander *p = new Commander(new InputCommand("[empty]"));

	//����China  
	p->ExecuteCommand(new InputCommand("China"));
	//����Shanghai  
	p->ExecuteCommand(new InputCommand("Shanghai"));
	//����Tongji  
	p->ExecuteCommand(new InputCommand("Tongji"));

	//ִ��һ��undo ������ Shanghai 
	p->Undo();
	//ִ��һ��undo ������ China  
	p->Undo();

	//undo���м��������ַ��� insert ���� China 
	p->ExecuteCommand(new InputCommand("insert"));

	//ִ��һ��undo ������ China  
	p->Undo();

	//ִ��һ��undo ������������ [empty]  
	p->Undo();

	//ִ��ʧ���Ѿ�undo ����ԭʼ���  
	p->Undo();

	//ִ��һ��redo ������ China 
	p->Redo();
	//ִ��һ��redo ������ insert  
	p->Redo();
	//ִ��һ��redo ������ Shanghai  
	p->Redo();

	//redo���м��������ַ��� insert again ���� Shanghai
	p->ExecuteCommand(new InputCommand("insert again"));

	//ִ��һ��undo ������Shanghai  
	p->Undo();

	//ִ��һ��redo ������ insert again  
	p->Redo();

	//ִ��һ��redo ������ Tongji 
	p->Redo();

	//ִ��ʧ���Ѿ�redo ���������  
	p->Redo();
	delete p;
	while (1);
}