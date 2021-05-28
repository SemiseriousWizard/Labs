#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Stack {
private:
	stack<int> st;
	vector<int> copy_stack_to_vector(stack<int> st)
	{
		vector<int> vec;
		while (!st.empty())
		{
			vec.push_back(st.top());
			st.pop();
		}
		return vec;
	}
	stack<int> copy_vector_to_stack(vector<int> vec)
	{
		stack<int> st;
		for (int i = 0;i < vec.size();i++)
			st.push(vec[i]);
		return st;
	}
public:
	Stack() {}
	void make_stack(const int n)
	{
		int number;
		for (int i = 0;i < n;i++)
		{
			cout << i + 1 << ") ";
			cin >> number;
			st.push(number);
		}
	}
	void print_stack() {
		vector<int> temp_vec = copy_stack_to_vector(st);
		for (int i = 0; i < temp_vec.size(); i++)
			cout << i + 1 << ") " << temp_vec[i] << endl;
		temp_vec.clear();
	}
	int find_max()
	{
		int max = st.top();
		vector<int> vec = copy_stack_to_vector(st);
		for (int i = 0; i < vec.size(); i++)
			if (vec[i] > max)
				max = vec[i];
		return max;
	}
	void push_back_max() {
		int max_value = find_max();
		vector<int> temp_stack = copy_stack_to_vector(st);
		int i;
		for (i = 0; i < temp_stack.size(); i++)
			if (temp_stack[i] == max_value)
				break;
		temp_stack.erase(temp_stack.begin() + i);
		vector<int> temp_stack2;
		for (int i = temp_stack.size() - 1; i >= 0; i--)
			temp_stack2.push_back(temp_stack[i]);
		temp_stack2.push_back(max_value);
		st = copy_vector_to_stack(temp_stack2);
		temp_stack.clear();
		temp_stack2.clear();
	}
	void delete_element(const int element) {
		vector<int> temp_stack = copy_stack_to_vector(st);
		vector<int> temp_stack2;
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
	int increase_values_on_arithmetical_mean() {
		if (st.size() == 0) {
			cout << "Стек пуст" << endl;
			return 0;
		}
		int arithmetical_mean = 0, sum = 0;
		vector<int> temp_stack = copy_stack_to_vector(st);
		for (int i = 0; i < temp_stack.size(); i++)
			sum += temp_stack[i];
		arithmetical_mean = sum / temp_stack.size();
		for (int i = 0; i < temp_stack.size(); i++)
			temp_stack[i] += arithmetical_mean;
		vector<int> temp_stack2;
		for (int i = temp_stack.size() - 1; i >= 0; i--)
			temp_stack2.push_back(temp_stack[i]);
		st = copy_vector_to_stack(temp_stack2);
		temp_stack.clear();
		temp_stack2.clear();
		return arithmetical_mean;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Stack mystack;
	int size;
	cout << "Введите количество элементов в стеке: ";
	cin >> size;
	cout << "Введите элементы стека:" << endl;
	mystack.make_stack(size);
	cout << "Содержимое стека:" << endl;
	mystack.print_stack();
	cout << mystack.find_max() << endl;
	cout << "Максимальный элемент стека помещен в конец:" << endl;
	mystack.push_back_max();
	mystack.print_stack();
	cout << "Введите элемент, который хотите удалить: ";
	int element_del;
	cin >> element_del;
	mystack.delete_element(element_del);
	cout << "Содержимое стека после удаления элементов:" << endl;
	mystack.print_stack();
	cout << "Значение элементов стека увеличено на среднее арифметическое значение всех элементов:" << endl;
	cout << "Сред. арифм. = " << mystack.increase_values_on_arithmetical_mean() << endl;
	cout << "Содержимое стека:" << endl;
	mystack.print_stack();
}
