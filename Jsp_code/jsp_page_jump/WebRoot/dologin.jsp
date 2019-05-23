<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	String path=request.getContextPath();
	String basePath=request.getScheme()+"://"+request.getServerName() +":"+request.getServerPort()+path+"/";
	String username="";
	String password="";
	request.setCharacterEncoding("utf-8");
	username=request.getParameter("username");
	password=request.getParameter("password");
	out.println(username);
	out.println(password);
	if("admin".equals(username) && "admin".equals(password)){
		session.setAttribute("loginUsername", username);
		session.setAttribute("loginUser",username);
		request.getRequestDispatcher("login_success.jsp").forward(request,response);
	}else{
		response.sendRedirect("login_failure.jsp");
	}	
%>