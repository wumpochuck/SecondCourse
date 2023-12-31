/*
Составить программу для игры в “кости”. Играющий называет любое число в диапазоне 
от 2 до 12 и ставку, которую он делает в этот ход. Программа с помощью генератора случайных 
чисел дважды выбирает числа от 1 до 6 (“бросает кубик”, на гранях которого цифры от 1 до 6). 
Если сумма выпавших очков меньше либо равна 7 и играющий назвал число меньше либо равное 7, 
он выигрывает ставку. Если сумма выпавших цифр больше 7 и играющий сделал ставку на число 
больше 7, он также выигрывает ставку. Если игрок угадал сумму цифр, он получает в 4 раза 
больше очков, чем сделанная ставка. Ставка проиграна, если ни одна из описанных ситуаций 
не имеет места. В начальный момент у игрока и компьютера по 100 очков. Игра идет до тех пор, 
пока у кого-либо из играющих останется 0 очков.  
*/

#include <iostream>
#include <time.h>
// #include <cmath>
#include <stdlib.h>

using namespace std;

// Формула для генератора от m до n
// num = m + rand() % (n - m + 1);

int main(){
    setlocale(LC_ALL,"rus");
    time_t t;
    srand(time(&t));

    int n, stavka;
    int userPoints = 100;
    int pcPoints = 100;
    
    int dice;

    cout << "[Task 4]" << endl; 

    while (userPoints > 0 && pcPoints > 0)
    {
        // Выбираем число
        cout << "\nВведите число от 2ух до 12ти: "; cin >> n;  
        while (n < 2 || n > 12) {cout << "Неверное число, попробуйте еще раз: "; cin >> n; }

        // Делаем ставку
        cout << "Сделайте ставку: "; cin >> stavka;
        while (stavka <= 0 || stavka > userPoints) {cout << "Неверная ставка, введите повторно: "; cin >> stavka; }
        
        // Генерация чисел на костях
        dice = int(2 + rand() %(12 - 2 + 1));

        cout << "\nНа костях выпало число " << dice << endl;

        // Проверка победы
        if (dice == n) {cout << "\nВы выйграли: "<< stavka * 4 <<" очков"; userPoints += stavka * 4; pcPoints -= stavka;}
        else if (dice <= 7 && n <= 7 || dice > 7 && n > 7 ) {cout << "\nВы выйграли: "<< stavka <<" очков"; userPoints += stavka;pcPoints -= stavka;}
        else {cout << "\nВы проиграли: "<< stavka <<" очков"; userPoints -= stavka; pcPoints += stavka;}

        cout << "\n\nВаши очки: " << userPoints << "\nОчки компьютера: "<< pcPoints;
        
        cout << "\n\n\n";
    }
    
    if (pcPoints > userPoints) {cout << "Компьютер победил\n";}
    else {cout << "Вы победили\n";}

}