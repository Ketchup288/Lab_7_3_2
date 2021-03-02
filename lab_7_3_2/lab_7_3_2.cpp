#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void New_Matrix(int** a, int** b, const int rowCount, const int colCount);
int Sum_Mtrx(int** b, const int rowCount);


int main()
{
    /*
    srand((unsigned)time(NULL));
    int Low = -100;
    int High = -1;
        */

    int n;
    cout << "n = "; cin >> n;
    int rowCount = n, colCount = n; // Матриця n x n


    int** a = new int* [rowCount];
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        a[rowNo] = new int[colCount];

    //Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int** b = new int* [rowCount];
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        b[rowNo] = new int[colCount];

    New_Matrix(a, b, rowCount, colCount);
    Print(b, rowCount, colCount);

    int sum = Sum_Mtrx(b, rowCount);

    cout << "sum (modul) = " << sum << endl;

    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        delete[] a[rowNo];
    delete[] a;

    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        delete[] b[rowNo];
    delete[] b;

    return 0;
}


/*
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        for (int colNo = 0; colNo < colCount; colNo++)
            a[rowNo][colNo] = Low + rand() % (High - Low + 1);
}
*/




void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}




void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
    {
        for (int colNo = 0; colNo < colCount; colNo++)
            cout << setw(4) << a[rowNo][colNo];
        cout << endl;
    }
    cout << endl;
}





void New_Matrix(int** a, int** b, const int rowCount, const int colCount)
{

    for (int rowNo = 0; rowNo < rowCount; rowNo++) {
        for (int colNo = 0; colNo < colCount; colNo++)
        {
            int tmp = a[rowNo][colNo]; int col = 1; // добавляє до розрахунків сам елемент
            if (rowNo > 0)  // далі поетапна перевірка кожної з позицій навколо елемента
            {
                tmp += a[rowNo - 1][colNo];
                col++;
                if (colNo > 0)
                {
                    tmp += a[rowNo - 1][colNo - 1];
                    col++;
                }
                if (colNo < colCount - 1)
                {
                    tmp += a[rowNo - 1][colNo + 1];
                    col++;
                }
            }
            if (rowNo < rowCount - 1)
            {
                tmp += a[rowNo + 1][colNo];
                col++;
                if (colNo > 0)
                {
                    tmp += a[rowNo + 1][colNo - 1];
                    col++;
                }
                if (colNo < colCount - 1)
                {
                    tmp += a[rowNo + 1][colNo + 1];
                    col++;
                }
            }
            if (colNo > 0)
            {
                tmp += a[rowNo][colNo - 1];
                col++;
            }
            if (colNo < colCount - 1)
            {
                tmp += a[rowNo][colNo + 1];
                col++;
            }
            b[rowNo][colNo] = tmp / col;
        }
    }
}


int Sum_Mtrx(int** b, const int rowCount) { 
    int sum = 0;
    for (int rowNo = 1; rowNo < rowCount; rowNo++) 
        for (int colNo = 0; colNo < rowNo; colNo++) // визначення суми модулів елементів, розташованих нижче від головної діагоналі
            sum += abs(b[rowNo][colNo]); 
    return sum;
}