#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
std::string VectorIntInString(std::vector<int> vect) {
    std::string str;
    for (auto i : vect)
        str += char(i + '0');
    return str;
}
std::vector<int> StringToVectorInt(std::string str) {
    std::vector<int> vect;
    for (auto i : str)
        vect.push_back(int(i - '0'));
    return vect;
}
std::string sum(std::vector<int> a, std::vector<int> b) {
    std::string result;
    int length = max(a.size(), b.size());
    while (a.size() < length) a.emplace(a.begin(), 0);
    while (b.size() < length) b.emplace(b.begin(), 0);
    for (int i = length - 1; i >= 0; i--)
    {
        if (b[i] + a[i] > 9) {
            b[i] += a[i];// суммируем последние разряды чисел
            if (i - 1 < 0) {
                b.emplace(b.begin(), b[i] / 10);
                b[i + 1] %= 10;
            }
            else
                b[i - 1] += (b[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
            b[i] %= 10; // если есть разряд для переноса он отсекается
        }
        else
            b[i] += a[i];
    }
    result = VectorIntInString(b);
    return result;
}

int main() {
	
    

    std::string str = ("111111111111111111111111111111111111111111111111111111111111111111111");
	std::cout << sum(StringToVectorInt(str), StringToVectorInt("9999999999999999999999999999999999999999999999999999")) << std::endl;
    system("pause");

}