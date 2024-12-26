# CppStu
唐老师的C++深度解析课程
## 运行环境
`vs2019`

## lesson03 
### C语言中的const
- const 修饰的变量是只读的，本质还是变量
- const 修饰的局部变量在栈上分配空间
- const 修饰的全局变量在只读存储区分配空间
- const 只在编译期有用，在运行期无用
> const修饰的变量不是真的常量，它只是告诉编译器该变量不能出现在赋值符号的左边。
> C语言中的const使得变量具有只读属性
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**const将具有全局生命周期的变量存储于只读存储区 const不能定义真正意义上的常量**</font>

### C++中的const(C++在C的基础上对const进行了进化处理)
- 当碰见const声明时在符号表中放入从常量
- 编译过程中若发现使用常量则直接以符号表中的值替换
- 编译过程中若发现下述情况则给对应的常量分配存储空间
	- 对const常量使用了extern
	- 对const常量使用&操作符
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**注意：C++编译器虽然可能为const常量分配空间，但不会使用其存储空间的值。**</font>

- C语言中的const变量
	- C语言中const变量是只读变量，会分配存储空间
- C++中的const常量
	- 可能分配存储空间
		- 当const常量为全局，并且需要在其他文件中使用[extern]
		- 当使用&操作符对const常量取址
- C++中的const常量类似于宏定义
	- const int c = 5;  约等于 #define c 5
- C++中的const常量与宏定义的不同
	- const常量是由编译器处理
	- 编译器对const常量进行类型检查和作用域检查
	- 宏定义由预处理器处理，单纯的文本替换
### 小结
- <font color=Teal>与C语言不同，C++中的const不是只读变量</font>
- <font color=Teal>C++中的const是一个真正意义上的常量</font>
- <font color=Teal>C++编译器可能会为const常量分配空间</font>
- <font color=Teal>C++完全兼容C语言中const常量的语法特性</font>

## lesson04 布尔类型和引用
### C++中的布尔类型
- C++在C语言的几倍类型系统之上增加了bool
- C++中的bool可取的值只有true和false
- 理论上bool只占用一个字节
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**true 代表真值，编译器内部用1来表示**</font>
> <font color=Chocolate>**false代表非真值，编译器内部用0来表示**</font>

### 布尔类型的值
- bool类型只有true(非0)和false(0)两个值
- C++编译器会将非0值转换为true,0值转换为false

### 布尔类型是C++中的基本数据类型
- 可以定义bool类型的全局变量
- 可以定义bool类型的常量
- 可以定义bool类型的指针
- 可以定义bool类型的数组

### C++对三目运算符进行了升级
``` c++
int a = 1;
int b = 2;
(a<b?a:b) = 3;
printf("a = %d, b = %d\n", a, b);
```
- C语言中的三目运算符返回的是变量值 不能作为左值使用
- C++中的三目运算符可直接返回变量本身
	- 即可作为右值使用，又可作为左值使用
	- <font color=Chocolate>**注意：三目运算符可能返回的值中如果有一个是常量值，则不能作为左值使用**</font>

### C++中的引用
- 变量名回顾
	- 变量是一段实际连续存储空间的别名
	- 程序中通过变量来申请并命名存储空间
	- 通过变量的名字可以使用存储空间
- 在C++中新增加了引用的概念
	- 引用可以看作一个已定义变量的别名
	- 引用的语法：`Type& name = var`
- C++对三目运算符做了什么？
	- 当三目运算符的可能返回都是变量时，返回的是变量引用
	- 当三目运算符的可能返回中有常量时，返回的是值

### 小结
- <font color=Teal>bool类型是C++新增加的基础类型</font>
- <font color=Teal>bool类型的值只能是true和false</font>
- <font color=Teal>C++中的三目运算符可作为左值使用</font>
- <font color=Teal>C++中的引用可以看作变量的别名来使用</font>
- <font color=Teal>三目运算符的可能返回都是变量时，返回的是引用</font>

