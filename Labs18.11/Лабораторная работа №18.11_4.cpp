#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef stack<int> Stack;
typedef vector<int> Vector;
Stack make_stack(int n)
{
	Stack st;
	int number;
	for (int i = 0;i < n;i++)
	{
		cout << i + 1 << ") ";
		cin >> number;
		st.push(number);
	}
	return st;
}
Vector copy_stack_to_vector(Stack st)
{
	Vector vec;
	while (!st.empty())
	{
		vec.push_back(st.top());
		st.pop();
	}
	return vec; 
}
Stack copy_vector_to_stack(Vector vec)
{
	Stack st;
	for (int i = 0;i < vec.size();i++)
		st.push(vec[i]);
	return st; 
}
void print_stack(Stack st) {
	Vector temp_vec = copy_stack_to_vector(st);
	for (int i = 0; i < temp_vec.size(); i++)
		cout << i + 1 << ") " << temp_vec[i] << endl;
	temp_vec.clear();
}
int find_max(Stack st)
{
	int max = st.top();
	Vector vec = copy_stack_to_vector(st);
	while(!st.empty())
	{
		if (st.top() > max)
			max = st.top();
		st.pop();
	}
	st = copy_vector_to_stack(vec);
	return max; 
}
void push_back_max(Stack& st) {
	int max_value = find_max(st);
	Vector temp_stack = copy_stack_to_vector(st);
	int i;
	for (i = 0; i < temp_stack.size(); i++)
		if (temp_stack[i] == max_value)
			break;
	temp_stack.erase(temp_stack.begin() + i);
	Vector temp_stack2;
	for (int i = temp_stack.size()-1; i >= 0; i--)
		temp_stack2.push_back(temp_stack[i]);
	temp_stack2.push_back(max_value);
	st = copy_vector_to_stack(temp_stack2);
	temp_stack.clear();
	temp_stack2.clear();
}
void delete_element(Stack& st, const int element) {
	Vector temp_stack = copy_stack_to_vector(st);
	Vector temp_stack2;
	for (int i = 0; i < temp_stack.size(); i++)
		if (temp_stack[i] != element)
			temp_stack2.push_back(temp_stack[i]);
	temp_stack.clear();
	for (int i = temp_stack2.size() - 1; i >= 0; i--)
		temp_stack.push_back(temp_stack2[i]);
	st = copy_vector_to_stack(temp_stack);
	temp_stack.clear();
	temp_stack2.clear();
}
int increase_values_on_arithmetical_mean(Stack& st) {
	if (st.size() == 0) {
		cout << "Стек пуст" << endl;
		return 0;
	}
	int arithmetical_mean = 0, sum = 0;
	Vector temp_stack = copy_stack_to_vector(st);
	for (int i = 0; i < temp_stack.size(); i++)
		sum += temp_stack[i];
	arithmetical_mean = sum / temp_stack.size();
	for (int i = 0; i < temp_stack.size(); i++)
		temp_stack[i] += arithmetical_mean;
	Vector temp_stack2;
	for (int i = temp_stack.size() - 1; i >= 0; i--)
		temp_stack2.push_back(temp_stack[i]);
	st = copy_vector_to_stack(temp_stack2);
	temp_stack.clear();
	temp_stack2.clear();
	return arithmetical_mean;
}
void main()
{
	setlocale(LC_ALL, "");
	Stack mystack; 
	int size;
	cout << "Введите количество элементов в стеке: "; 
	cin >> size;
	cout << "Введите элементы стека:" << endl;
	mystack = make_stack(size);
	cout << "Содержимое стека:" << endl;
	print_stack(mystack);
	cout << "Максимальный элемент стека помещен в конец:" << endl;
	push_back_max(mystack);
	print_stack(mystack);
	cout << "Введите элемент, который хотите удалить: ";
	int element_del;
	cin >> element_del;
	delete_element(mystack, element_del);
	cout << "Содержимое стека после удаления элементов:" << endl;
	print_stack(mystack);
	cout << "Значение элементов стека увеличено на среднее арифметическое значение всех элементов:" << endl;
	cout << "Сред. арифм. = " << increase_values_on_arithmetical_mean(mystack) << endl;
	cout << "Содержимое стека:" << endl;
	print_stack(mystack);
}
