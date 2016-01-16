#include<algorithm>

template<typename t>
class my_node{
public:
	t value;
	my_node*next;
	my_node(t v){
		value = v;
	}
};
template<typename t>
class my_linkedlist{
private:
	my_node<t>*head;
	int	size;
	int list_to_int_v2(my_node<t>*node, int count){
		if (node == NULL)return 0;
		else{
			cout << node->value;
			return pow(10, count)*node->value + list_to_int_v2(node->next, count-1);
		}

	}
public:
	my_linkedlist(){
		head = NULL;
		size = 0;
	}
	void add_front(t value){
		if (head == NULL){
			head = new my_node<t>(value);
			size++;
		}
		else{
			my_node<t>*temp = new my_node<t>(value);
			temp->next = head;
			head = temp;
			size++;
		}
	}
	void print_list(){
		my_node<t>*temp = head;
		while (temp != NULL){
			cout << temp->value << "-->";
			temp = temp->next;
		}
	}
	void add_end(t value){
		if (head == NULL){
			head = new my_node<t>(value);
			size++;
		}
		else{
			my_node<t>*temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new my_node<t>(value);
			size++;
		}
	}
	int get_size(){
		return size;
	}
	bool contain(t v){
		my_node<t>*temp = head;
		while (temp != NULL){
			if (temp->value == v){
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void del(t v){

		my_node<t>*temp = head;
		if (temp->value == v){
			head = head->next;
			size--;
			delete temp;
		}
		else{
			while (temp->next != NULL){
				if (temp->next->value == v){
					my_node<t>*target = temp->next;
					temp->next = temp->next->next;
					size--;
					delete target;
					//break;
				}
				else{
					temp = temp->next;
				}
			}
		}
	}

	//find kth to last element of the list
	void find_kth(int k){
		my_node<t>*temp = head;
		int count=1;
		while (temp != NULL){
			if (count >= k){
				cout << temp->value<< "-->";
			}
			temp = temp->next;
			count++;
		}
	}
	//remove middle element of a linkedlist, by using a fast runner and a slow runner method, slow pointer travel 2 nodes at a time
	//and the slow runner travel 1 node at a time, by the time fast runner travel to the last node, the slow runner will travel to 
	//the middle of the linkedlist
	void remove_middle(){
		my_node<t>*fast = head;
		my_node<t>*slow = head;

		while (fast->next!= NULL){
			// avoid having the problem of "null->next"
			if (fast->next->next != NULL){
				fast = fast->next->next;
				slow = slow->next;
			}
			else{
				fast = fast->next;
			}
		}
		my_node<t>*check = head;
		while (check->next != slow){
			check = check->next;
		}
		check->next = check->next->next;
		delete slow;
	}
	// transform a linkedlist into a integer. example: (7-> 1 -> 6) to 617
	int list_to_int(){
		my_node<t>*temp = head;
		int count=0;
		int result=0;
		while (temp != NULL){
			result=result+(temp->value*pow(10, count));
			count++;
			temp = temp->next;
		}
		return result;
	}
	// transform a linkedlist into a integer. example: (6-> 1 -> 7) to 617
	int list_to_int_rec(){
		my_node<t>*temp = head;
		return list_to_int_v2(temp, size-1);
	}
	
};