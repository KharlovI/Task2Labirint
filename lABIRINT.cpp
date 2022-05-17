#include <iostream>
#include <ctime>
#include <cmath>
struct coordinats
{
    int ii;

    int jj;
};

void showLabirint(int** lab, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << lab[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

coordinats findExitPosition(int n, int** lab)
{
    coordinats resultat;

    resultat.ii = 0;

    resultat.jj = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lab[i][j] == 3)
            {
                resultat.ii = i;

                resultat.jj = j;

                return resultat;
            }
        }
    }
    return resultat;
}

void goToFinish(int n, int** lab, coordinats position, int** buffer, int pointer)
{
    if (position.ii != 0 && (lab[position.ii - 1][position.jj] == 1 || lab[position.ii - 1][position.jj] == 2))
    {
        buffer[pointer][0] = position.ii - 1;

        buffer[pointer][1] = position.jj;

        if (lab[position.ii - 1][position.jj] == 2)
        {
            for (int i = 0; (buffer[i][0] != buffer[i + 1][0] || buffer[i][1] != buffer[i + 1][1]) && i < pow(n,2); i++)
            {
                std::cout << buffer[i][0] << " " << buffer[i][1] << '\t';
            }

            std::cout << std::endl;

            return;
        }

        else
        {
            position.ii -= 1;

            lab[position.ii][position.jj] = 0;

            goToFinish(n, lab, position, buffer, ++pointer);

            position.ii += 1;

            buffer[pointer][0] = 0;

            buffer[pointer][1] = 0;

            pointer--;
        }
    }

    if (position.jj != 0 && (lab[position.ii][position.jj - 1] == 1 || lab[position.ii][position.jj - 1] == 2))
    {
        buffer[pointer][0] = position.ii;

        buffer[pointer][1] = position.jj - 1;
       
            if (lab[position.ii][position.jj-1] == 2)
            {
                    for (int i = 0; (buffer[i][0] != buffer[i + 1][0] || buffer[i][1] != buffer[i + 1][1]) && i < pow(n, 2); i++)
                    {
                        std::cout << buffer[i][0] << " " << buffer[i][1] << '\t';
                    }

                    std::cout << std::endl;

                return;
            }

            else
            {
                position.jj -= 1;

                lab[position.ii][position.jj] = 0;

                goToFinish(n, lab, position, buffer, ++pointer);

                position.jj += 1;

                buffer[pointer][0] = 0;

                buffer[pointer][1] = 0;

                pointer--;
            }
    }

    if (position.ii != n-1 && (lab[position.ii + 1][position.jj] == 1 || lab[position.ii + 1][position.jj] == 2))
    {
        buffer[pointer][0] = (position.ii + 1);

        buffer[pointer][1] = position.jj;

        if (lab[position.ii + 1][position.jj] == 2)
        {
            for (int i = 0; (buffer[i][0] != buffer[i + 1][0] || buffer[i][1] != buffer[i + 1][1]) && i < pow(n, 2); i++)
            {
                std::cout << buffer[i][0] << " " << buffer[i][1] << '\t';
            }

            std::cout << std::endl;

            return;
        }
        
        else
        {
            position.ii += 1;

            lab[position.ii][position.jj] = 0;

            goToFinish(n, lab, position, buffer, ++pointer);

            position.ii -= 1;

            buffer[pointer][0] = 0;

            buffer[pointer][1] = 0;

            pointer--;
        }
    }

    if (position.jj != n - 1 && (lab[position.ii][position.jj + 1] == 1 || lab[position.ii][position.jj + 1] == 2))
    {
        buffer[pointer][0] = position.ii;

        buffer[pointer][1] = (position.jj + 1);

        if (lab[position.ii][position.jj + 1] == 2)
        {
            std::cout << std::endl;

            for (int i = 0; (buffer[i][0] != buffer[i + 1][0] || buffer[i][1] != buffer[i + 1][1]) && i < pow(n, 2); i++)
            {
                std::cout << buffer[i][0] << " " << buffer[i][1] << '\t';
            }

            std::cout << std::endl;

            return;
        }

        else
        {
            position.jj += 1;

            lab[position.ii][position.jj] = 0;

            goToFinish(n, lab, position, buffer, ++pointer);

            position.jj -= 1;

            buffer[pointer][0] = 0;

            buffer[pointer][1] = 0;

            pointer--;
        }
    }

    /*buffer[pointer][0] = 0;

    buffer[pointer][1] = 0;*/
    return;
}

void creatLabirintAndFindWay(int n)
{    
    int** lab = new int*[n];

    int size = pow(n, 2);

    int** buffer = new int*[size];

    for (int i = 0; i < n; i++)
    {
        lab[i] = new int[n];
    }

    for (int i = 0; i < size; i++)
    {
        buffer[i] = new int[2];

        buffer[i][0] = 0;

        buffer[i][1] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lab[i][j] = rand() % 2;
        }
    }

    lab[rand()% (n - 1)][rand() % (n - 1)] = 2;

    int a = rand() % (n - 1);

    int b = rand() % (n - 1);

    while (true)
    {
        if (lab[a][b] != 2)
        {
            lab[a][b] = 3;

            break;
        }

        a = rand() % (n - 1);

        b = rand() % (n - 1);
    }
    coordinats position;

    position = findExitPosition(n, lab);

    showLabirint(lab, n);

    goToFinish(n, lab, position, buffer, 0);
}

int main()
{
    srand(time(0));

    int n = rand() % 25 + 3;

    creatLabirintAndFindWay(n);

    return 0;
}


