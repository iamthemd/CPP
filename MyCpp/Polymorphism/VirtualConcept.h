#pragma once

/* Virtual Function: Virtual function declare with virtual keyword.
*  when you declare function as virtual, it tells compiler to take decision at runtime or perform dynamic binding on the function.
*  Why?
*   : When it is necessary to have single pointer to refer all object of different class, this can only be possibe by creating base
*     class's pointer and refer to all derived class object.
*     But problem is when we use base class's pointer it always refer to base class's object and called base class method, to resolve
*     this problem we use function as virutal function which tells compiler to take decision at runtime and check in vtable where 
*     basse class pointer pointing.
*/
class BaseClass {
public:
	BaseClass();					//				| ----- vTable ----- |
	virtual void print();			// 				|    print()		 |			
	virtual void fun1_virtual();	// _vPtr ----->	|  fun1_virtual() <------------+	 
	virtual void fun2_virtual();	//				|  fun2_virtual() <-------+	   |
};									//				| ------------------ |	  |	   |
									//										  |	   |
class DerivedClass : public BaseClass {//									  |	   |
public:								//				| ----- vTable ----- |	  |	   |
	DerivedClass();					// 				|    print()		 |	  |	   |
	virtual void print();			// _vPtr ----->	|  fun1_virtual()	 |	  |	   |
	virtual void fun1_virtual();	// (Inherited)	|  fun2_virtual() --------+	   |
};									//				| ------------------ |		   |
									//											   |
class SecondDeriveClass : public BaseClass {//									   |
public:								//				| ----- vTable ----- |		   |
	SecondDeriveClass();			// 				|    print()		 |		   |
	virtual void print();			// _vPtr ----->	|	fun1_virtual() ------------+	 
	virtual void fun2_virtual();	//	(Inherited)	|	fun2_virtual()	 |		   
};									//				| ------------------ |
// ----------------------------------------------------------------------------

void Test_VirtualConcept();

