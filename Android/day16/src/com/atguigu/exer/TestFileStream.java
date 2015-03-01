package com.atguigu.exer;

import java.io.*;

import org.junit.Test;

public class TestFileStream {
	@Test
	public void test1() {
		File file1 = new File("/Users/yucai/Coding_Practice/Android/day16/1.txt");
		File file2 = new File("/Users/yucai/Coding_Practice/Android/day16/3.txt");
		
		BufferedReader br = null;
		BufferedWriter bw = null;
		try {
			FileInputStream fis = new FileInputStream(file1);
			FileOutputStream fos = new FileOutputStream(file2);
			
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF-8");
			
			br = new BufferedReader(isr);
			bw = new BufferedWriter(osw);
			
			String s = null;
			while ((s = br.readLine()) != null) {
				bw.write(s);
				bw.newLine();
				bw.flush();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {		
			if (bw != null) {
				try {
					bw.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if (br != null) {
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
	
	@Test
	public void test() {
		File file1 = new File("/Users/yucai/Coding_Practice/Android/day16/1.txt");
		File file2 = new File("/Users/yucai/Coding_Practice/Android/day16/2.txt");
		
		BufferedInputStream bis = null;
		BufferedOutputStream bos = null;
		try {
			FileInputStream fis = new FileInputStream(file1);
			FileOutputStream fos = new FileOutputStream(file2);
			
			bis = new BufferedInputStream(fis);
			bos = new BufferedOutputStream(fos);
			
			byte[] b = new byte[64];
			int len;
			while ((len = bis.read(b)) != -1) {
				bos.write(b, 0, len);
				bos.flush();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {		
			if (bos != null) {
				try {
					bos.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if (bis != null) {
				try {
					bis.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
}