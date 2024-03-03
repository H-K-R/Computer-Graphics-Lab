#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void drawCircle(int xc, int yc, int radius)
{
    vector<pair<int, int>> points;
    int x = 0, y = radius;
    int p = 1 - radius;
    while (x <= y)
    {
        points.push_back({x, y});
        points.push_back({y, x});
        x++;
        if (p >= 0)
        {
            p += 2 * (x - y) + 1;
            y--;
        }
        else p += 2 * x + 1;
    }
    for (auto v: points)
    {
        putpixel(xc + v.first, yc + v.second, WHITE);
        putpixel(xc - v.first, yc + v.second, WHITE);
        putpixel(xc + v.first, yc - v.second, WHITE);
        putpixel(xc - v.first, yc - v.second, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 200, radius = 150;
    drawCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
