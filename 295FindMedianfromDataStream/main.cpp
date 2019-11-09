#include <iostream>
#include <vector>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    	if(list.size() == 0)
    	{
    		list.push_back(num);
    		mid.push_back(0);
    		return;
    	}else if(list.size() == 1)
    	{
    		if(num>list[0])
    		{
    			list.push_back(num);
    			mid.push_back(1);
    		}else
    		{
    			list.insert(list.begin(),num);
    			mid.insert(mid.begin(),1);
    		}
    		return;
    	}
    	vector<int>::iterator pre=list.begin();
    	if(num <= *pre)
    	{
    		list.insert(pre,num);
    		if(mid.size() == 1)
    		{
    			mid.push_back(*(mid.begin())+1);
    		}else
    		{
				mid.erase(mid.begin());
    		}
    		return;
    	}
    	vector<int>::iterator it=list.begin();
    	it++;
    	int count = 1;
    	for(vector<int>::iterator it2=it;it2<list.end();it2++)
    	{
    		if(num >= *pre && num <= *it2)
    		{
    			list.insert(it2,num);
    			if(count > list.size()/2)
    			{

    			}else
    			{

    			}
    			return;
    		}
    		count += 1;
    		pre = it2;
    	}
    	return;
    }
    
    double findMedian() {
        
    }

    void print(){
    	for(vector<int>::iterator it=list.begin();it<list.end();it++)
    	{
    		cout<<*it<<endl;
    	}
    	return;
    }
private:
	vector<int> list;
    vector<int> mid;
};

int main()
{
	MedianFinder * myMedianFinder = new MedianFinder();
	myMedianFinder->addNum(2);
	myMedianFinder->addNum(1);
	myMedianFinder->print();
	// cout<<myMedianFinder->findMedian()<<endl;
	// myMedianFinder->addNum(3);
	// cout<<myMedianFinder->findMedian()<<endl;
	delete myMedianFinder;
	return 0;
}