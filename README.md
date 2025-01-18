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
### new Test和new Test()的区别
- 当类中显示定义了无参的构造函数时无区别
- 当类中没有显示定义无参构造函数时：
	- new Test 不会对成员变量进行初始化
	- new Test()会自动完成成员变量初始化
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

## lesson22 对象的销毁
### 对象的销毁
- 生活中的对象都是被初始化后才上市的
- 生活中的对象被销毁前会做一些清理工作
### 析构函数
- C++的类中类中可以定义一个特殊的清理函数
	- 这个特殊的清理函数叫做<font color=CornflowerBlue>**析构函数**</font>
	- <font color=CornflowerBlue>**析构函数**</font>的功能与构造函数相反
- 定义：~ClassName()
	- 析构函数<font color=Chocolate>**没有参数**</font>也没有返回值类型声明
	- 析构函数在对象销毁时自动被调用
### 析构函数的定义准则
- 当类中<font color=Chocolate>**自定义了构造函数**</font>，并且构造函数中<font color=CornflowerBlue>**使用了系统资源（如：内存申请，文件打开，等）**</font>则需要自定义析构函数。

## lesson23 神秘的临时对象
### 下面的程序输出什么？
``` c++
#include <stdio.h>

class Test {
private:
	int mi;
public:
	Test() {
		Test(0); // 临时对象
	}
	Test(int i) {
		mi = i;
	}
	void print() { printf("mi = %d\n", mi); }
};

int main(int argc, char* argv[]) {
	Test t;		

	t.print();

	return 0;
}
```
> mi = -858993460 // 随机值

### 构造函数是一个特殊函数
- 是否可以直接调用？	是
- 是否可以在构造函数中调用构造函数?
- 直接调用构造函数的行为是什么?
### 答案
- 直接调用构造函数将产生一个<font color=CornflowerBlue>**临时对象**</font>
- <font color=CornflowerBlue>**临时对象**</font>的生命周期只有一条语句的时间
- <font color=CornflowerBlue>**临时对象**</font>的作用域只在一条语句中
- <font color=CornflowerBlue>**临时对象**</font>C++中值得警惕的灰色地带
- <font color=CornflowerBlue>**临时对象**</font>没有名字
### 小结
- 直接调用构造函数将产生一个<font color=CornflowerBlue>**临时对象**</font>
- 临时对象是<font color=Teal>**性能的瓶颈**</font>也是<font color=CornflowerBlue>**bug的来源**</font>
- 现代C++编译器会尽力<font color=Chocolate>**避开临时对象**</font>成员变量
- 实际工程开发中需要认为的<font color=Chocolate>**避开临时对象**</font>

## lesson24 经典问题解析二
### 关于析构的问题
> 当程序中存在<font color=CornflowerBlue>**多个对象**</font>的时候，如何确定这些对象的<font color=CornflowerBlue>**析构顺序**</font>?
- <font color=CornflowerBlue>**单个对象**</font>创建时构造函数的调用顺序
	1. 调用父类的构造过程(<font color=Teal>**后续课程中讲解**</font>)
	2. 调用<font color=Chocolate>**成员变量的构造函数**</font>（调用顺序与生命顺序相同）
	3. 调用<font color=CornflowerBlue>**类自身的构造函数**</font>
- <font color=Chocolate>**析构函数**</font>与对应<font color=Teal>**构造函数的调用顺序相反**</font>
	
- <font color=CornflowerBlue>**多个对象**</font>创建时构造函数的调用顺序
- 析构顺序与构造顺序相反

### 关于析构的答案
- 对于栈对象和全局对象，类似于入栈和出栈的顺序，<font color=Teal>**最后构造的随心被最先析构**</font>！！
- <font color=CornflowerBlue>**堆对象**</font>的析构发生在使用<font color=CornflowerBlue>**delete**</font>的时候，<font color=HotPink>**与delete的使用顺序相关**</font>！！

### 关于const对象的疑惑
> 关键字能否<font color=HotPink>**修饰类的对象**</font>？如果可以，<font color=Chocolate>**有什么特性**</font>？
- <font color=CornflowerBlue>**const**</font>关键字能够修饰对象
- <font color=CornflowerBlue>**const**</font>修饰的对象为<font color=MediumOrchid>**只读对象**</font>
- 只读对象的<font color=Chocolate>**成员变量不允许改变**</font>，运行时无线
- 只读对象的是<font color=CornflowerBlue>**编译阶段的概念**</font>，运行时无效

### C++中的<font color=HotPink>**const成员函数**</font>
- <font color=CornflowerBlue>**const**</font>对象<font color=Chocolate>**只能调用const的成员函数**</font>
- <font color=CornflowerBlue>**const**</font>成员函数中<font color=Chocolate>**只能调用const成员函数**</font>
- <font color=CornflowerBlue>**const**</font>成员函数中<font color=HotPink>**不能直接改写成员变量的值**</font>
### <font color=CornflowerBlue>**const**</font>成员函数的定义
- <font color=MediumOrchid>**Type**</font> <font color=Chocolate>**ClassName::**</font>function(<font color=MediumOrchid>**Type**</font> p) <font color=CornflowerBlue>**const**</font>
> 类中的<font color=CornflowerBlue>**函数声明**</font>与实际<font color=MediumOrchid>**函数定义**</font>中都必须带<font color=CornflowerBlue>**const**</font>关键字

### 关于类成员的疑问
> <font color=Chocolate>**成员函数**</font>和<font color=CornflowerBlue>**成员变量**</font>都是隶属于<font color=HotPink>**具体对象**</font>的吗？
- 从<font color=CornflowerBlue>**面向对象**</font>的角度
	- 对象由属性(成员变量)和方法(成员函数)构成
- 从<font color=Chocolate>**程序运行**</font>的角度
	- 对象由<font color=Teal>**数据**</font>和<font color=MediumOrchid>**函数**</font>构成
		- 数据可以位于栈，堆，和全局数据区
		- 函数只能位于代码段

### 结论
- 每一个<font color=Teal>**对象拥有自己独立的属性**</font>（成员变量）
- 所有的<font color=Chocolate>**对象共享类的方法**</font> （成员函数）
- <font color=MediumOrchid>**方法能够直接访问对象的属性**</font>
- 方法中的<font color=HotPink>**隐藏参数**</font> <font color=CornflowerBlue>**this**</font> 用于指代<font color=MediumOrchid>**当前对象**</font>

### 小结
- 对象的<font color=CornflowerBlue>**析构顺序于构造顺序相反**</font>
- <font color=CornflowerBlue>**const**</font>关键字能够修饰对象，得到<font color=Chocolate>**只读对象**</font>
- 只读对象只能调用<font color=CornflowerBlue>**const**</font>成员函数
- 所有对象共享类的成员函数
- 隐藏的<font color=CornflowerBlue>**this**</font>指针用于表示<font color=MediumOrchid>**当前对象**</font>

## lesson25 类的静态成员变量
### 成员变量的回顾
- 通过<font color=HotPink>**对象名**</font>能够访问<font color=CornflowerBlue>**public**</font>成员变量
- 每个对象的<font color=MediumOrchid>**成员变量**</font>都是<font color=Chocolate>**专属的**</font>
- 成员变量<font color=HotPink>**不能**</font>在对象之间<font color=CornflowerBlue>**共享**</font>
### 新的需求
- 统计在程序运行期间<font color=CornflowerBlue>**某个类的对象数目**</font>
- 保证程序的安全性（<font color=HotPink>**不能使用全局变量**</font>）
- <font color=Chocolate>**随时**</font>可以获取当前对象的数目
### 在C++中可以定义<font color=CornflowerBlue>**静态成员变量**</font>
- 静态成员变量<font color=Chocolate>**属于整个类所有**</font>
- 静态成员变量的生命周期不依赖于任何对象
- 可以通过类名直接访问公有静态成员变量
- <font color=MediumOrchid>**所有对象共享类的静态成员变量**</font>
- 可以<font color=Teal>**通过对象名访问**</font>公有静态成员变量
### 静态成员变量的特性
- 在定义时直接通过<font color=CornflowerBlue>**static**</font>关键字修饰
- 静态成员变量<font color=CornflowerBlue>**需要在类外单独分配空间**</font>
- 静态成员变量在程序内部<font color=CornflowerBlue>**位于全局数据区**</font>
### 语法规则
> <font color=MediumOrchid>**Type**</font> <font color=CornflowerBlue>**ClassName**</font>::VarName = <font color=Chocolate>**Value**</font>;

