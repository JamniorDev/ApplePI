// KOLOROWY TEKST - UZYWAMY

//     cout << "Zwykły tekst, ";
//     cout << "\033[31mto jest czerwone\033[0m, ";
//     cout << "\033[32ma to zielone.\033[0m\n";
/*

65x24
|---------------------------[ApplePI]---------------------------|
|                                                      0 1      |
|                                               0 -> [ * * ] <- |
|                                               1    [ * * ]    |
|                                               2    [ * * ]    |
|                                               3    [ * * ]    |
|                                               4    [ * * ]    |
|                                               5    [ * * ]    |
|                                               6    [ * * ]    |
|                                               7    [ * * ]    |
|                                               8    [ * * ]    |
|                                               9    [ * * ]    |
|                                              10    [ * * ]    |
|                                              11    [ * * ]    |
|                                              12    [ * * ]    |
|                                              13    [ * * ]    |
|                                              14    [ * * ]    |
|                                              15    [ * * ]    |
|                                              16    [ * * ]    |
|                                              17    [ * * ]    |
|                                              18    [ * * ]    |
|                                              19    [ * * ]    |
|                                              20    [ * * ]    |
|                                                               |
|---------------------------------------------------------------|
*/

#include <iostream>

struct Character
{
    char symbol;
    std::string colorCode;
};

int main()
{
    //----------------[INIT]----------------
    const std::size_t X = 65, Y = 24;
    Character tab[Y][X];

    for(std::size_t i = 0; i < Y; i++)
    {
        for(std::size_t j = 0; j < X; j++)
        {
            //  && i > 31 && i < 37
            if(j == 0 || j == X-1)
                tab[i][j] = { '|', "\033[0m" };
            else if(i == 0 || i == Y-1)
                tab[i][j] = { '-', "\033[0m" };
            else if(j == 54 && i != 1 && i != Y-2)
                tab[i][j] = { '[', "\033[0m" };
            else if(j == 60 && i != 1 && i != Y-2)
                tab[i][j] = { ']', "\033[0m" };
            else
                tab[i][j] = { ' ', "\033[0m" };

            if(i == 0 && j == 29)
                tab[i][j] = { 'A', "\033[34m" };
            else if(i == 0 && j == 30 || i == 0 && j == 31)
                tab[i][j] = { 'p', "\033[34m" };
            else if(i == 0 && j == 32)
                tab[i][j] = { 'l', "\033[34m" };
            else if(i == 0 && j == 33)
                tab[i][j] = { 'e', "\033[34m" };
            else if(i == 0 && j == 34)
                tab[i][j] = { 'P', "\033[34m" };
            else if(i == 0 && j == 35)
                tab[i][j] = { 'I', "\033[34m" };
            else if(i == 0 && j == 28)
                tab[i][j] = { '[', "\033[0m" };
            else if(i == 0 && j == 36)
                tab[i][j] = { ']', "\033[0m" };

        }
    }
    
    //----------------[DISPLAY]----------------

    for(std::size_t i = 0; i < Y; i++)
    {
        for(std::size_t j = 0; j < X; j++)
        {
            std::cout << tab[i][j].colorCode << tab[i][j].symbol << "\033[0m";
        }
        std::cout << "\n";
    }
}