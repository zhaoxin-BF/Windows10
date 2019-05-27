<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<jsp:useBean id="user" scope="session" class="zhaoxin.javabean.Student"/>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'check.jsp' starting page</title>
    
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
    	String sno = request.getParameter("sno");
    	String spasswd = request.getParameter("spasswd");
    	if(sno.equals("95001") && spasswd.equals("123"))
    	{
    	%>
    		<jsp:setProperty property="*" name="user"/>
    		<jsp:forward page="success.jsp"/>
    	<% 
    	}
    	else
    	{
    	%>
    		<jsp:forward page="failure.jsp"/>
    	<%
    	}
    %>
  </body>
</html>
