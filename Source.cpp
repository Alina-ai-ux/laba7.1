#include <iostream>
#include <iomanip>
using namespace std;

bool Row2_greater_than_Row1(const int* Row1, const int* Row2, const int Cols)
{
    if (Row1[0] < Row2[0])
        return true;
    if (Row1[0] > Row2[0])
        return false;
    //Row1[0] == Row2[0]

    if (Row1[1] > Row2[1])
        return true;
    if (Row1[1] < Row2[1])
        return false;

    //Row1[1] == Row2[1]
    if (Row1[2] > Row2[2])
        return true;
    if (Row1[2] < Row2[2])
        return false;

    //Row1[2] == Row2[2]
    return false;
}

void print(int **  S, const int Rows, const int Cols)
{
    cout << endl;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
            cout << setw(4) << S[i][j];
        cout << endl;
    }
    cout << endl;
}
bool cond(const int S_i_j, const int i, const int j)
{
    if (S_i_j % 2 == 1 && (i + j) % 7 == 0)
        return false;
    return true;
}

int main()
{
    const int L = 9, R = 61, Rows = 7, Cols = 6;
    int **S = new int* [Rows];
    for (int i = 0; i < Rows; i++)
    {
        S[i] = new int[Cols];
        for (int j = 0; j < Cols; j++)
            S[i][j] = L + rand() % (R - L + 1);
    }
    print(S, Rows, Cols);
    for (int i0 = 0; i0 < Rows; i0++)
    {
        for (int i1 = 0; i1 < Rows - i0 - 1; i1++)
        {
            int* Row1 = S[i1];
            int* Row2 = S[i1 + 1];
            if (Row2_greater_than_Row1(Row2, Row1, Cols))
                swap(S[i1], S[i1 + 1]);
        }
    }
    print(S, Rows, Cols);
    int Count = 0, Sum = 0;
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
            if (cond(S[i][j], i, j))
            {
                Count++;
                Sum += S[i][j];
                S[i][j] = 0;
            }
    print(S, Rows, Cols);
    return 0;
}