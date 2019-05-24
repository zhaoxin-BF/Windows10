<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java_JDBC.LoginDao" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>检查登录</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <%   
		String uname = request.getParameter("name");
		String upassword  = request.getParameter("password");
		
		LoginDao dao = new LoginDao();
		int ret = dao.login(uname, upassword);
		if(ret > 0)
			out.print("登录成功！");
		else if(ret == 0)
			out.print("用户名或密码有误！！");
		else
			out.print("系统异常！！");
	%>    
  </body>
</html>
