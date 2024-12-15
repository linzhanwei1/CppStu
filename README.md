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