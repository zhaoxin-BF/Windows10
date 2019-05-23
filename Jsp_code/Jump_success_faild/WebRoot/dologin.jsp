<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>

  	<%
  		String n = request.getParameter("username");
  		String p = request.getParameter("password");
  		
  		if("zhaoxin".equals(n) && "123456".equals(p))
   			response.sendRedirect("success.jsp");
		else
   			response.sendRedirect("faild.jsp");
  	 %>
