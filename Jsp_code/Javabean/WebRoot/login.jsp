<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>登录</title>
    
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
  	<font color="blue"><h1>用户登录系统</h1></font>
    <form action="index.jsp" method="get">
    	
    	用户名：<input type="text" name="name">
    	<br>
    	密&nbsp;码啊：<input type="password" name="password">
    	<br>
    	ID：<input type="text" name="id">
    	<br>
    	<input type="submit" value="登录">
    </form>
 	</center>
  </body>
</html>
