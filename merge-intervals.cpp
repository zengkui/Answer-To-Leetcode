/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution 
{
    class Point
    {
        public :
            int idx;
            int flag;
        public:
            bool operator < ( const  Point &p ) const
            {
                if ( idx != p.idx )
                {
                    return idx < p.idx;
                }
                return flag < p.flag;
            }
    };
    public:    
        vector<Interval> merge(vector<Interval> &intervals) 
        {            
            vector<Interval> result;
            if (intervals.size() <= 0 )
            {
                return result;
            }
            vector<Point> vp;
            Point p;
            vector<Interval> ::iterator itr;
            for( itr = intervals.begin(); itr != intervals.end(); ++itr )
            {
                p.idx = itr->start;
                p.flag = -1;
                vp.push_back(p); 

                p.idx = itr->end;
                p.flag = 1;
                vp.push_back(p); 
            }
            vector<Point> ::iterator pitr;
            sort(vp.begin(), vp.end());

            int left;
            int right;
            int cnt = 0;

            for(pitr = vp.begin(); pitr != vp.end(); pitr++)
            {
                if ( cnt == 0 )
                {
                    left = pitr->idx;
                }
                if ( pitr->flag == 1 )
                {
                    right = pitr->idx;
                }
                cnt += pitr->flag;
                if ( cnt == 0 )
                {
                    result.push_back(Interval(left, right));
                }
            }
            return result;
        }
};
