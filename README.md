# Pat-exercise
记录刷题代码，菜鸟升级之路
### B1052

字符串操作

* “Are you kidding me? @\/@”的’\’是转义字符，想要输出’\’就要用’\\’表示

* 别忘了加上a<1||b<1||c<1||d<1||e<1

* ```c++
  if(t1[i]==' '||t1[i]=='['||t1[i]==']'){
      i++;
      continue;
  }
  ```
  
  改为
  
  ```c++
  if(t1[i++]!='['){
      continue;
  }
  ```
  
  因为'[]'外的字符不只有空格
  
* 程序改进之处：改用vector<vector <string> > ,不需要用map，用string的substr截取[]中的字符串substr(pos,len)

* 注意格式正确，在Are you kidding me? @\/@ 后输出换行符。

### B1077

* 四舍五入函数round在math.h中，sqrt和pow也在math.h中，max，min在algorithm中
* 四舍五入也可用` printf("%d\n",int(re+0.5));`

### B1070

* 排序加贪心

* ```c++
  for(int i=0;i<n-1;i++){
          double temp=(c[i]+c[i+1])/2;
          c[i+1]=temp;
  }
  ```

  可改成

  ```c++
  int result = v[0];
      for (int i = 1; i < n; i++)
          result = (result + v[i]) / 2;
  ```

* 向下取整用floor()

### B1087

* 利用set的去重性，一开始没想到，想找规律，这条路行不通就模拟从1到n的过程，将生成的结果放到set中
* 复习了set的insert用法
* 向下取整，整数除法自动向下取整

### B1066

* 多重循环中最好用printf，不用cout，防止超时

### B1084

* `memset(a,0,sizeof(a))`头文件cstring
* 注意迭代n-1次
* 我用的是三个vector做的很烦，柳神用两个字符串就解决了，转化为字符串拼接问题

### B1093

* 字符是ASCII码，可直接当作整数用
* 两个字符串可拼接后使用

### B1091

* 阶乘时注意谨慎使用pow()，`int n=pow(5,2)`结果n等于24，换成double即可
* `string c = a.substr(a.length() - b.length());`截取a的后x位，x为b的位数，即看a后几位是否和b相同，可以转化为字符串问题。
* to_string的使用

### B1072

* 输出编号时注意%04d格式
* map用不了find，set有find

### B1050(没写出来)

* vector容器只有在初始化之后才能直接输入

  ```c++
  vector<int> v(10);
  cin>>v[1];
  或
  vector<int> v;
  int temp=10;
  v.push_back(temp);
  ```

* 对二维向量进行初始化，创建一个10*5的二维向量

  ```c++
  vector< vector<int> > b(10, vector<int>(5));
  cin>>b[1][1]
  ```

* 复习了sort中cmp函数的写法

* 找两数(m>=n)相乘等于N，且两数之差最小的算法，N的平方根的整数部分向1递减到第一个能被N整除的数即为n，m=N/n

* 模拟题，分为两个循环，大循环次数为level，小循环有四种，慢慢确定小循环的上下边界

### B1053

* printf 要两个%%才能输出百分号

* 小数除法时，要用double，否则两个整型计算后为0

  如2/5=0，（double）2/5=0.4

### B1054(没写出来) （字符串转数字）

* 转化为字符串操作

* sscanf：从字符串读进指定格式的数据，这一步可以将许多非法数据过滤掉

  sprintf：将数据以指定格式写进字符串

  这里的**字符串为char字符数组**，用%s输入、输出

* 判断用原字符串和%.2f指定格式的字符串进行比较