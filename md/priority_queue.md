# c++ 中 priority_queue的使用

## 1.priority_queue定义

```cpp
template <class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> > class priority_queue;
```

- 按着这个模板定义来看，需要给出每一个**模板参数的类型**，来实例化模板。
默认使用的是小于操作的比较运算符，底层使用vector来实现，算法使用make_heap,push_heap,pop_heap一系列堆操作来完成。

```cpp
//一个int 类型的优先队列，默认是越小越优先
priority_queue<int> que;
```

## 2.使用自定义的比较规则来初始化priority_queue

- 对于使用lambda函数作为模板参数的情况如下代码的说明部分。

```cpp
class student{
    public:
        int age;
        string name;
        /**
        * 重载小于操作符，
        * 这里必须是非成员函数才可以
        */
        friend bool operator<(const student& a, const student & b){
            return a.age < b.age;
        }
};

/**可调用的函数操作符的对象*/
struct mycmp{
    bool operator()(const student & a,const student & b){
        return a.age < b.age;
    }
};

/**函数指针*/
bool cmpfunc(const student& a, const student& b){
    return a.age < b.age;
}

/**默认使用student的oprator<来进行比较*/
priority_queue<student> que1;

/**使用重载函数操作符的类对象*/
priority_queue<student,vector<student>,mycmp> que2;

/**定义一下比较函数*/
auto cmp = [](const student & a,const student & b){return a.age < b.age;};
/**
  * 需要把lambda表达式作为优先队列参数进行初始化
  * 并且指定priority_queue的模板实参，decltype(cmp)，c++11 declare type，声明类型
  * 可以认为是确定函数的类型
  * bool (const student & a,const student & b)
  **/
priority_queue<student,vector<student>,decltype(cmp)> que4(cmp);

/*使用函数对象来定义这个比较函数原型*/
//lambda 函数来初始化函数对象
priority_queue<student,vector<student>,function<bool(const student&,const student&)>> que5(cmp);

//函数指针来初始化函数对象
priority_queue<student,vector<student>,function<bool(const student&,const student&)>> que6(cmpfunc);

/**函数对象*/
function<bool(const student&,const student &)> func(cmpfunc);
priority_queue<student,vector<student>,function<bool(const student&,const student&)>> que7(func);

```

- 上述情况，也适用于其他的数据结构和算法。
- 例如：`lambda表达式`自定义函数算法，来进行结合`STL算法和数据结构`的使用
  