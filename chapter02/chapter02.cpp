#include <iostream>
#include<string>

int main()
{
    //ԭʼ�ַ�������ֵ
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

    //C++ �ַ���
    //c �ַ����Ƚ�
    const char* a = "hello";        //�����޸�
    char b[] = "hello";             //�����޸�
    //b[0] = 'a';
    //�Ƚϵ����ַ�ָ��
    if (a == b)         
    {
        std::cout << "a == b" << std::endl;
    }
    //C�ַ����Ƚ�
    if (strcmp(a, b) == 0)
    {
        std::cout << "a == b" << std::endl;
    }
    //stl C++ �ַ���
    std::string a1("hello");
    std::string b1("hello");
    //���ַ�����ȱ��:compate ����ֵ�� int �����׼���ȽϽ�� ʹ���������鷳
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
    //C++20 �ַ����Ƚ�
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