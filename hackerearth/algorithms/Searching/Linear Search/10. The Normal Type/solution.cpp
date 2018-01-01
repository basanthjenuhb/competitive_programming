#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node
{
	private:

		unsigned long int offset, data = 0, count = 0, blockSize = 64;

		/**
			Return 1 if the offset is same.
			0 if the number is less than offset.
			2 if number is greater than offset.
		*/
		int isRightNode(int number)
		{
			int requiredOffset = number - number % blockSize;
			if(requiredOffset == offset)
				return 1;
			else if(requiredOffset < offset)
				return 0;
			else
				return 2;
		}
	
	public:

		Node(int number)
		{
			offset = number - number % blockSize;
			add(number);
		}

		int add(int number)
		{
			int flag = isRightNode(number);
			if(flag == 1)
			{
				data = data | ( 1 << (number % blockSize));
				return 1;
			}
			return flag;
		}

		int getData()
		{
			return data;
		}

		int getOffset()
		{
			return offset;
		}

		void display()
		{
			for(int i = 0; i < blockSize; i++)
			{
				if(data & (1 << i))
				{
					cout << offset + i << " ";
				}
			}
		}

		int find(int number)
		{
			int flag = isRightNode(number);
			if(flag == 0)
				return flag;
			if(flag == 1)
			{
				if(data & (1 << (number % blockSize)))
					return 1;
				else
					return 2;
			}
			return 3;
		}
};

class SparseSet
{
	private:
		
		int count = 0;
		list <Node> dataList;
	
	public:
		void add(int number)
		{
			if(dataList.empty())
			{
				count++;
				dataList.push_back(Node(number));
				return;
			}
			list <Node> :: iterator iter;
			int flag;
			for(iter = dataList.begin(); iter != dataList.end(); iter++)
			{
				int flag = iter->find(number);
				if(flag == 1)
					return;
				if(flag == 2)
				{
					count++;
					iter->add(number);
					return;
				}
				else if(flag == 0)
					break;
			}
			count++;
			if(!flag)
			{
				dataList.insert(iter, Node(number));
				return;
			}
			dataList.push_back(Node(number));
		}

		int find(int number)
		{
			list <Node> :: iterator iter;
			for(iter = dataList.begin(); iter != dataList.end(); iter++)
			{

				int flag = iter->find(number);
				if(flag == 1)
					return 1;
				if(!flag)
					return 0;
			}
			return 0;
		}

		int size()
		{
			return count;
		}

		int length()
		{
			return dataList.size();
		}

		list <Node> :: iterator begin()
		{
			return dataList.begin();
		}

		list <Node> :: iterator end()
		{
			return dataList.end();
		}

		void display()
		{
			list <Node> :: iterator iter;
			for(iter = dataList.begin(); iter != dataList.end(); iter++)
			{
				iter->display();
			}
			cout << endl;
		}

		int hasSameElements(SparseSet sparseSet)
		{
			if(size() != sparseSet.size() || length() != sparseSet.length())
				return 0;
			list <Node> :: iterator iter1, iter2;
			for(iter1 = dataList.begin(), iter2 = sparseSet.begin(); iter1 != dataList.end() && iter2 != sparseSet.end(); iter1++, iter2++)
			{
				// cout << iter1->getData() << endl;
				// cout << iter2->getData() << endl;
				// cout << iter1->getOffset() << endl;
				// cout << iter2->getOffset() << endl;
				if( iter1->getOffset() != iter2->getOffset() || iter1->getData() != iter2->getData())
					return 0;
			}
			return 1;
		}
};

int main()
{
	unsigned long int n, number, count = 0, elements[200001];
	SparseSet s1;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> elements[i];
		s1.add(elements[i]);
	}
	// cout << s1.size() << endl;
	// s1.display();
	for(int i = 0; i < n - s1.size(); i++)
	{
		for(int j = i + s1.size() - 1; j < n; j++)
		{
			SparseSet s2;
			for(int k = i; k <= j; k++)
			{
				s2.add(elements[k]);
			}
			// s2.display();
			if(s1.hasSameElements(s2))
				count++;
		}
	}
	cout << count << endl;
}