# CNU moodle answer
首都师范大学 moodle 平台的多数 C 语言题目参考解答.<br/>
建议电脑访问，手机端点上面的 `view code` 查看代码. 

每份解答都可以通过所有的测试用例(Accepted).<br/>
请务必只将我的程序作为参考，不应该限制你的思路。<br/>
毕竟参考解答**不一定~一定不~是最优解**. ~而且还有些写的很烂~<br/>

![image](https://raw.githubusercontent.com/hatsune-miku/cnu_moodle_answer/master/you_fool.jpg)
<br/>

### 开发环境
> Visual Studio 2017<br/>
> 少部分的 vim + Clang<br/>
> 少部分的 Xcode<br/>
> 警告视为错误
<br/>

请忽略代码里面的 `"miku!"` 和 `#define _CRT_SECURE_NO_WARNINGS` .

# 常见问题
### 如何找到某一题的解答？
> `cnuw_68` 文件夹，对应 moodle 平台的 `6.8 不吉利日期` .<br/>
> 以此类推.
### 有的题找不到？
> 只收录大一下. 期中考试题没有收录.<br/>
> 部分题目对应同一问题的多种解法，这里只收录最快的一种.
### 为什么忽略那两个东西？
> 前者是一只名叫 miku 的无效的字符串，用于调戏编译器.<br/><br/>
> 至于后者，是编译器认为一些 C 标准库函数容易导致内存非法访问，<br/>
> 比如 `gets` 函数，它不遇到换行或者 EOF 就无限读下去，是不安全的，所以不建议开发者使用.<br/>
> 与此同时，不安全的函数大都有对应的安全版本. 比如 `gets` 函数的安全版本是 `gets_s` .<br/>
> 但是 moodle 平台使用的编译器不会检查这一点，同时它那里没有 `gets_s` 的定义，它只认 `gets` .<br/>
> 所以加上 `#define _CRT_SECURE_NO_WARNINGS` 让较为先进的编译器忽略这个安全问题.
