#include <iostream>
#include <string>
#include <format>

std::string_view extractExtension(std::string_view filename)
{
    return filename.substr(filename.rfind('.'));
}

void handleExtension(const std::string& extension)
{
    std::cout << extension << std::endl;
}

int main()
{
    /***************************ԭʼ�ַ�������ֵ***************************************/
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

    /***************************C++ �ַ���***************************************/
    //c �ַ����Ƚ�
    const char* a = "hello";        //�����޸�
    char b[] = "hello";             //�����޸�
    //b[0] = 'a';
    //�Ƚϵ����ַ�ָ��
    if (a == b)         
    {
        std::cout << "a == b" << std::endl;
    }
    /***************************C�ַ����Ƚ�***************************************/
    if (strcmp(a, b) == 0)
    {
        std::cout << "a == b" << std::endl;
    }
    /***************************stl C++ �ַ���***************************************/
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
    /***************************C++20 �ַ����Ƚ�***************************************/
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

    /***************************��ȡ�ַ���ָ��***************************************/
    auto pChar1 = a1.c_str();
    auto pChar2 = a1.data();
    std::cout << pChar1 << std::endl;
    std::cout << pChar2 << std::endl;

    /***************************find substr replace starts_with ends_with***************************************/
    std::string strHello{ "Hello!!" };
    std::string strWorld{ "The World..." };
    auto position{ strHello.find("!!") };
    if (position != std::string::npos) {
        // Found the "!!" substring, now replace it.
        strHello.replace(position, 2, strWorld.substr(3, 6));
    }
    std::cout << strHello << std::endl;

    bool bStart = strHello.starts_with("Hel");
    std::cout << bStart << std::endl;
    bool bEnd = strHello.ends_with("d");
    std::cout << bEnd << std::endl;

    /***************************��ֵת�ַ���***************************************/
    long double d{ 3.14L };
    std::string strD{ std::to_string(d) };
    std::cout << strD << std::endl;

    /***************************�ַ���ת��ֵ***************************************/
    const std::string toParse{ "123USD232" };
    size_t index{ 0 };
    int value{ stoi(toParse, &index) };

    std::cout << std::format("�ַ���ת��ֵ��{}", value) << std::endl;
    std::cout << std::format("��һ������ת�����ַ���{}", toParse[index]) << std::endl;
    
    /***************************string_view***************************************/
    std::string filename{ R"(c:\temp\my file.ext)" };
    std::cout << format("C++ string: {}", extractExtension(filename)) << std::endl;
    const char* cString{ R"(c:\temp\my file.ext)" };
    std::cout << format("C string: {}", extractExtension(cString)) << std::endl;
    std::cout << format("Literal: {}", extractExtension(R"(c:\temp\my file.ext)")) << std::endl;

    const char* raw{ "hfdskfd" };
    size_t length{ 3 };
    std::string_view stringView(raw, length);
    std::cout << stringView << std::endl;

    /***************************string_view �� string***************************************/
    //handleExtension(extractExtension("my file.ext")); //error
    handleExtension(extractExtension("my file.ext").data()); // data() method
    handleExtension(std::string{ extractExtension("my file.ext") }); // explicit ctor

    std::string str{ "Hello" };
    std::string_view sv{ " world" };
    //auto result{ str + sv };   //error
    auto result1{ str + sv.data() };
    std::string result22{ str };
    result22.append(sv.data(), sv.size());

    std::string sss{ "Hello" };
    //std::string_view svsss{ sss + " World!" };      //error
    //std::cout << svsss << std::endl;

    return 0;
}