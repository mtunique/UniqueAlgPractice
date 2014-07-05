#include <fstream>
#include <math.h>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("tetris.in");
ofstream fout("tetris.out");

const int oo = 1000000000;
int f[1001][6561];
int g[1001][9];
int n;
int maxstat;
int curline[9];
int nxtline[9];

void init()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=8; j++)
            cin >> g[i][j];
    maxstat = (int)pow(3, 8) - 1;
    for (int i=0; i<=n; i++)
        for (int j=0; j<= maxstat; j++)
            f[i][j] = -oo;
}

void dfs(int lev, int x, int y, int income)
{
    int t1, t2;
    int done = 0;
    if (lev == 9)
    {
        int z = 0;
        for (int i=8; i>=1; i--)
        {
            z *= 3;
            if (nxtline[i] == 1)
                z += 2;
            else
                z += curline[i]/2;
        }
        f[x+1][z] = max(f[x+1][z], f[x][y] + income);
        return;
    }
    dfs(lev+1, x, y, income);
  if (nxtline[lev] == 0)
  {
    if ( (curline[lev] == 0) )
    {
        curline[lev] = 2;
        nxtline[lev] = 1;
        dfs(lev+1, x, y, income+1);
        curline[lev] = 0;
        nxtline[lev] = 0;
    }
    else
    if ( (lev >= 2) && (curline[lev-1] != 2) && (curline[lev] != 2) )
    {
        t1 = curline[lev-1];
        t2 = curline[lev];
        curline[lev-1] = 2;
        curline[lev] = 2;
        nxtline[lev] = 1;
        dfs(lev+1, x, y, income+1);
        curline[lev-1] = t1;
        curline[lev] = t2;
        nxtline[lev] = 0;
    }
    else
    if ( (lev <= 7) && (curline[lev] != 2) && (curline[lev+1] != 2) )
    {
        t1 = curline[lev];
        t2 = curline[lev+1];
        curline[lev] = 2;
        curline[lev+1] = 2;
        nxtline[lev] = 1;
        dfs(lev+1, x, y, income+1);
        curline[lev] = t1;
        curline[lev+1] = t2;
        nxtline[lev] = 0;
    } 
            
    if ( (lev <= 6) && (nxtline[lev+1] == 0) && (nxtline[lev+2] == 0) )
    {
        nxtline[lev] = 1;
        nxtline[lev+1] = 1;
        nxtline[lev+2] = 1;
        dfs(lev+3, x, y, income+1);
        nxtline[lev] = 0;
        nxtline[lev+1] = 0;
        nxtline[lev+2] = 0;
    }


    if ( (lev <= 7) && (curline[lev] != 2) && (nxtline[lev+1] == 0) )
    {
        t1 = curline[lev];
        curline[lev] = 2;
        nxtline[lev] = 1;
        nxtline[lev+1] = 1;
        dfs(lev+2, x, y, income+1);
        curline[lev] = t1;
        nxtline[lev] = 0;
        nxtline[lev+1] = 0;
    }
    else
    if ( (lev <= 7) && (curline[lev+1] != 2) && (nxtline[lev+1] == 0) )
    {
        t1 = curline[lev+1];
        curline[lev+1] = 2;
        nxtline[lev] = 1;
        nxtline[lev+1] = 1;
        dfs(lev+2, x, y, income+1);
        curline[lev+1] = t1;
        nxtline[lev] = 0;
        nxtline[lev+1] = 0;
    }
  }
}

void work()
{
    f[0][maxstat] = 0;
    for (int i=0; i<=n-1; i++)
    {
        for (int j=0; j<=maxstat; j++)
            if (f[i][j] >= 0)
            {
                int t = j;
                for (int k=1; k<=8; k++)
                {
                    curline[k] = j % 3;
                    j = j/3;
                }
                j = t;
                for (int k=1; k<=8; k++)
                    nxtline[k] = g[i+1][k];
                dfs(1, i, j, 0);
            }
    }
    int ans = 0;
    for (int i=0; i<=maxstat; i++)
        if (f[n][i] > ans)
            ans = f[n][i];
    cout << ans << endl;
}

int main()
{
    init();
    work();
    return 0;
} 