### 小结
- 类中可以通过<font color=CornflowerBlue>**static**</font>关键字定义<font color=Chocolate>**静态成员变量**</font>
- 静态成员变量<font color=HotPink>**隶属于类所有**</font>
- 每一个<font color=CornflowerBlue>**对象都可以访问**</font>静态成员变量
- 静态成员变量<font color=Teal>**在全局数据区分配空间**</font>
- 静态成员变量的<font color=CornflowerBlue>**生命周期为程序运行期**</font>
## lesson26 类的静态成员变量
### 在C++中可以定义静态成员函数
- 静态成员函数是类中<font color=MediumOrchid>**特殊的成员函数**</font>
- 静态成员函数<font color=Chocolate>**属于整个类所有**</font>
- 可以<font color=Teal>**通过类名直接访问**</font>公有静态成员函数
- 可以<font color=CornflowerBlue>**通过对象名访问**</font>公有静态成员函数
### 静态成员函数的定义
- 直接通过<font color=MediumOrchid>**static**</font>关键字修饰成员函数
### 静态成员函数 vs 普通成员函数
| / | <font color=CornflowerBlue>静态成员函数</font> | <font color=Chocolate>**普通成员函数**</font> |
| :-----------: | :-----------: | :-----------: |
| 所有对象共享 | Yes | Yes|
| 隐含this指针 | No | Yes |
| 访问普通成员变量(函数) | No | Yes|
| 访问静态成员变量(函数) | Yes | Yes|
| 通过类名直接调用 | Yes | No|
| 通过对象名直接调用 | Yes | Yes|
### 小结
- 静态成员函数是类中<font color=MediumOrchid>**特殊的成员函数**</font>
- 静态成员函数<font color=HotPink>**没有**</font>隐藏的<font color=CornflowerBlue>**this**</font>参数
- 静态成员函数<font color=CornflowerBlue>**可以通过类名直接访问**</font>
- 静态成员函数<font color=MediumOrchid>**只能直接访问静态成员变量(函数)**</font>
## lesson27 二阶构造模式
### 构造函数的回顾
- 类的<font color=CornflowerBlue>**构造函数**</font>用于对象的<font color=Chocolate>**初始化**</font>
- 构造函数<font color=MediumOrchid>**与类同名并且没有返回值**</font>
- 构造函数在对象定义时<font color=Teal>**自动被调用**</font>
### 问题
1. 如何判断构造函数的执行结果？
2. 在构造函数中执行return语句会发生什么？
3. 构造函数执行结束是否意味着对象构造成功？
> 编程实验一：异常的构造函数27-1.cpp
``` c++
#include <stdio.h>

class Test {
private:
	int mi;
	int mj;
	bool mStatus;
public:
	Test(int i, int j):mStatus(false) {
		mi = i;

		return;

		mj = j;
		mStatus = true;
	}
	int getI() {
		return mi;
	}
	int getJ() {
		return mj;
	}
	int status() {
		return mStatus;
	}
};

int main(int argc, char* argv[]) {
	Test t1(1, 2);

	if (t1.status()) {
		printf("t1.mi = %d\n", t1.getI());
		printf("t1.mj = %d\n", t1.getJ());
	}
	else {
		printf("construct failed!");
	}

	return 0;
}
```
### 回答
1. 没有办法[<font color=CornflowerBlue>**只提供自动初始化成员变量的机会**</font>]
2. 返回就结束了构造函数的调用[<font color=CornflowerBlue>**执行return语句后构造函数立即结束**</font>]
3. 不一定成功[<font color=CornflowerBlue>**不能保证初始化逻辑一定成功**</font>]
> 构造函数能决定的<font color=Chocolate>**只是对象的初始状态**</font>，<font color=CornflowerBlue>**而不是对象的诞生**</font>!!
### <font color=CornflowerBlue>**半成品对象的概念**</font>
- <font color=Chocolate>**初始化操作不能按照预期完成而得到的对象**</font>
- 半成品对象是<font color=MediumOrchid>**合法的C++对象**</font>,也是<font color=HotPink>**Bug的重要来源**</font>
### 工程开发中的构造过程可分为
- <font color=CornflowerBlue>**资源无关**</font>的初始化操作
	- 不可能出现异常情况的操作
- 需要<font color=Chocolate>**使用系统资源**</font>的操作
	- 可能出现异常情况：如：内存申请，访问文件
### 二阶构造示例：
```C++
class TwoPhaseCons {
private:
	TwoPhaseCons(){		// 第一阶段构造函数
	}
	bool construct() {	// 第二阶段构造函数
		return true;
	}
public:
	static TwoPhaseCons* NewInstance();	// 对象创建函数
};

TwoPhaseCons* TwoPhaseCons::NewInstance() {
	TwoPhaseCons* ret = new TwoPhaseCons();
	
	// 若第二阶段构造失败，返回NULL
	if(!(ret && ret->construct())) {
		delete ret;
		ret = nullptr;
	}
	
	return ret;
}
```
### 小结
- 构造函数<font color=Chocolate>**只能决定对象的初始化状态**</font>
- 构造函数中<font color=CornflowerBlue>**初始化操作的失败不影响对象的诞生**</font>
- 初始化不完全的<font color=Chocolate>**半成品对象是Bug的重要来源**</font>
- 二阶构造认为的<font color=MediumOrchid>**将初始化过程分为两部分**</font>
- <font color=CornflowerBlue>**二阶构造**</font>能够确保创建的<font color=CornflowerBlue>**对象都是完整初始化的**</font>
## lesson28 友元的尴尬能力
### 什么是友元？
- 友元是C++中的<font color=Chocolate>**一种关系**</font>
- 友元关系发生在<font color=HotPink>**函数与类之间**</font>或者<font color=MediumOrchid>**类鱼类之间**</font>
- 友元关系是单项的，不能传递
### 友元的用法
- 在类中以<font color=CornflowerBlue>**friend**</font>关键字声明友元
- 类的友元可以是<font color=MediumOrchid>**其他类或者具体函数**</font>
- 友元<font color=CornflowerBlue>**不是**</font>类的一部分
- 友元<font color=HotPink>**不受**</font>类中访问级别的限制
- <font color=MediumOrchid>**友元可以直接访问具体类的所有成员**</font>
```c++
class Point{
private:
	double x;
	double y;
	
	friend void func(Point& p);	// 将全局域的函数func声明为class Point的友元
};

void func(Point& p) {

}
```
### 友元的尴尬
- 友元是为了<font color=CornflowerBlue>**兼顾C语言的高效**</font>而诞生的
- 友元<font color=Chocolate>**直接破坏**</font>了面向对象的封装性
- 友元在实际产品中的<font color=Chocolate>**高效是得不偿失的**</font>
- 友元在现代软件工程中<font color=MediumOrchid>**已经逐渐被遗弃**</font>
- 友元关系<font color=Chocolate>**不具备传递性**</font>
- 类的友元可以是<font color=CornflowerBlue>**其它类的成员函数**</font>
- 类的引用可以是<font color=MediumOrchid>**某个完整的类**</font>
	- 所有的成员函数都是友元