## lesson05 引用的本质分析
### 引用的意义
- 用用作为变量别名而存在，因此在一些场合可以代替指针
- 引用相对于指针来说具有更好的可读性和实用性
### 特殊的引用
- const引用
	- 在C++中可以声明const引用
	- const Type& name = var;
	- const引用让变量拥有只读属性
- 当使用常量对const引用进行初始化时，C++编译器会为常量值分配空间，并将引用名作为这段空间的别名<font color=SkyBlue>[使用常量对const引用初始化后将生成一个只读变量]</font>
- 引用的本质
	- 引用在C++中的内部实现是一个指针常量

| 引用 | 指针常量 |
| ----------- | ----------- |
| Type& name; | Type\* const name; |

 <font color=Chocolate>**注意：**</font>
 <font color=Chocolate>**C++编译器在编译过程中用指针常量作为引用的内部实现，因此引用所占用的空间大小与指针相同。**</font>
 <font color=Chocolate>**从使用的角度，引用只是一个别名，C++为了实用性而隐藏了引用的存储空间这一细节。**</font>
- C++中的引用旨在大多数的情况下代替指针
	- 功能性：可以满足多数需要使用指针的场合
	- 安全性：可以避开由于指针操作不当而带来的内存错误
	- 操作性：简单易用，又不失功能强大
### 小结
- <font color=Teal>引用作为变量别名而存在旨在代替指针</font>
- <font color=Teal>const引用可以使得变量具有只读属性</font>
- <font color=Teal>引用在编译器内部使用指针常量实现</font>
- <font color=Teal>引用的最终本质为指针</font>
- <font color=Teal>引用可以尽可能的避开内存错误</font>

## lesson06 内联函数分析
- C++中的const常量可以替代宏常数定义，如：

| 常量 | 宏定义 |
| ----------- | ----------- |
| const int A = 3; | #define A 3 |

- 内联函数
	- C++中推荐使用内联函数替代宏代码片段
	- C++中使用inline关键字声明内联函数
``` c++
inline int func(int a, int b) {
	return a < b ? a : b;
}
```
<font color=Chocolate>**内联函数声明时inline关键字必须和函数定义结合在一起，否则编译器会直接忽略内联请求**</font>
- C++ 编译器可以将一个函数进行内联编译
- 被C++编译器内联编译的函数叫做内联函数
- C++ 编译器直接将函数体插入函数调用的地方
- 内联函数没有普通函数调用时的额外开销(压栈，跳转，返回)
- C++ 编译器不一定满足函数的内联请求
### 内联函数
- 内联函数具有普通函数的特征(参数检查，返回类型等)
- 函数的内联请求可能被编译器拒绝
- 函数被内联编译后，函数体直接扩展到调用的地方
> <font color=Chocolate>**宏代码片段由预处理器处理，进行简单的文本替换，没有任何编译过程，因此可能出现副作用**</font>

- 现代C++编译器能够进行编译优化，一些函数即使没有inline声明，也可能被内联编译
- 一些现代C++编译器提供了扩展语法，能够对函数进行强制内联如：
	- g++:__attribute__((always_inline))属性
	- MSVC:__forceinline

### 注意事项
- C++中Inline内联编译的限制：
	- <font color=Chocolate>**不能存在任何形式的循环语句**</font>
	- <font color=Chocolate>**不能存在过多的条件判断语句**</font>
	- <font color=Chocolate>**函数体不能过于庞大**</font>
	- <font color=Chocolate>**不能对函数进行取址操作**</font>
	- <font color=Chocolate>**函数内联声明必须在调用语句之前**</font>
### 小结
- <font color=Teal>C++中可以通过inline声明内联函数</font>
- <font color=Teal>编译器直接将内联函数体扩展到函数调用的地方</font>
- <font color=Teal>inline只是一种请求，编译器不一定允许这种请求</font>
- <font color=Teal>内联函数省去了函数调用时压栈，跳转和返回的开销</font>

