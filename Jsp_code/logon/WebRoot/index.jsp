<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
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
  	<center><h1>用户登录</h1></center>
    <center>
    	<form action="index.jsp">
	    	用户名：<input type="text" name="Username"><br>
	    	密码啊：<input type="password" name="Password"><br>
	    	<input type="submit" value="登录">
	    	<input type="reset" value="重置"><br>
    	</form>
    	
    	<%
    		String u = request.getParameter("Username");
    		String p = request.getParameter("Password");
    		if("zhaoxin".equals(u)&&"123456".equals(p))
    		{
			    response.sendRedirect("Hello.jsp");
    		}
    	 %>
    </center>
  </body>
</html>
