class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int totalPoints = points.size();

        if (totalPoints <= 2) {
            return totalPoints;
        }

        int maximumPoints = 0;

        for (int firstPoint = 0; firstPoint < totalPoints; firstPoint++) {
            unordered_map<string, int> lineCount;
            int currentMaximum = 0;

            for (int secondPoint = firstPoint + 1; secondPoint < totalPoints; secondPoint++) {
                int xDifference = points[secondPoint][0] - points[firstPoint][0];
                int yDifference = points[secondPoint][1] - points[firstPoint][1];

                int commonFactor = gcd(abs(xDifference), abs(yDifference));

                xDifference /= commonFactor;
                yDifference /= commonFactor;
                if (xDifference < 0) 
                {xDifference = -xDifference;
                yDifference = -yDifference;}
                if (xDifference == 0) 
                {
                    yDifference = 1;
                }
                if (yDifference == 0) {
                    xDifference = 1;}
                string lineKey = to_string(xDifference) + "/" + to_string(yDifference);
        lineCount[lineKey]++;
        currentMaximum = max(currentMaximum, lineCount[lineKey]);
            }maximumPoints = max(maximumPoints, currentMaximum + 1);
        }return maximumPoints;
    }
};