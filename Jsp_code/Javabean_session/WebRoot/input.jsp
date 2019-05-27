<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>input</title>
    
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
    <font color="blue"><h1>学生注册</h1></font>
    <form action="register.jsp" method="post">
    	学号：<input type="text" name="sno"/>
    	<br>
    	姓名：<input type="text" name="sname"/>
    	<br>
    	座位：<input type="text" name="sdno"/>
    	<br>
    	<input type="submit" value="注册"/><input type="reset" value="重置"/>
    </form>
    </center>
  </body>
</html>
