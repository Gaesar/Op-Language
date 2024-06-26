# 基于Flex&Bison的自定义编程语言

## 功能

在bison的.y文件中编写一系列的动作，通过语法制导翻译，翻译成C语言代码执行。实现了简单的运算（+\\-\\*\\÷\\<\\>\\<=\\>=\\==）、赋值语句、条件语句、循环语句、输入输出语句。 

## 结果展示

in.txt 中是使用OpLang编写的测试程序，下面是in.txt文件，体现了所有的功能点。

```
sum = 0;
i = 1;
n = 1;
m = 0;
read flag;
write flag;
if flag > 0 then 
    m = 11 - 1;
else
    m = (100/10 + 10)*5;
end;
write m;
repeat
    sum = sum + i;
    i = i + n;
until i > m;
write sum;
```

运行结果

```
D:\Desktop\oplang\Op-Language>op in.txt
<< 5
flag = 5
m = 10
sum = 55

D:\Desktop\oplang\Op-Language>op in.txt
<< 10
flag = 10
m = 10
sum = 55
```

## 快速开始

### 配置环境

1.下载配置Mingw:[Win10系统下用汇编代码输出Hello World - 灰信网（软件开发博客聚合） (freesion.com)](https://www.freesion.com/article/4840365954/#1Mingw_3)

2.下载配置flex&bison:[手把手教你win10下lex与yacc的安装_lex安装-CSDN博客](https://blog.csdn.net/wang_yr/article/details/106000167)

### 运行程序

1.cmd输入gen.bat op，编译项目

2.cmd输入op ”测试的文件名“，运行程序
