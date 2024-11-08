#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


int main()
{
    ifstream file("str.txt");

    struct car
    {
        string name;//название
        string model;//модель
        string color;//цвет
        int speed; //лошадиные  силы(среднее)
        string type; // механика или автомат

    };

    vector<car> myCar;
    car cars;

    if(!file.is_open()) //проверка открыт ли файл
    {
        cout << "no open" << endl;
        return 1;
    }

    while(!file.eof())
    {
        file >> cars.name >> cars.model >> cars.color >> cars.speed >> cars.type; //добавление информации из файла в экземпляры вектора
        myCar.push_back(cars);
    }
    file.close();//закрытие файла
    myCar.pop_back(); //удаляет лишний элемент из вектора

     string help_string(64, '_');//для красоты добавление палочек
    //3 пункт - создание таблицы в терминале
    cout << "|" << help_string << "|" << endl;
    cout << "|" << setw(12) << "Name" << "|" << setw(12) << "Model"
         << "|" << setw(12) << "Color" << "|" << setw(12) << "Speed"
         << "|" << setw(12) << "Type" << "|" << endl;
    cout << "|" << help_string << "|" << endl;
    for (auto car : myCar) {
        cout << "|" << setw(12) << car.name << "|" << setw(12) << car.model
             << "|" << setw(12) << car.color << "|" << setw(12) << car.speed
             << "|" << setw(12) << car.type << "|" << endl;
    }
    cout << "|" << help_string << "|" << endl;
    //4 пункт - создание широкой строки
    stringstream ss;
    for (const auto& car : myCar) {
        ss << "Name: " << car.name << endl;
        ss << "Model: " << car.model << endl;
        ss << "Color: " << car.color << endl;
        ss << "Speed: " << car.speed << endl;
        ss << "Type: " << car.type << endl << endl;
    }

    //вывод строки ss для проверки
    string s2 = ss.str();
    cout << "\n" << s2 << endl;

    //5 пункт - записаь в файл строки
    ofstream outputFile("cars_output.txt", ios::binary);
    string str = ss.str();
    outputFile.write(str.c_str(), str.length());
    outputFile.close();

    return 0;
}
