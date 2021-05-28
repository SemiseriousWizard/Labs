#include <iostream>
#include <vector>
using namespace std;
int array_size;
vector<int> vecMain;
int indexOfPart = 1;
const int for_void_filling = -1;
void make_array(int size)	//формирование массива
{
	for (int i = 0; i < size; i++)
		vecMain.push_back(rand() % 300);
}
void print_array(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}
void print_parts(vector<vector<int>> parts)
{
	cout << indexOfPart++ << ": ";
	for (int i = 0; i < parts.size(); i++)
	{
		cout << "(  ";
		for (int j = 0; j < parts[i].size(); j++)
			cout << parts[i][j] << "  ";
		cout << ") ";
	}
	cout << endl;
}
vector<int> join_two_parts(vector<int> part1, vector<int> part2)	//сортировка двух серий
{
	int index_in_first_part = 0, index_in_second_part = 0;
	vector<int> sorted_part;
	while (index_in_first_part < part1.size() || index_in_second_part < part2.size())
	{
		while (index_in_first_part < part1.size() && 
				(index_in_second_part == part2.size() || part1[index_in_first_part] <= part2[index_in_second_part]))
			sorted_part.push_back(part1[index_in_first_part++]);
		while (index_in_second_part < part2.size() && 
				(index_in_first_part == part1.size() || part2[index_in_second_part] <= part1[index_in_first_part]))
			sorted_part.push_back(part2[index_in_second_part++]);
	}
	return sorted_part;
}
vector<vector<int>> create_parts(vector<int> array) //разбиение на части
{
	int i = 0;
	vector<vector<int>> arrayOfParts; //для хранения серий
	while (i < array.size())
	{
		vector<int> new_part;
		new_part.push_back(array[i]);
		i++;
		while (i < array.size() && array[i - 1] < array[i])
			new_part.push_back(array[i++]);
		arrayOfParts.push_back(new_part);
	}
	return arrayOfParts;
}
vector<int> merge_sort(vector<int> array)	//сортировка естественным слиянием
{
	vector<vector<int>> parts = create_parts(array);
	cout << "Вывод серий:" << endl;
	print_parts(parts);
	while (parts.size() > 1) //пока элементы полностью не отсортировались
	{
		parts.push_back(join_two_parts(parts[0], parts[1]));
		parts.erase(parts.begin(), parts.begin() + 2);
		print_parts(parts);
	}
	return parts[0];
}
// сбалансированное слияние
vector<vector<int>> create_balanced_parts(vector<int> array)
{
	vector<vector<int>> parts;
	parts.push_back(array);
	print_parts(parts);
	bool isSplitArray = true;
	while (isSplitArray)
	{
		isSplitArray = false;
		vector<vector<int>> new_parts;
		for (int i = 0; i < parts.size(); i++)
		{
			if (parts[i].size() > 2)	//при количестве серий больше двух происходит дальнейшее разбиение
			{
				isSplitArray = true;
				vector<int> new_first_part, new_second_part;
				int j = 0;
				while (parts[i].size() % 2 == 0 && j < parts[i].size() / 2 || parts[i].size() % 2 != 0 && j < parts[i].size() / 2 + 1)
				{	//разное условие для нечетного и четного количества элементов в серии
					new_first_part.push_back(parts[i][j]);
					if (j < parts[i].size() / 2)
						new_second_part.insert(new_second_part.begin(), parts[i][parts[i].size() - 1 - j]);
					j++;
				}
				//запись отдельных серий
				new_parts.push_back(new_first_part); 
				new_parts.push_back(new_second_part);
			}
			else if (parts[i].size() == 2) //сортировка двух элементов в серии
			{
				if (parts[i][0] > parts[i][1])
					swap(parts[i][0], parts[i][1]);
				new_parts.push_back(parts[i]);
			}
			else
				new_parts.push_back(parts[i]); //добавление одиночного элемента в конец
		}
		parts = new_parts;
		print_parts(parts);
	}
	return parts;
}
vector<int> balanced_merge_sort(vector<int> array) //сортировка сбалансированным слиянием
{
	cout << "Деление на серии:" << endl;
	vector<vector<int>> parts = create_balanced_parts(array);
	cout << "Слияние серий:" << endl;
	print_parts(parts);
	vector<vector<int>> new_parts; 
	for (int i = parts.size() - 1; i > 0; i--)
		if (parts[i].size() == 1)
		{ //если количество элементов в серии = 1, то происходит слияние данной серии с предыдущей
			new_parts.insert(new_parts.begin(), join_two_parts(parts[i], parts[i - 1]));
			i--;
		}
		else
			new_parts.insert(new_parts.begin(), parts[i]);
	parts = new_parts;
	print_parts(parts);
	// слияние элементов в одну упорядоченную серию
	new_parts.clear();
	while (parts.size() > 1)
	{
		new_parts.clear();
		for (int i = 0; i < parts.size(); i += 2)
			new_parts.push_back(join_two_parts(parts[i], parts[i + 1]));
		parts = new_parts;
		print_parts(parts);
	}
	return parts[0];
}
//функции для полифазной сортировки
void output_data_from_files(vector<vector<int>> file1, vector<vector<int>> file2, vector<vector<int>>file3)
{
	cout << "Содержимое первого файла : ";
	print_parts(file1);
	cout << "Содержимое второго файла : ";
	print_parts(file2);
	cout << "Содержимое третьего файла : ";
	print_parts(file3);
	cout << endl;
}
vector<int> erase_void_filler(vector<int> array)	//удалить заполнители (-1)
{
	for (int i = array.size() - 1; i >= 0; i--)
		if (array[i] == for_void_filling)
			array.erase(array.begin() + i);
	return array;
}
// функция Фиббоначи для поиска размера серий
void fibbonachi_function(int numberOfSeries, int& length1, int& length2)
{
	length1 = 0;
	length2 = 1;
	while (length1 + length2 < numberOfSeries)
	{
		int temp = length2;
		length2 = length2 + length1;
		length1 = temp;
	}
}
vector<vector<int>> create_equal_parts(vector<int> array)
{	//поиск подходящего количества элементов в серии
	int amountOfElements = 2;
	while (array.size() % amountOfElements != 0 && amountOfElements < 1000) amountOfElements++;
	vector<vector<int>> result_array;
	for (int i = 0; i < array.size() / amountOfElements; i++)
	{
		vector<int> new_part;
		for (int j = 0; j < amountOfElements; j++)
			new_part.push_back(array[i * amountOfElements + j]);
		result_array.push_back(new_part);
	}
	return result_array;
}
vector<vector<int>> join_files(vector<vector<int>>& array1, vector<vector<int>>& array2)
{
	vector<vector<int>> result_array;
	int min_length;
	if (array1.size() < array2.size())
		min_length = array1.size();
	else
		min_length = array2.size();
	for (int i = 0; i < min_length; i++) //сливаем попарно серии из двух файлов 
		result_array.push_back(join_two_parts(array1[i], array2[i]));
	// удаление ненужных элементов
	array1.erase(array1.begin(), array1.begin() + min_length);
	array2.erase(array2.begin(), array2.begin() + min_length);
	return result_array;
}
vector<int> polyphase_merge_sort(vector<int> array)
{
	//разбиение по файлам
	vector<vector<int>> parts = create_equal_parts(array);
	int length1, length2;
	fibbonachi_function(parts.size(), length1, length2);
	//"файлы" для хранения элементов массивов
	vector<vector<int>> file1, file2, file3; 
	cout << "Разделение на равные серии" << endl;
	print_parts(parts);
	for (int i = 0; i < length1; i++)	//разделение по файлам
		file1.push_back(parts[i]);
	for (int i = length1; i < parts.size(); i++)
		file2.push_back(parts[i]);
	for (int i = parts.size(); i < length1 + length2; i++)
	{ //создание пустой серии
		vector<int> part;
		for (int j = 0; j < file2[0].size(); j++)
			part.push_back(for_void_filling);
		file2.push_back(part);
	}
	cout << "Разделение серий на файлы 1 и 2 (" << length1 << " " << length2 << ")" << endl;
	output_data_from_files(file1, file2, file3);
	// сортировка элементов внутрии серии
	cout << "Сортировка элементов внутри файлов" << endl;
	for (int i = 0; i < file1.size(); i++)
		file1[i] = merge_sort(file1[i]);
	for (int i = 0; i < file2.size(); i++)
		file2[i] = merge_sort(file2[i]);
	output_data_from_files(file1, file2, file3);
	// сортировка
	cout << "Слияние файлов" << endl;
	int amountEmptyFiles = 1;
	while (amountEmptyFiles < 2)
	{
		// поиск пустого файла
		int indexOfEmptyFile = 1;
		if (file2.size() == 0) 
			indexOfEmptyFile = 2;
		if (file3.size() == 0) 
			indexOfEmptyFile = 3;
		// слияние в один файл
		switch (indexOfEmptyFile)
		{
		case 1: 
			file1 = join_files(file2, file3);
			break;
		case 2:
			file2 = join_files(file1, file3); 
			break;
		case 3:
			file3 = join_files(file1, file2); 
			break;
		}
		// посчитать количество пустых файлов
		amountEmptyFiles = 0;
		if (file1.size() == 0) 
			amountEmptyFiles++;
		if (file2.size() == 0) 
			amountEmptyFiles++;
		if (file3.size() == 0)
			amountEmptyFiles++;
		output_data_from_files(file1, file2, file3);
	}
	if (file1.size() != 0) 
		return erase_void_filler(file1[0]);
	if (file2.size() != 0) 
		return erase_void_filler(file2[0]);
	return erase_void_filler(file3[0]);
}
void show_menu() {
	int option;
	vector<int> vec1;
	cout << "Выберите дальнейшее действие:\n";
	cout << "0) Выйти" << endl;
	cout << "1) Отсортировать массив методом естественного слияния" << endl;
	cout << "2)Отсортировать массив методом сбалансированного слияния" << endl;
	cout << "3) Отсортировать массив методом многофазного слияния" << endl;
	cout << ">";
	cin >> option;
	switch (option)
	{
	case 0:
		break;
	case 1:
		cout << "Введите размер массива: " << endl;
		cin >> array_size;
		cout << "Неотсортированный массив:" << endl;
		make_array(array_size);
		print_array(vecMain);
		cout << endl << "Сортировка методом естественного слияния" << endl;
		vec1 = merge_sort(vecMain);
		cout << "Отсортированный массив:" << endl;
		print_array(vec1);
		break;
	case 2:
		cout << "Введите размер массива: " << endl;
		cin >> array_size;
		cout << "Неотсортированный массив:" << endl;
		make_array(array_size);
		print_array(vecMain);
		cout << endl << "Сортировка методом сбалансированного слияния" << endl;
		vec1 = balanced_merge_sort(vecMain);
		cout << "Отсортированный массив:" << endl;
		print_array(vec1);
		break;
	case 3:
		cout << "Введите размер массива: " << endl;
		cin >> array_size;
		cout << "Неотсортированный массив:" << endl;
		make_array(array_size);
		print_array(vecMain);
		cout << endl << "Сортировка методом многофазного слияния" << endl;
		vec1 = polyphase_merge_sort(vecMain);
		cout << "Отсортированный массив:" << endl;
		print_array(vec1);
		break;
	}
}
int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	show_menu();
	system("pause");
	return 0;
}