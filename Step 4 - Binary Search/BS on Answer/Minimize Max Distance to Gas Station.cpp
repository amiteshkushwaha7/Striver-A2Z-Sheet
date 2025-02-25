//Brute Force
double findSmallestMaxDist(vector<int> &vec, int k) 
    {
        vector<double> stations(vec.begin(), vec.end());
        for (int station = 1; station <= k; station++) 
        {
            double maxGap = 0.0;
            int left = 0, right = 0;

            for (int i = 1; i < stations.size(); i++) 
            {
                double currentGap = stations[i] - stations[i - 1];
                if (currentGap >= maxGap) 
                {
                    maxGap = currentGap;
                    left = i - 1;
                    right = i;
                }
            }

            stations.push_back((stations[left] + stations[right]) / 2.0);
            sort(stations.begin(), stations.end());  
        }
 
        double maxGap = 0.0;
        for (int i = 1; i < stations.size(); i++) 
        {
            double currentGap = stations[i] - stations[i - 1];
            if (currentGap > maxGap) 
                maxGap = currentGap;
        }

        return maxGap;
    }