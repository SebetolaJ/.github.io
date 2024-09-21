#include <iostream>
#include <vector>
using namespace std;

bool bValidate(vector<vector<char>> &Sudoku,int iCol,int iRow,char iNum){               

int iSize=9;
for (int i=0;i<iSize;i=i+1){                 
    if (Sudoku[iRow][i]==iNum){
        return false;
    }
}

for (int j=0;j<iSize;j=j+1){                
    if (Sudoku[j][iCol]==iNum){
        return false;
    }
}

int subRow=iRow-iRow%3;               
int subCol=iCol-iCol%3;

for (int z=0;z<3;z=z+1){                            
    for (int w=0;w<3;w=w+1){
        if (Sudoku[z+subRow][w+subCol]==iNum){
            return false;
        }
    }
}
return true;
}

bool EmptyCell(vector<vector<char>>&Sudoku,int &iRow,int &iCol){
int iSize=9;
 for (int i = 0; i < iSize; i=i+1) {
        for (int j = 0; j < iSize; j=j+1) {
            if (Sudoku[i][j] == 0) {
                iRow = i;
                iCol = j;
                return true;;
    }
}
}
return false;
}
bool Solve(vector<vector<char>>&Sudoku){
    int iRow,iCol;
    int iSize=9;
    int iEl;
    vector<char>vNum={'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

if (EmptyCell(Sudoku,iRow,iCol)==false){
    return true;
}
for (auto i:vNum){
    int iEl=i;
        if (bValidate(Sudoku,iCol,iRow,iEl)==true){      
            Sudoku[iRow][iCol]=iEl;
            if (Solve(Sudoku)){   
                return true;
            }
                Sudoku[iRow][iCol]=0;
        }
    }
            
    
return false;
}

int main(){
    int iRow=9;
    int iCol=9;
    int n;
   
vector<vector<char>>vNumbers(iRow,vector<char>(iCol,'0'));

for (int i=0;i<iRow;i=i+1){
    for (int j=0;j<iCol;j=j+1){
        cin>>n;
        vNumbers[i][j]=n;
    }
}
//prints the solved Sudoku
if (Solve(vNumbers)){
     for (int i=0;i<iRow;i=i+1){
        for (int j=0;j<iCol;j=j+1){
            cout<<vNumbers[i][j]<<" ";
        }
            cout<<endl;
     }
}

else{
    cout<<"No Solution"<<endl;
}

    return 0;

}

