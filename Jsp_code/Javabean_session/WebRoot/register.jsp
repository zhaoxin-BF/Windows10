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
    
    <title>register</title>
    
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
    	student stu = new student();
		String sno = request.getParameter("sno");
		String sname = request.getParameter("sname");
		String sdno = request.getParameter("sdno");
    	if(sno != "" && sname != "")
    	{
	    	stu.setSno(sno);
	    	stu.setSname(sname);
	    	stu.setSdno(sdno);
	    	
    		session.setAttribute("stu", stu);
    		response.sendRedirect("success.jsp");
    	}
    	else
    	{
    		response.sendRedirect("failure.jsp");
    	}
     %>
  </body>
</html>
