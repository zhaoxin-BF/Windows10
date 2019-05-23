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
  <center>
    		<form action="rate.jsp" method="post">
    			请输入美元：<input type="text" name="dollar"><br>
    		</form>
    		
    		<%
    			String s = request.getParameter("dollar");
    			if(s!=null && s.length()>0)
    			{
    				double n =Double.parseDouble(s);
    				double result = n*7.8;
    				out.print(s+"美元 = "+result+"人民币");
    			}
    		 %>
  </center>

  </body>
</html>
