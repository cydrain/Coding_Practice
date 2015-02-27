package com.atguigu.exer;

public class EcmDef {
	public static void main(String[] args) {
		try {
			int i = Integer.parseInt(args[0]);
			int j = Integer.parseInt(args[1]);
			ecm(i, j);
		} catch (NumberFormatException e) {
			System.out.println("number format mis-match");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("need 2 input number");
		} catch (ArithmeticException e) {
			System.out.println("0 cannot be used as divisor");
		} catch (EcDef e) {
			System.out.println(e.getMessage());
		}
	}
	
	public static void ecm(int i, int j) throws EcDef {
		if (i < 0 || j < 0) {
			throw new EcDef("Get negative input number");
		}
		System.out.println(i/j);
	}
}

class EcDef extends Exception {
	final static long serialVersionUID = 123456789L;
	public EcDef() {
		super();
	}
	public EcDef(String msg) {
		super(msg);
	}
}