## lesson29 类中的函数重载
### 函数重载回顾
- 函数重载的<font color=Chocolate>**本质为相互独立的不同函数**</font>
- C++中通过<font color=Chocolate>**函数名**</font>和<font color=CornflowerBlue>**函数参数**</font>确定函数调用
- <font color=Chocolate>**无法**</font>直接通过<font color=CornflowerBlue>**函数名**</font>得到重载函数的<font color=CornflowerBlue>**入口地址**</font>
- 函数重载<font color=MediumOrchid>**必然发生在同一个作用域中**</font>
### 类中的成员函数可以进行重载
- <font color=Chocolate>**构造函数的重载**</font>
- <font color=CornflowerBlue>**普通成员函数的重载**</font>
- <font color=MediumOrchid>**静态成员函数的重载**</font>
### 重载的本质
1. 重载函数的<font color=MediumOrchid>**本质为多个不同的函数**</font>
2. <font color=CornflowerBlue>**函数名**</font>和<font color=CornflowerBlue>**参数列表**</font>是唯一标识
3. 函数重载<font color=Chocolate>**必须发生在同一个作用域中**</font>
### 重载的意义
- 通过<font color=Chocolate>**函数名**</font>对函数功能进行提示
- 通过<font color=CornflowerBlue>**参数列表**</font>对函数用法进行提示
- 扩展系统中<font color=MediumOrchid>**构造函数的重载**</font>的函数功能
## lesson30 操作符重载
### 操作符重载
- C++中的<font color=CornflowerBlue>**重载**</font>能够<font color=Chocolate>**扩展操作符的功能**</font>
- 操作符的重载<font color=CornflowerBlue>**以函数的方式进行**</font>
- 本质：用<font color=MediumOrchid>**特殊形式的**</font>函数扩展操作符的功能
- 通过<font color=CornflowerBlue>**operator**</font>关键字可以定义<font color=CornflowerBlue>**特殊的函数**</font>
- <font color=CornflowerBlue>**operator**</font>的本质是<font color=CornflowerBlue>**通过函数重载操作符**</font>进行操作符重载
> <font color=Chocolate>**Type**</font> <font color=CornflowerBlue>**operator**</font> <font color=Chocolate>**Sign**</font>(<font color=CornflowerBlue>**const**</font> <font color=Chocolate>**Type**</font> p1, (<font color=CornflowerBlue>**const**</font> <font color=Chocolate>**Type**</font> p2)
> {
> 	<font color=Chocolate>**Type**</font> ret;
> 	<font color=CornflowerBlue>**return**</font> ret;
> }
> <font color=HotPink>**Sign**</font>为系统中预定义的操作符：+、-、*、/等

### 可以将<font color=CornflowerBlue>**操作符重载函数**</font>定义为类的成员函数
- <font color=CornflowerBlue>**比全局操作符重载函数少一个参数**</font>(<font color=MediumOrchid>**左操作数**</font>)
- <font color=CornflowerBlue>**不需要依赖友元**</font>就可以完成操作符重载
- <font color=HotPink>**编译器优先在成员函数中寻找操作符重载函数**</font>
> <font color=CornflowerBlue>**class**</font> <font color=Chocolate>**Type**</font>
> {
> <font color=CornflowerBlue>**public:**</font>
> 	<font color=Chocolate>**Type**</font> <font color=CornflowerBlue>**operator**</font> <font color=Chocolate>**Sign**</font>(<font color=CornflowerBlue>**const**</font> <font color=Chocolate>**Type**</font>& p) {
>	<font color=Chocolate>**Type**</font> ret;
>	<font color=CornflowerBlue>**return**</font> ret;
> };

## lesson31 完善的复数类
### 复数类应该有的操作
- 运算：+、-、*、/
- 比较：==，!=
- 赋值：=
- 求模：modulus

### 利用操作符重载
- 统一<font color=Chocolate>**复数**</font>与<font color=HotPink>**实数**</font>的运算方式
- 统一<font color=Chocolate>**复数**</font>与<font color=HotPink>**实数**</font>的比较方式
```c++
Complex operator + (const Complex& c);
Complex operator - (const Complex& c);
Complex operator * (const Complex& c);
Complex operator / (const Complex& c);

bool operator == (const Complex& c);
bool operator != (const Complex& c);

Complex& operator = (const Complex& c);
```
### 小结
- C++规定<font color=Teal>赋值操作符</font>(=)<font color=Teal>只能重载为成员函数</font>
- 操作符重载<font color=Chocolate>不能改变</font>原操作符的<font color=HotPink>优先级</font>
- 操作符重载<font color=Chocolate>不能改变</font>操作数的个数
- 操作符重载<font color=Chocolate>不能改变</font>操作符的<font color=Teal>原有语义</font>
## lesson32 初探C++标准库
### C++标准库
- C++标准库并<font color=Chocolate>不是</font>C++语言的一部分
- C++标准库是由<font color=MediumOrchid>类库</font>和<font color=Chocolate>函数库</font>组成的集合
- C++标准库中定义的类和对象都位于<font color=Chocolate>std</font>命名空间
- C++标准库的头文件都<font color=Chocolate>不带</font><font color=Teal>.h</font>后缀
- C++标准库<font color=Chocolate>涵盖了C库的功能</font>
## lesson33 C++中的字符串类
### C++标准库提供了string类型
- string直接支持<font color=MediumOrchid>字符串连接</font>
- string直接支持<font color=Chocolate>字符串的大小比较</font>
- string直接支持<font color=MediumOrchid>字符串查找和提取</font>
- string直接支持<font color=CornflowerBlue>字符串的插入和替换</font>
### 字符串与数字的转换
- 标准库中提供了<font color=Chocolate>相关的类</font>对字符串和数字进行转换
- 字符串流类(<font color=MediumOrchid>sstream</font>)用于string的转换
### 使用方法
- string -> 数字
```c++
	istringstream iss("123.45");
	double num;
	iss >> num;
```
- 数字 -> string
```c++
	ostringstream oss;
	oss << 543.21;
	string s = oss.str();
```

## lesson34 数组操作符的重载
### 数组访问操作符(<font color=HotPink>[]</font>)
- 只能通过类的<font color=CornflowerBlue>成员函数重载</font>
- 重载函数<font color=Teal>能且仅能</font>使用一个参数
- 可以定义不同参数的<font color=Chocolate>多个重载函数</font>
## lesson35 函数对象分析
### 编写一个函数
- 函数可以获得斐波那契数列每项的值
- <font color=MediumOrchid>**每调用一次返回一个值**</font>
- <font color=CornflowerBlue>**函数可以根据需要重复使用**</font>
### 解决方案：函数对象
- <font color=HotPink>**使用具体的类对象取代函数**</font>
- 该类的对象<font color=CornflowerBlue>**具备函数调用的行为**</font>
- <font color=Chocolate>**构造函数**</font>指定具体string直接支持<font color=MediumOrchid>**数列项的起始位置**</font>
- 多个对象相互独立的求解数列项
### 小结
- 函数调用操作符(<font color=HotPinkl>**()**</font>)是可重载的
- 函数调用操作符只能通过类的<font color=CornflowerBlue>**成员函数重载**</font>
- 函数调用操作符可以定义不同参数的<font color=Chocolate>**多个重载函数**</font>
- 函数对象用于在工程中<font color=HotPinkl>**取代函数指针**</font>
## lesson36 经典问题解析三
### 什么时候需要<font color=CornflowerBlue>**重载赋值操作符**</font>
- 编译器为每个类<font color=Chocolate>**默认重载了赋值操作符**</font>
- 默认的赋值操作符<font color=CornflowerBlue>**仅完成浅拷贝**</font>
- 当需要进行<font color=MediumOrchid>**深拷贝时必须重载赋值操作符**</font>
- <font color=Teal>**赋值操作符**</font>与<font color=Teal>**拷贝构造函数**</font>由相同的存在意义
### 小结
- 在需要进行<font color=HotPinkl>**深拷贝**</font>的时候必须<font color=Chocolate>**重载赋值操作符**</font>
- <font color=CornflowerBlue>**赋值操作符**</font>和<font color=Chocolate>**拷贝构造函数**</font>有同等重要的意义
- <font color=Chocolate>**string**</font>类通过一个数据空间保存字符数据
- <font color=Chocolate>**string**</font>类通过一个成员变量保存当前字符串的长度
- C++开发时尽量避开C语言中惯用的编程思想
## lesson37 智能指针
### 内存泄漏
- 动态申请堆空间，<font color=CornflowerBlue>**用完后不归还**</font>
- C++语言中<font color=Chocolate>**没有垃圾回收**</font>的机制
- 指针<font color=HotPink>**无法控制**</font>所指堆空间的生命周期
> 本质问题是指针和实际指向的内存空间没有任何关系

### 我们需要什么
- 需要一个<font color=HotPink>**特殊的**</font>指针
- 指针生命周期结束时<font color=Chocolate>**主动释放堆空间**</font>
- 一片堆空间<font color=CornflowerBlue>**最多只能由一个指针标识**</font>
- <font color=MediumOrchid>**无法控制**</font>指针运算和指针比较
### 解决方案
- <font color=MediumOrchid>**重载指针特征操作符**</font>(->和*)
- 只能通过类的<font color=CornflowerBlue>**成员函数重载**</font>
- 重载函数<font color=Chocolate>**不能**</font>使用参数
- 只能定义<font color=MediumOrchid>**一个**</font>重载函数
## lesson38 逻辑操作符的陷阱
### 逻辑运算符的原生语义
- 操作数只有两种值(<font color=CornflowerBlue>**true**</font>和<font color=CornflowerBlue>**fasle**</font>)
- 逻辑表达式<font color=HotPink>**不用完全计算就能确定最终值**</font>
- 最终结果只能是<font color=CornflowerBlue>**true**</font>或者<font color=CornflowerBlue>**false**</font>
### 一些有用的建议
- <font color=HotPink>**实际工程开发中避免重载逻辑操作符**</font>
- 通过<font color=Chocolate>**重载比较操作符**</font>代替逻辑操作符重载
- 直接<font color=MediumOrchid>**使用成员函数**</font>代替逻辑操作符重载
- 使用<font color=HotPink>**全局函数**</font>对逻辑操作符进行重载
## lesson40 前置操作符和后置操作符
- 现代编译器产品会<font color=Chocolate>**对代码进行优化**</font>
- 优化使得最终的二进制程序<font color=MediumOrchid>**更加高效**</font>
- 优化后的二进制程序<font color=CornflowerBlue>**丢失了C/C++的原生语义**</font>
- <font color=Chocolate>**不可能**</font>从编译后的二进制程序<font color=Chocolate>**还原C/C++程序**</font>
### ++操作符可以被重载
- <font color=HotPink>**全局函数**</font>和<font color=Chocolate>**成员函数**</font>均可进行重载
- 重载前置++操作符<font color=MediumOrchid>**不需要额外的参数**</font>
- 重载后置++操作符<font color=Teal>**需要一个**</font>int<font color=Teal>**类型的占位参数**</font>
### 真正的区别
- 对于<font color=Chocolate>**基础类型**</font>的变量
	- 前置++的效率与后置++的效率基本相同
	- 根据项目组编码规范进行选择
- 对于<font color=CornflowerBlue>**类类型**</font>的对象
	- 前置++的效率高于后置++
	- 尽量使用<font color=MediumOrchid>**前置++操作符提高程序效率**</font>
## lesson41 类型转换函数
### 基本数据类型转换
- 标准数据类型之间会进行<font color=Teal>**隐士的类型安全转换**</font>
- 转换规则如下：
> char  ->
> 		int->unsigned int->long->unsigned long->float->double
> short->

### 再论构造函数
- 构造函数可以定义<font color=Chocolate>**不同类型的参数**</font>
- 参数满足下列条件时称为<font color=HotPink>**转换构造函数**</font>
	- <font color=Teal>**有且仅有一个参数**</font>
	- <font color=Teal>**参数是基本类型**</font>
	- <font color=Teal>**参数是其它类类型**</font>
### 编译器的行为
- 编译器<font color=CornflowerBlue>**尽力尝试**</font>的结果是<font color=HotPink>**隐式类型转换**</font>
- 隐式类型转换
	- 会让程序以<font color=MediumOrchid>**意想不到**</font>的方式进行工作
	- 是工程中<font color=Chocolate>**bug**</font>的重要来源
- 工程中通过<font color=CornflowerBlue>**explicit**</font>关键字<font color=Chocolate>**杜绝编译器的转换尝试**</font>
- 转换构造函数被<font color=CornflowerBlue>**explicit**</font>修饰时只能进行<font color=Chocolate>**显示转换**</font>
	- <font color=CornflowerBlue>**static_cast**</font><<font color=Chocolate>**ClassName**</font>>(value);
	- <font color=Chocolate>**ClassName**</font>(value);
	- (<font color=Chocolate>**ClassName**</font>)value		// <font color=Teal>**不推荐**</font>
### 类型转换函数
- C++类中可以定义<font color=CornflowerBlue>**类型转换函数**</font>
- 类型转换函数用于<font color=CornflowerBlue>**将类对象转换为其它类型**</font>
- 语法规则：
```c++
operator Type() {
	Type ret;
	// ...
	return ret;
}
```
### <font color=CornflowerBlue>**类型转换函数**</font> vs <font color=MediumOrchid>**转换构造函数**</font>
- <font color=Chocolate>**无法抑制**</font>隐式的类型转换函数调用
- 类型转换函数<font color=Teal>**可能与转换构造函数冲突**</font>
- 工程中以<font color=HotPink>**Type**</font> <font color=CornflowerBlue>**toType**</font>()的公有成员函数代替类型转换函数
## lesson43 继承的概念和意义
### 组合关系的特点
- 将<font color=Chocolate>**其它类的对象**</font>作为<font color=Chocolate>**当前类的成员**</font>使用
- 当前类的对象与成员对象的<font color=MediumOrchid>**生命期相同**</font>
- 成员对象在<font color=CornflowerBlue>**用法上**</font>与普通对象<font color=CornflowerBlue>**完全一致**</font>
### 面向对象中的<font color=CornflowerBlue>**继承**</font>指类之间的<font color=Chocolate>**父子关系**</font>
- 子类拥有父类的<font color=MediumOrchid>**所有属性和行为**</font>
- 子类就是一种<font color=Navy>**特殊的父类**</font>
- <font color=GoldenRod>**子类对象可以当作父类对象使用**</font>
- 子类中可以<font color=Teal>**添加父类没有的**</font>方法和属性
> C++中通过下面的方式描述继承关系
``` C++
class Parent {
private:
	int mv;
public:
	void method() {};
};

class Child:public Parent	// 描述继承关系
{};
```
### 重要原则：
- 子类就是一个<font color=Chocolate>**特殊的父类**</font>
- 子类对象可以<font color=MediumOrchid>**直接初始化**</font>父类对象
- 子类对象可以<font color=HotPink>**直接赋值给**</font>父类对象
### 继承的意义
- 继承是C++中<font color=MediumOrchid>**代码复用**</font>的重要手段。通过<font color=Chocolate>**继承**</font>，可以<font color=CornflowerBlue>**获得父类的所有功能**</font>，并且可以在子类中<font color=Teal>**重写已有功能**</font>，或者<font color=Teal>**添加新功能**</font>。
### 小结
- 继承是面向对象中<font color=CornflowerBlue>**类之间的一种关系**</font>
- 子类拥有父类的<font color=CornflowerBlue>**所有属性和行为**</font>
- 子类对象可以当作父类对象使用
- 子类中可以<font color=Teal>**添加父类没有的**</font>方法和属性
- 继承是面向对象中<font color=HotPink>**代码复用的重要手段**</font>
## lesson44 继承中的访问级别
- 面向对象中的访问级别不只是<font color=CornflowerBlue>**public**</font>和<font color=CornflowerBlue>**private**</font>
- 可以定义<font color=Chocolate>**protected**</font>访问级别
- 关键字<font color=CornflowerBlue>**protected**</font>的意义
	- 修饰的成员<font color=Chocolate>**不能被外界直接访问**</font>
	- 修饰的成员<font color=MediumOrchid>**可以被子类直接访问**</font>
### 小结
- 面向对象中的访问级别不只是<font color=CornflowerBlue>**public**</font>和<font color=CornflowerBlue>**private**</font>
- <font color=HotPink>**protected**</font>修饰的成员<font color=Teal>**不能被外界所访问**</font>
- <font color=HotPink>**protected**</font>使得<font color=Chocolate>**子类能够访问父类的成员**</font>
- <font color=HotPink>**protected**</font>关键字是<font color=HotPink>**为了继承而专门设计的**</font>
- 没有<font color=HotPink>**protected**</font>就无法完成真正意义上的<font color=Chocolate>**代码复用**</font>
## lesson45 不同的继承方式(略)
## lesson46 继承中的构造与析构
### 子类对象的构造
- 子类中可以定义构造函数
- 子类构造函数
	- <font color=CornflowerBlue>**必须对继承而来的成员进行初始化**</font>
	- 直接通过<font color=MediumOrchid>**初始化列表**</font>或者<font color=MediumOrchid>**赋值的方式**</font>进行初始化
	- <font color=Chocolate>**调用父类构造函数**</font>进行初始化
### 父类构造函数在子类中的调用方式
- 默认调用
	- 适用于<font color=CornflowerBlue>**无参构造函数**</font>和<font color=Teal>**使用默认参数的构造函数**</font>
- 显示调用
	- 通过<font color=Chocolate>**初始化列表**</font>进行调用
	- 适用于<font color=HotPink>**所有**</font>父类构造函数
### 父类构造函数的调用
```c++
class Child: public Parent {
public:
	Child() {	// 隐式调用
		cout << "Child()" << endl;
	}
	Child(String s) : Parent("Parameter to Parent") {	// 显示调用
		cout << "Child() : " << s << endl;
	} 
};
```
### 构造规则
- 子类对象在创建时会<font color=CornflowerBlue>**首先调用父类的构造函数**</font>
- <font color=Chocolate>**先执行父类构造函数**</font>再执行子类的构造函数
- 父类构造函数可以被<font color=MediumOrchid>**隐式调用**</font>或者<font color=HotPink>**显示调用**</font>
### <font color=CornflowerBlue>**对象**</font>创建时构造函数的调用顺序
1. <font color=MediumOrchid>**调用父类的构造函数**</font>
2. 调用<font color=MediumOrchid>**成员变量的构造函数**</font>
3. 调用<font color=Green>**类自身的构造函数**</font>
> 先父母，后客人，再自己

### <font color=CornflowerBlue>**析构函数**</font>的调用顺序与构造函数相反
1. 执行<font color=CornflowerBlue>**自身的**</font>析构函数
2. 执行<font color=Chocolate>**成员变量的**</font>析构函数
3. 执行<font color=MediumOrchid>**父类的**</font>析构函数
### 小结
- 子类对象在创建时<font color=CornflowerBlue>**需要调用父类构造函数**</font>进行初始化
- 先执行<font color=CornflowerBlue>**父类构造函数**</font>然后执行<font color=HotPink>**成员的构造函数**</font>
- 父类构造函数<font color=Chocolate>**显示调用需要在初始化列表中进行**</font>析构函数
- 子类对象在销毁时<font color=Green>**需要调用父类析构函数**</font>进行清理
- 析构顺序与构造顺序<font color=HotPink>**对称相反**</font>
## lesson47 父子间的冲突
### 父子间的冲突
- 子类<font color=CornflowerBlue>**可以定义**</font>父类中的<font color=Chocolate>**同名成员**</font>
- 子类中的成员将<font color=MediumOrchid>**隐藏父类中的同名成员**</font>
- 父类中的<font color=MediumOrchid>**同名成员依然存在于子类中**</font>
- 通过<font color=HotPink>**作用域分辨符（::）**</font>访问父类中的同名成员
- 子类中的函数将<font color=GoldenRod>**隐藏父类的同名函数**</font>
- 子类<font color=HotPink>**无法重载**</font>父类中的成员函数
- 使用<font color=MediumOrchid>**作用域分辨符**</font>访问父类中的同名函数
- 子类可以定义父类中<font color=Green>**完全相同的成员函数**</font>
## lesson48 同名覆盖引发的问题
### 子类对象可以当作父类对象使用(兼容性)
- 子类对象可以<font color=CornflowerBlue>**直接赋值**</font>给父类对象
- 子类对象可以<font color=Green>**直接初始化**</font>父类对象
- <font color=Green>**父类指针**</font>可以<font color=HotPink>**直接指向**</font>子类 对象
- <font color=Chocolate>**父类引用**</font>可以<font color=MediumOrchid>**直接引用**</font>子类对象
### 当使用父类指针(引用)指向子类对象时
- 子类对象<font color=CornflowerBlue>**退化为父类对象**</font>
- <font color=Chocolate>**只能访问**</font>父类中定义的成员
- 可以<font color=HotPink>**直接访问**</font>被子类<font color=MediumOrchid>**覆盖的**</font>同名成员
### 特殊的同名函数
- 子类中可以<font color=CornflowerBlue>**重定义**</font>父类中<font color=HotPink>**已经存在的成员函数**</font>
- 这种重定义<font color=Chocolate>**发生在继承中**</font>，叫做<font color=MediumOrchid>**函数重写**</font>
- <font color=Green>**函数重写**</font>时同名覆盖的一种特殊情况
``` c++
#include <iostream>

using namespace std;

class Parent {
public:
	void print() {
		cout << "I'm Parent." << endl;
	}
};

class Child : public Parent {
public:
	void print() {	// 函数重写，有一定意义
		cout << "I'm Child." << endl;
	}
};

int main(int argc, char* argv[]) {
	Parent().print();
	Child().print();

	return 0;
}
```
### 父子间的赋值兼容
- <font color=CornflowerBlue>**编译期间**</font>，编译器<font color=Chocolate>**只能根据指针的类型判断**</font>所指向的对象
- 根据赋值兼容,<font color=MediumOrchid>**编译器认为父类指针指向的是父类对象**</font>
- 因此，编译结果只可能是<font color=HotPink>**调用父类中定义的同名函数**</font>
### 小结
- 子类对象可以当作父类对象使用(<font color=HotPink>**赋值兼容**</font>)
- 父类指针可以<font color=Chocolate>**正确的指向子类对象**</font>
- 父类引用可以<font color=MediumOrchid>**正确的代表子类对象**</font>
- 子类中可以<font color=CornflowerBlue>**重写**</font>父类中<font color=HotPink>**的成员函数**</font>
## lesson49 多态的概念和本质
### 面向对象中期望的行为
- <font color=CornflowerBlue>**根据实际的对象类型判断如何调用重写函数**</font>
- 父类指针(引用)指向
	- <font color=Green>**父类对象则调用父类中定义的函数**</font>
	- <font color=Chocolate>**子类对象则调用子类中定义的重写函数**</font>
### 面向对象中的多态的概念
- 根据实际的<font color=HotPink>**对象类型决定函数调用**</font>的具体目标
- 同样的<font color=CornflowerBlue>**调用语句**</font>在实际运行时有<font color=Chocolate>**多种不同的表现形态**</font>
### C++语言直接支持多态概念
- 通过使用<font color=CornflowerBlue>**virtual**</font>关键字对<font color=HotPink>**多态**</font>进行支持
- 被<font color=CornflowerBlue>**virtual**</font>声明的函数<font color=MediumOrchid>**被重写后具有多态特性**</font>
- 被<font color=CornflowerBlue>**virtual**</font>声明的函数叫做<font color=Chocolate>**虚函数**</font>
### 多态的意义
- 在程序<font color=CornflowerBlue>**运行过程中**</font>展现出<font color=Chocolate>**动态的特性**</font>
- <font color=MediumOrchid>**函数重写必须多态实现**</font>，否则没有意义
- 多态是<font color=Green>**面向对象组件化程序设计**</font>的基础特性
### 理论中的概念
- 静态联编
	- 在程序的<font color=Green>**编译期间就能确定具体的函数调用**</font> 函数重载
- 动态联编
	- 在程序<font color=HotPink>**实际运行后才能确定具体的函数调用**</font> 函数重写
## lesson50 C++对象模型分析(上)
### class是一种特殊的struct
- 在内存中<font color=CornflowerBlue>**class**</font>依旧可以看作变量的集合
- <font color=CornflowerBlue>**class**</font>与<font color=CornflowerBlue>**struct**</font>遵循相同的内存对齐规则
- <font color=CornflowerBlue>**class**</font>中的<font color=Chocolate>**成员函数**</font>与<font color=MediumOrchid>**成员变量**</font>是<font color=Green>**分开存放**</font>的
	- 每个对象有<font color=HotPink>**独立的**</font>成员变量
	- 所有对象<font color=HotPink>**共享**</font>类中的成员函数
### 运行时的对象退化为结构体的形式
- 所有<font color=Chocolate>**成员函数**</font>在内存中<font color=MediumOrchid>**依次排布**</font>
- 成员变量间<font color=Green>**可能存在内存空隙**</font>
- 可以<font color=Green>**通过内存地址**</font>直接访问成员变量
- 访问权限关键字在运行时失效
### C++对象模型分析
- 类中的<font color=CornflowerBlue>**成员函数**</font>位于<font color=Chocolate>**代码段中**</font>
- 调用成员函数时<font color=Green>**对象地址作为参数隐式传递**</font>
- 成员函数<font color=MediumOrchid>**通过对象地址访问成员变量**</font>
- <font color=Teal>**语法规则隐藏了对象地址的传递过程**</font>
### 小结
- C++中的类对象在<font color=CornflowerBlue>**内存布局上与结构体相同**</font>
- <font color=MediumOrchid>**成员变量**</font>和<font color=Chocolate>**成员函数**</font>在内存中分开存放
- 父类引用可以<font color=Green>**访问权限**</font>关键字在<font color=HotPink>**运行时失效**</font>
- 调用成员函数时<font color=CornflowerBlue>**对象地址作为参数隐式传递**</font>
## lesson51 C++对象模型分析(下)
### 继承对象模型
- 在C++编译器的内部<font color=CornflowerBlue>**类可以理解为结构体**</font>
- 子类是由<font color=HotPink>**父类成员叠加子类新成员**</font>得到的
### 多态对象模型
- 当类中<font color=CornflowerBlue>**声明虚函数**</font>时，编译器会在类中<font color=CornflowerBlue>**生成一个虚函数表**</font>
- 虚函数表是一个<font color=Chocolate>**存储成员函数地址的数据结构**</font>
- 虚函数表是<font color=Green>**由编译器自动生成与维护的**</font>
- <font color=CornflowerBlue>**virtual**</font>成员函数会被编译器<font color=MediumOrchid>**放入虚函数表中**</font>
- <font color=HotPink>**存在虚函数时**</font>，每个对象中都有一个指向虚函数表的指针
### 小结
- 继承的本质就是<font color=CornflowerBlue>**父子间成员变量的叠加**</font>
- C++中的多态是<font color=Chocolate>**通过虚函数表实现的**</font>
- 虚函数表是<font color=Green>**由编译器自动生成与维护的**</font>
- 虚函数的效用效率<font color=Chocolate>**低于**</font>普通成员函数
## lesson52 C++中的抽象类和接口
### 什么是抽象类
- 在现实中<font color=CornflowerBlue>**需要知道具体的图形类型才能求面积**</font>
- 所以对<font color=CornflowerBlue>**概念上的"图形"**</font>求面积是没有意义的！
### 面向对象中的<font color=CornflowerBlue>**抽象类**</font>
- 可用于标识现实世界中的<font color=MediumOrchid>**抽象概念**</font>
- 是一种只能<font color=HotPink>**定义类型**</font>，而<font color=CornflowerBlue>**不能产生对象**</font>的类
- <font color=CornflowerBlue>**只能被继承**</font>并重写相关函数
- 直接特征是<font color=HotPink>**相关函数没有完整的实现**</font>
### 抽象类与纯虚函数
- C++语言中<font color=CornflowerBlue>**没有抽象类**</font>的概念
- C++中<font color=HotPink>**通过纯虚函数实现抽象类**</font>
- 纯虚函数是指<font color=CornflowerBlue>**只能定义原型**</font>的成员函数
- 一个C++类中<font color=HotPink>**存在纯虚函数**</font>就成了抽象类
- 抽象类<font color=CornflowerBlue>**只能**</font>用作父类<font color=CornflowerBlue>**被继承**</font>
- 子类必须<font color=HotPink>**实现纯虚函数**</font>的具体功能
- 纯虚函数被实现后<font color=CornflowerBlue>**成为虚函数**</font>
- 如果子类<font color=HotPink>**没有实现纯虚函数**</font>，则<font color=HotPink>**子类成为抽象类**</font>
### 纯虚函数的语法规则
```C++
class Shape {
public:
	virtual double area() = 0;
};
```
> "<font color=HotPink>**=0**</font>",用于告诉编译器当前是声明纯虚函数，因此不需要定义函数体。

### 满足下面条件的C++类则称为<font color=CornflowerBlue>**接口**</font>（<font color=Green>**interface**</font>）
- 类中<font color=HotPink>**没有**</font>定义任何的<font color=HotPink>**成员变量**</font>
- 所有的<font color=CornflowerBlue>**成员函数都是公有的**</font>
- 所有的<font color=HotPink>**成员函数都是纯虚函数**</font>
- 接口是一种<font color=CornflowerBlue>**特殊的抽象类**</font>
## lesson53 被遗弃的多重继承(上)
### C++支持编写<font color=CornflowerBlue>**多重继承**</font>的代码
- 一个子类可以<font color=CornflowerBlue>**拥有多个父类**</font>
- 子类拥有<font color=CornflowerBlue>**所有父类的**</font>成员变量
- 子类继承<font color=HotPink>**所有父类的**</font>成员函数
- 子类对象可以<font color=CornflowerBlue>**当作任意父类对象**</font>使用
> 多重继承的语法规则
```c++
class Derived : public BaseA, public BaseB, public BaseC{
	// ...
};
```
> 多重继承的本质与单继承相同!

### 多重继承的问题
- 通过<font color=CornflowerBlue>**多重继承**</font>
- 多重继承可能产生冗余的成员
### 虚继承
- <font color=CornflowerBlue>**虚继承**</font>能够<font color=HotPink>**解决数据冗余**</font>问题
- 中间层父类<font color=CornflowerBlue>**不再关系顶层父类的初始化**</font>
- 最终子类必须<font color=HotPink>**直接调用顶层父类的构造函数**</font>
### 小结
- C++<font color=CornflowerBlue>**支持多重继承**</font>的编程方式
- 多重继承<font color=HotPink>**容易带来问题**</font>
	- 可能出现<font color=CornflowerBlue>**“同一个对象的地址不同”**</font>的情况
	- 虚继承可以解决<font color=HotPink>**数据冗余**</font>的问题
	- 虚继承<font color=CornflowerBlue>使得架构设计可能出现问题
## lesson54 被遗弃的多重继承(下)
- 多重继承可能产生多个虚函数表
> 需要进行<font color=CornflowerBlue>**强制类型转换**</font>时，C++中推荐使用新式类型转换关键字<font color=HotPink>**dynamic_cast**</font>

###  工程开发中的“多重继承”方式：
- <font color=CornflowerBlue>**单继承某个类**</font>+<font color=CornflowerBlue>**实现多个接口**</font>
### 一些有用的工程建议
- 先继承自<font color=CornflowerBlue>**一个父类**</font>，然后实现<font color=HotPink>**多个接口**</font>
- 父类中提供<font color=CornflowerBlue>**equal()**</font>成员函数
- equal()成员函数用于<font color=HotPink>**判断指针是否指向当前对象**</font>
- 与<font color=HotPink>**多重继承**</font>相关的强制类型转换用<font color=CornflowerBlue>**dynamic_cast**</font>
### 小结
- 多继承中可能出现<font color=CornflowerBlue>**多个虚函数表指针**</font>
- 与<font color=HotPink>**多重继承**</font>相关的强制类型转换用<font color=CornflowerBlue>**dynamic_cast**</font>完成
- 工程开发中采用<font color=CornflowerBlue>**单继承多接口**</font>的方式使用多继承
- 父类提供成员函数用于<font color=HotPink>**判断指针是否指向当前对象**</font>
## lesson55 经典问题解析
> <font color=CornflowerBlue>**new**</font>和<font color=HotPink>**malloc**</font>的区别是什么？

- <font color=CornflowerBlue>**new**</font>关键字是<font color=CornflowerBlue>**C++的一部分**</font>
- <font color=HotPink>**malloc**</font>是由C库提供的函数
- <font color=CornflowerBlue>**new**</font>以具体<font color=CornflowerBlue>**类型为单位**</font>进行内存分配
- <font color=HotPink>**malloc**</font>以字节为单位进行内存分配
- <font color=CornflowerBlue>**new**</font>在申请内存空间是可进行<font color=CornflowerBlue>**初始化**</font>
- <font color=HotPink>**malloc**</font>仅根据需要申请定量的内存空间

> <font color=CornflowerBlue>**delete**</font>和<font color=HotPink>**free**</font>的区别是什么？

- delete在<font color=CornflowerBlue>**所有C++编译器中都被支持**</font>
- free在某些系统开发中是不能调用
- delete能够<font color=CornflowerBlue>**触发析构函数**</font>的调用
- free仅归还之前分配的内存空间
- <font color=CornflowerBlue>**对象的销毁只能使用delete**</font>
- free<font color=HotPink>**不适合面向对象开发**</font>

> <font color=CornflowerBlue>**构造函数**</font>是否可以成为<font color=CornflowerBlue>**new**</font>虚函数?

- 构造函数<font color=Chocolate>**不可能**</font>成为虚函数=<font color=MediumOrchid>**在构造函数执行结束后,**</font>虚函数表指针才会被正确的初始化
> <font color=HotPink>**析构函数**</font>是否可以成为<font color=HotPink>**虚函数**</font>

- 析构函数<font color=CornflowerBlue>**可以成为虚函数**</font>=建议在射击类时<font color=Chocolate>**将析构函数声明为虚函数**</font>

> 构造函数<font color=CornflowerBlue>**不可能**</font>发生多态行为

- <font color=Chocolate>**在构造函数执行时**</font>，虚函数表指针未被正确初始化

> 析构函数中<font color=HotPink>**不可能**</font>发生多态行为

<font color=Chocolate>**在析构函数执行时**</font>，虚函数表指针已经被摧毁

### 构造函数和析构函数中<font color=CornflowerBlue>**不能发生多态行为**</font>，<font color=HotPink>**只调用当前类中定义的函数版本**</font>！！
### 关于继承中的强制类型转换
- <font color=CornflowerBlue>**dynamic_cast**</font>是与<font color=HotPink>**继承相关**</font>的类型转换关键字
- <font color=CornflowerBlue>**dynamic_cast**</font>要求相关的类中<font color=HotPink>**必须有虚函数**</font>
- 用于有直接或者间接<font color=CornflowerBlue>**继承关系**</font>的<font color=Chocolate>**指针**</font>(<font color=MediumOrchid>**引用**</font>)之间
- 指针：
	- 转换成功：<font color=CornflowerBlue>**得到目标类型的指针**</font>
	- 转换失败：<font color=Chocolate>**得到一个空指针**</font>
- 引用：
	- 转换成功：<font color=CornflowerBlue>**得到目标类型的引用**</font>
	- 转换失败：<font color=Chocolate>**得到一个异常操作信息**</font>
- 编译器会检查<font color=CornflowerBlue>**dynamic_cast**</font>的使用是否正确
- 类型转换的<font color=HotPink>**结果只可能在运行阶段才能得到**</font>
## lesson56 函数模板的概念和意义
### 定义宏代码块
- 优点：<font color=Chocolate>**代码复用**</font>，适合所有的类型
- 缺点：编译器不知道宏的存在，<font color=Chocolate>**缺少类型检查**</font>
### 定义函数
- 优点：<font color=MediumOrchid>**真正的函数调用,**</font>编译器对类型进行检查
- 缺点：根据类型重复定义函数，<font color=MediumOrchid>**无法代码复用**</font>
### 泛型编程的概念
- <font color=CornflowerBlue>**不考虑具体数据类型的编程方式**</font>
- 一种特殊的函数<font color=CornflowerBlue>**可用不同类型进行调用**</font>
- 看起来和普通函数很类似，区别是<font color=HotPink>**类型可被参数化**</font>
```c++
template <typename T>		//template:告诉编译器开始泛型编程 <typename T>:告诉编译器T是一个泛指类型
void Swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}
```

### 函数模板的使用
- <font color=CornflowerBlue>**自动类型推导调用**</font>
- <font color=Chocolate>**具体类型显示调用**</font>Swap
### 小结
- 函数模板是<font color=CornflowerBlue>**泛型编程**</font>在C++中的应用方式之一
- 函数模板能够<font color=Chocolate>**根据实参对参数类型进行推导**</font>
- 函数模板支持<font color=MediumOrchid>**显示的指定参数类型**</font>
- 函数模板是<font color=HotPink>**C++中重要的代码复用方式**</font>普通成员函数
## lesson57 深入理解函数模板
### 函数模板深入理解
- 编译器从函数模板通过具体类型<font color=CornflowerBlue>**产生不同的函数**</font>
- 编译器会<font color=HotPink>**对函数模板进行两次编译**</font>
	- <font color=Chocolate>**对模板代码本身进行编译**</font>
	- <font color=Chocolate>**对参数替换后的代码进行编译**</font>
### 注意事项
- 函数模板本身<font color=CornflowerBlue>**不允许隐式类型转换**</font>
	- <font color=Chocolate>**自动推导类型时，必须严格匹配**</font>
	- <font color=Chocolate>**显示类型指定时，能够进行隐式类型转换**</font>
### 函数模板可以定义<font color=CornflowerBlue>**任意多个不同的类型参数**</font>
```c++
template <typename T1, typename T2, typename T3>
T1 Add(T2 a, T3 b) {
	return static_cast<T1>(a+b);
}
int r = Add<int, float, double>(0.5, 0.8);
```
### 对于多参数函数模板
- <font color=Chocolate>**无法自动**</font>推导返回值类型
- 可以<font color=HotPink>**从左向右**</font>部分指定类型参数
- 工程中将<font color=CornflowerBlue>**返回值参数**</font>作为<font color=HotPink>**第一个类型参数**</font>！
### 函数模板可以向普通函数意义被重载
- C++编译器<font color=CornflowerBlue>**优先考虑普通函数**</font>
- 如果函数模板可以产生一个<font color=HotPink>**更好的匹配**</font>，那么选择模板
- 可以通过<font color=Chocolate>**空模板实参列表**</font>限定编译器只匹配模板
```c++
	int r1 = Max(1, 2);
	double r2 = Max<>(0.5, 0.8);	// 限定编译器只匹配函数模板
```
### 小结
- 函数模板通过具体类型<font color=CornflowerBlue>**产生不同的函数**</font>
- 函数模板可以定义<font color=Chocolate>**任意多个不同的类型参数**</font>
- 函数模板中的<font color=MediumOrchid>**返回值必须显式指定**</font>
- 函数模板可以像普通函数一样被重载
## lesson58 类模板的概念和意义
### 类模板
- 一些类主要用于<font color=CornflowerBlue>**存储和组织数据元素**</font>
- 类中数据组织的方式和数据元素的<font color=HotPink>**具体类型无关**</font>
- 如：数组类，链表类，Stack类，Queue类，等
- <font color=Chocolate>**C++中将模板的思想应用于类，使得类的实现不关注数据元素的具体类型，而只关注类所需要实现的功能。**</font>
### C++中的类模板
- 以相同的方式处理不同的类型
- 在类声明前使用<font color=CornflowerBlue>**template**</font>进行标识
- <typename T>用于说明类中使用的<font color=HotPink>**泛指类型 T**</font>
```c++
template <typename T>
class Operator {
public:
	T op(T a, T b);
};
```
### 类模板的应用
- 只能显示指定具体类型，<font color=HotPink>**无法自动推导**</font>
- 使用具体类型<Type>定义对象
-  声明的<font color=CornflowerBlue>**泛指类型**</font><font color=HotPink>**T**</font>可以出现在类模板的任意地方
- 编译器对类模板的处理方式和函数模板相同
	- 从类模板通过具体类型<font color=CornflowerBlue>**产生不同的类**</font>
	- <font color=Chocolate>**在声明的地方对类模板代码本身进行编译**</font>
	- <font color=Chocolate>**在使用的地方对参数替换后的代码进行编译**</font>
### 类模板的工程应用
- 类模板必须在<font color=HotPink>**头文件中定义**</font>
- 类模板<font color=Chocolate>**不能分开实现在不同的文件中**</font>
- 类模板<font color=CornflowerBlue>**外部定义的**</font>成员函数需要加上<font color=CornflowerBlue>**模板<>**</font>声明
### 小结
- <font color=Green>**泛型编程的思想可以应用于类**</font>
- 类模板以<font color=CornflowerBlue>**相同的方式处理不同类型的数据**</font>
- 类模板非常<font color=Chocolate>**适用于**</font>编写<font color=Chocolate>**数据结构**</font>相关的代码
- 类模板在使用时<font color=HotPink>**只能显示指定类型**</font>
## lesson59 类模板深度剖析
### 类模板可以定义<font color=CornflowerBlue>**任意多个不同的类型参数**</font>

### 类模板可以被特化
- 指定类模板的<font color=CornflowerBlue>**特定实现**</font>
- <font color=HotPink>**部分类型参数**</font>必须显示指定
- <font color=Chocolate>**一个类模板**</font>根据类型参数<font color=MediumOrchid>**分开实现类模板**</font>
```c++
template <typename T1, typename T2>
class Test {};
// 特化
template <typename T>
class Test<T, T>{};
```
### 类模板的特化类型
- <font color=HotPink>**部分特化**</font> 用特定规则约束类型参数
- <font color=CornflowerBlue>**完全特化**</font> 完全显示指定类型参数
```c++
template <typename T1, typename T2>
class Test {};
// 完全特化
template <>
class Test<int, int>{};
```
### 类模板特化注意事项
- 特化只是<font color=CornflowerBlue>**模板的分开实现**</font>
	- 本质上是同一个类模板
- 特化类模板的<font color=HotPink>**使用方式是统一的**</font>
	必须显示指定每一个类型参数
### 重定义和特化不同
- <font color=CornflowerBlue>**重定义**</font>
	- 一个类模板和一个新类(或者两个类模板)
	- 使用的时候需要<font color=CornflowerBlue>**考虑如何选择的问题**</font>
- <font color=CornflowerBlue>**特化**</font>
	- 以统一的方式使用类模板和特化类
	- 编译器<font color=HotPink>**自动优先选择特化类**</font>
### 函数模板只支持类型参数完全特化
```c++
template <typename T>		// 函数模板定义
bool Equal(T a, T b) {
	return a == b;
}
template < >				// 函数模板完全特化
bool Equal<void*>(void* a, void* b) {
	return a == b;
}
```
### 工程中的建议
- 当需要重载函数模板时，<font color=CornflowerBlue>**优先考虑使用模板特化**</font>
- <font color=HotPink>**当模板特化无法满足需求**</font>，再使用函数重载！！！
### 小结
- 类模板可以定义<font color=CornflowerBlue>**任意多个不同的类型参数**</font>
- 类模板可以被<font color=Chocolate>**部分特化**</font>和<font color=MediumOrchid>**完全特化**</font>
- 特化的本质是<font color=CornflowerBlue>**模板的分开实现**</font>
- 函数模板只支持完全特化
- 工程中使用<font color=HotPink>**模板特化代替类(函数)重定义**</font>
## lesson60 数组类模板
### 模板参数可以是数值型参数(非类型参数)
```c++
template <typename T, int N>
void func() {
	T a[N];		// 使用模板参数定义局部数组
}
```
### 数值型模板参数的限制
- <font color=Chocolate>**变量**</font>不能作为模板参数
- <font color=Chocolate>**浮点数**</font>不能作为模板参数
- <font color=Chocolate>**类对象**</font>不能作为模板参数
> 本质：
> 模板参数是<font color=CornflowerBlue>**在编译阶段被处理**</font>的单元，因此，<font color=HotPink>**在编译阶段必须准确无误的唯一确定**</font>

### 小结
- 模板参数可以是<font color=CornflowerBlue>**数值型参数**</font>
- 数值型模板参数<font color=HotPink>**必须在编译期间唯一确定**</font>
- <font color=Chocolate>**数组类模板**</font>是基于数值型模板参数实现的
- 数组类模板是简易的<font color=Chocolate>**线性表数据结构**</font>
## lesson61 智能指针
### 智能指针的意义
- 现代C++开发库中<font color=HotPink>**最重要的类模板之一**</font>
- C++中<font color=MediumOrchid>**自动内存管理**</font>的主要手段
- 能够在<font color=CornflowerBlue>**很大程度上**</font>避开内存相关的问题
### STL中的智能指针<font color=CornflowerBlue>**auto_ptr**</font>
- <font color=Chocolate>**生命周期结束时**</font>，销毁指向的内存空间
- 不能指向堆数组，<font color=CornflowerBlue>**只能指向堆对象（变量）**</font>
- <font color=Green>**一片堆空间只属于一个只能指针对象**</font>
- 多个智能指针对象<font color=HotPink>**不能指向同一片堆空间**</font>
## lesson62 单例类模板
### 在架构设计时，某些类在整个系统生命期中<font color=CornflowerBlue>**最多只能有一个对象存在(Single Instance).**</font>
- 要控制类的对象数目，<font color=CornflowerBlue>**必须对外隐藏构造函数**</font>
	- 将构造函数的访问属性设置为private
	- 定义instance并初始化为NULL
	- 当需要使用对象时，访问Instance的值
- <font color=CornflowerBlue>**将单例模式相关的代码抽取出来**</font>，开发单例类模板。当需要单例类时，直接使用单例类模板。
### 小结
- 单例模式是开发中<font color=CornflowerBlue>**最常用的设计模式之一**</font>
- 单例模式的应用使得<font color=HotPink>**一个类最多只有一个对象**</font>
- <font color=Green>**可以将单例模式相关的代码抽象成类模板**</font>
- 需要使用单例模式的类直接使用<font color=Chocolate>**单例模板**</font>
## lesson63 C语异常处理
### 异常的概念
- 程序在运行过程中可能产生异常
- <font color=Chocolate>**异常（Exception）**</font>与<font color=MediumOrchid>**Bug的区别**</font>
- <font color=Green>**异常时程序运行时可预料的执行分支**</font>
- <font color=HotPink>**Bug时程序中的错误**</font>，是不被预期的运行方式
### 异常(Exception)和Bug的对比：
- 异常
	- <font color=CornflowerBlue>**运行时产生除0的情况**</font>
	- <font color=CornflowerBlue>**需要打开的外部文件不存在**</font>
	- <font color=CornflowerBlue>**数组访问时越界**</font>
- Bug
	- <font color=HotPink>**使用野指针**</font>
	- <font color=HotPink>**堆数组使用结束后未释放**</font>
	- <font color=HotPink>**选择排序无法处理长度为0的数组**</font>
## lesson64 C++中的异常处理(上)
### C++内置了异常处理的语法元素 try... catch...
- <font color=CornflowerBlue>**try**</font>语句处理正常代码逻辑
- <font color=CornflowerBlue>**catch**</font>语句处理异常情况
- <font color=CornflowerBlue>**try**</font>语句中的异常由对应的<font color=CornflowerBlue>**catch**</font>语句处理
```c++
try {
	double r = divide(1, 0);
}catch(...) {
	cout << "Divided by zero..." << endl;
}
```
### C++异常处理分析
- <font color=CornflowerBlue>**throw**</font>抛出的异常必须被<font color=CornflowerBlue>**catch**</font>处理
	- 当前函数<font color=CornflowerBlue>**能够处理异常**</font>，程序继续往下执行
	- 当前函数<font color=HotPink>**无法处理异常**</font>，则函数当前函数<font color=HotPink>**停止执行**</font>，并返回
### 同一个<font color=CornflowerBlue>**try**</font>语句可以跟上多个<font color=CornflowerBlue>**catch**</font>语句
- <font color=CornflowerBlue>**catch**</font>语句可以定义具体处理的异常类型
- <font color=MediumOrchid>**Bug的区别**</font>由不同的<font color=CornflowerBlue>**catch**</font>语句负责处理
- <font color=HotPink>**try**</font>语句中可以抛出任何类型的异常
- <font color=Chocolate>**catch(...)**</font>用于处理所有的类型的异常
- 任何异常都只能被捕获（<font color=CornflowerBlue>**catch**</font>）<font color=Chocolate>**一次**</font>
### 小结
- C++中直接支持异常处理的概念
- <font color=CornflowerBlue>**try**</font>...<font color=CornflowerBlue>**catch**</font>...是C++中异常处理的专用语句
- <font color=CornflowerBlue>**try**</font>语句处理正常代码逻辑，<font color=CornflowerBlue>**catch**</font>语句处理异常情况
- 同一个<font color=CornflowerBlue>**try**</font>语句可以跟上多个<font color=CornflowerBlue>**catch**</font>语句
- 异常处理必须严格匹配，<font color=HotPink>**不进行任何的类型转换**</font>
## lesson65 C++中的异常处理(下)
### catch语句块中可以抛出异常
- <font color=CornflowerBlue>**catch**</font>中捕获的异常可以被重新解释后抛出
- 工程开发中使用<font color=HotPink>**catch**</font>中可以抛出异常的特性，封装一层重新抛出异常，形成统一的异常处理形式<font color=HotPink>**统一异常类型**</font>
- 异常的类型可以是<font color=CornflowerBlue>**自定义类类型**</font>
- 对于类类型异常的匹配依旧是<font color=Chocolate>**自上而下严格匹配**</font>
- <font color=MediumOrchid>**赋值兼容性原则**</font>在异常匹配中依然使用
- 一般而言
	- <font color=Chocolate>**匹配子类异常的catch放在上部**</font>
	- <font color=Chocolate>**匹配夫类异常的catch放在下部**</font>
- 在工程中会定义<font color=CornflowerBlue>**一系列的异常类**</font>
- 每个类代表工程中可能出现的一种异常类型
- <font color=Chocolate>**代码服用时**</font>可能需要<font color=MediumOrchid>**重解释不同的异常类**</font>
- 在定义catch语句块时<font color=HotPink>**推荐使用引用作为参数**</font>（避免拷贝构造提高程序运行效率）
### C++中的异常处理
- C++标准库中提供了实用异常类族
- 标准库中的异常都是从<font color=CornflowerBlue>**exception**</font>类派生的
- <font color=CornflowerBlue>**exception**</font>类有两个主要的分支
	- <font color=Chocolate>**logic_error**</font>:常用于程序中的可避免逻辑错误
	- <font color=Chocolate>**runtime_error**</font>:常用于程序中无法避免的恶性错误
## lesson66 C++中的类型识别
### 在面向对象中可能出现下面的情况
- <font color=Chocolate>**基类指针**</font>指向子类对象
- <font color=MediumOrchid>**基类引用**</font>
- 静态类型=变量(对象)<font color=CornflowerBlue>**自身的类型**</font>
- 动态类型=指针(引用)所指向<font color=HotPink>**对象的实际类型**</font>
```c++
void test(Base* b) {
	/* 危险的转换方式 */
	Derived* d = static_cast<Derived*>(b);
}
```
- 基类指针是否可以强制类型转换为子类指针<font color=HotPink>**取决于动态类型**</font>！
### 解决方案-利用多态(不好)
1. 在基类中<font color=CornflowerBlue>**定义虚函数**</font>返回具体的类型信息
2. 所有的派生类都<font color=HotPink>**必须实现**</font>类型相关的虚函数
3. 每个类中的类型虚函数都<font color=Chocolate>**需要不同的实现**</font>
### C++提供了<font color=CornflowerBlue>**typeid**</font>关键字用于获取类型信息
- <font color=CornflowerBlue>**typeid**</font>关键字返回对应参数的<font color=MediumOrchid>**类型信息**</font>
- <font color=CornflowerBlue>**typeid**</font>返回一个<font color=Chocolate>**type_info**</font>类对象
- 当<font color=CornflowerBlue>**typeid**</font>的参数为<font color=Chocolate>**NULL**</font>时将抛出异常
### typeid的注意事项
- 当<font color=CornflowerBlue>**参数为类型**</font>时：返回静态类型信息
- 当<font color=CornflowerBlue>**参数为变量**</font>时：
	- 不存在虚函数表-返回静态类型信息
	- <font color=HotPink>**存在虚函数表-返回动态类型信息**</font>
### 小结
- C++中有<font color=CornflowerBlue>**静态类型**</font>和<font color=HotPink>**动态类型**</font>的概念
- 利用<font color=Chocolate>**多态**</font>能够实现对象的<font color=Chocolate>**动态类型识别**</font>
- <font color=CornflowerBlue>**typeid**</font>是专用于类型识别的关键字
- <font color=CornflowerBlue>**typeid**</font>能够返回对象的动态类型信息
## lesson67 略
## lesson68 略
## lesson69 自定义内存管理
### 统计对象中某个<font color=CornflowerBlue>**成员变量的访问次数**</font>
- <font color=CornflowerBlue>**mutable**</font>是为了突破<font color=CornflowerBlue>**const**</font>函数的限制而设计的
- <font color=CornflowerBlue>**mutable**</font>成员变量将<font color=Chocolate>**永远处于可改变的状态**</font>
- <font color=CornflowerBlue>**mutable**</font>成员变量的出现<font color=MediumOrchid>**无法保证**</font>状态不变性
### 被忽略的事实
- <font color=CornflowerBlue>**new/delete**</font>的本质是C++预定义的<font color=Chocolate>**操作符**</font>
- C++对这两个操作符做了严格的行为定义
	- <font color=Chocolate>**new:**</font>
	1. 获取足够大的内存空间(<font color=CornflowerBlue>**默认为堆空间**</font>)
	2. 在获取的空间中调用构造函数创建对象
	- <font color=Chocolate>**delete:**</font>
	1. 调用析构函数销毁对象
	2. 归还对象所占用的空间(默认为堆空间)
### 在C++中能够重载<font color=CornflowerBlue>**new/delete**</font>操作符
- 全局重载(<font color=HotPink>**new/delete**</font>)
- 局部重载(<font color=Green>**针对具体类进行重载**</font>)
### <font color=CornflowerBlue>**new/delete**</font>的重载方式
```c++
// static member function
void* operator new (unsigned int size) {
	void* ret = null;
	/* ret point to allocated memory */
	return ret;
}
```
// static member function
void operator delete (void *p) {
	/* free the memory which is pointed by p */
	free(p)
}
### 在指定位置申请内存空间
- 在类中重载<font color=CornflowerBlue>**new/delete**</font>操作符
- 在<font color=CornflowerBlue>**new**</font>的操作符重载函数中<font color=Chocolate>**返回指定的地址**</font>
- 在<font color=CornflowerBlue>**delete**</font>操作符重载中<font color=MediumOrchid>**标记对应的地址可用**</font>
### <font color=HotPink>**new[]/delete[]**</font>与<font color=CornflowerBlue>**new/delete**</font>完全不同
- 动态对象数组创建通过 new[]完成
- 动态对象数组的销毁通过 delete[]完成
- new[]/delete[]<font color=MediumOrchid>**能够被重载**</font>，进而<font color=Chocolate>**改变内存管理方式**</font>
### <font color=CornflowerBlue>**new[]/delete[]**</font>的重载方式
```c++
// static member function
void* operator new[] (unsigned int size) {
	void* ret = null;
	/* ret point to allocated memory */
	return ret;
}
```
```c++
// static member function
void operator delete[] (void *p) {
	/* free the memory which is pointed by p */
	free(p);
}
```
### 注意事项
- <font color=CornflowerBlue>**new[]**</font>实际需要返回的内存空间<font color=HotPink>**可能**</font>比期望的要多
- 对象数组占用的内存中<font color=Chocolate>**需要保存数组信息**</font>
- 数组信息用于确定<font color=Green>**构造函数**</font>和<font color=Green>**析构函数**</font>的调用次数
## lesson70 展望：未来的学习之路
## lesson71 异常处理深度解析
### 如果异常不处理，<font color=Chocolate>**最后会传到哪里？**</font>
- <font color=MediumOrchid>**如果异常无法被处理**</font>，terminate()结束函数会被自动调用
- <font color=Chocolate>**默认情况下**</font>，terminate()调用库函数abort()终止程序
- abort()函数使得程序指向异常而<font color=Chocolate>**立刻退出**</font>
- C++支持替换默认的terminate()函数实现
### terminate()函数的替换
- 自定义一个无返回值无参数的函数
	- 不能抛出异常
	- 必须以某种方式结束当前程序
- 调用set_terminate()设置自定义的结束函数
	- 参数类型为void(\*)()
	- 返回值为默认的terminate()函数入口地址
### 如果<font color=Chocolate>**析构函数中抛出异常**</font>会发生什么情况？
- 如果异常没有被处理，<font color=MediumOrchid>**最后terminate()结束整个程序**</font>
- terminate()是整个程序<font color=CornflowerBlue>**释放系统资源的最后机会**</font>
- 结束函数可以自定义，但不能继续抛出异常
- <font color=Chocolate>**析构函数中不能抛出异常**</font>，可能导致terminate()多次调用
### 小结
- <font color=CornflowerBlue>**C++中的函数可以声明异常规格说明**</font>
- 异常规格说明可以看作<font color=Green>**接口的一部分**</font>
- 函数抛出的<font color=Chocolate>**异常不在规格说明中**</font>，unexpected()被调用
- unexpected()中能够再次抛出异常
	- <font color=CornflowerBlue>**异常能够匹配，恢复程序的执行**</font>
	- <font color=HotPink>**否则，调用terminate()结束程序**</font>能够返回对象的动态类型信息
## lesson72 函数的异常规格说明
### 如何判断一个函数是否会抛出异常，以及抛出那些异常?
- C++提供语法用于声明函数所抛出的异常
- <font color=CornflowerBlue>**异常声明**</font>作为函数声明的修饰符，<font color=Chocolate>**写在函数列表后面**</font>
```c++
// 可能安排出任何异常
void func1();
// 只能抛出的异常类型： char 和 int
void func2() throw(char, int);
// 不能抛出任何异常
void func3() throw();
```
### 异常规格说明的意义
- 提示函数调用者必须<font color=Chocolate>**做好异常处理的准备**</font>
- 提示函数的维护者<font color=MediumOrchid>**不要抛出其它异常**</font>
- 异常规格说明是<font color=HotPink>**函数接口的一部分**</font>
- 函数抛出的<font color=Chocolate>**异常不在规格说明中**</font>，全局<font color=CornflowerBlue>**unexpected()**</font>被调用
- 默认的unexpected()函数会调用全局的terminate()函数
- 可以<font color=MediumOrchid>**自定义**</font>函数替换默认的unexpected()函数实现
- <font color=Chocolate>**注意：**</font>不是所有C++编译器都支持这个标准行为
### unexpected()函数的替换
- 自定义一个无返回值无参数的函数
	- 能够再次抛出异常
		- 当异常符合出发函数的异常规格说明时，回复程序执行
		- 否则，调用全局terminate()函数结束程序
- 调用set_unexpected()设置自定义的异常函数
	- 参数类型为void(\*)()
	- 返回值为默认的unexpected()函数入口地址

## lesson73 动态内存申请的结果
### 动态内存申请一定成功吗？
- malloc函数申请失败是返回NULL值
- <font color=CornflowerBlue>**new**</font>关键字申请失败时(<font color=MediumOrchid>**根据编译器不同**</font>)
- 返回<font color=Chocolate>**NULL**</font>值
- 抛出<font color=Chocolate>**std::bad_alloc**</font>异常
### <font color=CornflowerBlue>**new**</font>关键字在C++规范中的<font color=MediumOrchid>**标准行为**</font>
- 在堆空间申请足够大的内存
	- <font color=Green>**成功**</font>：
	1. 在获取的空间中调用构造函数创建对象
	2. 返回对象的地址
	- <font color=Chocolate>**失败**</font>
	1. 抛出std::bad_alloc异常
### <font color=CornflowerBlue>**new**</font>关键字在C++规范中的<font color=MediumOrchid>**标准行为**</font>
- new在分配内存时
	- 如果空间不足，会调用全局的 new_handler()函数
	- new_handler()函数中<font color=Chocolate>**抛出std::bad_alloc异常**</font>
- 可以自定义new_handler()函数
	- 处理默认的<font color=CornflowerBlue>**new**</font>内存分配失败的情况
### 如何跨编译器统一new的行为，<font color=Chocolate>**提高代码移植性**</font>？
### 解决方案
- <font color=Chocolate>**全局范围（不推荐）**</font>
	- 重新定义new/delete的实现，不抛出任何异常
	- 自定义new_handler()函数，不抛出任何异常
- <font color=CornflowerBlue>**类层次范围**</font>
	- 重载new/delete，不抛出任何异常
- <font color=HotPink>**单次动态内存分配**</font>
	- 使用nothrow参数，指明new不抛出异常
### 实验结论
- <font color=MediumOrchid>**不是所有的编译器都遵循C++的标准规范**</font>
- 编译器可能重定义new的实现，并在实现中<font color=Chocolate>**抛出bad_alloc异常**</font>
- <font color=CornflowerBlue>**编译器的默认实现中**</font>，可能没有设置全局的new_handler()函数
- 对于移植性要求较高的代码，需要考虑new的具体细节
### 小结
- 不同的编译器在动态内存分配上的<font color=HotPink>**实现细节不同**</font>的概念
- malloc函数在内存申请失败时返回<font color=Chocolate>**NULL**</font>
- <font color=CornflowerBlue>**new**</font>关键字在内存申请失败时
	- 可能返回NULL值
	- 可能抛出bad_alloc异常