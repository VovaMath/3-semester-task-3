/*

� ������� Dim2_to_Dim1 ���� ���������� �������� iB �� ������ ������� �� �������,
� ����� �������� �������� � ������� �� ������� ����� ��������� ���� ��������

� ������� Dim1_to_Dim2 ��� ����� �? ���������� �������� ���������� iB � iBB,
����� �� ����� ���� ���� ������, ������ ���� ���� �� �

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

//------------------------------------------------------
void Print1(vector<int>&A)
{
    for( vector<int>::iterator it= A.begin(); it<A.end(); it++ )
        printf("%3d,", *it);
    printf("\n-------------------------\n");
}
void Print2(vector<vector<int>> &A)
{
    for( vector<vector<int>>::iterator iA=A.begin(); iA<A.end(); iA++) {
        for( vector<int>::iterator iA1= iA->begin(); iA1<iA->end(); iA1++ )
            printf("%3d,", *iA1);
        printf("\n");
    }
    printf("\n-------------------------\n");
}
//------------------------------------------------------
// �������� ��������� ������ A � ����� B

// � ������� Dim2_to_Dim1 ���� ���������� �������� iB �� ������ ������� �� �������,
// � ����� �������� �������� � ������� �� ������� ����� ��������� ���� ��������

void Dim2_to_Dim1( vector<vector<int>> &A, vector<int>&B)
{
    int my = A.size(), mx = A[0].size();        // ������� mx*my
    B.resize(mx*my);
    vector<int>::iterator iB= B.begin();
    for( vector<vector<int>>::iterator iA=A.begin(); iA<A.end(); iA++) {
        for( vector<int>::iterator iA1= iA->begin(); iA1<iA->end(); iA1++ ) {
            int offset = mx*(iA-A.begin()) + (iA1-iA->begin());
            //*iB++ = *iA1;
            *(iB+offset) = *iA1;
        }
    }
}
//------------------------------------------------------
// �� ����������� ������� A ��������� B ������� mx

// � ������� Dim1_to_Dim2 ��� ����� �? ���������� �������� ���������� iB � iBB,
// ����� �� ����� ���� ���� ������, ������ ���� ���� �� �

void Dim1_to_Dim2(vector<int>&A, vector<vector<int>> &B, int mx)
{
    int my = A.size()/mx;        // ������� �: mx*my
    vector<vector<int> >B1(my, vector<int>(mx));
    vector<vector<int>>::iterator iB=B1.begin();
    vector<int>::iterator iBB;

    for( vector<int>::iterator iA=A.begin(); iA<A.end(); iA++ ) {
        int y = (iA-A.begin())/mx;
        int x = (iA-A.begin())%mx;
        iBB = (iB+y)->begin() + x;
        *iBB = *iA;

    }
    B=B1;
}
//------------------------------------------------------
int main()
{

    // ������ 1
    // �������, ��� ��������� ������ ������� m �� n ������������� � ����������
    // ������ ������� m* n ����� ���������������� ������ �����. (m � n ������)
    // ����������� ����� �������������� ����� � ��������.
    vector<vector<int>> A = {{1,2, 4, 5}, {3,4, -1, -2}, {3,4, -1, -2}};
    vector<int> B;
    Print2(A);
    Dim2_to_Dim1(A,B);
    Print1(B);
    vector<int> A1= {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
    vector<vector<int>> B1;
    Dim1_to_Dim2(A1, B1, 5);
    Print1(A1);
    Print2(B1);

}
