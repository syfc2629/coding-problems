#include<iostream>
#include<string>
#include<algorithm>
#include"my_linkedlist.h"
using namespace std;

// add two list and produce a new list with the form of (7-->1-->6) + (5-->9-->2) = 617+295 and produce (2-->1-->9) = 912
my_linkedlist<int> add_list(my_linkedlist<int>a,my_linkedlist<int>b){
	//"list_to_int" covert the linkedlist into a integer
	 int temp1=int(a.list_to_int());
	 int temp2=int(b.list_to_int());
	 int sum = temp1 + temp2;
	 my_linkedlist<int> result = my_linkedlist<int>();
	 cout << sum << endl;
	 //while sum have remainder 
	 while (sum > 1){
		 int temp = sum % 10;
		 sum = sum / 10;
		 result.add_end(temp);
	 }
	 return result;
}

int main(){


	my_linkedlist<int> list = my_linkedlist<int>();
	list.add_front(5);
	list.add_front(1);
	list.add_front(8);
	list.add_front(9);
	my_linkedlist<int> list1 = my_linkedlist<int>();
	list1.add_front(2);
	list1.add_front(3);
	list1.add_front(7);
	list1.add_front(9);
	my_linkedlist<int> list2=add_list(list, list1);
	list2.print_list();
	list2.list_to_int_rec();
}
