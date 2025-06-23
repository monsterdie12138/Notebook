---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter8 流和文件

***

## 8.1 IO流和流类库

$~$

**流（stream）：**

流指的是数据从一个设备流向另一个设备。

流本质上是一个对象，在使用前被建立，在使用后被删除。数据的输入/输出就是从流中提取数据/向流中插入数据。

$~$

**预定义流对象：**

对象定义|说明
:---:|---
`istream cin`|与标准输入设备相关联
`ostream cout`|与标准输出设备相关联
`ostream cerr`|与标准错误输出设备相关联（非缓冲方式）
`ostream clog`|与标准错误输出设备相关联（缓冲方式）

$~$

***

## 8.2 IO流类的成员函数

$~$

**`istream`流中的常用成员函数：**

```cpp linenums="1"
class istream: virtual public ios
{
    public:
        istream& operator>>(double &);
        int get();
        istream& get(char* c,int n,char='\n');
        istream& read(char* c,int n);
        istream& ignore(int=1,int=EOF);
        istream& getline(char* c,int n,char='\n');
};
```

!!! Example
    ```cpp linenums="1"
    int main()
    {
        char c,a[50],s[100];
        cout<<"use get() input char: ";
        while((c=cin.get())!='\n') cout<<c;         //L1
        cout<<endl;
        cout<<"use get(a,10) input char: ";
        cin.get(a,10);                              //L2
        cout<<a<<endl;
        cin.ignore(1);                              //L3
        cout<<"use getline(s,10) input char: ";
        cin.getline(s,10);                         //L4
        cout<<s<<endl;
    }
    ```

    输入输出示例：

    ```
    use get() input char: abcd 
    abcd
    use get(a,10) input char: 12345678 
    12345678
    use getline(s,10) input char: this is a str 
    this is a
    ```

    L1处的`cin.get()`函数理论上每输入一个字符就应该输出一个字符，但由于输入缓冲区的存在，实际输出被延迟。

    L2处的`cin.get(a,10)`函数从输入流中读取最多9个字符（最后一个字符留给`\0`），并将其存储在数组`a`中。如果输入超过9个字符，多余字符会留在缓冲区。如果遇到`\n`则停止，`\n`并不会被存储到`a`上，但是会留在缓冲区中。

    L3处的`cin.ignore(1)`函数会清除缓冲区的第一个字符，这里是`\n`。

    L4处的`cin.getline(s,10)`函数同样从输入流中读取最多9个字符（最后一个字符留给`\0`），并将其存储在数组`s`中，直到遇到`\n`为止。但与`cin.get()`不同的是，`cin.getline()`并不会将`\n`留在缓冲区中。

$~$

**`ostream`流中的常用成员函数：**

```cpp linenums="1"
class ostream: virtual public ios
{
    public:
        ostream& operator<<(...);
        ostream& operator<<(long);
        ostream& put(char);
        ostream& write(const char*,int);
};
```

!!! Example
    ```cpp linenums="1"
    int main()
    {
        char c;
        char a[50]="this is a string...";
        cout<<"use get() input char: ";
        while((c=cin.get())!='\n') cout.put(c);     //L1
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(a,sizeof(a)-1).put('\n');
    }
    ```

    输入输出示例：

    ```
    use get() input char: how are you!
    how are you!
    this
    this is a string...
    ```

$~$

**`ios`类的格式化标志：**

```cpp linenums="1"
ios::skipws         //跳过输入流中的空白字符
ios::left           //左对齐输出
ios::right          //右对齐输出
ios::dec            //十进制输出
ios::oct            //八进制输出
ios::hex            //十六进制输出
ios::showbase       //在输出数据前面显示基数（八进制为0，十六进制为0x）
ios::showpoint      //在输出浮点数时显示小数点和完整小数位，不足补0
ios::uppercase      //在输出十六进制数时使用大写字母
ios::showpos        //在输出正数时显示正号
ios::scientific     //用科学计数法输出浮点数，如[2.122E2]
ios::fixed          //用定点数形式输出浮点数，如[212.2]
ios::unitbuf        //操作完成后立即刷新缓冲区
```

