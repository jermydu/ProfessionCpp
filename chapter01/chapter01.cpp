import <iostream>;   //导入模块
import <format>;

//导入自定义模块不需要尖括号
import Employee;

using namespace std;

//[[nodiscard]] 属性告诉编译器 这个函数返回值必须被使用，否则编译发出警告 warning C4834: 放弃具有 "nodiscard" 属性的函数的返回值
[[nodiscard("这个返回值不能忽视")]] int func()
{
	return 42;
}

int func2(int param1,[[maybe_unused]]int param2)
{
	return 42;
}

[[noreturn]] void forceProgramTermination()
{
	std::exit(1); 
}
bool isDongleAvailable()
{
	bool isAvailable{ false };
	return isAvailable;
}
bool isFeatureLicensed(int featureId)
{
	if (!isDongleAvailable()) {
		forceProgramTermination();
	}
	else {
		bool isLicensed{ featureId == 42 };
		return isLicensed;
	}
}


int main()
{
	std::cout << std::format("hello world {}", 100) << std::endl;

	//统一的变量初始化
	int uninitializedInt;
	int initializedInt{ 7 };

	/*******************************格式化*********************************/
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

	//指定宽度
	int i42{ 42 };
	cout << format("|{:5}|", i42) << endl; 
	cout << format("|{:{}}|", i42, 7) << endl; 

	//格式对齐
	cout << format("|{:7}|", i42) << endl; 
	cout << format("|{:<7}|", i42) << endl; 
	cout << format("|{:_>7}|", i42) << endl; 
	cout << format("|{:_^7}|", i42) << endl; 

	cout << format("|{:<5}|", i42) << endl; 
	cout << format("|{:<+5}|", i42) << endl; 
	cout << format("|{:< 5}|", i42) << endl; 
	cout << format("|{:< 5}|", i42) << endl; 

	//type # 
	cout << format("|{:10b}|", i42) << endl;
	cout << format("|{:10B}|", i42) << endl;
	cout << format("|{:#10b}|", i42) << endl;
	cout << format("|{:#10B}|", i42) << endl;
	cout << format("|{:10o}|", i42) << endl; 
	cout << format("|{:#10o}|", i42) << endl; 
	cout << format("|{:10d}|", i42) << endl; 
	cout << format("|{:#10d}|", i42) << endl; 
	cout << format("|{:10x}|", i42) << endl;
	cout << format("|{:10X}|", i42) << endl;
	cout << format("|{:#10x}|", i42) << endl;
	cout << format("|{:#10X}|", i42) << endl;

	double f3 = 13.141592653;
	cout << format("|{}|", f3) << endl;
	cout << format("|{:10.5e}|", f3) << endl;
	cout << format("|{:10.5E}|", f3) << endl;
	cout << format("|{:10.5f}|", f3) << endl;
	cout << format("|{:10.5F}|", f3) << endl;
	cout << format("|{:10.5g}|", f3) << endl;
	cout << format("|{:10.5G}|", f3) << endl;
	cout << format("|{:10.5a}|", f3) << endl;
	cout << format("|{:10.5A}|", f3) << endl;
	int width{ 12 };
	int precision{ 3 };
	cout << format("|{2:{0}.{1}f}|", width, precision, f3) << endl;

	bool bl = true;
	cout << format("|{:s}|", bl) << endl;

	/*******************************枚举类型*********************************/
	//老式 没有范围限定
	enum PieceTypeOld { PieceTypeKing, PieceTypeQueen, PieceTypeRook, PieceTypePawn };
	PieceTypeOld old = PieceTypeKing;

	//C++20  有范围限定 安全
	enum class PieceTypeNew
	{
		King = 1,
		Queen,
		Rook = 10,
		Pawn
	};
	using PieceTypeNew::King;
	PieceTypeNew piece1{ King };
	PieceTypeNew piece2{ PieceTypeNew::Queen };

	/*******************************自定义导出模块*********************************/
	Employee anEmployee;
	anEmployee.firstInitial = 'J';
	anEmployee.lastInitial = 'D';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;
	// Output the values of an employee.
	cout << format("Employee: {}{}", anEmployee.firstInitial,
		anEmployee.lastInitial) << endl;
	cout << format("Number: {}", anEmployee.employeeNumber) << endl;
	cout << format("Salary: ${}", anEmployee.salary) << endl;

	/*******************************三元操作符*********************************/
	// <=>
	//strong_ordering::less: First operand less than second
	//strong_ordering::greater : First operand greater than second
	//strong_ordering::equal : Equal operands
	int i{ 11 };
	strong_ordering result{ i <=> 0 };

	if (result == strong_ordering::less) { cout << "less" << endl; }
	if (result == strong_ordering::greater) { cout << "greater" << endl; }
	if (result == strong_ordering::equal) { cout << "equal" << endl; }

	if (is_lt(result)) { cout << "less" << endl; }
	if (is_gt(result)) { cout << "greater" << endl; }
	if (is_eq(result)) { cout << "equal" << endl; }

	/**************************************************************************/
	//属性
	//[[nodiscard]]
	func();
	//[[maybe_unused]]
	func2(1,2);
	//[[noreturn]]
	bool bLicense{ isFeatureLicensed(42) };
}