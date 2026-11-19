
#include <iostream>
#include <ctime>
using namespace std;

int prices[] = {100, 102, 101, 105, 103, 110, 108, 115, 112, 120};
int changes[9];

int maxProfit(int left, int right)
{

    if (left == right)
        return changes[left];

    int mid = (left + right) / 2;

    int a = maxProfit(left, mid);
    int b = maxProfit(mid + 1, right);

    int sum = 0, leftMax = -100000;
    for (int i = mid; i >= left; i--)
    {
        sum += changes[i];
        if (sum > leftMax)
            leftMax = sum;
    }

    sum = 0;
    int rightMax = -100000;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += changes[i];
        if (sum > rightMax)
            rightMax = sum;
    }

    int c = leftMax + rightMax;

    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}

// Linear Scan
int linearScan()
{
    int current = 0, best = 0;

    for (int i = 0; i < 9; i++)
    {
        current += changes[i];

        if (current < 0)
            current = 0;

        if (current > best)
            best = current;
    }

    return best;
}

int main()
{

    for (int i = 0; i < 9; i++)
        changes[i] = prices[i + 1] - prices[i];

    clock_t start = clock();
    int result1 = maxProfit(0, 8);
    double time1 = double(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    int result2 = linearScan();
    double time2 = double(clock() - start) / CLOCKS_PER_SEC;

    cout << "Divide and Conquer Profit: " << result1 << endl;
    cout << "Linear Scan Profit: " << result2 << endl;

    cout << "Divide and Conquer Time: " << time1 << endl;
    cout << "Linear Scan Time: " << time2 << endl;

    cout << "Results Match: "
         << (result1 == result2 ? "Yes" : "No") << endl;

    return 0;
}
