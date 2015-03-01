package com.atguigu.exer;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import org.junit.Test;

public class TestTCP {
	@Test
	public void client() {
		// 1.
		Socket socket = null;
		// 2.
		OutputStream os = null;
		Scanner scanner = null;
		// 4. receive msg from server
		InputStream is = null;
		try {
			socket = new Socket(InetAddress.getByName("127.0.0.1"), 9090);
			
			os = socket.getOutputStream();
			
			// 3. send msg to server
			System.out.println("Please input a string:");
			scanner = new Scanner(System.in);
			String str = scanner.next();
			os.write(str.getBytes());
			socket.shutdownOutput();
			
			is = socket.getInputStream();
			byte[] b = new byte[20];
			int len;
			while ((len = is.read(b)) != -1) {
				String str1 = new String(b, 0, len);
				System.out.println(str1);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			// 5. close all resource
			if (is != null) {
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (scanner != null) {
				scanner.close();
			}
			if (os != null) {
				try {
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (socket != null) {
				try {
					socket.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
	@Test
	public void server() {
		ServerSocket ss = null;
		Socket s = null;
		InputStream is = null;
		OutputStream os = null;
		try {
			ss = new ServerSocket(9090);
			s = ss.accept();
			
			// 3. receive the msg from client
			is = s.getInputStream();
			byte[] b = new byte[20];
			int len;
			String str = new String();
			while ((len = is.read(b)) != -1) {
				String str1 = new String(b, 0, len);
				str += str1;
			}
			String strUpperCase = str.toUpperCase();
			
			os = s.getOutputStream();
			os.write(strUpperCase.getBytes());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (os != null) {
				try {
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (is != null) {
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (s != null) {
				try {
					s.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (ss != null) {
				try {
					ss.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}
