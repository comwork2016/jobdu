/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    //判断数独是否能放在此处
    bool isPlaceOK(vector<vector<char>> board,int row,int col)
    {
        for(int i=0; i<board[row].size(); i++) // check row duplicated
        {
            if(col != i && board[row][col] == board[row][i])
            {
                return false;
            }
        }
        for(int i=0; i<board.size(); i++) // check col duplicated
        {
            if(i != row && board[row][col] == board[i][col])
            {
                return false;
            }
        }
        // check small square duplicated
        int range = (row/3)*3 + col/3;
        int rangeRowStart = range/3 * 3;
        int rangeColStart = range%3 * 3;
        for(int i=rangeRowStart; i<rangeRowStart+3; i++)
        {
            for(int j=rangeColStart; j<rangeColStart+3; j++)
            {
                if(i !=row && j !=col && board[row][col] == board[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    void helper(int curRow,int curCol,vector<vector<char>>& board)
    {
        if(curRow == 9)//fill down
        {
            printBoard(board);
            return;
        }
        if(board[curRow][curCol] != '.')
        {
            if(curCol==8)
            {
                helper(curRow+1,0,board);
            }else
            {
                helper(curRow,curCol+1,board);
            }
            return;
        }
        char nums[9] = {'1','2','3','4','5','6','7','8','9'};
        for(int i=0;i<9;i++)
        {
            board[curRow][curCol] = nums[i];
            if(isPlaceOK(board,curRow,curCol))
            {
                if(curCol==8)
                {
                    helper(curRow+1,0,board);
                }else
                {
                    helper(curRow,curCol+1,board);
                }
            }
            board[curRow][curCol] = '.';
        }
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        helper(0,0,board);
    }

    void printBoard(const vector<vector<char>>& board)
    {
        for(int row=0; row<board.size(); row++)
        {
            if(row > 0 &&row%3==0)
            {
                cout <<"---------------------"<<endl;
            }
            for(int col=0; col<board[row].size(); col++)
            {
                if(col > 0 && col%3 == 0)
                {
                    cout<<"|"<<" ";
                }
                cout<<board[row][col]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution* s = new Solution();
    vector<string> vec_Str = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char>> board;
    for(int i = 0; i<vec_Str.size(); i++)
    {
        vector<char> vec_char;
        string str_Row = vec_Str[i];
        for(int i=0; i<str_Row.length(); i++)
        {
            vec_char.push_back(str_Row[i]);
        }
        board.push_back(vec_char);
    }
    s->solveSudoku(board);
    //s->printBoard(board);
    delete s;
    return 0;
}
