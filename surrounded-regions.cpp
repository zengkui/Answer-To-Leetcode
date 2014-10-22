#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class node_t
{
    public:
        int r;
        int c;
    public:
        node_t(){}
        node_t(int _r, int _c) : r(_r), c(_c){}
};

node_t q[1<<20];
class Solution {
    private:
        int _R;
        int _C;
    public:
        void solve(vector<vector<char> > &board) 
        {
            if(board.size() == 0)
            {
                return ;
            }
            _R = board.size();
            _C = board.begin()->size();
            bool status = false;
            for(int i = 0; i < _R; ++i)
            {
                for(int k = 0; k < _C; ++k)
                {
                    if(board[i][k] == 'O')
                    {
                        status = true;
                        bfs(board, i, k, status); 
                    }
                }
            }
            for(int i = 0; i < _R; ++i)
            {
                for(int k = 0; k < _C; ++k)
                {
                    if(board[i][k] == '?')
                    {
                        board[i][k] = 'O';
                    }
                }
            }
        }
        void bfs(vector<vector<char> > &board, int r, int c, bool &status)
        {
            static const int dr[] = {1, -1, 0 , 0};
            static const int dc[] = {0, 0, -1 , 1};
            int front = 0;
            int rear = 0;
            node_t t;
            t.r = r;
            t.c = c;
            q[rear++] = t;
            board[t.r][t.c] = '?'; 
            while(front < rear)
            {
                t = q[front++];
                if(t.r == _R - 1 || t.r == 0 || t.c == _C - 1 || t.c == 0)
                {
                    status = false;
                }
                for(int i = 0 ; i < 4; ++i)
                {
                    int xr = t.r + dr[i];
                    int xc = t.c + dc[i];
                    if(xr < _R and xr >= 0 and xc < _C and xc >= 0 and board[xr][xc] == 'O')
                    {
                        q[rear++] = node_t(xr, xc);
                        board[xr][xc] = '?'; 
                    }
                }
            }
            if(status)
            {
                front = 0;
                while( front < rear )
                {
                    board[q[front].r][q[front].c] = 'X';
                    front++;
                }
            }            
        }
};
/*
char *test_case[] = {
    "xxxx",
    "xoox",
    "xxox",
    "xoxx",
    NULL
};
*/
/*
char *test_case[] = {
    "XXX",
    "XOX",
    "XXX",
    NULL
};
*/

const char *test_case[] = {
"XOOOOOOOOOOOOOOOOOOO",
"OXOOOOXOOOOOOOOOOOXX",
"OOOOOOOOXOOOOOOOOOOX",
"OOXOOOOOOOOOOOOOOOXO",
"OOOOOXOOOOXOOOOOXOOX",
"XOOOXOOOOOXOXOXOXOXO",
"OOOOXOOXOOOOOXOOXOOO",
"XOOOXXXOXOOOOXXOXOOO",
"OOOOOXXXXOOOOXOOXOOO",
"XOOOOXOOOOOOXXOOXOOX",
"OOOOOOOOOOXOOXOOOXOX",
"OOOOXOXOOXXOOOOOXOOO",
"XXOOOOOXOOOOOOOOOOOO",
"OXOXOOOXOXOOOXOXOXOO",
"OOXOOOOOOOXOOOOOXOXO",
"XXOOOOOOOOXOXXOOOXOO",
"OOXOOOOOOOXOOXOXOXOO",
"OOOXOOOOOXXXOOXOOOXO",
"OOOOOOOOOOOOOOOOOOOO",
"XOOOOXOOOXXOOXOXOXOO",
NULL,
};                                                                                                                                                           
int main()
{
    Solution slt;
    int i = 0; 
    vector<vector<char> > board;
    for(int i = 0; test_case[i]; ++i)
    {
        vector<char> v;
        for(int k = 0 ; test_case[i][k] != 0; ++k)
        {
            v.push_back(test_case[i][k]); 
        }
        board.push_back(v);
    }
    for(int i = 0 ; test_case[i]; ++i)
    {
        for(int k = 0 ; test_case[i][k] != 0; ++k)
        {
            cout << board[i][k];
        }
        cout << endl;
    }
    cout   << endl;
    slt.solve(board); 
    for(int i = 0 ; test_case[i]; ++i)
    {
        for(int k = 0 ; test_case[i][k] != 0; ++k)
        {
            cout << board[i][k];
        }
        cout << endl;
    }
}