## lesson07 函数参数的扩展
### 函数参数的默认值
- C++中可以在函数声明时为参数提供一个默认值
- 当函数调用时没有提供参数的值，则使用默认值
``` c++
int mul(int x = 0);
int main(int argc, char *argv[]) {
	printf("%d\n", mul());	// mul(0)
	return 0;
}
int mul(int x) {
	return x * x;
}
```
### 函数参数的默认值
- 参数的默认值必须在函数声明中指定
### 函数参数的默认值
- 函数默认参数的规则
	- 参数的默认值必须从右向左提供
	- 函数调用时使用了默认值，则后续参数必须使用默认值
### 函数的占位参数
- 在C++中可以为函数提供占位参数
	- 占位参数只有参数类型声明，而没有参数名声明
	- 一般情况下，在函数体内部无法使用占位参数
	- 占位参数与默认参数结合起来使用
	- 兼容C语言程序中可能出现的不规范写法
### 小结
- <font color=Teal>C++中支持函数参数的默认值</font>
- <font color=Teal>如果函数调用时没有提供参数值，则使用默认值</font>
- <font color=Teal>参数的默认值必须从右向左提供</font>
- <font color=Teal>函数调用时使用了默认值，则后续参数必须使用默认值</font>
- <font color=Teal>C++中支持占位参数，用于兼容C语言中的不规范写法</font>

## lesson08 函数重载分析(上)
### 重载(Overload)
- 同一个标识符在不同的上下文有不同的意义
### C++中的函数重载
- 用一个函数名定义不同的函数
- 当函数名和不同的参数搭配时函数的含义不同
- 函数重载至少满足下面的一个条件：
	- 参数个数不同
	- 参数类型不同
	- 参数顺序不同
### 编译器调用重载函数的准则
- 将所有同名函数作为候选者
- 尝试寻找可行的候选函数
	- 精确匹配实参
	- 通过默认参数能够匹配实参
	- 通过默认类型转换匹配实参
- 匹配失败
	- 最终寻找到的候选函数不唯一，则出现二义性，编译失败
	- 无法匹配所有候选者，函数未定义，编译失败
### 函数重载的注意事项
- 重载函数在本质上是相互独立的不同函数
- 重载函数的函数类型不同
- 函数返回值不能作为函数重载的依据
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**函数重载是由函数名和参数列表决定的**</font>

### 小结
- <font color=Teal>函数重载是C++中引入的概念</font>
- <font color=Teal>函数重载用于模拟自然语言中的词汇搭配</font>
- <font color=Teal>函数重载使得C++具有更丰富的语义表达能力</font>
- <font color=Teal>函数重载的本质为相互独立的不同函数</font>
- <font color=Teal>C++中通过函数名和函数参数确定函数调用</font>
## lesson08 函数重载分析(下)
### 重载与指针
- 函数重载遇上函数指针
	- 将重载函数名赋值给函数指针时
		1. 根据重载规则挑选与函数指针参数列表一致的候选者
		2. 严格匹配候选者的函数类型与函数指针的函数类型. 
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**函数重载必然发生在同一个作用域中**</font>
> 编译器需要用参数列表或函数类型进行函数选择
> 无法直接通过函数名得到重载函数的入口地址

### C++和C相互调用
- 实际工程中C++和C代码相互调用是不可避免的
- C++编译器能够兼容C语言的编译方式
- C++编译器会优先使用C++编译的方式
- <font color=CornflowerBlue>**extern**</font>关键字能强制让C++编译器进行C方式的编译
``` c++
extern "C"
{
	// do C-style compilation here
}
```
### 如何保证一段C代码只会以C的方式被编译？
- __cplusplus是C++编译器内置的标准宏定义
- __cplusplus的意义
	- 确保C代码以统一的C方式被编译成目标文件
