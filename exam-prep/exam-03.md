# _CRT_SECURE_NO_WARNINGS in Visual Studio
За да може да използвате `strcpy` без да се оплаква компилатора:
- Right click on project -> Properties -> C/C++ -> Preprocessor 
- В Preprocessor Definitions полето добавете `;_CRT_SECURE_NO_WARNINGS`

# Число от низ ([atoi](https://cplusplus.com/reference/cstdlib/atoi/))
```c++
#include <iostream>
#include <cstring>

int main() {
    char buffer[1000] = "a123a";
    std::cout << atoi(buffer) << " " << atoi(buffer + 1) << " " << atoi(buffer + 2);
    // Output: 0 123 23

    return 0;
}
```

# Task 1
Напишете програма, която получава текст `str` и число `n`, в която всяка дума от текста се завърта `n` пъти и се извежда резултата.     
Завъртане ще наричаме действие, при което последната буква идва за първа, например "днес" завъртяно веднъж става "сдне".    
За дума считаме всяка редица от малки и главни букви, която не е прекъсната от друг символ.

```
Вход: "Dnes shte uchim mnogo, nali taka, kolegi? Kolegi? Kolegi?!?!??" 2    
Изход: "esDn tesh imuch gomno, lina kata, gikole? giKole? giKole?!?!??" 
```

```c++
#include <iostream>
#include <cstring>

const size_t MAX_SIZE = 1000;
int ptrCount = 0;

void allocate(char*& str, size_t n) {
	str = new char[n];
	ptrCount++;
}

void deallocate(char*& str) {
    delete[] str;
    str = nullptr;
	ptrCount--;
}

bool isLetter(char c) {
    return ________;
}

void rotateWord(char* str, int start, int end, int n) {
    int len = ________;
    if (len <= 1) return;

    n = n % len;
    if (n == 0) return;

    for (int i = 0; i < n; ++i) {
        char last = str[end];
        for (int j = end; j > start; --j) {
            str[j] = str[j - 1];
        }
        str[start] = last;
    }
}

void processText(char* str, int n) {
    int i = 0;
    while (str[i] != '\0') {
        if (isLetter(str[i])) {
            int start = i;
            while (________) {
                i++;
            }
            int end = ________;

            rotateWord(str, start, end, n);
        }
        else {
            i++;
        }
    }
}

int main() {
    char buffer[MAX_SIZE] = "Dnes shte uchim mnogo, nali taka, kolegi? Kolegi? Kolegi?!?!??";
    int n = 2;

    // std::cin.getline(buffer, MAX_SIZE);
    // std::cin >> n;

    char* text = nullptr;
    allocate(text, ________);
    strcpy(________);

    processText(text, n);

    std::cout << "Output: " << text << std::endl;

    return 0;
}
```

# Input & output from file in Visual Studio
- Project Properties -> Debugging
- В полето Command Arguments: `< input.txt; > output.txt`

# Task 2
Напишете програма, която въвежда от потребителя символен низ и обръща някои от думите в него.  

Програмата трябва да използва речник, който съдържа думите, които ще се обръщат. Той трябва да се представи като двумерен масив от тип `char`.  

- Когато програмата започне работа, тя трябва да въведе от потребителя броя на думите в речника. След това тя трябва да задели динамична памет за масива от думи и да въведете самите думи. Всяка дума ще е с дължина не по-голяма от `40` символа.
- Програмата трябва също да въведе от потребителя символен низ с дължина до `80` символа. Низът може да съдържа произволни символи, включително интервали и табулации. 
- Програмата трябва да обърне всички думи в низа, които се съдържат в речника. Останалите думи трябва да останат непроменени. 
- Думите в низа се разделят една от друга с един или повече празни символи (whitespace) -- интервали, табулации и т.н. 
- Завъртането трябва да стане на място в низа, без да се използва допълнителен масив.

По-долу е даден пример за работата на програмата. Забележете, че се завъртат само цели думи. Например програмата завърта низа `abc`, защото той се среща в речника, но `abcabc` трябва да остане непроменен.

```
Enter dictionary size> 4
Enter dictionary words> abc zs34 _1_2! ads
Enter a string> abcdef abc abcabc _1_2_! 34 zs34 abc
abcdef cba abcabc !_2_1_ 34 43sz cba
```
