import <iostream>;   //导入模块
import <format>;

using namespace std;

int main()
{
	std::cout << std::format("hello world {}", 100) << std::endl;

	int uninitializedInt;
	int initializedInt{ 7 };			//统一的变量初始化
	cout << format("{} is a random value", uninitializedInt) << endl;
	cout << format("{} was assigned an initial value", initializedInt) << endl;

	cout << "int:\n";
	cout << format("Max int value: {}\n", numeric_limits<int>::max());
	cout << format("Min int value: {}\n", numeric_limits<int>::min());
	cout << format("Lowest int value: {}\n", numeric_limits<int>::lowest());
	cout << "\ndouble:\n";
	cout << format("Max double value: {}\n", numeric_limits<double>::max());
	cout << format("Min double value: {}\n", numeric_limits<double>::min());
	cout << format("Lowest double value: {}\n", numeric_limits<double>::lowest());
}