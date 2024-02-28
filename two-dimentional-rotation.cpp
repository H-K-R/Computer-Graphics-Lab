#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void draw(vector<int> x, vector<int> y)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void rotation(vector<int> &x, vector<int> &y, int n, int angle, int xp, int yp)
{
    for (int i = 0; i < n; i++)
    {
        double radian = angle * (acos(-1.0) / 180), sin_term = sin(radian), cos_term = cos(radian);
        int x_shift = x[i] - xp, y_shift = y[i] - yp;
        x[i] = xp + (x_shift * cos_term) - (y_shift * sin_term); y[i] = yp + (x_shift * sin_term) + (y_shift * cos_term);
    }
}

int main()
{
    int n; //... Total vertex of the polygon
    cin >> n;
    vector<int> x(n), y(n); //... (x,y) coordinates of vertex points
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int angle; //... Rotation angle in degree
    cin >> angle;
    int x_pivot, y_pivot; //... Pivot point coordinates
    cin >> x_pivot >> y_pivot;

    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    draw(x, y); //... White polygon before rotation
    rotation(x, y, n, angle, x_pivot, y_pivot); //... Applying 2d geometric rotation
    setcolor(YELLOW);
    draw(x, y); //... Yellow polygon after rotation

    getch();
    closegraph();
    return 0;
}

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
4 100 100 100 200 200 200 200 100 45 200 200

*///...
