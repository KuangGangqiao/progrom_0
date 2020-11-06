# progrom_0
这是我的第一个仓库
ezprintf:

一定用过printf吧，非常实用的函数。但是，这家伙太大了，我们只需要一个小巧简单的版本就好了。

我们希望你实现一个简单的printf，叫它ezprintf吧。

我们不需要你处理可变函数参数的情况，并且假设所有的参数都已经放在了一个`void *`型的数组里。

我们限定ezprintf只接受'字符'(%s)、'字符串'(%c)和无符号整型（%x, 只需要以16进制形式输出）。
那么我们会以像下面的形式调用：

	const char format[] = "Welcome to %s, do you like %x%c\n";
	
	const char str[] = "CredO~";
	unsigned int int32 = 0xbeef;
	char ch = '?';

	void * args[] = {
		(void*)str,
		(void*)&int32,
		(void*)&ch
	};

	ezprintf(format, args);

期望的输出应该是：

	Welcome to CredO~, do you like beef?

限制和假设：
	* 我们假设args中元素的个数总是大于等于format中所请求的数量。
	* 当你需要输出单个字符时，请使用putchar这个标准库函数(需要包含 "stdio.h")，
                   它接受一个char型的输入并将其输出到标准输出。除此之外，请不要使用任何其他C标准库的函数。
	* 开发环境是一台32位Linux机器，装有gcc, make, vim, emacs, eclipse等常用的开发工具。
	* 请使用遵循C99标准的C语言(而非C++)编写程序。


