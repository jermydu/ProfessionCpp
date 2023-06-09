#include <iostream>
#include<string>

int main()
{
    //原始字符串字面值
    std::string redist_path1 = "C:\Program Files (x86)\Microsoft.NET\RedistList";
    std::string redist_path2 = "C:\\Program Files (x86)\\Microsoft.NET\\RedistList";
    std::string redist_path3 = R"(C:\Program Files (x86)\Microsoft.NET\RedistList)";
    std::string redist_path4 = R"(C:\\Program Files (x86)\\Microsoft.NET\\RedistList)";

    std::cout << "redist_path1: " << redist_path1 << std::endl;
    std::cout << "redist_path2: " << redist_path2 << std::endl;
    std::cout << "redist_path3: " << redist_path3 << std::endl;
    std::cout << "redist_path4: " << redist_path4 << std::endl;

    std::string fozu = R"(
                            _ooOoo_
                           o8888888o
                           88" . "88
                           (| -_- |)
                            O\ = /O
                        ____/`---'\____
                      .   ' \\| |// `.
                       / \\||| : |||// \
                     / _||||| -:- |||||- \
                       | | \\\ - /// | |
                     | \_| ''\---/'' | |
                      \ .-\__ `-` ___/-. /
                   ___`. .' /--.--\ `. . __
                ."" '< `.___\_<|>_/___.' >'"".
               | | : `- \`.;`\ _ /`;.`/ - ` : | |
                 \ \ `-. \_ __\ /__ _/ .-` / /
         ======`-.____`-.___\_____/___.-`____.-'======
                            `=---='
		)";

    std::cout << fozu << std::endl;

    //C++ 字符串
    //c 字符串比较
    const char* a = "hello";        //不可修改
    char b[] = "hello";             //可以修改
    //b[0] = 'a';
    //比较的是字符指针
    if (a == b)         
    {
        std::cout << "a == b" << std::endl;
    }
    //C字符串比较
    if (strcmp(a, b) == 0)
    {
        std::cout << "a == b" << std::endl;
    }
    //stl C++ 字符串
    std::string a1("hello");
    std::string b1("hello");
    //这种方法的缺点:compate 返回值是 int 不容易记忆比较结果 使用起来很麻烦
    auto    result = a1.compare(b1);
    if (result == 0)
    {
        std::cout << "a1 equal b1" << std::endl;
    }else if (result < 0)
    {
        std::cout << "a1 less b1" << std::endl;
    }else if (result > 0)
    {
        std::cout << "a1 greater b1" << std::endl;
    }
    //C++20 字符串比较
    auto result2{ a1 <=> b1 };
    if (std::is_eq(result2))
    {
        std::cout << "a1 equal b1" << std::endl;
    }
    else if (std::is_lt(result2))
    {
        std::cout << "a1 less b1" << std::endl;
    }
    else if (std::is_gt(result2))
    {
        std::cout << "a1 greater b1" << std::endl;
    }
    return 0;
}