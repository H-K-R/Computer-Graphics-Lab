#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void snowfalke(int x1, int y1, int x5, int y5, int it)
{
    if (it)
    {
        vector<pair<int, int>> x(5);
        int dx = (x5 - x1) / 3, dy = (y5 - y1) / 3;
        x[0] = {x1, y1};
        x[1] = {x1 + dx, y1 + dy};
        x[2] = {(x1 + x5) / 2 + sqrt(3) * (y1 - y5) / 6, (y1 + y5) / 2 + sqrt(3) * (x5 - x1) / 6};
        x[3] = {x1 + 2 * dx, y1 + 2 * dy};
        x[4] = {x5, y5};
        for (int i = 0; i < 4; i++)
        {
            snowfalke(x[i].first, x[i].second, x[i + 1].first, x[i + 1].second, it - 1);
        }
    }
    else line (x1, y1, x5, y5);
    delay(5);
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int iteration = 4;
    vector<pair<int, int>> x = {{250, 15}, {50, 350}, {450, 350}};
    for (int i = 0; i < 3; i++)
    {
        snowfalke(x[i].first, x[i].second, x[(i + 1) % 3].first, x[(i + 1) % 3].second, iteration);
    }

    getch();
    closegraph();
    return 0;
}