``` c++
#ifdef __cplusplus
extern "C" {
#endif

// C-Style Compilation

#ifdef __cplusplus
}
#endif
```
> <font color=Chocolate>**注意：**</font>
> <font color=Chocolate>**C++编译器不能以C的方式编译重载函数**</font>
> <font color=Chocolate>**编译方式决定函数名被编译后的目标名**</font>

	- <font color=Chocolate>**C++编译方式将函数名和参数列表编译成目标名**</font>
	- <font color=Chocolate>**C编译方式只将函数名作为目标名进行编译**</font>

### 小结
- <font color=Teal>函数重载是C++对C的一个重要升级</font>
- <font color=Teal>函数重载通过函数参数列表区分不同的同名函数</font>
- <font color=Teal><font color=CornflowerBlue>**extern**</font>关键字能够实现C和C++的相互调用</font>
- <font color=Teal>编译方式决定符号表中的函数名的最终目标名</font>
## lesson10 C++中的新成员
### C++中的动态内存分配
- C++中通过<font color=CornflowerBlue>**new**</font>关键字进行动态内存申请
- C++中的动态内存申请是基于类型进行的
- <font color=CornflowerBlue>**delete**</font>关键字用于内存释放

| 变量申请 | 数组申请 |
| ----------- | ----------- |
| Type\* pointer = new Type; | Type\* pointer = new Type[N]; |
| delete pointer; | delete[] pointer |

### 动态内存分配
- <font color=CornflowerBlue>**new**</font>关键字与<font color=CornflowerBlue>**malloc**</font>函数的区别
	- <font color=CornflowerBlue>**new**</font>关键字是C++的一部分
	- <font color=Chocolate>**malloc**</font>是由C库提供的函数
	- <font color=CornflowerBlue>**new**</font>以具体类型为单位进行内存分配
	- <font color=Chocolate>**malloc**</font>以字节为单位进行内存分配
	- <font color=CornflowerBlue>**new**</font>在申请单个类型变量时可进行初始化
	- <font color=Chocolate>**malloc**</font>不具备内存初始化的特性
### C++中的命名空间
- 在C语言中只有一个全局作用域
	- C语言中所有的全局标识符共享同一个作用域
	- 标识符之间可能发生冲突
- C++中提出了命名空间的概念
	- 命名空间将全局作用域分成不同的部分
	- 不同命名空间中的标识符可以同名而不会发生冲突
	- 命名空间可以相互嵌套
	- 全局作用域也叫默认命名空间
- C++命名空间的定义
```c++
namespace Name {
	namespace Internal {
		/* ... */
	}
	/* ... */
}
```
- C++命名空间的使用：
	- 使用整个命名空间：using namespace name;
	- 使用命名空间中的变量：using name::variable;
	- 使用默认命名空间中的变量：::variable
### 小结
- <font color=Teal>C++中内置了动态内存分配的专用关键字</font>
- <font color=Teal>C++中的动态内存分配可以同时进行初始化</font>
- <font color=Teal>C++中的动态内存分配是基于类型进行的</font>
- <font color=Teal>C++中命名空间概念用于解决名称冲突问题</font>

## lesson11 新型的类型转换
### C方式的强制类型转换
- (Type)(Expression)
- Type(Expression)
### C方式强制类型转换存在的问题
- 过于粗暴
	- 任意类型直接都可以进行转换，编译器很难判断其正确性
- 难于定位
	- 在源码中无法快速定位所有使用强制类型转换的语句
### 新式类型转换
- C++将强制类型转换分为4种不同的类型
| static_cast | const_cast |
| ----------- | ----------- |
| dynamic_cast | reinterpret_cast |
> 用法：xxx_cast<Type>(Expression)

- static_cast强制类型转换
	- 用于基本类型间的转换
	- <font color=Chocolate>**不能**</font>用于基本类型指针间的转换
	- 用于有继承关系类对象之间的转换和类指针之间的转换
	
