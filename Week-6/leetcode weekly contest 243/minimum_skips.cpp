//Question link: https://leetcode.com/contest/weekly-contest-243/problems/minimum-skips-to-arrive-at-meeting-on-time/

//Error - Double value gets rounded off
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        double hours = 0;
        vector<double> skipTimes(dist.size());
        for(int i=0; i<dist.size()-1; i++){
            hours = hours + ceil(dist[i]*1.0/speed);
            skipTimes[i] = hours - dist[i]*1.0/speed;
        }
        hours += dist[dist.size()-1]*1.0/speed;
        
        if(hours <= hoursBefore)
            return 0;
        
        int skips = 0;
        for(int i=0; i<dist.size()-1; i++){
            double t = dist[i]*1.0/speed + dist[i+1]*1.0/speed;
            if(floor(t) == ceil(t)){
                skips += 1;
                hours -= skipTimes[i] + skipTimes[i+1];
                skipTimes[i] = 0;
                skipTimes[i+1] = 0;
            }
            if(hours <= hoursBefore)
                break;
        }
        
        if(hours <= hoursBefore)
            return skips;
        else{
            for(int i=0; i<dist.size()-1; i++){
                if(skipTimes[i] != 0){
                    hours -= skipTimes[i];
                    skips++;
                    skipTimes[i] = 0;
                }
                if(hours <= hoursBefore)
                break;
            }
            if(hours <= hoursBefore)
                return skips;
            return -1;
        }
    }
};
