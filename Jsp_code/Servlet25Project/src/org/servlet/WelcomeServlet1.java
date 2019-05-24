package org.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@SuppressWarnings("serial")//Servlet2.5–Ë“™≈‰÷√web.xml
public class WelcomeServlet1 extends HttpServlet{
	
	public void init() {
		System.out.print("init....");
	}
	
	public void destory() {
		System.out.print("destory....");
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("doGet");
		response.getWriter().print("doGet");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("doPost");
		response.getWriter().print("doPost");
	}

}
