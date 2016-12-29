#include "Command.cpp"  

//模拟输入字符串,然后对输入的字符串进行undo redo操作  
//你可以打开有undo redo功能的文本编辑程序测试是否是这样  
//这里记录的是完整记录,即:即便在undo 或 redo 过程中又发生数据改变  
//也会记录,如果不想这样在undo 或者 redo 输入新字符串时 将redo清空即可  
//即认为在历史记录中修改值被认为是最新的值，不需要再redo  
int main()
{
	//默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串  
	Commander *p = new Commander(new InputCommand("[empty]"));

	//输入China  
	p->ExecuteCommand(new InputCommand("China"));
	//输入Shanghai  
	p->ExecuteCommand(new InputCommand("Shanghai"));
	//输入Tongji  
	p->ExecuteCommand(new InputCommand("Tongji"));

	//执行一次undo 撤销到 Shanghai 
	p->Undo();
	//执行一次undo 撤销到 China  
	p->Undo();

	//undo后中间输入新字符串 insert 覆盖 China 
	p->ExecuteCommand(new InputCommand("insert"));

	//执行一次undo 撤销到 China  
	p->Undo();

	//执行一次undo 撤销到最初情况 [empty]  
	p->Undo();

	//执行失败已经undo 到最原始情况  
	p->Undo();

	//执行一次redo 重做到 China 
	p->Redo();
	//执行一次redo 重做到 insert  
	p->Redo();
	//执行一次redo 重做到 Shanghai  
	p->Redo();

	//redo后中间输入新字符串 insert again 覆盖 Shanghai
	p->ExecuteCommand(new InputCommand("insert again"));

	//执行一次undo 撤销到Shanghai  
	p->Undo();

	//执行一次redo 重做到 insert again  
	p->Redo();

	//执行一次redo 重做到 Tongji 
	p->Redo();

	//执行失败已经redo 到最新情况  
	p->Redo();
	delete p;
	while (1);
}