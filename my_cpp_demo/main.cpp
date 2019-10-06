#include "Pointer.h"

Pointer test()
{
	Pointer a(2,"test");
	return a;
}
 
int main(int argc, char* argv[])
{
	//加花括号是为了观察析构函数的调用
	{
		Pointer(4,"notname1");
 
		Pointer a1=test();//调用移动构造函数，创建对象a1
		cout << "a1.showID():\n";
		a1.showID();
 
		Pointer a2;
		a2=Pointer(5, "notname2");//调用移动赋值运算符
		
		Pointer a3(Pointer(7, "notname3"));//此处没有调用移动构造函数，也就是说Pointer(7, "notname3") 这个变量没有被立即销毁（即不是临时变量），也许是因为它有了名字a3，所以不是临时变量了
		
		cout << "a3.showID():\n";
		a3.showID();//验证a3确实是Pointer(7, "notname3")

        Pointer a4(move(a3));
        cout << "a4.showID():\n";
        a4.showID();
	}
 
	cout << endl;	
	return 0;
}