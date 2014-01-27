/*
 * Simplify Path
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 */

    string getOneDir(string path, int &i) {
        string s;
        while (path[i] && path[i] == '/') {
            i++;
        }
        while (path[i] && path[i] != '/') {
            s += path[i++];
        }
        return s;
    }
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = path.length();
        int i = 0;
        string str, r;
        stack<string> s;
        
        while (path[i]) {
            str = getOneDir(path, i);
            
            if (str.empty() || !str.compare(".")) {
                continue;
            }
            else if (!str.compare("..")) {
                if (!s.empty()) {
                    s.pop();
                }
            }
            else {
                s.push(str);
            }
        }
        
        while (!s.empty()) {
            str = s.top();
            s.pop();
            r = "/" + str + r;
        }
        return r.empty() ? string("/") : r;
    }