- const_cast强制类型转换
	- 用于去除变量的只读属性
	- 强制转换的目标类型必须是指针或引用
	
- reinterpret_cast强制类型转换
	- 用于指针类型间的强制转换
	- 用于整数和指针类型间的强制转换
	
- dynamic_cast强制类型转换
	- 用于有继承关系的类指针间的转换
	
	- 用于有交叉关系的类指针间的转换
	
	- 具有类型检查的功能
	
	- 需要虚函数的支持
	
### 小结
- <font color=Teal>C方式的强制类型转换</font>
	- <font color=Teal>过于粗暴</font>
	- <font color=Teal>潜在的问题不易被发现</font>
	- <font color=Teal>不易在代码中定位</font>
- <font color=Teal>新式类型转换以C++关键字的方式出现</font>
	- <font color=Teal>编译器能够帮助检查潜在的问题</font>
	- <font color=Teal>非常方便在代码中定位</font>
	- <font color=Teal>支持动态类型识别(dynamic_cast)</font>

## lesson12 经典问题解析一
### <font color=CornflowerBlue>**const**</font>常量的判别准则
- 只有用字面量初始化的<font color=CornflowerBlue>**const**</font>常量才会进入符号表
- 使用其它变量初始化的<font color=CornflowerBlue>**const**</font>常量仍然是只读变量
- 被<font color=CornflowerBlue>**volatile**</font>修饰的<font color=CornflowerBlue>**const**</font>常量不会进去符号表
- 在<font color=Chocolate>**编译期间不能直接确定初始值**</font>的<font color=CornflowerBlue>**const**</font>标识符，否被作为只读变量处理。
### const引用的类型与初始化变量的类型
- 相同：初始化变量成为只读变量
- 不同：生成一个新的只读变量
### 指针是一个变量
- 值为一个内存地址，不需要初始化，可以保存不同的地址
- 通过指针可以访问对应内存地址中的值
- 指针可以被<font color=CornflowerBlue>**const**</font>修饰成为常量或者只读变量
### 引用只是一个变量的新名字
- 对引用的操作(赋值，取地址等)都会传递到代表的变量上
- <font color=CornflowerBlue>**const**</font>引用使其代表的变量具有只读属性
- 引用必须在定义时初始化，之后无法代表其它变量
### 从使用C++语言的角度看
- 引用与指针没有任何关系
- 引用是变量的新名字，操作引用就是操作对应的变量
### 从C++编译器的角度来看
- 为了支持新概念，“引用”必须要有一个有效的解决方案
- 在编译器内部，使用指针常量来实现“引用”
- 因此“引用”在定义时必须初始化

> 实例二[c++不支持引用数组]：
```c++
#include <stdio.h>

int a = 1;
struct SV {
	int& x;
	int& y;
	int& z;
};

int main(int argc, char* argv[]) {
	int b = 2;
	int* pc = new int(3);
	SV sv = {a, b, *pc};
    // 数组的每个元素的地址是连续的。但实际值array[0]:全局静态存储区array[1]:栈区array[2]:堆区
	int& array[] = { a, b, *pc };	

	printf("&sv.x = %p\n", &sv.x);
	printf("&sv.y = %p\n", &sv.y);
	printf("&sv.z = %p\n", &sv.z);

	delete pc;
	pc = nullptr;
	return 0;
```
## lesson15 类于封装的概念
### 类成员的作用域
- 类成员的作用域都只在类的内部，外部无法直接访问
- 成员函数可以直接访问成员变量和调用成员函数
- 类的外部可以通过类变量访问public成员
- 类成员的作用域与访问级别没有关系
> <font color=Chocolate>**C++中用struct定义的类中所有成员默认为public**</font>

### 小结
- <font color=Teal>类通常可以分为使用方式和内部细节两个部分</font>
- <font color=Teal>类的封装机制使得使用方式和内部细节相分离</font>
- <font color=Teal>C++中通过定义类成员的访问级别实现封装机制</font>
- <font color=Teal>public成员可以在类的内部和外界访问和调用</font>
- <font color=Teal>private成员只能在类的内部被访问和调用</font>

