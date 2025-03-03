#include<iostream>
#include<vector>
using namespace std;
void printPermutation(string &str, int i){
    // base case
    if(i >= str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j=i; j<str.length(); j++){
        swap(str[i], str[j]);
        // recursion will handle further
        printPermutation(str, i+1);
        swap(str[i], str[j]);
    }
}
// a fuction below that will handle all below possiblities.
// possibility
            // -> path closed  X
            // out of Bound    X
            // check is position is alredy visited or not

bool isSafe(int maze[][4],int row, int col, int scrx, int scry, int newx, int newy, vector<vector<bool>>&visited){
    if((newx>=0 && newx<row) && (newy>=0 && newy <col) && maze[newx][newy]==1 && visited[newx][newy]==false){
        return true;
    }
    else{
        return false;
    }
}

void PrintAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>>&visited){
    // base case
    // destination coordinates are [row-1], [col-1]
    if(srcx==row-1 && srcy==col-1){
        // reached Destination
        cout<<output<<endl;
        return;
    }
    // solve 1st case recursion will handle till futher
    // UP
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(maze,row, col, srcx, srcy, newx, newy, visited)){

        // mark visited
        visited[newx][newy]=true;
        // call recursion
        output.push_back('U');
        PrintAllPath(maze, row, col, newx, newy, output, visited);
        // backTracking(Unmark visited)
        output.pop_back();
        visited[newx][newy]=false;
    }
    // DOWN
    newx = srcx+1;
    newy = srcy;
    if(isSafe(maze,row, col, srcx, srcy, newx, newy, visited)){

        // mark visited
        visited[newx][newy]=true;
        // call recursion
        output.push_back('D');
        PrintAllPath(maze, row, col, newx, newy, output, visited);
        // backTracking(Unmark visited)
        output.pop_back();
        visited[newx][newy]=false;
    }
    // LEFT
    newx = srcx;
    newy = srcy-1;
    if(isSafe(maze,row, col, srcx, srcy, newx, newy, visited)){

        // mark visited
        visited[newx][newy]=true;
        // call recursion
        output.push_back('L');
        PrintAllPath(maze, row, col, newx, newy, output, visited);
        // backTracking(Unmark visited)
        output.pop_back();
        visited[newx][newy]=false;
    }
    // RIGHT
    newx = srcx;
    newy = srcy+1;
    if(isSafe(maze,row, col, srcx, srcy, newx, newy, visited)){

        // mark visited
        visited[newx][newy]=true;
        // call recursion
        output.push_back('R');
        PrintAllPath(maze, row, col, newx, newy, output, visited);
        // backTracking(Unmark visited)
        output.pop_back();
        visited[newx][newy]=false;
    }
}

int main(){
    // string str = "pqr";
    // int i = 0;
    // printPermutation(str, i);


    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";

    // create visited 2D array
vector<vector<bool>>visited(row, vector<bool>(col,false));
    if(maze[0][0]==0){
        // src position is closed, that mean rat cannot move
        cout<<"No Path Exists"<<endl; 
    }else{
        visited[srcx][srcy]  = true;
        PrintAllPath(maze, row, col, srcx, srcy, output, visited);
    }
    return 0;
}