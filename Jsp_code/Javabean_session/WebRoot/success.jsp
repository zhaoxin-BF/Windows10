<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="zhaoxin_javabean.student" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>success</title>
    
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
  	<font color="green"><h1>注册成功</h1></font>
    <%
    	student stu = (student)session.getAttribute("stu");
     %>
     <%out.print(stu.getSno());%>
     <br>
     <%out.print(stu.getSname());%>
     <br>
     <%out.print(stu.getSdno());%>
  </body>
</html>