## lesson16 类的真正形态
### 类的关键字
- <font color=CornflowerBlue>**struct**</font>在C语言中已经有了自己的含义，必须继续兼容
- 在C++中提供了新的关键字<font color=CornflowerBlue>**class**</font>用于类定义
- <font color=CornflowerBlue>**struct**</font>和<font color=CornflowerBlue>**class**</font>的用法是完全相同的但有一定区别
- 在用<font color=CornflowerBlue>**struct**</font>定义类时，所有成员的默认访问级别为<font color=Chocolate>**public**</font>
- 在用<font color=CornflowerBlue>**class**</font>定义类时，所有成员的默认访问级别为<font color=Chocolate>**private**</font>
### 需求：开发一个用于四则运算的类
- 提供setOperator函数设置运算类型
- 提供setParameter函数设置运算参数
- 提供result函数进行运算
	- 其返回值表示运算的合法性
	- 通过引用参数返回结果
### 小结
- <font color=Teal>C++引进了新的关键字class用于定义类</font>
- <font color=Teal>struct和class的区别在于默认访问级别的不同</font>
- <font color=Teal>C++中的类支持声明和实现的分离</font>
	- <font color=Teal>在头文件中声明类</font>
	- <font color=Teal>在源文件中实现类</font>
## lesson17 对象的构造[上]
### 对象的初始化
- 从程序设计的角度，对象只是变量，因此：
	- 在栈上创建对象时，成员变量初始为随机值
	- 在堆上创建对象时，成员变量初始为随机值
	- 在静态存储区(全局或static)创建对象时，成员变量初始为0值
### C++中可以定义与类名相同的特殊成员函数
- 这种特殊的成员函数叫做构造函数
	- 构造没有任何返回类型的声明
	- 构造函数在对象定义时自动被调用
### 小结
- <font color=Teal>每个对象在使用之前都应该初始化</font>
- <font color=Teal>类的构造函数用于对象的初始化</font>
- <font color=Teal>构造函数与类同名并且没有返回值</font>
- <font color=Teal>构造函数在对象定义时自动被调用</font>

## lesson18 对象的构造[中]
### 带有参数的构造函数
	- 构造函数可以根据需要定义参数
	- 一个类中可以存在多个重载的构造函数
	- 构造函数的重载遵循C++重载的规则
### 友情提醒
- 对象定义和对象声明不同
	- 对象定义：申请对象的空间并调用构造函数
	- 对象声明：告诉编译器存在这样一个对象
### 需求：开发一个数组类解决原生数组的安全性问题
- 提供函数<font color=CornflowerBlue>**获取数组长度**</font>
- 提供函数<font color=CornflowerBlue>**获取数组元素**</font>
- 提供函数<font color=CornflowerBlue>**设置数组元素**</font>
### 小结
- <font color=Teal>构造函数可以根据需要定义参数</font>
- <font color=Teal>构造函数之间可以存在重载关系</font>
- <font color=Teal>构造函数遵循C++中重载函数的规则</font>
- <font color=Teal>对象定义时会触发构造函数的调用</font>
- <font color=Teal>在一些情况下可以手动调用构造函数</font>

## lesson19 对象的构造[下]
### 特殊的构造函数
- 无参构造函数
	- 没有参数的构造函数
	- 当类中没有定义构造函数时，编译器默认提供一个无参构造函数，并且其函数体为空
- 拷贝构造函数
	- 参数为<font color=CornflowerBlue>**const**</font> class_name&的构造函数
	- 当类中没有定义拷贝构造函数时，编译器默认提供一个拷贝构造函数，简单的进行成员变量的值复制
