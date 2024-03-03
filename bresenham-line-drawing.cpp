#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1, dy = abs(y1 - y2), p = 2 * dy - dx;

    for (int x = x1, y = y1; x <= x2; x++)
    {
        putpixel(x, y, WHITE);
        if (p >= 0)
        {
            p += 2 * (dy - dx);
            y1 < y2 ? y++ : y--;
        }
        else p += 2 * dy;
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100, x2 = 400, y2 = 370;
    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
