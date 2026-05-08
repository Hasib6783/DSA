#include <iostream>
#include "quetype.cpp"
using namespace std;

int main()
{
    int n, amount;

    cin >> n;

    int coins[n];
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cin >> amount;

    QueType<int> q;

    bool visited[10000] = {false};

    q.Enqueue(0);
    visited[0] = true;

    int count = 0;
    bool found = false;

    while(!q.IsEmpty() && !found)
    {
        int levelSize = 0;
        QueType<int> q2;

       
        while(!q.IsEmpty())
        {
            int val;
            q.Dequeue(val);
            q2.Enqueue(val);
            levelSize++;
        }

        count++; 

       
        for(int i = 0; i < levelSize; i++)
        {
            int curr;
            q2.Dequeue(curr);

            for(int j = 0; j < n; j++)
            {
                int next = curr + coins[j];

                if(next == amount)
                {
                    found = true;
                    break;
                }

                if(next < amount && !visited[next])
                {
                    visited[next] = true;
                    q.Enqueue(next);
                }
            }

            if(found) break;
        }
    }

    if(found)
        cout << "Possible. Min No. of coins = " << count << endl;
    else
        cout << "Not possible" << endl;

    return 0;
}