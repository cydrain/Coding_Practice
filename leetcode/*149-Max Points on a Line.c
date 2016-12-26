/*
 * Max Points on a Line
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */

    bool sameLine(Point p1, Point p2, Point p3){  
        return ((p2.y-p1.y)*(p3.x-p1.x) == (p3.y-p1.y)*(p2.x-p1.x));
    }
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n <= 2) return n;
        int maxnum = 2, dup, curr;
        int i, j, k;
        
        for (i = 0; i < n; i++) {
            dup = 0;
            for (j = i+1; j < n; j++) {
                curr = 1;   // now only 1 point
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;  // same as the start point
                    continue;
                }
                
                curr++;     // now get 2 points, start point and end point
                for (k = j+1; k < n; k++) {
                    if (sameLine(points[i], points[j], points[k])) {
                        curr++;
                    }
                }
                
                maxnum = max(maxnum, curr+dup);
            }
            maxnum = max(maxnum, curr+dup);
        }
        
        return maxnum;
    }

