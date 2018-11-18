#include <thread>
#include <iostream>
#include <vector>


using namespace std;

class ThreadedMergeSort{
public:
	static void mergeArrays(int arr[],int leftStart,int middleIndex, int rightEnd){

		int i;
		int j;
		int k;
		int n1=middleIndex-leftStart+1;
		int n2=rightEnd-middleIndex;
		int l[n1];
		int r[n2];
		for(i=0;i<n1;i++){
			l[i]=arr[i+leftStart];
		}
		for(j=0;j<n2;j++){
			r[j]=arr[j+middleIndex+1];
		}
		i=0;
		j=0;
		k=leftStart;
		while(i<n1 && j<n2){
			if(l[i]<r[j]){
				arr[k]=l[i];
				i++;
			}
			else{
				arr[k]=r[j];
				j++;
			}
			k++;
		}

		while(i<n1){
			arr[k]=l[i];
			i++;
			k++;
		}
		while(j<n2){
			arr[k]=r[j];
			j++;
			k++;
		}
}

	static void mergeSortHelper(int arr[],int l, int r){
		if(l<r){
			int middle=(l+r)/2;
			mergeSortHelper(arr,l,middle);
			mergeSortHelper(arr,middle+1,r);
			mergeArrays(arr, l, middle, r);
		}
	}
	
	static void mergeSort(int arr[],int size){
		int r=size-1;
		int l=0;
		mergeSortHelper(arr,l,r);
	}


static void print(vector<int> x)
{
	for(int i = 0 ; i<x.size() ; i++)
	{
		cout<<x[i]<<" ";
	}	
	cout<<endl;
}

static void threadmerge(vector<int>& left, vector<int>& right, vector<int>& result)
{
	int i=0,j=0,k=0;
	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
		k++;
	}
		
		while(i<left.size())
		{
			result.push_back(left[i]);
			i++;
			k++;
		}
		
		while(j<right.size())
		{
			result.push_back(right[j]);
			j++;
			k++;
		}

	}
};

class MergeSorter{

public:
	void mergeArrays(vector<int>& arr,int leftStart,int middleIndex, int rightEnd){

		int i;
		int j;
		int k;
		int n1=middleIndex-leftStart+1;
		int n2=rightEnd-middleIndex;
		int l[n1];
		int r[n2];
		for(i=0;i<n1;i++){
			l[i]=arr[i+leftStart];
		}

		for(j=0;j<n2;j++){
			r[j]=arr[j+middleIndex+1];
		}
		i=0;
		j=0;
		k=leftStart;
		while(i<n1 && j<n2){
			if(l[i]<r[j]){
				arr[k]=l[i];
				i++;
			}
			else{
				arr[k]=r[j];
				j++;
			}
			k++;
		}

		while(i<n1){
			arr[k]=l[i];
			i++;
			k++;
		}
		while(j<n2){
			arr[k]=r[j];
			j++;
			k++;
		}
}

	void mergeSortHelper(vector<int>& arr,int l, int r){
		if(l<r){


			int middle=(l+r)/2;
			mergeSortHelper(arr,l,middle);
			mergeSortHelper(arr,middle+1,r);
			mergeArrays(arr, l, middle, r);
		}

	}
	void mergeSort(vector<int>& arr,int size){
		int r=size-1;
		int l=0;
		mergeSortHelper(arr,l,r);
	}

};

