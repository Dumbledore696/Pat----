# Pat-exercise
记录刷题代码，菜鸟升级之路
### B1052:
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