#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//swaping two variables, pass by reference
template< typename t>
void my_swap(t&a, t&b){
	t temp = a;
	a = b;
	b = temp;
}


// reverse a word, input is the character string and the length of the string, assuming word[size] is a null character
void reverse(char* word,int size){
	for (int i = 0; i < size / 2; i++){
		int last = size - 1 - i; // the index of character in the word that will be swaped
		my_swap(word[i], word[last]);
	}
}
//determine wether two word is the permuatation of the others, meaning that does two word have both characters regardless of it's position.
//sort the two strings and compare it, if they are equal, it means they contain the same characters.
void permu_word(string a, string b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a == b){
		cout << "They are permuatation of each other"<<endl;
	}
	else{
		cout << "They are not permuatation of each other"<<endl;
	}
}
//replace space into %20 in a string
void replace_space(string&a){
	string temp = "";
	for (int i = 0; i < a.size(); i++){
		if (a[i] != ' '){
			temp += a[i];
		}
		else{
			temp += "%20";
		}
	}
	a = temp;
}
//compressed string, and return the string with smaller characters. examples: aabcccccaaa -->a2blc5a3
string compress(string a){
	string result = "";
	char temp = a[0];
	int count = 1;
	for (int i = 1; i < a.size(); i++){
		if (a[i] == temp){
			//same character found, therefore increasing the count of that character
			count++;
		}
		else{
			// different character found, therefore reset the temporary character and reset the count, also update the compress string
			result += temp + to_string(count);
			count = 1;
			temp = a[i];
		}
	}
	result += temp + to_string(count);
	// return the string with smaller size
	return result.size() < a.size() ? result : a;
}
//rotate a 2d matrix by 90 degree clockwise
void rotate_mat_90(int**matrix,int row,int col){
	//create a temporary array
	int **temp = new int*[row];
	for (int i = 0; i < row; i++){
		temp[i] = new int[col];
	}
	// store the turned value to the new temporaty array
	/* Notice that the pattern of rotated index to original index is always (i,j) --> (i,row-1-j)
	123		  741
	456 ----> 852
	789	  	  963
	*/
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			temp[i][j] = matrix[i][col-1- j];
		}
	}
	//copy the fully turned matrix to the original matrix
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			matrix[i][j] = temp[i][j];
		}
	}
	// delete the temporary array since it is dynamically allocated
	delete[]temp;
}
int main(){

	int **matrix = new int*[9];
	for (int i = 0; i < 9; i++){
		matrix[i] = new int[9];
	}
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			matrix[i][j] = (i + 1)*(j + 1);
		}
	}
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (matrix[i][j] > 9){
				cout << matrix[i][j] << " ";
			}
			else{
				cout << matrix[i][j] << "  ";
			}
		}
		cout << endl;
	}

	cout << endl; cout << endl; cout << endl;
	rotate_mat_90(matrix,9,9);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (matrix[i][j] > 9){
				cout << matrix[i][j] << " ";
			}
			else{
				cout << matrix[i][j] << "  ";
			}
		}
		cout << endl;
	}
}
