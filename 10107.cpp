#include <iostream>
#include <vector>

int insert_number(std::vector<int>& numbers, int n);
int mean(const std::vector<int>& numbers);

int main(int argc, char **argv)
{
	int n;
	std::vector<int> numbers;
	while(std::cin>>n)
	{
		insert_number(numbers, n);
		std::cout<<mean(numbers)<<std::endl;
	}	
}

// assumes the array was sorted, and maintains this
// property after the insert.
int insert_number(std::vector<int>& numbers, int n)
{
	int i = numbers.size() - 1;
	numbers.push_back(n);
	while(i >= 0 && numbers[i] > numbers[i + 1])
	{
		int aux = numbers[i + 1];
		numbers[i + 1] = numbers[i];
		numbers[i] = aux;
		i--;
	}
}

int mean(const std::vector<int>& numbers)
{
	size_t sz = numbers.size();
	if(sz%2)
		return numbers[sz/2];
	else
		return (numbers[(sz - 1)/2] + numbers[sz/2])/2;
}
