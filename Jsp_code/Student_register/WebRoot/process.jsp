<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'process.jsp' starting page</title>
    
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
        String sname = request.getParameter("sname");
        String sdno = request.getParameter("sdno");
        
    	String[] std = new String[3];
    	if(sno!=null && sname!=null && sdno!=null )
		{
			std[0] = sno;
			std[1] = sname;
			std[2] = sdno;
					
	    	application.setAttribute("std", std);
	    	response.sendRedirect("success.jsp");
		}
		else
		{
			response.sendRedirect("input.jsp");
		}
    %>
    
  </body>
</html>