### 拷贝构造函数的意义
- 兼容C语言的初始化方式
- 初始化行为能够符合预期的逻辑
### 拷贝构造函数的意义
- 浅拷贝
	- 拷贝后对象的物理状态相同
- 深拷贝
	- 拷贝后对象的逻辑状态相同
> <font color=CornflowerBlue>**编译器提供的拷贝构造函数只进行浅拷贝!**</font>
### 什么时候需要进行深拷贝？
- 对象中有成员指代了系统中的资源
	- 成员指向了动态内存空间
	- 成员打开了外存中的文件
	- 成员使用了系统中的网络端口
	- ...
### 一般性原则
- 自定义拷贝构造函数，必然需要实现深拷贝!!!
### 小结
- <font color=Teal>C++编译器会默认提供构造函数</font>
- <font color=Teal>无参构造函数用于定义对象的默认初始状态</font>
- <font color=Teal>拷贝构造函数在创建对象时拷贝对象的状态</font>
- <font color=Teal>对象的拷贝有浅拷贝和深拷贝两种方式</font>
	- <font color=Teal>浅拷贝使得对象的物理状态相同</font>
	- <font color=Teal>浅拷贝使得对象的逻辑状态相同</font>

## lesson20 初始化列表的使用
### 小实验
- 下面的类定义是否合法？
	- 如果合法，ci的值是什么，存储在哪里？
``` C++
#include <stdio.h>

class Test {
private:
	const int ci;
public:
	int getCI() { return ci; }
};


int main(int argc, char* argv[]) {
	Test t;
	printf("Test.ci:%d\n", t.getCI());

	return 0;
}
```
### 类成员的初始化
- C++中提供了初始化列表对成员变量进行初始化
- 语法规则
``` C++
className::ClassName():m1(v1),m2(v2),m3(v3){
	// some other initialize operation
}
```
### 类成员的初始化
- 成员的初始化顺序与成员的声明顺序相同
- 成员的初始化顺序与初始化列表中的位置无关
- 初始化列表先于构造函数的函数体执行

### 类中的const成员
- 类中的<font color=CornflowerBlue>**const**</font>成员会被分配空间的
- 类中的<font color=CornflowerBlue>**const**</font>成员本质是只读变量
- 类中的<font color=CornflowerBlue>**const**</font>成员只能在初始化列表中指定初始值
> 编译器<font color=Chocolate>**无法**</font>直接得到<font color=CornflowerBlue>**const**</font>成员的初始值，因此无法进入符号表成为真正意义上的常量。
### 初始化与赋值不同
- 初始化：对正在创建的对象进行初始值设置
- 赋值：对已经存在的对象进行值设置
- 
### 小结
- 类中可以<font color=CornflowerBlue>**使用初始化列表对成员进行初始化**</font>
- 初始化列表<font color=Teal>**先于构造函数体执行**</font>
- 类中可以定义<font color=Chocolate>**const**</font>成员变量
- <font color=Chocolate>**const**</font>成员变量必须在初始化列表中指定初始值
- <font color=Chocolate>**const**</font>成员变量为只读变量

## lesson21 对象的构造顺序
### 局部对象
- 当程序执行流到达对象的定义语句时进行构造
### 堆对象
- 当程序执行流到达<font color=CornflowerBlue>**new**</font>语句时创建对象
- 使用<font color=CornflowerBlue>**new**</font>创建对象将自动触发构造函数的调用
### 全局对象
- 对象的构造顺序是不确定的
- 不同的编译器使用不同的规则确定构造顺序
> 编译器<font color=Chocolate>**不同的编译器厂商行为不同导致构造顺序不同**</font>
### 小结
- <font color=Chocolate>**const**</font>的构造顺序依赖于程序的执行流
- <font color=CornflowerBlue>**堆对象**</font>的构造顺序依赖于<font color=Chocolate>**new**</font>的使用顺序
- <font color=Teal>**全局对象**</font>的构造顺序是<font color=Chocolate>**不确定的**</font>



