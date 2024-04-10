安装
把代码拷贝到你的cmake项目就行。
使用的时候就include logger.hpp 这个文件

这个工具类提供三个函数
LogInfo (formatStr,...args)
LogWarn (formatStr,...args)
LogError(formatStr,...args)

1. formatStr 就是c语言printf("a is %d", 1), 这个第一个参数
2. 默认formatStr是空。直接输出formatStr也可以，就是不能有%d,%s,这样的。
3. 有的时候会出现输出不对，在%s,后面接std::string类型变量的时候几率出现。得使用.c_str()。
4. 所有的输出默认会输出一份到当前目录下的loglog文件 logger.hpp logFilePath 静态常量控制文件位置。
5. 默认不使用使用终端颜色 logger.hpp  enableColor 静态常量控制是否使用终端颜色 Info 默认绿色，Warn 默认黄色，Error 默认红色, debug_str 默认蓝色。

实例
```
LogInfo("hellowrold %s %s %s", "1", "1", "1");
LogError("xxxxx %s %d %d", "1", 1, 1);
LogWarn("hhelkadsf");
```
输出
```
[INFO] 2024-03-10 17:02:10 hellowrold 1 1 1
[EROR] 2024-03-10 17:02:10 xxxxx 1 1 1
[WARN] 2024-03-10 17:02:10 hhelkadsf
```
debug 模式。
在logger.hpp中把//define DEBUG这行代码注释解开。就会输出调用行的文件和行号。

实例
```
LogInfo("hellowrold %s %s %s", "1", "1", "1");
LogError("xxxxx %s %d %d", "1", 1, 1);
LogWarn("hhelkadsf");
```
输出
```
example.cpp 3[INFO] 2024-03-10 17:13:40 hellowrold 1 1 1
example.cpp 4[EROR] 2024-03-10 17:13:40 xxxxx 1 1 1
example.cpp 5[WARN] 2024-03-10 17:13:40 hhelkadsf
```
