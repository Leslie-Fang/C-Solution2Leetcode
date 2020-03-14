#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }

    ~MedianFinder(){
        list.clear();
        //mid.clear();
    }
    
    void addNum(int num) {
        if(list.empty())
        {
            list.push_back(num);
        }else
        {
            list.insert(lower_bound(list.begin(), list.end(), num), num); 
        }
        return;
    }
    
    double findMedian() {
        double res;
        //sort(list.begin(), list.end());
        int list_size = list.size();
        if( list_size%2 == 0)
        {
            res = double(list[list_size/2]+list[list_size/2-1])/2;
        }else
        {
            res = list[list_size/2];
        }
        return res;
    }

    void print() {
    	for(vector<int>::iterator it=list.begin();it<list.end();it++)
    	{
    		cout<<*it<<endl;
    	}
    	return;
    }
private:
	vector<int> list;
    //vector<int> mid;
};

int main()
{
	MedianFinder * myMedianFinder = new MedianFinder();
	myMedianFinder->addNum(2);
	myMedianFinder->addNum(1);
	//myMedianFinder->print();
	cout<<myMedianFinder->findMedian()<<endl;
	myMedianFinder->addNum(3);
	cout<<myMedianFinder->findMedian()<<endl;
	delete myMedianFinder;
	return 0;
}