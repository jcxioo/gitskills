 ///
 /// @file    priority_queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-24 16:33:34
 ///
 
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
 
void test0(void)
{
	int arr[10] = {2, 3, 6, 7, 9, 8, 5, 1, 0, 4};
	priority_queue<int> pque(arr, arr + 10);
#if 0
	//优先级队列不能直接进行遍历
	for(auto & elem : pque)
	{
		cout << elem << " ";
	}
	cout << endl;
#endif 
}

void test1(void)
{
	int arr[10] = {2, 3, 6, 7, 9, 8, 5, 1, 0, 4};
	
	//优先级队列默认情况下的比较方式是: std::less<T>
	//元素出队的时候是按降序的方式进行排列
	//
	//优先级队列底层实现采用的是 堆排序,每一次比较都是用
	//堆顶的元素与新添加的元素进行比较,当compare(top, newElem)
	//返回值为true时，先把堆顶的元素放到堆底，再用新元素替换堆顶
	//的元素

	priority_queue<int> pque;
	for(size_t idx = 0; idx != 10; ++idx){
		pque.push(arr[idx]);
		cout << "当前队列中优先级最高的元素为：" << pque.top() << endl;
	}

	cout << endl << "优先级队列中的元素出队:" << endl;
	while(!pque.empty()){
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{		}

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
	}

	void set(int ix, int iy)
	{
		_ix = ix;
		_iy = iy;
	}

	double length() const
	{
		return sqrt(pow(_ix, 2) + pow(_iy, 2));
	}

	~Point()
	{}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

#if 0
bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.length() < rhs.length();
}
#endif
struct Compare
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs.length() > rhs.length();
	}
};

void test2(void)
{
	vector<Point> points{
		Point(1, 2),
		Point(3, 4),
		Point(-1, 2),
		Point(5, 6),
		Point(-1, 6)
	};
	priority_queue<Point, vector<Point>, Compare> pque;
	for(auto & element : points){
		pque.push(element);
	}

	cout << endl << "优先级队列中的元素出队:" << endl;
	while(!pque.empty()){
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
}
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
