/*
Kill Process

Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example 1:

Input: 
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation: 
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
 */ 
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        vector<int> ans;
        int n = pid.size(), i, j, p;
        for (i = 0; i < n; i++) {
            m[pid[i]] = ppid[i];
        }
        for (auto item : m) {
            for (p = item.first; m[p] != 0 && p != kill; p = m[p]);
            for (j = item.first; j != p; j = m[j]) {
                m[j] = p;
                if (p == kill) s.insert(j);
            }
        }
        s.insert(kill);
        for (int p : s) ans.push_back(p);
        return ans;
    }
};


class Solution {
public:
    void killProcess(unordered_map<int, vector<int>>& m, vector<int>& res, int kill) {
        res.push_back(kill);
        for (int i = 0; i < m[kill].size(); i++) {
            killProcess(m, res, m[kill][i]);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        vector<int> ans;
        int n = pid.size(), i, j;
        for (i = 0; i < n; i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        killProcess(m, ans, kill);
        return ans;
    }
};
