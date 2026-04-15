class Solution
{
public:
    int leastInterval(vector<char> &tasks, int cooldown)
    {
        vector<int> freq(26, 0);

        for (char t : tasks)
        {
            freq[t - 'A']++;
        }

        priority_queue<int> maxFreqHeap;
        for (int f : freq)
        {
            if (f > 0)
            {
                maxFreqHeap.push(f);
            }
        }

        int currentTime = 0;

        queue<pair<int, int>> cooldownQueue;

        while (!maxFreqHeap.empty() || !cooldownQueue.empty())
        {
            currentTime++;

            if (!maxFreqHeap.empty())
            {
                int remaining = maxFreqHeap.top();
                maxFreqHeap.pop();
                remaining--;

                if (remaining > 0)
                {
                    cooldownQueue.push({remaining, currentTime + cooldown});
                }
            }
            else
            {

                currentTime = cooldownQueue.front().second;
            }

            if (!cooldownQueue.empty() && cooldownQueue.front().second == currentTime)
            {
                maxFreqHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return currentTime;
    }
};