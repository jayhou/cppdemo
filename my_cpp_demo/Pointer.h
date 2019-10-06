#ifndef _POINTER_H_
#define _POINTER_H_
#include <string>
#include <iostream>

using namespace std;

class Pointer
{
public:
	Pointer(const int i,const string &n)
	{ 
		mptr = new int[i]; 
		length = i;
		name = n;
		cout <<"带参数构造函数\n";
		showID(); 
	}
	Pointer() :mptr(nullptr), length(0){ cout << "无参数构造函数\n"; showID(); }
	virtual ~Pointer()
	{
		cout <<name+ "析构函数\n";
		if (mptr)
			delete[] mptr;
		mptr = nullptr;
		
	}
	
	Pointer(const Pointer& s)
	{
		length = s.getlen();
		mptr = new int[length];	
		name = s.name;
		cout << "复制构造函数\n";
		showID();
	}
	Pointer& operator=(const Pointer &s)
	{
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = new int[length];
		name = s.name;
		cout << "赋值运算符\n";
		showID();
		return *this;
	}
	
	//移动构造函数，参数s不能是const Pointer&& s，因为要改变s的成员数据的值
	Pointer(Pointer&& s)
	{
		length = s.getlen();
		mptr = s.getmptr();
		name = s.name + "_yidonggouzao";//调用移动构造函数时，加一个标记
		s.mptr = nullptr;		
		cout << "移动构造函数\n";
		showID();
	}
 
	//移动赋值运算符
	Pointer& operator=(Pointer&& s)
	{
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = s.mptr;
		name = s.name+"_yidongfuzhi";//调用移动赋值运算符时，加一个标记
		s.mptr = nullptr;		
		cout << "移动赋值运算符\n";
		showID();
		return *this;
	}
 
	void showID()
	{ 
		cout << "长度：" << length<<"  指针："<< mptr <<"  名字："<<name<< endl;
	}
 
	int getlen() const
	{
		return length;
	}
 
	int* getmptr()const
	{
		return mptr;
	}
 
private:
	int* mptr;
	int length;
	string name="#NULL";//该参数用来标记不同的对象，c++11支持直接在类的数据成员定义处初始化
};
#endif