class ThreadedInsertion{

public:

static void threadsort(vector<int> &v)
{
	int index,value;

	for(int i=1 ; i<v.size() ; i++)
	{
		index = i;
		value = v[i];

		while(index>0 && (v[index-1]>value))
		{
			v[index] = v[index-1];
			index = index -1;
		}
		v[index] = value;
	}
}

static void print(vector<int> x)
{
	for(int i = 0 ; i<x.size() ; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

static void threadmerge(vector<int>& left, vector<int>& right, vector<int>& result)
{
	int i=0,j=0,k=0;
	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
		k++;
	}

		while(i<left.size())
		{
			result.push_back(left[i]);
			i++;
			k++;
		}

		while(j<right.size())
		{
			result.push_back(right[j]);
			j++;
			k++;
		}

	}
};

class InsertionSorter{
public:
vector<int> insertion_sort(vector<int> v)
{
	int index,value;

	for(int i=1 ; i<v.size() ; i++)
	{
		index = i;
		value = v[i];

		while(index>0 && (v[index-1]>value))
		{
			v[index] = v[index-1];
			index = index -1;
		}
		v[index] = value;
	}

	return v;

}

void print(vector<int> x)
{
	for(int i = 0 ; i<x.size() ; i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
};

int main()
{
	//vector<int> v1{10,9,8,7,1};
	//vector<int> v1;
	cout<<"Project 3: Multi threaded sorting application"<<endl;
	int v1[500000], v2[500000];
	for(int a=500000 ; a>0 ; a--)
	{
		v1[a] = a;
	}
	//vector<int> v2{11,34,44,6,100,55,77};
	//vector<int> v2;
	for(int a=500000 ; a>0 ; a--)
	{
		v2[a] = a+500000;
	}

	//cout<<"Point 1";
	vector<int> result; 
	cout<<"Merge sort using 3 threads-"<<endl;
	cout<<"total input array elements- 1000000"<<endl;
	std::chrono::time_point<std::chrono::system_clock> start, end; 	
	start = std::chrono::system_clock::now(); 

	ThreadedMergeSort tms;
	thread t1(tms.mergeSort, ref(v1),500000);
	thread t2(tms.mergeSort, ref(v2),500000);
	t1.join();
	t2.join();
	//cout<<"Point 2";
	vector<int> v11(v1, v1+sizeof(v1)/sizeof(int));
	vector<int> v12(v2, v2+sizeof(v2)/sizeof(int));
	thread t3(tms.threadmerge, ref(v11), ref(v12), ref(result));
	t3.join();
	//cout<<"Point 3";
	end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start; 
	for(int i=0;i<20;i++){
		cout<<result[i]<<" ";
	}
	cout<<"....";
	cout<<endl;
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n"; 
	cout<<"---------------------------------------------------------";
	//print(result);

	//single threaded merge sort
	vector<int> arr;
	for(int i=1000000;i>0;i--){
		arr.push_back(i);
	}

	cout<<endl;
		cout<<"Merge sort using 1 thread-"<<endl;
		cout<<"total input array elements- 1000000"<<endl;
		MergeSorter ms;
		start = std::chrono::system_clock::now();
		ms.mergeSort(arr, arr.size());
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		for(int i=0;i<20;i++){
							cout<<arr[i]<<" ";
					}
					cout<<"....";
		cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		cout<<"---------------------------------------------------------";
		cout<<endl;
		/*for(int k=0;k<10000;k++){
			cout<<arr[k]<<" ";
		}
		cout<<endl;*/

		//Multi threaded insertion sort
			vector<int> v3;
			for(int a=50000 ; a>0 ; a--)
			{
				v3.push_back(a);
			}
			//vector<int> v2{11,34,44,6,100,55,77};
			vector<int> v4;
			for(int a=100000 ; a>50000 ; a--)
			{
				v4.push_back(a);
			}

			vector<int> result3;
			cout<<"Insertion sort using 3 threads-"<<endl;
			cout<<"total input array elements- 1000000"<<endl;

			start = std::chrono::system_clock::now();

			ThreadedInsertion ti;
			thread t4(ti.threadsort, ref(v3));
			thread t5(ti.threadsort, ref(v4));
			t4.join();
			t5.join();


			thread t6(ti.threadmerge, ref(v3), ref(v4), ref(result3));
			t6.join();

			end = std::chrono::system_clock::now();

			elapsed_seconds = end - start;
			for(int i=0;i<20;i++){
					cout<<result3[i]<<" ";
			}
			cout<<"....";
		    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
		    cout<<"---------------------------------------------------------";
			cout<<endl;

			// single threaded insertion sort
			vector<int> v6;
			for(int a=100000 ; a>0 ; a--)
			{
				v6.push_back(a);
			}

			cout<<"Insertion sort using 1 thread-"<<endl;
			cout<<"total input array elements- 1000000"<<endl;
			InsertionSorter is;
			start = std::chrono::system_clock::now();
			v6=is.insertion_sort(v6);
			end = std::chrono::system_clock::now();

			elapsed_seconds = end - start;
			for(int i=0;i<20;i++){
								cout<<v6[i]<<" ";
					}
						cout<<"....";
			cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
			cout<<"---------------------------------------------------------";
			cout<<endl;
			cout<<"Thank You";









	return 0;
}
