#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void printArray(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printArrayRowWise(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printArrayColWise(int arr[][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool searchElement(int arr[3][3], int row, int col, int n){
    int target = n;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if (arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
void printMax(int arr[3][3], int row, int col){
    int maxAns = INT_MIN;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if (arr[i][j]>maxAns){
                maxAns=arr[i][j];
            }
        }
    }
    cout<<"Maximum is : "<<maxAns<<endl; 
}
void printMin(int arr[3][3], int row, int col){
    int minAns = INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if (arr[i][j]<minAns){
                minAns=arr[i][j];
            }
        }
    }
    cout<<"Minimum is : "<<minAns<<endl; 
}
void rowWiseSum(int arr[3][4], int row, int col){
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            // cout<<"row index : "<<i<<" column index : "<<j<<" with element : "<<arr[i][j]<<endl;
            sum = sum + arr[i][j];
            // cout<<"sum is : "<<sum<<endl;
        }
        cout<<"sum of row "<<i+1<<" is : "<<sum<<endl;
    }
}
void colWiseSum(int arr[3][4], int row, int col){
    for(int i=0; i<col; i++){
        int sum = 0;
        for(int j=0; j<row; j++){
            sum = sum + arr[j][i];
        }
        cout<<"sum of col "<<i+1<<" is : "<<sum<<endl;
    }
}
void printDiagonal(int arr[4][4], int row, int col){
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         if(arr[i][j]==arr[j][i]){
    //             cout<<arr[i][j]<<endl;
    //         }
    //     }
    // }

                //  OR (Easy and useful method)

    for(int i=0; i<row; i++){
        cout<<arr[i][i]<<endl;
    }
}

void printSumDiagonally(int arr[4][4], int row, int col){
    // int sum = 0;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         if(arr[i][j]==arr[j][i]){
    //             sum = sum + arr[i][j];
    //         }
    //     }
    // }
    // cout<<"Sum of Diagonal elements is "<<sum<<endl;

                // OR  (Easy and useful method)
                
    int sum = 0;
    for(int i=0; i<row; i++){
        sum = sum + arr[i][i];
    }
    cout<<"Sum of Diagonal elements is "<<sum<<endl;   
}
void transpose(int arr[3][3], int row, int col){
    // for(int i=0; i<col; i++){
    //     for(int j=0; j<row; j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

                // By Swapping

    for(int i=0; i<row; i++){
        for(int j=i; j<col; j++){
            swap(arr[i][j], arr[j][i]);
            
        }
    }

}
void printArray1(int arr[3][3], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    // // // 2-D Array

    

    // int arr[100][1000];
    // int arr2[4][5] = {{10,20,30,40,50},{20,30,40,50,60},{30,40,50,60,70},{40,50,60,70,80}};
    // int arr3[4][3] = {{10,20,30},{1,2,3},{4,6,8},{5,7,9}};   
    // cout<<arr3[1][2];

    

    // int arr[3][4] = {
    //                 {1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,1,11}
    //                 };

    // int row = 3;
    // int col = 4;
    // printArray(arr, row, col);

    // // Print 2D Array Row Wise 

    // int arr[3][3];

    // int row = 3;
    // int col = 3;

    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<"Enter the input for row index : "<<i<<" column index : "<<j<<endl;
    //         cin>>arr[i][j];
    //     }
    // }
    // printArrayRowWise(arr, row, col);

    // // Print 2D Array column Wise 

    // int arr[3][3];

    // int row = 3;
    // int col = 3;

    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<"Enter the input for row index : "<<i<<" column index : "<<j<<endl;
    //         cin>>arr[j][i];
    //     }
    // }
    // printArrayColWise(arr, row, col);

    // // Searching an element occur in the 2D array or not.

    // int arr[3][3]= {{10,20,30},
    //                 {40,50,60},
    //                 {70,80,90}
    //                 };

    // int row = 3;
    // int col = 3;
    // int n;
    // cin>>n;

    // bool ans = searchElement(arr, row, col, n);
    // // cout<<ans<<endl;
    // if(ans==1){
    //     cout<<"True"<<endl;
    // }else{ 
    //     cout<<"False"<<endl;
    // }

    // // Maximum number of an 2D Array

    // int arr[3][3]= {{10,20,30},
    //                 {40,50,60},
    //                 {70,80,90}
    //                 };

    // int row = 3;
    // int col = 3;
    // printMax(arr, row, col);

    // // Minimum number of an 2D Array

    // int arr[3][3]= {{10,20,30},
    //                 {40,50,60},
    //                 {70,80,90}
    //                 };

    // int row = 3;
    // int col = 3;
    // printMin(arr, row, col);

    // // Row-wise Summation

    // int arr[3][4]= {{10,20,5,7},
    //                 {2,4,6,8},
    //                 {10,15,15,10}
    //                 };

    // int row = 3;
    // int col = 4;
    // rowWiseSum(arr, row, col);

    // // Column-wise Summation

    // int arr[3][4]= {{10,20,5,7},
    //                 {2,4,6,8},
    //                 {10,15,15,10}
    //                 };

    // int row = 3;
    // int col = 4;
    // colWiseSum(arr, row, col);

    // // print Diagonal Elements

    // int arr[4][4] = {
    //                 {1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,11,12},
    //                 {13,14,15,16}
    //                 };

    // int row = 4;
    // int col = 4;
    // printDiagonal(arr, row, col);

    // // print the Sum of Diagonal elements

    // int arr[4][4] = {
    //                 {1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,11,12},
    //                 {13,14,15,16}
    //                 };

    // int row = 4;
    // int col = 4;
    // printSumDiagonally(arr, row, col);

    // // Transpose of a Matrix

    // int arr[3][3]= {{2,4,6},
    //                 {8,3,5},
    //                 {7,9,1}
    //                 };

    // int row = 3;
    // int col = 3;
    // // transpose(arr, row, col);

    // cout<<"Before Transpose :"<<endl;
    // printArray1(arr, row, col);
    // transpose(arr, row, col);
    // cout<<"After Transpose :"<<endl;
    // printArray1(arr, row, col);


    // // // 2D Vector

    // 1D vector 

    // int arr[5];
    // // vector<int> v(5);
    // vector<int> v(5,-2);

    // cout<<"Size of vector : "<<v.size()<<endl;
    // cout<<"Printing vector "<<endl;
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    // vector <int> arr;

    // arr.push_back(4);
    // arr.push_back(8);
    // arr.push_back(12);
    // arr.push_back(11);
    // arr.push_back(4);

    // cout<<arr.size()<<endl;

    // for(int i=0; i<arr.size(); i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // vector< vector<int> > arr(5, vector<int>(10,0));
    // // row size -> arr.size()
    // for(int i=0; i<arr.size(); i++){
    //     for(int j=0; j<arr[i].size(); j++){
    //         cout<< arr[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }

    vector< vector<int> > brr;

    vector<int> vec1(10, 0);
    vector<int> vec2(5, 1);
    vector<int> vec3(7, 0);
    vector<int> vec4(8, 1);
    vector<int> vec5(20, 0);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for(int i=0; i<brr.size(); i++){
        for(int j=0; j<brr[i].size(); j++){
            cout<<brr[i][j]<< " ";
        }
        cout<<endl;
    }



    return 0;
}