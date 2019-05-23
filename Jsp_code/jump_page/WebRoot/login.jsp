<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'login.jsp' starting page</title>
    
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
  <center>
 	<font color="green"><h1>用户登录系统</h1></font>
 	<br>
    <form action="login.jsp">
    		用户名：<input type="text" name="username">
    		<br>
    		密码啊：<input type="password" name="password">
    		<br>
    		<input type="submit" value="登录">
    		<input type="reset" value="重置">
    </form>
    <%
   	    String u = request.getParameter("username");
   		String p = request.getParameter("password");
   		if("zhaoxin".equals(u)&&"123456".equals(p))
   		{
		    response.sendRedirect("welcome.jsp");
   		}
     %>
  </center>
  

  </body>
</html>
