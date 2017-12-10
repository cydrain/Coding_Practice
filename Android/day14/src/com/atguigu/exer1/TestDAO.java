package com.atguigu.exer1;

import java.util.List;

public class TestDAO {

	public static void main(String[] args) {
		DAO<User> dao = new DAO<>();
		
		dao.save("1001", new User(1, 36, "CaiYudong"));
		dao.save("1002", new User(2, 33, "ChaiLei"));
		dao.save("1003", new User(3, 57, "ChaiFuyu"));
		dao.save("1004", new User(4, 71, "CaiYijun"));
		
		User u = dao.get("1003");
		System.out.println(u);
		
		dao.update("1003", new User(5, 57, "ZhuLianfeng"));
		u = dao.get("1003");
		System.out.println(u);
		
		dao.delete("1004");
		List<User> list = dao.list();
		System.out.println(list);
	}

}
