# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <time.h>
# include <cmath>
# include <stdio.h>

void subtraction()
{   
    std::cout << "Answer as many questions in 60 seconds!" << std::endl;
    time_t timeStart = clock();
    int count = 0;
    while(true)
    {
        if((clock() - timeStart) / CLOCKS_PER_SEC >= 60)
        {   
            std::cout << "Score: " << count << std::endl;
            break;
        }
        
        //ensure subtraction is more than 0
        int random = rand() % 100 + 2;
        int random2 = rand() % 100 + 2;
        int add = random + random2;
        int add2 = add - random2;
        std::cout << add << " - " << random2 << std::endl;
        
        while(true)
        {
            std::string ans_input;
            int ans;
            std::getline(std::cin, ans_input);
            std::stringstream(ans_input) >> ans;

            if(ans == add2)
            {
                count++;
                break;
            }
        }
    }
}

void addition()
{   
    std::cout << "Answer as many questions in 60 seconds!" << std::endl;
    time_t timeStart = clock();
    int count = 0;
    
    while(true)
    {
        if((clock() - timeStart) / CLOCKS_PER_SEC >= 60)
        {   
            std::cout << "Score: " << count << std::endl;
            break;
        }
        
        int random = rand() % 100 + 2;
        int random2 = rand() % 100 + 2;
        std::cout << random << " + " << random2 << std::endl;
        
        while(true)
        {
            std::string ans_input;
            int ans;
            std::getline(std::cin, ans_input);
            std::stringstream(ans_input) >> ans;

            if(ans == random + random2)
            {
                count++;
                break;
            }
        }
    }
}

void division()
{   
    int range;
    std::cout << "Enter Division range: ";
    while(!(std::cin >> range)) //While loop catch user string input error
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Invalid input! Try again: ";
    }
    while(range < 2) //while loop ensure input is more than 1
    {
        std::cin.clear();
        std::cout << "Range must be more than 2! Try again: ";
        while(!(std::cin >> range))
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input! Try again: ";
        }
    }
    int range1 = range - 1;
    std::cout << "Answer as many questions in 60 seconds!" << std::endl;
    time_t timeStart = clock();
    int count = 0;
    while(true)
    {
        if((clock() - timeStart) / CLOCKS_PER_SEC >= 60)
        {   
            std::cout << "Score: " << count << std::endl;
            break;
        }
        //ensure division is a whole number and numerator > denominator
        int random = rand() % range1 + 2; 
        int random2 = rand() % range1 + 2;
        int multi = random * random2;
        int multi2 = multi / random2;
        std::cout << multi << " / " << random2 << std::endl;
        
        while(true)
        {
            std::string ans_input;
            int ans;
            std::getline(std::cin, ans_input);
            std::stringstream(ans_input) >> ans;

            if(ans == multi2)
            {
                count++;
                break;
            }
        }
    }
}

void multiplication()
{   
    int range;
    std::cout << "Enter Multiplication range: ";
    while(!(std::cin >> range)) //While loop to catch user string input error
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Invalid input! Try again: ";
    }
    while(range < 2) //while loop ensure input is more than 1
    {
        std::cin.clear();
        std::cout << "Range must be more than 2! Try again: ";
        while(!(std::cin >> range))
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input! Try again: ";
        }
    }
    int range1 = range - 1;
    std::cout << "Answer as many questions in 60 seconds!" << std::endl;
    time_t timeStart = clock();
    int count = 0;
    
    while(true)
    {
        if((clock() - timeStart) / CLOCKS_PER_SEC >= 60)
        {   
            std::cout << "Score: " << count << std::endl;
            break;
        }
        
        int random = rand() % range1 + 2;
        int random2 = rand() % range1 + 2;
        std::cout << random << " x " << random2 << std::endl;
        
        while(true)
        {
            std::string ans_input;
            int ans;
            std::getline(std::cin, ans_input);
            std::stringstream(ans_input) >> ans;

            if(ans == random * random2)
            {
                count++;
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int choice;

    do
    {
        std::cout << "0. Quit\n" << "1. Practice Multipplication\n" << "2. Practice Division\n" << "3. Practice Addition\n" << "4. Practice Subtraction" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
            case 0:
                std::cout << "Come again later!\n";
                return 0;
            case 1:
                multiplication();
                break;
            case 2:
                division();
                break;
            case 3:
                addition();
                break;
            case 4:
                subtraction();
                break;
        }
    } 
    while (choice != 0);
    
}