$~$

**`ios`类的格式化成员函数：**

```cpp linenums="1"
setf(flags)         //设置指定格式
unsetf(flags)       //取消指定格式
setf(flags,filed)   //先清除指定格式，再设置指定格式
```

其中，`flags`即为上面提到的`ios`类的格式化标志。

$~$

**`ios`类设置域宽、精度、填充字符的成员函数：**

```cpp linenums="1"
fill(c)             //设置填充字符为c（默认为空格）
precision(p)        //设置浮点数的精度（数字位数）为p
width(w)            //设置输出宽度为w
```

!!! Example
    ```cpp linenums="1"
    int main()
    {
        char c[30]="this is string";
        double d=-1234.8976;
        cout.width(30);   cout.fill('*');    cout.setf(ios::left);
        cout<<c<<"----L1"<<endl;
        cout.width(30);   cout.setf(ios::right);
        cout<<c<<"----L2"<<endl;
        cout.width(30);    cout.setf(ios::internal); //数值符号左对齐，数值本身右对齐
        cout<<d<<"----L3"<<endl;
        cout.setf(ios::dec|ios::showbase|ios::showpoint);
        cout.width(30);    
        cout<<d<<"----L4"<<"\n";
        cout.setf(ios::showpoint);    cout.precision(10);
        cout.width(30);
        cout<<d<<"----L5"<<"\n";
        cout.width(30);    cout.setf(ios::oct,ios::basefield);
        cout<<100<<"----L6"<<"\n";
    }
    ```

    输出为：

    ```
    this is string****************----L1
    ****************this is string----L2
    ***********************-1234.9----L3
    **********************-1234.90----L4
    ******************-1234.897600----L5
    **************************0144----L6
    ```

    值得注意的是，L3本来应该要输出：

    ```
    -***********************1234.9----L3
    ```

    也就是说，`setf(ios::internal)`没有发挥作用，这是因为其无法覆盖之前的`setf(ios::right)`。但是，`setf(ios::left)`和`setf(ios::right)`是互斥的，因此后者可以覆盖前者。

    此外，浮点数默认四舍五入到六位，如果末尾为0则默认不输出，因此L3本来四舍五入为-1234.90，输出变成-1234.9。

$~$

**操纵符（manipulator）：**

操纵符与格式状态类似，但写法更加简洁。（需要头文件`<iomanip>`）

例如，上面的例子中，用操纵符的写法可以写成：

```cpp linenums="1"
cout<<setw(30)<<left<<setfill('*')<<c<<"----L1"<<endl;
cout<<setw(30)<<right<<setfill('*')<<c<<"----L2"<<endl;
cout<<dec<<showbase<<showpoint<<setw(30)<<d<<"----L3"<<endl;
cout<<setw(30)<<showpoint<<setprecision(10)<<d<<"----L4"<<endl;
cout<<setw(30)<<setbase(8)<<100<<"----L5"<<endl;
```

输出结果一样。

$~$

***

## 8.3 文件操作

$~$

**文件与流：**

用流操作文件的过程有以下四步：

* 建立文件流：`ifstream iFile`,`ofstream oFile`
* 打开文件：`void open(const char* filename,int mode,int access)`
* 访问文件：`iFile>>...`,`oFile<<...`
* 关闭文件：`iFile.close()`,`oFile.close()`

$~$

**二进制文件：**

二进制文件与文本文件在判定文件结束标志的方法上存在区别。二进制文件不能用EOF作为文件结束的判定值。

c++使用`int xx::eof()`判定文件是否结束，其中，`xx`表示输入流对象，到达文件末尾时，返回一个非零值，否则返回0。

$~$

**二进制文件操作方法：**

```cpp linenums="1"
istream& get(char& ch);                 //按字节方式读文件，定义于istream类
ostream& put(char ch);                  //按字节方式写文件，定义于ostream类
istream& read(char* buf,int n);         //一次从输入流中读取n字节的内容，定义于istream类
ostream& write(const char* buf,int n);  //一次插入n字节的内容到输出流中
```