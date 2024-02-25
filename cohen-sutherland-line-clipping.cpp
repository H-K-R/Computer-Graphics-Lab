#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

double x_left = 120, x_right = 500, y_bottom = 100, y_top = 350; //... Clipping window
int Left = 1, Right = 2, Bottom = 4, Top = 8; //... Region code

int regionCode(int x, int y)
{
    int code = 0;
    if (x > x_right) code |= Right;
    else if (x < x_left) code |= Left;
    if (y > y_top) code |= Top;
    else if (y < y_bottom) code |= Bottom;
    return code;
}

void cohenSutherland(double x1, double y1, double x2, double y2)
{
    int code1 = regionCode(x1, y1);
    int code2 = regionCode(x2, y2);
    while (true)
    {
        double x, y;
        if (!(code1 | code2)) //... Line is completely inside
        {
            line(x1, y1, x2, y2);
            return;
        }
        else if (code1 & code2) break; //... Line is completely outside
        else //... Line is partially inside
        {
            int code = code1 ? code1 : code2;
            if (code & Top)
            {
                y = y_top;
                x = x1 + (x2 - x1) / (y2 - y1) * (y - y1);
            }
            else if (code & Bottom)
            {
                y = y_bottom;
                x = x1 + (x2 - x1) / (y2 - y1) * (y - y1);
            }
            else if (code & Left)
            {
                x = x_left;
                y = y1 + (y2 - y1) / (x2 - x1) * (x - x1);
            }
            else if (code & Right)
            {
                x = x_right;
                y = y1 + (y2 - y1) / (x2 - x1) * (x - x1);
            }
            if (code == code1)
            {
                x1 = x;
                y1 = y;
                code1 = regionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = regionCode(x2, y2);
            }
        }
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    setcolor(YELLOW);
    rectangle(x_left, y_bottom, x_right, y_top);
    line(50, 200, 500, 400);
    setcolor(WHITE);
    cohenSutherland(50, 200, 500, 400);

    getch();
    closegraph();
    return 0;
}
