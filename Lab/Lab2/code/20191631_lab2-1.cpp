#include <iostream>

using namespace std;

int iterativeBinarySearch(int* list, int count, int num, int left, int right);
int recursiveBinarySearch(int* list, int count, int num, int left, int right);
int compare(int x, int y);

int main()
{
    while(true){
	int list[] = { 10,20,30,40,50,60,70,80,90,100 };
	int searchNum;
	int methodNum;
	int searchPos;
    
    cout << "Enter method of search(1.Binary Search	2.Recursive Binary Search 3. Exit) : ";
	cin >> methodNum;

      if (methodNum == 3){
        break;
	}
    
	cout << "Enter an integer to search : ";
	cin >> searchNum;
	

	if (methodNum == 1){
		searchPos = iterativeBinarySearch(list, sizeof(list) / sizeof(int), searchNum, 0, 9);
    }
	
    if (methodNum == 2){
		searchPos = recursiveBinarySearch(list, sizeof(list) / sizeof(int), searchNum, 0, 9);
    }

	if (searchPos == -1)
		cout << searchNum << " is not in the list" << endl;
	else
		cout << searchNum << " is at position " << searchPos+1 << endl;
    }
}

int iterativeBinarySearch(int* list, int count, int num, int left, int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (num < list[middle])
			right = middle - 1;
		else if (num == list[middle])
			return middle;
		else
			left = middle + 1;
	}
	return -1;
}

int recursiveBinarySearch(int* list, int count, int num, int left,int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		switch (compare(list[middle], num))
		{
		case -1:
			left = middle + 1;
			break;
		case 0:
			return middle;
		case 1:
			right = middle - 1;
			break;
		}
	}
	return -1;
}

int compare(int x, int y)
{
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}