typedef vector<Point> :: iterator VITR;
class coef_t 
{
    public :
        int den; 
        int num;
    public :
        coef_t () : den(0), num(0){}
        coef_t (const int &_den, const int &_num ) : den(_den), num(_num){}
    public :
        bool operator == (const coef_t & a ) const 
        {
            /*
                num    a.num
                ---  = -----   ==>  num * a.den == a.num * den ( den != 0 and a.den != 0)
                den    a.den
            */
            return (num * a.den == a.num * den);
        }
        bool operator != (const coef_t & a ) const 
        {
            return (num * a.den != a.num * den);
        }
        bool operator < (const coef_t & a ) const 
        {
            double t1 = (double)num/(double)den; 
            double t2 = (double)a.num/(double)a.den; 
            return t1 < t2; 
        }
        string to_string() const 
        {
            static char buffer[1024];
            sprintf(buffer, "(%d, %d)", num, den);
            return buffer;
        }
};
class line_t
{
    public :
        coef_t k;
        coef_t b;
        line_t () {}
        line_t (const coef_t &_k, const coef_t &_b) : k(_k), b(_b) {} 
        bool operator < (const line_t &l ) const 
        {
            if( k != l.k )
            {
                return k < l.k;
            }
            return b < l.b;
        }
        bool operator == (const line_t &l ) const 
        {
            return ((k == l.k) && (b == l.b));
        }
        bool operator != (const line_t &l ) const 
        {
            bool t = ((k != l.k) || (b != l.b));
            return ((k != l.k) || (b != l.b));
        }
        string to_string()
        {
            sprintf( buffer, "y = %sx + %s", k.to_string().c_str(), b.to_string().c_str());
            return buffer;
        }
};
class cmp
{
    public:
        bool operator()( const Point &p1, const Point &p2 ) const 
            {
                if ( p1.x != p2.x )
                {
                    return p1.x < p2.x;
                }
                if ( p1.y != p2.y )
                {
                    return p1.y < p2.y;
                }
                return false;
            }
    };

class Solution 
{
    public:    

    int maxPoints(vector<Point> &points) 
    {            
        int total = points.size();
        if ( total <= 2 )
        {
            return total; 
        }
        int maxp = get_same_cordinate(points);

        vector<line_t> lines;
        line_t line;
        for( int a = 0; a < total; ++a )
        {
            for( int b = 0; b < a; ++b )
            {
                bool ok = line_constructor(points[a], points[b], line); 
                if ( ok )
                {
                    lines.push_back(line);
                }
            }
        }
        int lsize = lines.size();
        if ( lsize == 0 )
        {
            return maxp;
        }
        sort(lines.begin(), lines.end());
        int left = 0;
        int right = 1;
        int cnt = 0;
        int max_lines = 1;
        do{
            if ( lines[left] != lines[right] || right == lsize - 1 )
            {
                if ( cnt > max_lines )
                {
                    max_lines = cnt;
                    line = lines[left];
                }
                left = right;
                cnt = 0;
            }
            cnt++;
            right++;
        }while ( right < lsize);
        cnt = 0;
        for ( VITR  itr = points.begin(); itr != points.end(); ++itr )
        {
            if ( point_at_line(*itr, line) )
            {
                cnt++;
            }
        }
        if( cnt > maxp )
        {
            maxp = cnt;
        }
        return maxp;

    }
    private :
        bool point_at_line(const Point &p, const line_t &line )
        {   
            return p.y * line.k.den * line.b.den == line.k.num * line.b.den * p.x + line.b.num * line.k.den;
        }
        int get_same_cordinate( vector<Point> &points)
        {
            map<int, int> X;
            map<int, int> Y;
            int max = -1;
            for (VITR itr = points.begin(); itr != points.end(); ++itr )
            {
                X[itr->x] += 1;
                if (X[itr->x] > max )
                {
                    max = X[itr->x];
                }
                Y[itr->y] += 1;
                if (Y[itr->y] > max )
                {
                    max = Y[itr->y];
                }
            }
            return max;
        }


        bool line_constructor(const Point &p1, const Point &p2, line_t &line )
        {
            if ( p1.x == p2.x || p1.y == p2.y )
            {
                return false;
            }
            coef_t k;
            coef_t b;
            k.num = p1.y - p2.y;
            k.den = p1.x - p2.x;
            b.num = p1.y * k.den - k.num * p1.x; 
            b.den = p1.x - p2.x;
            line = line_t(k, b);
            return true;
        }
};

