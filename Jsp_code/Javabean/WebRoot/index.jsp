<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<jsp:useBean id="zhaoxin" scope="session" class="zhaoxin.bean.PersonBean">

<jsp:setProperty name="zhaoxin" property="*"/>

</jsp:useBean>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>首页</title>
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
  <%=zhaoxin.getName() %>
  <br>
  <%=zhaoxin.getPassword() %>
  <br>
  <%=zhaoxin.getId() %>
  
  	<br>
    <jsp:getProperty  name="zhaoxin" property="name"/>
    <jsp:getProperty  name="zhaoxin" property="password"/>
    <br>
    <jsp:getProperty  name="zhaoxin" property="id"/>
    <br>
  </body>
</html>
