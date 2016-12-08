package com.atguigu.java;

import java.util.LinkedList;
import java.util.Queue;

class Pair {
    public final int first;
    public final int second;
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    public String toString() {
    	String s = "" + "[" + first + "," + second + "]";
    	return s;
    }
}
public class TestRegion {
    public static void main(String[] args) {
        char[][] board = new char[][]{{'O','O','O'},{'O','O','O'},{'O','O','O'}};
        solve(board);
        System.out.println(board[0]);
        System.out.println(board[1]);
        System.out.println(board[2]);
    }
    public static void bfs(char[][] board, int x, int y) {
    	int m = board.length;
    	int n = board[0].length;
        Queue<Pair> q = new LinkedList<>();
        int i, j;
        board[x][y] = '.';
        q.offer(new Pair(x,y));
        while (q.size() != 0) {
            i = q.peek().first;
            j = q.peek().second;
            q.poll();
            System.out.println("get [" + i + "," + j + "]");
            board[i][j] = '.';
            if (i > 0 && board[i-1][j] == 'O') {
            	board[i-1][j] = '.';
            	q.offer(new Pair(i-1, j));
            }
            if (i < m-1 && board[i+1][j] == 'O') {
            	board[i+1][j] = '.';
            	q.offer(new Pair(i+1, j));
            }
            if (j > 0 && board[i][j-1] == 'O') {
            	board[i][j-1] = '.';
            	q.offer(new Pair(i, j-1));
            }
            if (j < n-1 && board[i][j+1] == 'O') {
            	board[i][j+1] = '.';
            	q.offer(new Pair(i, j+1));
            }
        }
    }
    public static void solve(char[][] board) {
        int m = board.length;
        if (m <= 2) return;
        int n = board[0].length;
        if (n <= 2) return;
        int i, j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) &&
                    (board[i][j] == 'O')) {
                	bfs(board, i, j);
                }
            }
        }
        System.out.println(board[0]);
        System.out.println(board[1]);
        System.out.println(board[2]);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}